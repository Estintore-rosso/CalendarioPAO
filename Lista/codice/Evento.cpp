#include "Evento.h"
#include "Visitatore.h"

Evento::Evento(const QString& t, const QString& m, const QString& d, const QDate& data,
               const QString& link, const QString& pos, bool partecipero)
    : Attivita(t, m, d, data), linkMeeting(link), posizione(pos), intenzionePartecipare(partecipero) {}

bool Evento::isUrgente(const QDate& oggi) const {
    if (!intenzionePartecipare) return false;
    int giorni = getGiorniMancanti(oggi);
    return giorni >= 0 && giorni <= 1;
}

QJsonObject Evento::toJson() const {
    QJsonObject json;
    json["tipo"] = "Evento";
    json["titolo"] = getTitolo();
    json["materia"] = getMateria();
    json["descrizione"] = getDescrizione();
    json["dataAttivita"] = getDataAttivita().toString(Qt::ISODate);
    json["linkMeeting"] = linkMeeting;
    json["posizione"] = posizione;
    json["intenzionePartecipare"] = intenzionePartecipare;
    return json;
}

QString Evento::getLinkMeeting() const { return linkMeeting; }
QString Evento::getPosizione() const { return posizione; }
bool Evento::getIntenzionePartecipare() const { return intenzionePartecipare; }

void Evento::setLinkMeeting(const QString& link) { linkMeeting = link; }
void Evento::setPosizione(const QString& pos) { posizione = pos; }
void Evento::setIntenzionePartecipare(bool partecipero) { intenzionePartecipare = partecipero; }

void Evento::accept(Visitatore& v) {
    v.visita(*this);
}
