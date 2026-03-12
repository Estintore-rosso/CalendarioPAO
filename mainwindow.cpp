#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogaggiungi.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionAggiungi, &QAction::triggered, this, &MainWindow::on_actionAggiungi_triggered);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAggiungi_triggered()
{
    DialogAggiungi dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        QString titolo = dialog.getTitolo();
        QString tipo = dialog.getTipo();
        QDateTime dataInizio = dialog.getDataInizio();
        QDateTime dataFine = dialog.getDataFine();
        QString descrizione = getDescrizione();
        bool tuttoGiorno = isGiorno();
        if(tipo == "Scadenza") {
            QString etichetta = dialog.getEtichetta();
            bool urgente = dialog.isUrgente();
            Attivita* nuovaAttivita = new Scadenza(titolo, dataInizio, tuttoGiorno, etichetta, urgente);
        } elseif(tipo == "Appuntamento") {
            QString luogo = dialog.getLuogo();
            Attivita* nuovaAttivita = new Appuntamento(titolo, dataInizio, tuttoGiorno, luogo);
        } else if(tipo == "MeetingVirtuale") {
            QString link = dialog.getLink();
            QString partecipanti = dialog.getPartecipanti();
            Attivita* nuovaAttivita = new MeetingVirtuale(titolo, dataInizio, tuttoGiorno, link, partecipanti);
        } else if(tipo == "Task") {
            Attivita* nuovaAttivita = new Task(titolo);
        }

        if(descrizione != "") {
            nuovaAttivita->setDescrizione(descrizione);
        }
        
        nuovaAttiiva->setDataFine(dataFine);



         attivitaList.push_back(nuovaAttivita); // Aggiungi l'attività alla lista
        // Aggiungi il nuovo evento alla lista o al calendario
        // Ad esempio, potresti aggiungere una riga a una QTableWidget o aggiornare un modello di dati
    }
}