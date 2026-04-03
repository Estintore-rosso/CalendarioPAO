#pragma once

#include "Attivita.h"

class Esame : public Attivita {
private:
    int cfu;
    int voto;
    bool superato;

public:
    // 1. Costruttore per un ESAME FUTURO (non richiede voto e superato)
    Esame(const QString& t, const QString& m, const QString& d, const QDate& data, int c);

    // 2. Costruttore per un ESAME PASSATO (utile per caricare dal JSON)
    Esame(const QString& t, const QString& m, const QString& d, const QDate& data, int c, int v, bool s);

    // Override dei metodi base
    bool isUrgente(const QDate& oggi) const override;
    QJsonObject toJson() const override;

    // Getter
    int getCfu() const;
    int getVoto() const;
    bool isSuperato() const;

    // Metodi per aggiornare lo stato dell'esame in seguito
    void setSuperato(bool s);
    void setVoto(int v);
    
    // Opzionale: un metodo comodo che fa entrambe le cose
    void registraEsito(int v); 

    void accept(Visitatore& v) override;
};