#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Visitatore.h"
#include <QMessageBox>
#include <QPainter>
#include <QStyledItemDelegate>
#include <QStyleOptionViewItem>
#include <QCompleter>
#include <QStringList>
#include <QSet>

// --- VISITATORI ---

class VisitatoreTesto : public Visitatore {
public:
    QString risultatoTesto;

    void visita(Esame& esame) override {
        risultatoTesto = QString("Tipo: Esame\nCFU: %1\nVoto: %2\nSuperato: %3")
                             .arg(esame.getCfu())
                             .arg(esame.getVoto())
                             .arg(esame.isSuperato() ? "Sì" : "No");
    }

    void visita(Progetto& progetto) override {
        risultatoTesto = QString("Tipo: Progetto\nPartecipanti: %1\nRepository: %2")
                             .arg(progetto.getNumeroPartecipanti())
                             .arg(progetto.getLinkRepo().isEmpty() ? "Nessun link" : progetto.getLinkRepo());
    }

    void visita(Evento& evento) override {
        risultatoTesto = QString("Tipo: Evento\nLink: %1\nPosizione: %2\nParteciperò: %3")
                             .arg(evento.getLinkMeeting().isEmpty() ? "N/A" : evento.getLinkMeeting())
                             .arg(evento.getPosizione().isEmpty() ? "N/A" : evento.getPosizione())
                             .arg(evento.getIntenzionePartecipare() ? "Sì" : "No");
    }
};

class VisitatoreFormUI : public Visitatore {
private:
    Ui::MainWindow* ui;
public:
    VisitatoreFormUI(Ui::MainWindow* uiPtr) : ui(uiPtr) {}

    void visita(Esame& esame) override {
        ui->stackedInterno->setCurrentIndex(0);
        ui->spinCFU->setValue(esame.getCfu());
        ui->spinVoto->setValue(esame.getVoto());
        ui->checkSuperato->setChecked(esame.isSuperato());
        ui->spinVoto->setEnabled(esame.isSuperato());
    }

    void visita(Progetto& progetto) override {
        ui->stackedInterno->setCurrentIndex(1);
        ui->spinPartecip->setValue(progetto.getNumeroPartecipanti());
        ui->editRepo->setText(progetto.getLinkRepo());
    }

    void visita(Evento& evento) override {
        ui->stackedInterno->setCurrentIndex(2);
        ui->editMeeting->setText(evento.getLinkMeeting());
        ui->editPosizione->setText(evento.getPosizione());
        ui->checkPartecipazione->setChecked(evento.getIntenzionePartecipare());
    }
};

// 0=Tutti, 1=Esami, 2=Progetti, 3=Eventi
class VisitatoreFiltroTipo : public Visitatore {
private:
    int filtro;
public:
    bool isMatch;
    VisitatoreFiltroTipo(int f) : filtro(f), isMatch(false) {}

    void visita(Esame&) override    { isMatch = (filtro == 0 || filtro == 1); }
    void visita(Progetto&) override { isMatch = (filtro == 0 || filtro == 2); }
    void visita(Evento&) override   { isMatch = (filtro == 0 || filtro == 3); }
};

class VisitatoreImpostaCombo : public Visitatore {
private:
    QComboBox* combo;
public:
    VisitatoreImpostaCombo(QComboBox* c) : combo(c) {}

    void visita(Esame&) override    { combo->setCurrentIndex(0); }
    void visita(Progetto&) override { combo->setCurrentIndex(1); }
    void visita(Evento&) override   { combo->setCurrentIndex(2); }
};

// delegate che mostra una spunta sull'item in hover
class CheckOnHoverDelegate : public QStyledItemDelegate {
public:
    using QStyledItemDelegate::QStyledItemDelegate;

    void paint(QPainter* painter, const QStyleOptionViewItem& option,
               const QModelIndex& index) const override
    {
        QStyledItemDelegate::paint(painter, option, index);

        if (option.state & QStyle::State_MouseOver) {
            painter->save();
            painter->setRenderHint(QPainter::Antialiasing);
            painter->setPen(option.palette.color(QPalette::HighlightedText));
            QRect r = option.rect;
            r.setLeft(r.right() - 22);
            painter->drawText(r, Qt::AlignVCenter | Qt::AlignHCenter, "✓");
            painter->restore();
        }
    }
};

