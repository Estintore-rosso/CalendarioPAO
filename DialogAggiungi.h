#ifndef DIALOGAGGIUNGI_H
#define DIALOGAGGIUNGI_H

#include <QDialog>

namespace Ui {
class DialogAggiungi;
}

class DialogAggiungi : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAggiungi(QWidget *parent = nullptr);
    ~DialogAggiungi();

    QString getTitolo() const ;
    QString getTipo() const ;
    QDateTime getDataInizio() const ;
    QDateTime getDataFine() const ;
    QString getLuogo() const ;
    QString getLink() const ;
    QString getPartecipanti() const ;
    QString getDescrizione() const ;
    QString getEtichetta() const ;
    bool isUrgente() const ;
    bool isGiorno() const ;

private:
    Ui::DialogAggiungi *ui;
};

#endif // DialogAggiungi_H
