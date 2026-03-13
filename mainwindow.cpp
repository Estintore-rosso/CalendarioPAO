#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "DialogAggiungi.h"
#include "Model/Scadenza.h"
#include "Model/Task.h"
#include "Model/Appuntamento.h"
#include "Model/MeetingVirtuale.h"
#include "Model/AttivitaPersone.h"
#include <QTextCharFormat>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDialog>
#include <QColor>
#include <algorithm>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionAggiungi, &QAction::triggered, this, &MainWindow::on_actionAggiungi_triggered);
    connect(ui->actionSwitch, &QAction::triggered, this, [this]() {
    int paginaCorrente = ui->stackedWidget->currentIndex();
    ui->stackedWidget->setCurrentIndex(paginaCorrente == 0 ? 1 : 0);
});

// Importa JSON
connect(ui->actionImportaJson, &QAction::triggered, this, &MainWindow::on_actionImportaJson_triggered);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAggiungi_triggered()
{
    DialogAggiungi dialog(this);
    Attivita* nuovaAttivita = nullptr;
    if (dialog.exec() == QDialog::Accepted) {
        QString titolo = dialog.getTitolo();
        QString tipo = dialog.getTipo();
        QDateTime dataInizio = dialog.getDataInizio();
        QDateTime dataFine = dialog.getDataFine();
        QString descrizione = dialog.getDescrizione();
        bool tuttoGiorno = dialog.isGiorno();
        if(tipo == "Scadenza") {
            QString etichetta = dialog.getEtichetta();
            bool urgente = dialog.isUrgente();
            nuovaAttivita = new Scadenza(titolo, dataInizio, tuttoGiorno, etichetta, urgente);
        } else if(tipo == "Appuntamento") {
            QString luogo = dialog.getLuogo();
            std::vector<QString> persone;
            nuovaAttivita = new Appuntamento(titolo, dataInizio, tuttoGiorno, persone, luogo);

        } else if(tipo == "MeetingVirtuale") {
            QString link = dialog.getLink();
            std::vector<QString> persone;
            nuovaAttivita = new MeetingVirtuale(titolo, dataInizio, tuttoGiorno, persone, link);
        }else if(tipo == "Task") {
            nuovaAttivita = new Task(titolo);
        }

        if(nuovaAttivita) {
            if(!descrizione.isEmpty()) nuovaAttivita->setDescrizione(descrizione);
            if(dataFine.isValid()) nuovaAttivita->setDFine(dataFine);
            attivitaList.push_back(nuovaAttivita);
            aggiornaTutto();
        }
    }
}

void MainWindow::on_actionImportaJson_triggered() {
    // TODO
}

void MainWindow::aggiornaCalendario() {
    QTextCharFormat reset;
    ui->F1Calendario->setDateTextFormat(QDate(), reset);

    QTextCharFormat formato;
    formato.setBackground(QColor("#4A90D9"));
    formato.setForeground(QColor("white"));

    for(Attivita* a : attivitaList) {
        QDate data = a->getDInizio().date();
        if(data.isValid())
            ui->F1Calendario->setDateTextFormat(data, formato);
    }
}

