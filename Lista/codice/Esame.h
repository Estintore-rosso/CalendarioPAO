#pragma once

#include "Attivita.h"

class Esame : public Attivita {
private:
    int cfu;
    int voto;
    bool superato;

public:
    // costruttore per esame futuro (voto e superato inizializzati a default)
    Esame(const QString& t, const QString& m, const QString& d, const QDate& data, int c);
    // costruttore completo, usato principalmente in fase di caricamento JSON
    Esame(const QString& t, const QString& m, const QString& d, const QDate& data, int c, int v, bool s);

    bool isUrgente(const QDate& oggi) const override;
    QJsonObject toJson() const override;

    int getCfu() const;
    int getVoto() const;
    bool isSuperato() const;

    void setSuperato(bool s);
    void setVoto(int v);
    void registraEsito(int v);

    void accept(Visitatore& v) override;
};
