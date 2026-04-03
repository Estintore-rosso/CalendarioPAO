#include "Scadenza.h"

Scadenza::Scadenza(const QString& t, const QString& d, const QDate& scadenza)
    : Attivita(t, d), dataScadenza(scadenza) {}

QDate Scadenza::getDataScadenza() const {
    return dataScadenza;
}

void Scadenza::setDataScadenza(const QDate& scadenza) {
    dataScadenza = scadenza;
}

bool Scadenza::isUrgente(const QDate& dataOdierna) const {
    // Urgente se mancano 3 giorni o meno alla scadenza
    return dataOdierna.daysTo(dataScadenza) <= 3 && dataOdierna.daysTo(dataScadenza) >= 0;
}

QJsonObject Scadenza::toJson() const {
    QJsonObject json;
    json["tipo"] = "Scadenza"; // Utile in fase di lettura dal file
    json["titolo"] = getTitolo();
    json["descrizione"] = getDescrizione();
    json["dataScadenza"] = dataScadenza.toString(Qt::ISODate);
    return json;
}