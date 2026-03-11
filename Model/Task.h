#ifndef TASK_H
#define TASK_H

#pragma once
#include "Attivita.h"
#include <QString>
#include <QJsonObject>

class AttivitaVisitatore;

class Task: public Attivita{
    friend class CostruttAttivita;

    public:
        Task(const QString& tit);

        ~Task() override = default;

        void accetta(AttivitaVisitatore& v) override;
        QJsonObject toJson() const override;

    protected:
        Task() = default;
        void caricaJson(const QJsonObject& json) override;

};

#endif