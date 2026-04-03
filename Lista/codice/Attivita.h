#pragma once

#include <QString>
#include <QDate>
#include <QJsonObject>

class Visitatore;

class Attivita {
private:
    QString titolo;
    QString materia;
    QString descrizione;
    QDate dataAttivita;

public:
    Attivita(const QString& t, const QString& m, const QString& d, const QDate& data);
    virtual ~Attivita() = default; 

    // Getter
    QString getTitolo() const;
    QString getMateria() const;
    QString getDescrizione() const;
    QDate getDataAttivita() const;

    // Metodi di utilità
    int getGiorniMancanti(const QDate& oggi) const;

    // Metodi polimorfi puri
    virtual bool isUrgente(const QDate& oggi) const = 0;
    virtual QJsonObject toJson() const = 0;

    virtual void accept(Visitatore& v) = 0;
};