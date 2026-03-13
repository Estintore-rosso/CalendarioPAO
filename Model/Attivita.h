#ifndef ATTIVITA_H
#define ATTIVITA_H

#pragma once
#include <QDateTime>
#include <QString>
#include <QJsonObject>
#include <vector>

class AttivitaVisitatore; // dichiarazione anticipata per evitare dipendenze circolari
class Observer;

class Attivita {
    friend class CostruttAttivita;
public:
    
    Attivita(const QString& tit, const QDateTime& inizio, bool giorno);
    virtual ~Attivita() = default;

    // get
    QString getId() const;
    QDateTime getDInizio() const;
    QDateTime getDFine() const;
    QString getTitolo() const;
    QString getDescrizione() const;
    bool getTuttoGiorno() const;
    virtual QString getTipo() const = 0;

    // set
    void setDInizio(const QDateTime &date);
    void setDFine(const QDateTime &date);
    void setTitolo(const QString &text);
    void setDescrizione(const QString &text);
    void setTuttoGiorno(const bool &giorno);

    void registraObserver(Observer* oss);
    void rimuoviObserver(Observer* oss);
    void notify();

    // Polimorfismo puro (Visitor Pattern per la GUI)
    virtual void accetta(AttivitaVisitatore& v) = 0;

    // Persistenza JSON
    virtual QJsonObject toJson() const;

protected:
    Attivita()=default;
    virtual void caricaJson(const QJsonObject& json);

private:
    QString id;
    QDateTime dInizio;
    QDateTime dFine;
    bool tuttoGiorno=false;
    QString titolo;
    QString descrizione;
    std::vector<Observer*> observers;
};

#endif // ATTIVITA_H