// --- MAINWINDOW ---

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    ui->comboFiltroTipo->view()->setMouseTracking(true);
    ui->comboFiltroTipo->view()->setItemDelegate(new CheckOnHoverDelegate(ui->comboFiltroTipo));
    ui->comboTipo->view()->setMouseTracking(true);
    ui->comboTipo->view()->setItemDelegate(new CheckOnHoverDelegate(ui->comboTipo));

    ui->stackedPrincip->setCurrentIndex(2);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::aggiornaListaView() {
    ui->listaAttivita->clear();
    QDate oggi = QDate::currentDate();

    for (int i = 0; i < gestore.getNumeroAttivita(); ++i) {
        Attivita* a = gestore.getAttivita(i);
        if (!a) continue;

        QString urgenza = a->isUrgente(oggi) ? "🔴 " : "⚪ ";

        QString icona = "📅 ";
        if (dynamic_cast<Esame*>(a))    icona = "📝 ";
        else if (dynamic_cast<Progetto*>(a)) icona = "🛠 ";

        ui->listaAttivita->addItem(
            urgenza + icona + a->getTitolo() + " - " + a->getMateria()
            + "  |  " + a->getDataAttivita().toString("dd/MM/yyyy")
        );
    }

    applicaFiltri();
    aggiornaCompleterMaterie();
}

void MainWindow::svuotaCampiForm() {
    ui->editTitolo->clear();
    ui->editMateria->clear();
    ui->editDesc->clear();
    ui->editData->setDate(QDate::currentDate());
    ui->comboTipo->setCurrentIndex(0);
    ui->stackedInterno->setCurrentIndex(0);

    ui->spinCFU->setValue(1);
    ui->checkSuperato->setChecked(false);
    ui->spinVoto->setEnabled(false);
    ui->spinVoto->setValue(0);
    ui->spinPartecip->setValue(1);
    ui->editRepo->clear();
    ui->editMeeting->clear();
    ui->editPosizione->clear();
    ui->checkPartecipazione->setChecked(false);
}

void MainWindow::on_checkSuperato_toggled(bool checked) {
    ui->spinVoto->setEnabled(checked);
    if (!checked) ui->spinVoto->setValue(0);
}

void MainWindow::on_editRicerca_textChanged(const QString &) { applicaFiltri(); }
void MainWindow::on_comboFiltroTipo_currentIndexChanged(int) { applicaFiltri(); }
void MainWindow::on_checkFiltroUrgente_stateChanged(int)     { applicaFiltri(); }

void MainWindow::applicaFiltri() {
    QString testo = ui->editRicerca->text().toLower();
    int indiceTipo = ui->comboFiltroTipo->currentIndex();
    bool soloUrgenti = ui->checkFiltroUrgente->isChecked();
    QDate oggi = QDate::currentDate();

    for (int i = 0; i < gestore.getNumeroAttivita(); ++i) {
        Attivita* att = gestore.getAttivita(i);
        QListWidgetItem* item = ui->listaAttivita->item(i);
        if (!att || !item) continue;

        bool matchTesto = att->getTitolo().toLower().contains(testo) ||
                          att->getMateria().toLower().contains(testo);

        VisitatoreFiltroTipo visFiltro(indiceTipo);
        att->accept(visFiltro);

        bool matchUrgenza = !soloUrgenti || att->isUrgente(oggi);

        item->setHidden(!(matchTesto && visFiltro.isMatch && matchUrgenza));
    }
}

void MainWindow::on_listaAttivita_currentRowChanged(int currentRow) {
    if (currentRow < 0) return;

    Attivita* att = gestore.getAttivita(currentRow);
    if (!att) return;

    ui->stackedPrincip->setCurrentIndex(1);
    ui->lbl_TitoloDet->setText(att->getTitolo());

    QString info = QString("Materia: %1\nData: %2\nDescrizione: %3\n\n-- Dettagli Specifici --\n")
                       .arg(att->getMateria())
                       .arg(att->getDataAttivita().toString("dd/MM/yyyy"))
                       .arg(att->getDescrizione());

    VisitatoreTesto visTesto;
    att->accept(visTesto);
    ui->textDett->setText(info + visTesto.risultatoTesto);
}

void MainWindow::on_btnNuovo_clicked() {
    ui->listaAttivita->clearSelection();
    svuotaCampiForm();
    modalitaCreazione = true;

    ui->stackedPrincip->setCurrentIndex(0);
    ui->comboTipo->setEnabled(true);
    ui->btnSalva->setText("Crea Attività");
}

void MainWindow::on_btnModifica_clicked() {
    int riga = ui->listaAttivita->currentRow();
    if (riga < 0) return;

    Attivita* att = gestore.getAttivita(riga);
    if (!att) return;

    modalitaCreazione = false;
    ui->stackedPrincip->setCurrentIndex(0);
    ui->comboTipo->setEnabled(false);
    ui->btnSalva->setText("Salva Modifiche");

    ui->editTitolo->setText(att->getTitolo());
    ui->editMateria->setText(att->getMateria());
    ui->editDesc->setText(att->getDescrizione());
    ui->editData->setDate(att->getDataAttivita());

    VisitatoreImpostaCombo visCombo(ui->comboTipo);
    att->accept(visCombo);

    VisitatoreFormUI visForm(ui);
    att->accept(visForm);
}

void MainWindow::on_comboTipo_currentIndexChanged(int index) {
    if (modalitaCreazione)
        ui->stackedInterno->setCurrentIndex(index);
}

