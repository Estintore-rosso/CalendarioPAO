#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#pragma once
#include <vector>
#include "Model/Attivita.h"
#include <QMainWindow>
#include <QLayout>
#include <QCheckBox>
#include "Model/Task.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    std::vector<Attivita*> attivitaList; // Lista per memorizzare le attività

    void aggiornaTutto();
    void aggiornaCalendario();
    void aggiornaListeAttivita();
    void svuotaLayout(QLayout* layout);
    QWidget* creaRigaAttivita(Attivita* a);
    QWidget* creaRigaTask(Task* t);
    void eliminaAttivita(Attivita* a);
    void mostraDettagli(Attivita* a);
    private slots:
        void on_actionAggiungi_triggered();
        void on_actionImportaJson_triggered();
};
#endif // MAINWINDOW_H
