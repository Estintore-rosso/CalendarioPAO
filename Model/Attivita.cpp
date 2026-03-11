
#include "Attivita.h"
#include "Observer.h"
#include <QUuid>
#include <algorithm>

//Serve per i fromJson, non da fuori
Attivita::Attivita() : id(QUuid::createUuid().toString(QUuid::WithoutBraces)), dInizio(), dFine(), titolo(), descrizione(){}

/*Attivita::Attivita(const QString& tit, const QString& desc, const QDateTime& inizio, const QDateTime& fine, bool giorno)
    : id(QUuid::createUuid().toString(QUuid::WithoutBraces)), 
      dInizio(inizio), 
      dFine(fine),
      tuttoGiorno(giorno),
      titolo(tit), 
      descrizione(desc)
{}

Attivita::Attivita(const QString& tit, const QString& desc, const QDateTime& inizio, bool tuttoGiorno): Attivita(tit, desc, inizio, inizio, tuttoGiorno){}
Attivita::Attivita(const QString& tit, const QDateTime& inizio, const QDateTime& fine, bool tuttoGiorno): Attivita(tit, "", inizio, fine, tuttoGiorno){}
*/
Attivita::Attivita(const QString& tit, const QDateTime& inizio, bool giorno): 
    id(QUuid::createUuid().toString(QUuid::WithoutBraces)), 
    dInizio(inizio), 
    dFine(QDateTime()),
    tuttoGiorno(giorno),
    titolo(tit), 
    descrizione(QString())
{}

// getters
QString Attivita::getId() const { return id; }
QDateTime Attivita::getDInizio() const { return dInizio; }
QDateTime Attivita::getDFine() const { return dFine; }
QString Attivita::getTitolo() const { return titolo; }
QString Attivita::getDescrizione() const { return descrizione; }
bool Attivita::getTuttoGiorno() const {return tuttoGiorno; }

// setters
void Attivita::setDInizio(const QDateTime &data) { dInizio = data; notify(); }
void Attivita::setDFine(const QDateTime &data) { dFine = data; notify(); }
void Attivita::setTitolo(const QString &tit) { titolo = tit; notify(); }
void Attivita::setDescrizione(const QString &desc) { descrizione = desc; notify(); }
void Attivita::setTuttoGiorno(const bool &giorno) {tuttoGiorno = giorno; notify(); }

void Attivita::registraObserver(Observer* oss) {
    observers.push_back(oss);
}

void Attivita::rimuoviObserver(Observer* oss) {
    observers.erase(std::remove(observers.begin(), observers.end(), oss), observers.end());
}

void Attivita::notify() {
    for (Observer* oss : observers) {
        oss->update(); 
    }
}



QJsonObject Attivita::toJson() const {
    QJsonObject json;
    json["id"] = id;
    json["titolo"] = titolo;
    json["descrizione"] = descrizione;
    if(dInizio.isValid())   json["inizio"] = dInizio.toString(Qt::ISODate);
    if(dFine.isValid())     json["fine"] = dFine.toString(Qt::ISODate); //per salvare spazio, andrebbe lo stesso anche in caso di null
    json["tuttoGiorno"] = tuttoGiorno;
    return json;
}


void Attivita::caricaJson(const QJsonObject& json) {
    id = json["id"].toString();
    descrizione = json["descrizione"].toString();
    titolo = json["titolo"].toString();
    dInizio = QDateTime::fromString(json["inizio"].toString(), Qt::ISODate);
    dFine = QDateTime::fromString(json["fine"].toString(), Qt::ISODate);
    tuttoGiorno = json["tuttoGiorno"].toBool();
}
