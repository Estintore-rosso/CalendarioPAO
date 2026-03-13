#ifndef ATTIVITAVISITATORE_H
#define ATTIVITAVISITATORE_H

class MeetingVirtuale;
class Task;
class Appuntamento;
class Scadenza;

class AttivitaVisitatore {
public:
    virtual ~AttivitaVisitatore() = default;

    // Creare per ogni classe concreta
    virtual void visit(MeetingVirtuale& appuntamento) = 0;
    virtual void visit(Task& appuntamento) = 0;
    virtual void visit(Appuntamento& appuntamento) = 0;
    virtual void visit(Scadenza& appuntamento) = 0;

};

#endif