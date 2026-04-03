#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Visitatore.h"
#include <QMessageBox>

// ==========================================
// 1. VISITATORE PER IL TESTO (Sola Lettura)
// ==========================================
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

// ==========================================
// 2. VISITATORE PER IL FORM (Riempie i widget)
// ==========================================
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

// ==========================================
// MAINWINDOW
// ==========================================

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    ui->stackedPrincip->setCurrentIndex(2); // Indice 2 = page_Vuota
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::aggiornaListaView() {
    ui->listaAttivita->clear();
    for (int i = 0; i < gestore.getNumeroAttivita(); ++i) {
        Attivita* att = gestore.getAttivita(i);
        QString testo = att->getDataAttivita().toString("dd/MM/yyyy") + " - " + att->getTitolo();
        ui->listaAttivita->addItem(testo);
    }
}

void MainWindow::svuotaCampiForm() {
    ui->editTitolo->clear();
    ui->editMateria->clear();
    ui->editDesc->clear();
    ui->editData->setDate(QDate::currentDate());
    ui->comboTipo->setCurrentIndex(0);
    ui->stackedInterno->setCurrentIndex(0);

    ui->spinCFU->setValue(1);
    ui->spinVoto->setValue(0);
    ui->checkSuperato->setChecked(false);
    ui->spinPartecip->setValue(1);
    ui->editRepo->clear();
    ui->editMeeting->clear();
    ui->editPosizione->clear();
    ui->checkPartecipazione->setChecked(false);
}


// --- NAVIGAZIONE LISTA -> LETTURA ---
void MainWindow::on_listaAttivita_currentRowChanged(int currentRow) {
    if (currentRow < 0) return;

    Attivita* att = gestore.getAttivita(currentRow);
    if (!att) return;

    ui->stackedPrincip->setCurrentIndex(1); // Pagina 1 = page_Info

    ui->lbl_TitoloDet->setText(att->getTitolo());

    QString infoComuni = QString("Materia: %1\nData: %2\nDescrizione: %3\n\n-- Dettagli Specifici --\n")
                             .arg(att->getMateria())
                             .arg(att->getDataAttivita().toString("dd/MM/yyyy"))
                             .arg(att->getDescrizione());

    VisitatoreTesto visTesto;
    att->accept(visTesto);

    ui->textDett->setText(infoComuni + visTesto.risultatoTesto);
}

// --- BOTTONE + AGGIUNGI ---
void MainWindow::on_btnNuovo_clicked() {
    ui->listaAttivita->clearSelection();
    svuotaCampiForm();
    modalitaCreazione = true;

    ui->stackedPrincip->setCurrentIndex(0); // Pagina 0 = page_AggMod
    ui->comboTipo->setEnabled(true);
    ui->btnSalva->setText("Crea Attività");
}

void MainWindow::on_comboTipo_currentIndexChanged(int index) {
    if (modalitaCreazione) {
        ui->stackedInterno->setCurrentIndex(index);
    }
}

// --- BOTTONI PAGINA LETTURA ---
void MainWindow::on_btnElimina_clicked() {
    int riga = ui->listaAttivita->currentRow();
    if (riga >= 0) {
        gestore.rimuoviAttivita(riga);
        aggiornaListaView();
        ui->stackedPrincip->setCurrentIndex(2); // Torna alla vuota
    }
}

// --- ESPORTAZIONE JSON ---
void MainWindow::on_btnEsporta_clicked()
{
    // Apre la finestra di dialogo per il salvataggio
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Esporta Attività"), "",
                                                    tr("JSON Files (*.json);;All Files (*)"));

    if (fileName.isEmpty())
        return;

    // Assicuriamoci che l'estensione sia corretta
    if (!fileName.endsWith(".json"))
        fileName += ".json";

    // Usiamo il metodo polimorfo del Gestore
    if (gestore.salvaSuFile(fileName)) {
        QMessageBox::information(this, tr("Successo"), tr("Dati esportati correttamente."));
    } else {
        QMessageBox::critical(this, tr("Errore"), tr("Impossibile salvare il file."));
    }
}

