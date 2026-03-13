#ifndef SCADENZA_H
#define SCADENZA_H

#pragma once
#include "Attivita.h"
#include <QString>
#include <QDateTime>
#include <QJsonObject>

class AttivitaVisitatore;

class Scadenza: public Attivita{
    friend class CostruttAttivita;

    public:
        Scadenza(const QString& tit, const QDateTime& inizio, bool tuttoGiorno, const QString& etich, bool urg);

        ~Scadenza() override = default;

        bool isUrgente() const;
        void setUrgente( bool urg);
        QString getTipo() const override;

        QString getEtichetta() const;
        void setEtichetta(const QString& etich);

        void accetta(AttivitaVisitatore& v) override;
        QJsonObject toJson() const override;

    protected:
        Scadenza() = default;
        void caricaJson(const QJsonObject& json) override;

    private:
        QString etichetta;
        bool urgente;
};

#endif