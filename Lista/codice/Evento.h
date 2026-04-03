#pragma once

#include "Attivita.h"
#include <QString>

class Evento : public Attivita {
private:
    QString linkMeeting;
    QString posizione;
    bool intenzionePartecipare;

public:
    // Costruttore: link e posizione possono essere stringhe vuote se non applicabili
    Evento(const QString& t, const QString& m, const QString& d, const QDate& data, 
           const QString& link, const QString& pos, bool partecipero);

    // Override dei metodi base
    bool isUrgente(const QDate& oggi) const override;
    QJsonObject toJson() const override;

    // Getter specifici di Evento
    QString getLinkMeeting() const;
    QString getPosizione() const;
    bool getIntenzionePartecipare() const;

    // Setter specifici
    void setLinkMeeting(const QString& link);
    void setPosizione(const QString& pos);
    void setIntenzionePartecipare(bool partecipero);

    void accept(Visitatore& v) override;
};