// --- IMPORTAZIONE JSON ---
void MainWindow::on_btnImporta_clicked()
{
    // Apre la finestra di dialogo per l'apertura
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Importa Attività"), "",
                                                    tr("JSON Files (*.json);;All Files (*)"));

    if (fileName.isEmpty())
        return;

    // Carica i dati tramite il Gestore
    if (gestore.caricaDaFile(fileName)) {
        // Dopo l'importazione, dobbiamo rinfrescare l'interfaccia
        aggiornaListaView();

        // Torniamo alla pagina vuota per sicurezza
        ui->stackedPrincip->setCurrentIndex(2); // page_Vuota
        ui->listaAttivita->clearSelection();

        QMessageBox::information(this, tr("Successo"), tr("Dati importati correttamente."));
    } else {
        QMessageBox::critical(this, tr("Errore"), tr("Il file selezionato non è un formato JSON valido."));
    }
}

void MainWindow::on_btnModifica_clicked() {
    int riga = ui->listaAttivita->currentRow();
    if (riga < 0) return;

    Attivita* att = gestore.getAttivita(riga);
    if (!att) return;

    modalitaCreazione = false;

    ui->stackedPrincip->setCurrentIndex(0); // Vai al Modulo
    ui->comboTipo->setEnabled(false); // Il tipo non si cambia in modifica!
    ui->btnSalva->setText("Salva Modifiche");

    // Popola campi comuni
    ui->editTitolo->setText(att->getTitolo());
    ui->editMateria->setText(att->getMateria());
    ui->editDesc->setText(att->getDescrizione());
    ui->editData->setDate(att->getDataAttivita());

    if (dynamic_cast<Esame*>(att)) ui->comboTipo->setCurrentIndex(0);
    else if (dynamic_cast<Progetto*>(att)) ui->comboTipo->setCurrentIndex(1);
    else if (dynamic_cast<Evento*>(att)) ui->comboTipo->setCurrentIndex(2);

    VisitatoreFormUI visForm(ui);
    att->accept(visForm);
}

// --- BOTTONI PAGINA MODULO ---
void MainWindow::on_btnAnnulla_clicked() {
    if (modalitaCreazione) {
        ui->stackedPrincip->setCurrentIndex(2); // Torna alla vuota
    } else {
        ui->stackedPrincip->setCurrentIndex(1); // Torna alla lettura
    }
}

void MainWindow::on_btnSalva_clicked() {
    QString titolo = ui->editTitolo->text();
    QString materia = ui->editMateria->text();
    QString desc = ui->editDesc->toPlainText();
    QDate data = ui->editData->date();

    if (titolo.isEmpty()) {
        QMessageBox::warning(this, "Errore", "Il titolo è obbligatorio!");
        return;
    }

    int tipo = ui->comboTipo->currentIndex();

    if (modalitaCreazione) {
        if (tipo == 0) gestore.aggiungiAttivita(std::make_unique<Esame>(titolo, materia, desc, data, ui->spinCFU->value(), ui->spinVoto->value(), ui->checkSuperato->isChecked()));
        else if (tipo == 1) gestore.aggiungiAttivita(std::make_unique<Progetto>(titolo, materia, desc, data, ui->spinPartecip->value(), ui->editRepo->text()));
        else if (tipo == 2) gestore.aggiungiAttivita(std::make_unique<Evento>(titolo, materia, desc, data, ui->editMeeting->text(), ui->editPosizione->text(), ui->checkPartecipazione->isChecked()));

        aggiornaListaView();
        ui->listaAttivita->setCurrentRow(gestore.getNumeroAttivita() - 1);

    } else {
        int riga = ui->listaAttivita->currentRow();
        if (riga >= 0) {
            gestore.rimuoviAttivita(riga);

            if (tipo == 0) gestore.aggiungiAttivita(std::make_unique<Esame>(titolo, materia, desc, data, ui->spinCFU->value(), ui->spinVoto->value(), ui->checkSuperato->isChecked()));
            else if (tipo == 1) gestore.aggiungiAttivita(std::make_unique<Progetto>(titolo, materia, desc, data, ui->spinPartecip->value(), ui->editRepo->text()));
            else if (tipo == 2) gestore.aggiungiAttivita(std::make_unique<Evento>(titolo, materia, desc, data, ui->editMeeting->text(), ui->editPosizione->text(), ui->checkPartecipazione->isChecked()));

            aggiornaListaView();
            ui->listaAttivita->setCurrentRow(gestore.getNumeroAttivita() - 1);
        }
    }
}
