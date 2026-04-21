#include "Progetto.h"
#include "Visitatore.h"

Progetto::Progetto(const QString& t, const QString& m, const QString& d, const QDate& data, int numPartecipanti, const QString& link)
    : Attivita(t, m, d, data), numeroPartecipanti(numPartecipanti), linkRepo(link) {}

bool Progetto::isUrgente(const QDate& oggi) const {
    int giorni = getGiorniMancanti(oggi);
    return giorni >= 0 && giorni <= 14;
}

QJsonObject Progetto::toJson() const {
    QJsonObject json;
    json["tipo"] = "Progetto";
    json["titolo"] = getTitolo();
    json["materia"] = getMateria();
    json["descrizione"] = getDescrizione();
    json["dataAttivita"] = getDataAttivita().toString(Qt::ISODate);
    json["numeroPartecipanti"] = numeroPartecipanti;
    json["linkRepo"] = linkRepo;
    return json;
}

int Progetto::getNumeroPartecipanti() const { return numeroPartecipanti; }
QString Progetto::getLinkRepo() const { return linkRepo; }

void Progetto::setNumeroPartecipanti(int num) { numeroPartecipanti = num; }
void Progetto::setLinkRepo(const QString& link) { linkRepo = link; }

void Progetto::accept(Visitatore& v) {
    v.visita(*this);
}
