#include "Task.h"
#include "AttivitaVisitatore.h"
#include <QString>
#include <QDateTime>

Task::Task(const QString& tit): 
    Attivita(tit,QDateTime(),false)
    {}

void Task::accetta(AttivitaVisitatore& v) {
    v.visit(*this);
}

QString Task::getTipo() const { return "Task"; }

QJsonObject Task::toJson() const{
    QJsonObject json = Attivita::toJson();
    json["tipo"] = getTipo(); 
    return json;
}


