#include "Scadenza.h"
#include "AttivitaVisitatore.h"
#include <QString>
#include <QDateTime>

Scadenza::Scadenza(const QString& tit, const QDateTime& inizio, bool tuttoGiorno,const QString& etich, bool urg): 
    Attivita(tit,inizio,tuttoGiorno), 
    etichetta(etich),
    urgente(urg)
    {}


QString Scadenza::getTipo() const { return "Scadenza"; }
bool Scadenza::isUrgente() const {return urgente;}
QString Scadenza::getEtichetta() const { return etichetta; }
void Scadenza::setEtichetta(const QString& etich) { etichetta = etich; notify(); }

void Scadenza::setUrgente(bool urg){ urgente=urg; notify(); }

void Scadenza::accetta(AttivitaVisitatore& v) {
    v.visit(*this);
}

QJsonObject Scadenza::toJson() const{
    QJsonObject json = Attivita::toJson(); 
    json["etichetta"] = etichetta;
    json["urgente"] = urgente;
    json["tipo"] = getTipo(); 
    return json;
}

void Scadenza::caricaJson(const QJsonObject& json ){
    Attivita::caricaJson(json);
    etichetta = json["etichetta"].toString();
    urgente = json["urgente"].toBool();
}


