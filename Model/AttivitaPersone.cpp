
#include "AttivitaPersone.h"
#include <QJsonArray>
#include <algorithm>

//AttivitaPersone::AttivitaPersone(const QString& tit, const QString& desc, const QDateTime& inizio, const QDateTime& fine, bool giorno, const std::vector<QString>& listaPersone): Attivita(tit, desc, inizio, fine, giorno), persone(listaPersone) {}
//AttivitaPersone::AttivitaPersone(const QString& tit, const QString& desc, const QDateTime& inizio, bool tuttoGiorno, const std::vector<QString>& listaPersone): Attivita(tit, desc, inizio, tuttoGiorno), persone(listaPersone) {}
//AttivitaPersone::AttivitaPersone(const QString& tit, const QDateTime& inizio, const QDateTime& fine, bool tuttoGiorno, const std::vector<QString>& listaPersone): Attivita(tit, inizio, fine, tuttoGiorno), persone(listaPersone) {}
AttivitaPersone::AttivitaPersone(const QString& tit, const QDateTime& inizio, bool tuttoGiorno, const std::vector<QString>& listaPersone): 
    Attivita(tit, inizio, tuttoGiorno), 
    persone(listaPersone) 
{}

void AttivitaPersone::aggiungiPersona(const QString& persona) {
    persone.push_back(persona);
    notify();
}

void AttivitaPersone::rimuoviPersona(const QString& persona) {
    persone.erase(std::remove(persone.begin(), persone.end(), persona), persone.end());
    notify();
}

std::vector<QString> AttivitaPersone::getPersone() const {
    return persone;
}

QJsonObject AttivitaPersone::toJson() const {
    QJsonObject json = Attivita::toJson(); 

    QJsonArray arrayPersone;
    for (const QString& persona : persone) {
        arrayPersone.append(persona);
    }
    json["persone"] = arrayPersone;
    return json;
}

void AttivitaPersone::caricaJson(const QJsonObject& json) {
    Attivita::caricaJson(json);
    persone.clear();

    if (json.contains("persone") && json["persone"].isArray()) {
        QJsonArray arrayPersone = json["persone"].toArray();
        for (const QJsonValue& valore : arrayPersone) {
            persone.push_back(valore.toString());
        }
    }
}
