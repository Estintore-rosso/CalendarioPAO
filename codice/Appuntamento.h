#ifndef APPUNTAMENTO_H
#define APPUNTAMENTO_H

#include "Attivita.h"
#include <QDateTime>

class Appuntamento : public Attivita {
private:
    QDateTime inizio;
    QDateTime fine;
    QString luogo;

public:
    Appuntamento(const QString& t, const QString& d, const QDateTime& i, const QDateTime& f, const QString& l);

    QDateTime getInizio() const;
    QDateTime getFine() const;
    QString getLuogo() const;

    bool isUrgente(const QDate& dataOdierna) const override;
    QJsonObject toJson() const override;
};

#endif // APPUNTAMENTO_H