#pragma once

// Forward declarations: diciamo al compilatore che queste classi esistono,
// senza dover includere i loro file .h (evitando loop infiniti di inclusioni).
class Esame;
class Progetto;
class Evento;

class Visitatore {
public:
    virtual ~Visitatore() = default;

    // Un metodo di visita puro per ogni classe concreta che abbiamo
    virtual void visita(Esame& esame) = 0;
    virtual void visita(Progetto& progetto) = 0;
    virtual void visita(Evento& evento) = 0;
};