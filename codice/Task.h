#ifndef TASK_H
#define TASK_H

#include "Attivita.h"

class Task : public Attivita {
private:
    bool completato;
    int priorita; // Esempio: da 1 (bassa) a 5 (alta)

public:
    Task(const QString& t, const QString& d, int p);

    bool isCompletato() const;
    void setCompletato(bool stato);
    int getPriorita() const;

    bool isUrgente(const QDate& dataOdierna) const override;
    QJsonObject toJson() const override;
};

#endif // TASK_H