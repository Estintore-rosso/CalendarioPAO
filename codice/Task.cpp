#include "Task.h"

// Un task nuovo parte sempre come non completato
Task::Task(const QString& t, const QString& d, int p)
    : Attivita(t, d), completato(false), priorita(p) {}

bool Task::isCompletato() const { return completato; }

void Task::setCompletato(bool stato) { completato = stato; }

int Task::getPriorita() const { return priorita; }

bool Task::isUrgente(const QDate& dataOdierna) const {
    // Il parametro dataOdierna in questo caso specifico non ci serve, e va bene così!
    // Un Task è urgente se non è completato e ha priorità alta (es. 4 o 5)
    return !completato && priorita >= 4;
}

QJsonObject Task::toJson() const {
    QJsonObject json;
    json["tipo"] = "Task";
    json["titolo"] = getTitolo();
    json["descrizione"] = getDescrizione();
    json["completato"] = completato;
    json["priorita"] = priorita;
    return json;
}