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

QJsonObject Task::toJson() const{
    QJsonObject json = Attivita::toJson();
    json["tipo"] = "Task"; 
    return json;
}

void Task::caricaJson(const QJsonObject& json ){
    Attivita::caricaJson(json);
}


