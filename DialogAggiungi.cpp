#include "DialogAggiungi.h"
#include "ui_DialogAggiungi.h"

DialogAggiungi::DialogAggiungi(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogAggiungi)
{
    ui->setupUi(this);
}

DialogAggiungi::~DialogAggiungi()
{
    delete ui;
}

QString DialogAggiungi::getTitolo() const { return ui->PPUTitolo->text(); }
QString DialogAggiungi::getTipo() const { return ui->PPUSceltaAtt->currentText(); }
QDateTime DialogAggiungi::getDataInizio() const { return ui->PPUDataInizio->dateTime(); }
QDateTime DialogAggiungi::getDataFine() const {
    if (ui->PPUDataFine->date() == ui->PPUDataFine->minimumDate()) {
        return QDateTime();
    }
    return ui->PPUDataFine->dateTime(); 
}

QString DialogAggiungi::getLuogo() const { return ui->PPULuogo->text(); }
QString DialogAggiungi::getLink() const { return ui->PPULink->text(); }
QString DialogAggiungi::getPartecipanti() const { return ui->PPUPersone->text(); }
QString DialogAggiungi::getDescrizione() const { return ui->PPUDesc->toPlainText(); } 
QString DialogAggiungi::getEtichetta() const { return ui->PPUEtichetta->text(); } 
bool DialogAggiungi::isUrgente() const { return ui->PPUUrgente->isChecked(); }
bool DialogAggiungi::isGiorno() const { return ui->PPUTuttoGiorno->isChecked(); }