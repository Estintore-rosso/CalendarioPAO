#ifndef MEETINGVIRTUALE_H
#define MEETINGVIRTUALE_H

#pragma once
#include "AttivitaPersone.h"
#include <QString>
#include <QDateTime>
#include <QJsonObject>

class AttivitaVisitatore;

class MeetingVirtuale: public AttivitaPersone{
    friend class CostruttAttivita;

    public:
        MeetingVirtuale(const QString& tit, const QDateTime& inizio, bool tuttoGiorno, const std::vector<QString>& listaPersone, const QString& link);

        ~MeetingVirtuale() override = default;

        QString getUrl() const;
        void setUrl(const QString& urlNuovo);

        QString getTipo() const override;
        
        void accetta(AttivitaVisitatore& v) override;
        QJsonObject toJson() const override;

    protected:
        MeetingVirtuale() = default;
        void caricaJson(const QJsonObject& json) override;

    private:
        QString url;
};

#endif