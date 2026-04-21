#include "Gestore.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

void Gestore::aggiungiAttivita(std::unique_ptr<Attivita> nuovaAttivita) {
    if (nuovaAttivita)
        listaAttivita.push_back(std::move(nuovaAttivita));
}

bool Gestore::rimuoviAttivita(int indice) {
    if (indice >= 0 && indice < static_cast<int>(listaAttivita.size())) {
        listaAttivita.erase(listaAttivita.begin() + indice);
        return true;
    }
    return false;
}

Attivita* Gestore::getAttivita(int indice) const {
    if (indice >= 0 && indice < static_cast<int>(listaAttivita.size()))
        return listaAttivita[indice].get();
    return nullptr;
}

int Gestore::getNumeroAttivita() const {
    return static_cast<int>(listaAttivita.size());
}

void Gestore::svuota() {
    listaAttivita.clear();
}

bool Gestore::salvaSuFile(const QString& percorsoFile) const {
    QFile file(percorsoFile);
    if (!file.open(QIODevice::WriteOnly))
        return false;

    QJsonArray arrayJson;
    for (const auto& att : listaAttivita)
        arrayJson.append(att->toJson());

    file.write(QJsonDocument(arrayJson).toJson());
    file.close();
    return true;
}

bool Gestore::caricaDaFile(const QString& percorsoFile) {
    QFile file(percorsoFile);
    if (!file.open(QIODevice::ReadOnly))
        return false;

    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    file.close();

    if (!doc.isArray())
        return false;

    svuota();

    for (const QJsonValue& val : doc.array()) {
        QJsonObject obj = val.toObject();
        QString tipo = obj["tipo"].toString();
        QString titolo = obj["titolo"].toString();
        QString materia = obj["materia"].toString();
        QString descrizione = obj["descrizione"].toString();
        QDate data = QDate::fromString(obj["dataAttivita"].toString(), Qt::ISODate);

        if (tipo == "Esame") {
            aggiungiAttivita(std::make_unique<Esame>(
                titolo, materia, descrizione, data,
                obj["cfu"].toInt(), obj["voto"].toInt(), obj["superato"].toBool()
            ));
        } else if (tipo == "Progetto") {
            aggiungiAttivita(std::make_unique<Progetto>(
                titolo, materia, descrizione, data,
                obj["numeroPartecipanti"].toInt(), obj["linkRepo"].toString()
            ));
        } else if (tipo == "Evento") {
            aggiungiAttivita(std::make_unique<Evento>(
                titolo, materia, descrizione, data,
                obj["linkMeeting"].toString(), obj["posizione"].toString(),
                obj["intenzionePartecipare"].toBool()
            ));
        }
    }
    return true;
}
