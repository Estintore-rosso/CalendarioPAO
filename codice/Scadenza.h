#ifndef SCADENZA_H
#define SCADENZA_H

#include "Attivita.h"

class Scadenza : public Attivita {
private:
    QDate dataScadenza;

public:
    Scadenza(const QString& t, const QString& d, const QDate& scadenza);

    QDate getDataScadenza() const;
    void setDataScadenza(const QDate& scadenza);

    bool isUrgente(const QDate& dataOdierna) const override;
    QJsonObject toJson() const override;
};

#endif // SCADENZA_H