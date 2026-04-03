#include "Gestore.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QVariant>

void Gestore::aggiungiAttivita(std::unique_ptr<Attivita> nuovaAttivita) {
    if (nuovaAttivita) {
        listaAttivita.push_back(std::move(nuovaAttivita));
    }
}

bool Gestore::rimuoviAttivita(int indice) {
    if (indice >= 0 && indice < listaAttivita.size()) {
        listaAttivita.erase(listaAttivita.begin() + indice);
        return true;
    }
    return false;
}

Attivita* Gestore::getAttivita(int indice) const {
    if (indice >= 0 && indice < listaAttivita.size()) {
        return listaAttivita[indice].get();
    }
    return nullptr;
}

int Gestore::getNumeroAttivita() const {
    return listaAttivita.size();
}

void Gestore::svuota() {
    listaAttivita.clear();
}

// --- SALVATAGGIO JSON ---
bool Gestore::salvaSuFile(const QString& percorsoFile) const {
    QFile file(percorsoFile);
    if (!file.open(QIODevice::WriteOnly)) {
        return false;
    }

    QJsonArray arrayJson;
    for (const auto& att : listaAttivita) {
        arrayJson.append(att->toJson());
    }

    QJsonDocument doc(arrayJson);
    file.write(doc.toJson());
    file.close();
    return true;
}

// --- CARICAMENTO JSON ---
bool Gestore::caricaDaFile(const QString& percorsoFile) {
    QFile file(percorsoFile);
    if (!file.open(QIODevice::ReadOnly)) {
        return false;
    }

    QByteArray dati = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(dati);
    if (!doc.isArray()) {
        return false;
    }

    svuota(); 

    QJsonArray arrayJson = doc.array();
    for (int i = 0; i < arrayJson.size(); ++i) {
        QJsonObject obj = arrayJson[i].toObject();

        QString tipo = obj["tipo"].toString();
        QString titolo = obj["titolo"].toString();
        QString materia = obj["materia"].toString();
        QString descrizione = obj["descrizione"].toString();
        QDate data = QDate::fromString(obj["dataAttivita"].toString(), Qt::ISODate);

        if (tipo == "Esame") {
            int cfu = obj["cfu"].toInt();
            int voto = obj["voto"].toInt();
            bool superato = obj["superato"].toBool();
            
            aggiungiAttivita(std::make_unique<Esame>(titolo, materia, descrizione, data, cfu, voto, superato));
        } 
        else if (tipo == "Progetto") {
            int numPartecipanti = obj["numeroPartecipanti"].toInt();
            QString link = obj["linkRepo"].toString();
            
            aggiungiAttivita(std::make_unique<Progetto>(titolo, materia, descrizione, data, numPartecipanti, link));
        }
        else if (tipo == "Evento") {
            QString link = obj["linkMeeting"].toString();
            QString pos = obj["posizione"].toString();
            bool partecipa = obj["intenzionePartecipare"].toBool();
            
            aggiungiAttivita(std::make_unique<Evento>(titolo, materia, descrizione, data, link, pos, partecipa));
        }
    }
    return true;
}