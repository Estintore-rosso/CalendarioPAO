#ifndef ATTIVITAPERSONE_H
#define ATTIVITAPERSONE_H

#pragma once
#include "Attivita.h"

class AttivitaPersone : public Attivita {
    friend class CostruttAttivita;
    public:
        
        AttivitaPersone(const QString& tit, const QDateTime& inizio, bool tuttoGiorno, const std::vector<QString>& listaPersone);

        ~AttivitaPersone() override = default;

        QJsonObject toJson() const override;

        void aggiungiPersona(const QString& persona);
        void rimuoviPersona(const QString& persona);
        std::vector<QString> getPersone() const;
    
    protected:
        AttivitaPersone()=default;
        void caricaJson(const QJsonObject& json) override;
    
    private:
        std::vector<QString> persone;

};
#endif