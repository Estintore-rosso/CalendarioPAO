#ifndef DIALOGAGGIUGNI_H
#define DIALOGAGGIUGNI_H

#include <QDialog>

namespace Ui {
class DialogAggiugni;
}

class DialogAggiugni : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAggiugni(QWidget *parent = nullptr);
    ~DialogAggiugni();

    QString getTitolo() const ;
    QString getTipo() const ;
    QDate getDataInizio() const ;
    QDate getDataFine() const ;
    QString getLuogo() const ;
    QString getLink() const ;
    QString getPartecipanti() const ;
    QString getDescrizione() const ;
    QString getEtichetta() const ;
    bool isUrgente() const ;
    bool isGiorno() const ;

private:
    Ui::DialogAggiugni *ui;
};

#endif // DIALOGAGGIUGNI_H
