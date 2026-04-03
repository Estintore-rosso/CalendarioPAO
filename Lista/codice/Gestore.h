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

    // --- Operazioni sulla lista ---
    void aggiungiAttivita(std::unique_ptr<Attivita> nuovaAttivita);
    bool rimuoviAttivita(int indice);
    
    // Restituisce un puntatore nudo per leggere/modificare l'attività
    Attivita* getAttivita(int indice) const;
    
    int getNumeroAttivita() const;
    void svuota();

    // --- Operazioni su File (JSON) ---
    bool salvaSuFile(const QString& percorsoFile) const;
    bool caricaDaFile(const QString& percorsoFile);
};