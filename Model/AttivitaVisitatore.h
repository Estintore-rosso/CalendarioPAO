#ifndef ATTIVITAVISITOR_H
#define ATTIVITAVISITOR_H

// senza dover includere i loro file .h (evita inclusioni circolari!)
class Appuntamento;

class AttivitaVisitor {
public:
    virtual ~AttivitaVisitor() = default;

    // Un metodo visit() per OGNI classe concreta che creerai
    virtual void visit(Appuntamento& appuntamento) = 0;
    
};

#endif