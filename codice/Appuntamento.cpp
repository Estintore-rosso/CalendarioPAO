#include "Appuntamento.h"

Appuntamento::Appuntamento(const QString& t, const QString& d, const QDateTime& i, const QDateTime& f, const QString& l)
    : Attivita(t, d), inizio(i), fine(f), luogo(l) {}

QDateTime Appuntamento::getInizio() const { return inizio; }
QDateTime Appuntamento::getFine() const { return fine; }
QString Appuntamento::getLuogo() const { return luogo; }

bool Appuntamento::isUrgente(const QDate& dataOdierna) const {
    // Urgente se l'appuntamento è oggi
    return inizio.date() == dataOdierna;
}

QJsonObject Appuntamento::toJson() const {
    QJsonObject json;
    json["tipo"] = "Appuntamento";
    json["titolo"] = getTitolo();
    json["descrizione"] = getDescrizione();
    json["inizio"] = inizio.toString(Qt::ISODate);
    json["fine"] = fine.toString(Qt::ISODate);
    json["luogo"] = luogo;
    return json;
}