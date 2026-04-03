#ifndef ATTIVITA_H
#define ATTIVITA_H

#include <QString>
#include <QDate>
#include <QJsonObject>

class Attivita {
private:
    QString titolo;
    QString descrizione;

public:
    Attivita(const QString& t, const QString& d);
    virtual ~Attivita() = default; // Distruttore virtuale

    QString getTitolo() const;
    QString getDescrizione() const;

    void setTitolo(const QString& t);
    void setDescrizione(const QString& d);

    // Metodi polimorfi puri
    virtual bool isUrgente(const QDate& dataOdierna) const = 0;
    virtual QJsonObject toJson() const = 0; 
};

#endif // ATTIVITA_H