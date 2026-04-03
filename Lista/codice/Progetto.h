#pragma once

#include "Attivita.h"
#include <QString>

class Progetto : public Attivita {
private:
    int numeroPartecipanti;
    QString linkRepo;

public:
    // Costruttore
    Progetto(const QString& t, const QString& m, const QString& d, const QDate& data, int numPartecipanti, const QString& link);

    // Override dei metodi base
    bool isUrgente(const QDate& oggi) const override;
    QJsonObject toJson() const override;

    // Getter specifici di Progetto
    int getNumeroPartecipanti() const;
    QString getLinkRepo() const;

    // Setter specifici
    void setNumeroPartecipanti(int num);
    void setLinkRepo(const QString& link);

    void accept(Visitatore& v) override;
};