void MainWindow::svuotaLayout(QLayout* layout) {
    QLayoutItem* item;
    while((item = layout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }
}

// Riga per attività normali: [Titolo]  [Info]  [Elimina]
QWidget* MainWindow::creaRigaAttivita(Attivita* a) {
    QWidget* riga = new QWidget();
    QHBoxLayout* layout = new QHBoxLayout(riga);
    layout->setContentsMargins(0, 0, 0, 0);

    QLabel* label = new QLabel(a->getTitolo());
    QPushButton* btnInfo = new QPushButton("ℹ");
    QPushButton* btnElimina = new QPushButton("🗑");
    btnInfo->setFixedWidth(30);
    btnElimina->setFixedWidth(30);

    layout->addWidget(label);
    layout->addStretch();
    layout->addWidget(btnInfo);
    layout->addWidget(btnElimina);

    connect(btnInfo, &QPushButton::clicked, this, [this, a]() {
        mostraDettagli(a);
    });
    connect(btnElimina, &QPushButton::clicked, this, [this, a]() {
        eliminaAttivita(a);
    });

    return riga;
}

// Riga per task: [☐ Titolo]  [Info]  [Elimina]
QWidget* MainWindow::creaRigaTask(Task* t) {
    QWidget* riga = new QWidget();
    QHBoxLayout* layout = new QHBoxLayout(riga);
    layout->setContentsMargins(0, 0, 0, 0);

    QCheckBox* check = new QCheckBox(t->getTitolo());
    QPushButton* btnInfo = new QPushButton("ℹ");
    QPushButton* btnElimina = new QPushButton("🗑");
    btnInfo->setFixedWidth(30);
    btnElimina->setFixedWidth(30);

    layout->addWidget(check);
    layout->addStretch();
    layout->addWidget(btnInfo);
    layout->addWidget(btnElimina);

    // Spuntare = eliminare
    connect(check, &QCheckBox::stateChanged, this, [this, t](int state) {
        if(state == Qt::Checked) eliminaAttivita(t);
    });
    connect(btnInfo, &QPushButton::clicked, this, [this, t]() {
        mostraDettagli(t);
    });
    connect(btnElimina, &QPushButton::clicked, this, [this, t]() {
        eliminaAttivita(t);
    });

    return riga;
}

void MainWindow::eliminaAttivita(Attivita* a) {
    auto it = std::find(attivitaList.begin(), attivitaList.end(), a);
    if(it != attivitaList.end()) {
        delete *it;
        attivitaList.erase(it);
        aggiornaTutto(); // ridisegna tutto
    }
}

void MainWindow::mostraDettagli(Attivita* a) {
    QDialog* dialog = new QDialog(this);
    dialog->setWindowTitle(a->getTitolo());
    QVBoxLayout* layout = new QVBoxLayout(dialog);

    layout->addWidget(new QLabel("Tipo: " + a->getTipo()));
    layout->addWidget(new QLabel("Inizio: " + a->getDInizio().toString("dd/MM/yyyy HH:mm")));
    if(a->getDFine().isValid())
        layout->addWidget(new QLabel("Fine: " + a->getDFine().toString("dd/MM/yyyy HH:mm")));
    if(!a->getDescrizione().isEmpty())
        layout->addWidget(new QLabel("Descrizione: " + a->getDescrizione()));

    QPushButton* chiudi = new QPushButton("Chiudi");
    connect(chiudi, &QPushButton::clicked, dialog, &QDialog::accept);
    layout->addWidget(chiudi);

    dialog->exec();
    delete dialog;
}

void MainWindow::aggiornaTutto() {
    aggiornaCalendario();    // aggiorna QCalendarWidget in page 1
    aggiornaListeAttivita(); // aggiorna le liste in page 2
    // in futuro potresti aggiungere anche aggiornaScrollPage1()
    // per F1ScrollAtt e F1ScrollTask
}

void MainWindow::aggiornaListeAttivita() {
    // svuota tutti i layout
    svuotaLayout(ui->F2VertTask);
    svuotaLayout(ui->F2VertOggi);
    svuotaLayout(ui->F2VertSett);
    svuotaLayout(ui->F2VertFut);

    QDate oggi = QDate::currentDate();

    for(Attivita* a : attivitaList) {
        Task* t = dynamic_cast<Task*>(a);

        if(t) {
            ui->F2VertTask->addWidget(creaRigaTask(t));
            continue; // i task non vanno nelle altre sezioni
        }

        QWidget* riga = creaRigaAttivita(a);
        QDate data = a->getDInizio().date();

        if(data == oggi)
            ui->F2VertOggi->addWidget(riga);
        else if(data <= oggi.addDays(7))
            ui->F2VertSett->addWidget(riga);
        else
            ui->F2VertFut->addWidget(riga);
    }
}