#include "CostruttAttivita.h"
#include "Scadenza.h"
#include "Task.h"
#include "Appuntamento.h"
#include "MeetingVirtuale.h"

Attivita* CostruttAttivita::fromJson(const QJsonObject& json) {

    QString tipo = json["tipo"].toString();
    Attivita* nuova = nullptr;

    if (tipo == "MeetingVirtuale") {
        nuova = new MeetingVirtuale(); 
    } 
    else if (tipo == "Appuntamento") {
        nuova = new Appuntamento();
    } 
    else if (tipo == "Scadenza") {
        nuova = new Scadenza();
    }
    else if (tipo == "Task") {
        nuova = new Task();
    }

    if (nuova) {
        nuova->caricaJson(json);
    }

    return nuova;
}