#include "dialogaggiugni.h"
#include "ui_dialogaggiugni.h"

DialogAggiugni::DialogAggiugni(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogAggiugni)
{
    ui->setupUi(this);
}

DialogAggiugni::~DialogAggiugni()
{
    delete ui;
}

QString DialogAggiugni::getTitolo() const { return ui->PPUTitolo->text(); }
QString DialogAggiugni::getTipo() const { return ui->PPUScaletaAtt->currentText(); }
QDate DialogAggiugni::getDataInizio() const { return ui->PPUDataInizio->date(); }
QDate DialogAggiugni::getDataFine() const {
    if (ui->PPUDataFine->date() == ui->PPUDataFine->minimumDate()) {
        return QDateTime();
    }
    return ui->PPUDataFine->dateTime(); 
}

QString DialogAggiugni::getLuogo() const { return ui->PPULuogo->text(); }
QString DialogAggiugni::getLink() const { return ui->PPULink->text(); }
QString DialogAggiugni::getPartecipanti() const { return ui->PPUPersone->text(); }
QString DialogAggiugni::getDescrizione() const { return ui->PPUDescrizione->toPlainText(); } 
QString DialogAggiugni::getEtichetta() const { return ui->PPUEtichetta->toPlainText(); } 
bool DialogAggiugni::isUrgente() const { return ui->PPUUrgente->isChecked(); }
bool DialogAggiugni::isGirono() const { return ui->PPUTuttoGiorno->isChecked(); }