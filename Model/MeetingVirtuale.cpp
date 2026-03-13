#include "MeetingVirtuale.h"
#include "AttivitaVisitatore.h"
#include <QString>
#include <QDateTime>

MeetingVirtuale::MeetingVirtuale(const QString& tit, const QDateTime& inizio, bool tuttoGiorno, const std::vector<QString>& listaPersone, const QString& link): 
    AttivitaPersone(tit,inizio,tuttoGiorno,listaPersone), 
    url(link)
    {}

QString MeetingVirtuale::getTipo() const { return "MeetingVirtuale"; }
QString MeetingVirtuale::getUrl() const {return url;}

void MeetingVirtuale::setUrl(const QString& link){ url=link; notify(); }

void MeetingVirtuale::accetta(AttivitaVisitatore& v) {
    v.visit(*this);
}

QJsonObject MeetingVirtuale::toJson() const{
    QJsonObject json = AttivitaPersone::toJson(); 
    json["url"] = url;
    json["tipo"] = getTipo(); 
    return json;
}

void MeetingVirtuale::caricaJson(const QJsonObject& json ){
    AttivitaPersone::caricaJson(json);
    url = json["url"].toString();
}


