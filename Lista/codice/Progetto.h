#pragma once

#include "Attivita.h"
#include <QString>

class Progetto : public Attivita {
private:
    int numeroPartecipanti;
    QString linkRepo;

public:
    Progetto(const QString& t, const QString& m, const QString& d, const QDate& data, int numPartecipanti, const QString& link);

    bool isUrgente(const QDate& oggi) const override;
    QJsonObject toJson() const override;

    int getNumeroPartecipanti() const;
    QString getLinkRepo() const;

    void setNumeroPartecipanti(int num);
    void setLinkRepo(const QString& link);

    void accept(Visitatore& v) override;
};
