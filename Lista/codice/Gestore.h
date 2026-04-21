#pragma once

#include "Attivita.h"
#include "Esame.h"
#include "Progetto.h"
#include "Evento.h"

#include <vector>
#include <memory>
#include <QString>

class Gestore {
private:
    std::vector<std::unique_ptr<Attivita>> listaAttivita;

public:
    Gestore() = default;
    ~Gestore() = default;

    void aggiungiAttivita(std::unique_ptr<Attivita> nuovaAttivita);
    bool rimuoviAttivita(int indice);
    Attivita* getAttivita(int indice) const;
    int getNumeroAttivita() const;
    void svuota();

    bool salvaSuFile(const QString& percorsoFile) const;
    bool caricaDaFile(const QString& percorsoFile);
};
