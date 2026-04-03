#include "Attivita.h"

// Costruttore
Attivita::Attivita(const QString& t, const QString& m, const QString& d, const QDate& data)
    : titolo(t), materia(m), descrizione(d), dataAttivita(data) {}

// Implementazione dei Getter
QString Attivita::getTitolo() const {
    return titolo;
}

QString Attivita::getMateria() const {
    return materia;
}

QString Attivita::getDescrizione() const {
    return descrizione;
}

QDate Attivita::getDataAttivita() const {
    return dataAttivita;
}

// Implementazione logica dei giorni
int Attivita::getGiorniMancanti(const QDate& oggi) const {
    return oggi.daysTo(dataAttivita); 
}