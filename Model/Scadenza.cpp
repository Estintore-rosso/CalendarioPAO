#include "Scadenza.h"
#include "AttivitaVisitatore.h"
#include <QString>
#include <QDateTime>

Scadenza::Scadenza(const QString& tit, const QDateTime& inizio, bool tuttoGiorno, const QString& link, const QString etich, bool urg): 
    Attivita(tit,inizio,tuttoGiorno), 
    etichetta(etich),
    urgente(urg)
    {}


bool    Scadenza::isUrgente() const {return urgente;}

void Scadenza::setUrgente(bool urg){ urgente=urg; notify(); }

void Scadenza::accetta(AttivitaVisitatore& v) {
    v.visit(*this);
}

QJsonObject Scadenza::toJson() const{
    QJsonObject json = Attivita::toJson(); 
    json["etichetta"] = etichetta;
    json["urgente"] = urgente;
    json["tipo"] = "Scadenza"; 
    return json;
}

void Scadenza::caricaJson(const QJsonObject& json ){
    Attivita::caricaJson(json);
    etichetta = json["etichetta"].toString();
    urgente = json["urgente"].toBool();
}


