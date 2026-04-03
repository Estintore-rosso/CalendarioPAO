#include "Progetto.h"
#include "Visitatore.h"

// Costruttore: passa i parametri comuni ad Attivita e inizializza quelli specifici
Progetto::Progetto(const QString& t, const QString& m, const QString& d, const QDate& data, int numPartecipanti, const QString& link)
    : Attivita(t, m, d, data), numeroPartecipanti(numPartecipanti), linkRepo(link) {}

// Logica specifica per l'urgenza del Progetto (14 giorni)
bool Progetto::isUrgente(const QDate& oggi) const {
    int giorni = getGiorniMancanti(oggi);
    // Il progetto è urgente se non è ancora scaduto e mancano 14 giorni o meno alla consegna
    return giorni >= 0 && giorni <= 14;
}

// Salvataggio specifico per il Progetto
QJsonObject Progetto::toJson() const {
    QJsonObject json;
    json["tipo"] = "Progetto"; // Fondamentale per quando dovrai ricaricare i dati
    json["titolo"] = getTitolo();
    json["materia"] = getMateria();
    json["descrizione"] = getDescrizione();
    json["dataAttivita"] = getDataAttivita().toString(Qt::ISODate);
    json["numeroPartecipanti"] = numeroPartecipanti;
    json["linkRepo"] = linkRepo;
    return json;
}

// Implementazione Getter
int Progetto::getNumeroPartecipanti() const { 
    return numeroPartecipanti; 
}

QString Progetto::getLinkRepo() const { 
    return linkRepo; 
}

// Implementazione Setter
void Progetto::setNumeroPartecipanti(int num) { 
    numeroPartecipanti = num; 
}

void Progetto::setLinkRepo(const QString& link) { 
    linkRepo = link; 
}

void Progetto::accept(Visitatore& v) {
    v.visita(*this);
}