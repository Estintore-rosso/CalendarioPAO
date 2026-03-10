#ifndef COSTRUTTATTIVITA_H
#define COSTRUTTATTIVITA_H

#include "Attivita.h"
#include <QJsonObject>

class CostruttAttivita {
    public:
        static Attivita* fromJson(const QJsonObject& json);

    private:
        CostruttAttivita() = delete;
};

#endif