void MainWindow::on_btnSalva_clicked() {
    QString titolo = ui->editTitolo->text().trimmed();
    QString materia = ui->editMateria->text();
    QString desc = ui->editDesc->toPlainText();
    QDate data = ui->editData->date();

    if (titolo.isEmpty()) {
        QMessageBox::warning(this, "Errore", "Il titolo è obbligatorio!");
        return;
    }

    int tipo = ui->comboTipo->currentIndex();

    if (tipo == 2) {
        QString link = ui->editMeeting->text().trimmed();
        QString pos = ui->editPosizione->text().trimmed();
        if (link.isEmpty() && pos.isEmpty()) {
            QMessageBox::warning(this, "Dati Incompleti", "Un evento deve avere almeno un Link o una Posizione fisica!");
            return;
        }
    }

    if (modalitaCreazione) {
        if (tipo == 0)      gestore.aggiungiAttivita(std::make_unique<Esame>(titolo, materia, desc, data, ui->spinCFU->value(), ui->spinVoto->value(), ui->checkSuperato->isChecked()));
        else if (tipo == 1) gestore.aggiungiAttivita(std::make_unique<Progetto>(titolo, materia, desc, data, ui->spinPartecip->value(), ui->editRepo->text()));
        else if (tipo == 2) gestore.aggiungiAttivita(std::make_unique<Evento>(titolo, materia, desc, data, ui->editMeeting->text(), ui->editPosizione->text(), ui->checkPartecipazione->isChecked()));

        aggiornaListaView();
        ui->listaAttivita->setCurrentRow(gestore.getNumeroAttivita() - 1);
    } else {
        int riga = ui->listaAttivita->currentRow();
        if (riga >= 0) {
            gestore.rimuoviAttivita(riga);
            if (tipo == 0)      gestore.aggiungiAttivita(std::make_unique<Esame>(titolo, materia, desc, data, ui->spinCFU->value(), ui->spinVoto->value(), ui->checkSuperato->isChecked()));
            else if (tipo == 1) gestore.aggiungiAttivita(std::make_unique<Progetto>(titolo, materia, desc, data, ui->spinPartecip->value(), ui->editRepo->text()));
            else if (tipo == 2) gestore.aggiungiAttivita(std::make_unique<Evento>(titolo, materia, desc, data, ui->editMeeting->text(), ui->editPosizione->text(), ui->checkPartecipazione->isChecked()));

            aggiornaListaView();
            ui->listaAttivita->setCurrentRow(gestore.getNumeroAttivita() - 1);
        }
    }
}

void MainWindow::on_btnAnnulla_clicked() {
    if (modalitaCreazione) ui->stackedPrincip->setCurrentIndex(2);
    else                   ui->stackedPrincip->setCurrentIndex(1);
}

void MainWindow::on_btnElimina_clicked() {
    int riga = ui->listaAttivita->currentRow();
    if (riga < 0) return;

    auto risposta = QMessageBox::question(
        this, "Conferma Eliminazione",
        "Sei sicuro di voler eliminare questa attività?",
        QMessageBox::Yes | QMessageBox::No
    );

    if (risposta == QMessageBox::Yes) {
        gestore.rimuoviAttivita(riga);
        aggiornaListaView();
        ui->stackedPrincip->setCurrentIndex(2);
    }
}

void MainWindow::on_btnEsporta_clicked() {
    QString fileName = QFileDialog::getSaveFileName(this, "Esporta Attività", "", "JSON Files (*.json);;All Files (*)");
    if (fileName.isEmpty()) return;
    if (!fileName.endsWith(".json")) fileName += ".json";

    if (gestore.salvaSuFile(fileName))
        QMessageBox::information(this, "Successo", "Dati esportati correttamente.");
    else
        QMessageBox::critical(this, "Errore", "Impossibile salvare il file.");
}

void MainWindow::on_btnImporta_clicked() {
    QString fileName = QFileDialog::getOpenFileName(this, "Importa Attività", "", "JSON Files (*.json);;All Files (*)");
    if (fileName.isEmpty()) return;

    if (gestore.caricaDaFile(fileName)) {
        aggiornaListaView();
        ui->stackedPrincip->setCurrentIndex(2);
        ui->listaAttivita->clearSelection();
        QMessageBox::information(this, "Successo", "Dati importati correttamente.");
    } else {
        QMessageBox::critical(this, "Errore", "Il file selezionato non è un formato JSON valido.");
    }
}

void MainWindow::aggiornaCompleterMaterie() {
    QSet<QString> materie;
    for (int i = 0; i < gestore.getNumeroAttivita(); ++i) {
        Attivita* a = gestore.getAttivita(i);
        if (a && !a->getMateria().trimmed().isEmpty())
            materie.insert(a->getMateria().trimmed());
    }

    QStringList lista = materie.values();
    lista.sort();

    QCompleter* completer = new QCompleter(lista, this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    completer->setFilterMode(Qt::MatchContains);
    ui->editMateria->setCompleter(completer);
}
