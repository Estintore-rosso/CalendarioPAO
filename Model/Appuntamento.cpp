#include "Appuntamento.h"
#include "AttivitaVisitatore.h"
#include <QString>
#include <QDateTime>

Appuntamento::Appuntamento(const QString& tit, const QDateTime& inizio, bool tuttoGiorno, const std::vector<QString>& listaPersone, const QString& loco): 
    AttivitaPersone(tit,inizio,tuttoGiorno,listaPersone), 
    luogo(loco)
    {}

QString Appuntamento::getLuogo() const {return luogo;}

void Appuntamento::setLuogo(const QString& loco){ luogo=loco; notify(); }

void Appuntamento::accetta(AttivitaVisitatore& v) {
    v.visit(*this);
}

QJsonObject Appuntamento::toJson() const{
    QJsonObject json = AttivitaPersone::toJson(); 
    json["luogo"] = luogo;
    return json;
}

void Appuntamento::caricaJson(const QJsonObject& json ){
    AttivitaPersone::caricaJson(json);
    luogo = json["luogo"].toString();
}


