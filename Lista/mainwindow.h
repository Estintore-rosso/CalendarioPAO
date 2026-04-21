#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QComboBox>
#include "Gestore.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_listaAttivita_currentRowChanged(int currentRow);
    void on_btnNuovo_clicked();
    void on_btnModifica_clicked();
    void on_btnElimina_clicked();
    void on_btnSalva_clicked();
    void on_btnAnnulla_clicked();
    void on_comboTipo_currentIndexChanged(int index);
    void on_btnEsporta_clicked();
    void on_btnImporta_clicked();

    void on_checkSuperato_toggled(bool checked);

    // Filtri
    void on_editRicerca_textChanged(const QString &arg1);
    void on_comboFiltroTipo_currentIndexChanged(int index);
    void on_checkFiltroUrgente_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;
    Gestore gestore;
    bool modalitaCreazione;

    void svuotaCampiForm();
    void aggiornaListaView();
    void applicaFiltri();
    void aggiornaCompleterMaterie();
};
#endif // MAINWINDOW_H
