#include "Attivita.h"

Attivita::Attivita(const QString& t, const QString& d) : titolo(t), descrizione(d) {}

QString Attivita::getTitolo() const {
    return titolo;
}

QString Attivita::getDescrizione() const {
    return descrizione;
}

void Attivita::setTitolo(const QString& t) {
    titolo = t;
}

void Attivita::setDescrizione(const QString& d) {
    descrizione = d;
}