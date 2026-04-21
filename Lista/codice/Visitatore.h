#pragma once

class Esame;
class Progetto;
class Evento;

class Visitatore {
public:
    virtual ~Visitatore() = default;

    virtual void visita(Esame& esame) = 0;
    virtual void visita(Progetto& progetto) = 0;
    virtual void visita(Evento& evento) = 0;
};
