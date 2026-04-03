#include "Evento.h"
#include "Visitatore.h"

// Costruttore
Evento::Evento(const QString& t, const QString& m, const QString& d, const QDate& data, 
               const QString& link, const QString& pos, bool partecipero)
    : Attivita(t, m, d, data), linkMeeting(link), posizione(pos), intenzionePartecipare(partecipero) {}

// Logica per l'urgenza dell'Evento
bool Evento::isUrgente(const QDate& oggi) const {
    // Se non hai intenzione di partecipare, non è mai urgente
    if (!intenzionePartecipare) {
        return false;
    }

    int giorni = getGiorniMancanti(oggi);
    // Urgente se mancano 1 o 0 giorni (quindi dal giorno prima fino al giorno stesso)
    return giorni >= 0 && giorni <= 1;
}

// Salvataggio specifico per l'Evento
QJsonObject Evento::toJson() const {
    QJsonObject json;
    json["tipo"] = "Evento";
    json["titolo"] = getTitolo();
    json["materia"] = getMateria();
    json["descrizione"] = getDescrizione();
    json["dataAttivita"] = getDataAttivita().toString(Qt::ISODate);
    
    // I campi stringa possono essere vuoti, il JSON li gestirà tranquillamente
    json["linkMeeting"] = linkMeeting;
    json["posizione"] = posizione;
    json["intenzionePartecipare"] = intenzionePartecipare;
    
    return json;
}

// Implementazione Getter
QString Evento::getLinkMeeting() const { 
    return linkMeeting; 
}

QString Evento::getPosizione() const { 
    return posizione; 
}

bool Evento::getIntenzionePartecipare() const { 
    return intenzionePartecipare; 
}

// Implementazione Setter
void Evento::setLinkMeeting(const QString& link) { 
    linkMeeting = link; 
}

void Evento::setPosizione(const QString& pos) { 
    posizione = pos; 
}

void Evento::setIntenzionePartecipare(bool partecipero) { 
    intenzionePartecipare = partecipero; 
}

void Evento::accept(Visitatore& v) {
    v.visita(*this);
}