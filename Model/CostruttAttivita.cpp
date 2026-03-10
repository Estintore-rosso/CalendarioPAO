#include "CostruttAttivita.h"

Attivita* CostruttAttivita::fromJson(const QJsonObject& json) {

    QString tipo = json["tipo"].toString();
    Attivita* nuova = nullptr;

    // 2. Logica di creazione (Factory Method)
    // Qui si decide quale istanza creare in base alla stringa nel JSON
    if (tipo == "MeetingVirtuale") {
        nuova = new MeetingVirtuale(); 
    } 
    else if (tipo == "Appuntamento") {
        nuova = new Appuntamento();
    } 
    else if (tipo == "Scadenza") {
        nuova = new Scadenza();
    }

    // 3. Inizializzazione polimorfa
    // Se il tipo è stato riconosciuto e l'oggetto creato con successo
    if (nuova) {
        // Chiamata al metodo virtuale caricaJson. 
        // Grazie al polimorfismo, verrà eseguita la versione corretta 
        // della classe specifica (es. MeetingVirtuale::caricaJson)
        nuova->caricaJson(json);
    }

    // Restituisce il puntatore all'oggetto pronto (o nullptr se il tipo è ignoto)
    return nuova;
}