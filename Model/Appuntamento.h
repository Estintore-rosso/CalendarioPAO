#ifndef APPUNTAMENTO_H
#define APPUNTAMENTO_H

#pragma once
#include "AttivitaPersone.h"
#include <QString>
#include <QDateTime>
#include <QJsonObject>

class AttivitaVisitatore;

class Appuntamento: public AttivitaPersone{
    friend class CostruttAttivita;

    public:
        Appuntamento(const QString& tit, const QDateTime& inizio, bool tuttoGiorno, const std::vector<QString>& listaPersone, const QString& loco);

        ~Appuntamento() override = default;

        QString getLuogo() const;
        void setLuogo(const QString& loco);

        void accetta(AttivitaVisitatore& v) override;
        QJsonObject toJson() const override;

    protected:
        Appuntamento() = default;
        void caricaJson(const QJsonObject& json) override;

    private:
        QString luogo;
};

#endif