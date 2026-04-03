#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog> // Necessario per le finestre di dialogo
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
    // Slot per la gestione della lista e dei bottoni (già visti)
    void on_listaAttivita_currentRowChanged(int currentRow);
    void on_btnNuovo_clicked();
    void on_btnSalva_clicked();
    void on_btnAnnulla_clicked();
    void on_btnModifica_clicked();
    void on_btnElimina_clicked();
    void on_comboTipo_currentIndexChanged(int index);

    // --- NUOVI SLOT PER JSON ---
    void on_btnEsporta_clicked();
    void on_btnImporta_clicked();

private:
    Ui::MainWindow *ui;
    Gestore gestore;
    bool modalitaCreazione;

    void svuotaCampiForm();
    void aggiornaListaView();
};
#endif // MAINWINDOW_H
