#include "Esame.h"
#include "Visitatore.h"

Esame::Esame(const QString& t, const QString& m, const QString& d, const QDate& data, int c)
    : Attivita(t, m, d, data), cfu(c), voto(0), superato(false) {}

Esame::Esame(const QString& t, const QString& m, const QString& d, const QDate& data, int c, int v, bool s)
    : Attivita(t, m, d, data), cfu(c), voto(v), superato(s) {}

bool Esame::isUrgente(const QDate& oggi) const {
    int giorni = getGiorniMancanti(oggi);
    return !superato && giorni >= 0 && giorni <= 7;
}

QJsonObject Esame::toJson() const {
    QJsonObject json;
    json["tipo"] = "Esame";
    json["titolo"] = getTitolo();
    json["materia"] = getMateria();
    json["descrizione"] = getDescrizione();
    json["dataAttivita"] = getDataAttivita().toString(Qt::ISODate);
    json["cfu"] = cfu;
    json["voto"] = voto;
    json["superato"] = superato;
    return json;
}

int Esame::getCfu() const { return cfu; }
int Esame::getVoto() const { return voto; }
bool Esame::isSuperato() const { return superato; }

void Esame::setSuperato(bool s) { superato = s; }
void Esame::setVoto(int v) { voto = v; }

void Esame::registraEsito(int v) {
    voto = v;
    superato = (v >= 18);
}

void Esame::accept(Visitatore& v) {
    v.visita(*this);
}
