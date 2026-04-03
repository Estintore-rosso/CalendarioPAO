/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QListWidget *listaAttivita;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btnNuovo;
    QPushButton *btnImporta;
    QPushButton *btnEsporta;
    QStackedWidget *stackedPrincip;
    QWidget *page_AggMod;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_4;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *editTitolo;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *editMateria;
    QDateEdit *editData;
    QTextEdit *editDesc;
    QComboBox *comboTipo;
    QStackedWidget *stackedInterno;
    QWidget *page_Esame;
    QHBoxLayout *horizontalLayout_7;
    QFormLayout *formLayout_2;
    QLabel *label_6;
    QSpinBox *spinCFU;
    QCheckBox *checkSuperato;
    QLabel *label_7;
    QLabel *label_8;
    QSpinBox *spinVoto;
    QWidget *page_Progetto;
    QHBoxLayout *horizontalLayout_8;
    QFormLayout *formLayout_3;
    QLabel *label_9;
    QSpinBox *spinPartecip;
    QLabel *label_10;
    QLineEdit *editRepo;
    QWidget *page_Evento;
    QHBoxLayout *horizontalLayout_9;
    QFormLayout *formLayout_4;
    QLabel *label_11;
    QLabel *label_12;
    QLineEdit *editMeeting;
    QLineEdit *editPosizione;
    QCheckBox *checkPartecipazione;
    QLabel *label_13;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *btnAnnulla;
    QPushButton *btnSalva;
    QWidget *page_Info;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *lbl_TitoloDet;
    QTextBrowser *textDett;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *btnElimina;
    QPushButton *btnModifica;
    QWidget *page_Vuota;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listaAttivita = new QListWidget(widget);
        listaAttivita->setObjectName(QString::fromUtf8("listaAttivita"));

        verticalLayout->addWidget(listaAttivita);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        btnNuovo = new QPushButton(widget);
        btnNuovo->setObjectName(QString::fromUtf8("btnNuovo"));

        horizontalLayout_3->addWidget(btnNuovo);

        btnImporta = new QPushButton(widget);
        btnImporta->setObjectName(QString::fromUtf8("btnImporta"));

        horizontalLayout_3->addWidget(btnImporta);

        btnEsporta = new QPushButton(widget);
        btnEsporta->setObjectName(QString::fromUtf8("btnEsporta"));

        horizontalLayout_3->addWidget(btnEsporta);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout->addWidget(widget);

        stackedPrincip = new QStackedWidget(centralwidget);
        stackedPrincip->setObjectName(QString::fromUtf8("stackedPrincip"));
        page_AggMod = new QWidget();
        page_AggMod->setObjectName(QString::fromUtf8("page_AggMod"));
        horizontalLayout_6 = new QHBoxLayout(page_AggMod);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_2 = new QLabel(page_AggMod);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        editTitolo = new QLineEdit(page_AggMod);
        editTitolo->setObjectName(QString::fromUtf8("editTitolo"));

        formLayout->setWidget(0, QFormLayout::FieldRole, editTitolo);

        label_3 = new QLabel(page_AggMod);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(page_AggMod);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);

        label_5 = new QLabel(page_AggMod);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_5);

        editMateria = new QLineEdit(page_AggMod);
        editMateria->setObjectName(QString::fromUtf8("editMateria"));

        formLayout->setWidget(1, QFormLayout::FieldRole, editMateria);

        editData = new QDateEdit(page_AggMod);
        editData->setObjectName(QString::fromUtf8("editData"));
        editData->setCalendarPopup(true);

        formLayout->setWidget(2, QFormLayout::FieldRole, editData);

        editDesc = new QTextEdit(page_AggMod);
        editDesc->setObjectName(QString::fromUtf8("editDesc"));

        formLayout->setWidget(3, QFormLayout::FieldRole, editDesc);


        verticalLayout_4->addLayout(formLayout);

        comboTipo = new QComboBox(page_AggMod);
        comboTipo->addItem(QString());
        comboTipo->addItem(QString());
        comboTipo->addItem(QString());
        comboTipo->setObjectName(QString::fromUtf8("comboTipo"));

        verticalLayout_4->addWidget(comboTipo);

        stackedInterno = new QStackedWidget(page_AggMod);
        stackedInterno->setObjectName(QString::fromUtf8("stackedInterno"));
        page_Esame = new QWidget();
        page_Esame->setObjectName(QString::fromUtf8("page_Esame"));
        horizontalLayout_7 = new QHBoxLayout(page_Esame);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        label_6 = new QLabel(page_Esame);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_6);

        spinCFU = new QSpinBox(page_Esame);
        spinCFU->setObjectName(QString::fromUtf8("spinCFU"));
        spinCFU->setMinimum(1);
        spinCFU->setMaximum(20);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, spinCFU);

        checkSuperato = new QCheckBox(page_Esame);
        checkSuperato->setObjectName(QString::fromUtf8("checkSuperato"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, checkSuperato);

        label_7 = new QLabel(page_Esame);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_7);

        label_8 = new QLabel(page_Esame);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_8);

        spinVoto = new QSpinBox(page_Esame);
        spinVoto->setObjectName(QString::fromUtf8("spinVoto"));
        spinVoto->setMaximum(31);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, spinVoto);


        horizontalLayout_7->addLayout(formLayout_2);

        stackedInterno->addWidget(page_Esame);
        page_Progetto = new QWidget();
        page_Progetto->setObjectName(QString::fromUtf8("page_Progetto"));
        horizontalLayout_8 = new QHBoxLayout(page_Progetto);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        label_9 = new QLabel(page_Progetto);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_9);

        spinPartecip = new QSpinBox(page_Progetto);
        spinPartecip->setObjectName(QString::fromUtf8("spinPartecip"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, spinPartecip);

        label_10 = new QLabel(page_Progetto);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_10);

        editRepo = new QLineEdit(page_Progetto);
        editRepo->setObjectName(QString::fromUtf8("editRepo"));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, editRepo);


        horizontalLayout_8->addLayout(formLayout_3);

        stackedInterno->addWidget(page_Progetto);
        page_Evento = new QWidget();
        page_Evento->setObjectName(QString::fromUtf8("page_Evento"));
        horizontalLayout_9 = new QHBoxLayout(page_Evento);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        label_11 = new QLabel(page_Evento);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_11);

        label_12 = new QLabel(page_Evento);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        formLayout_4->setWidget(1, QFormLayout::LabelRole, label_12);

        editMeeting = new QLineEdit(page_Evento);
        editMeeting->setObjectName(QString::fromUtf8("editMeeting"));

        formLayout_4->setWidget(0, QFormLayout::FieldRole, editMeeting);

        editPosizione = new QLineEdit(page_Evento);
        editPosizione->setObjectName(QString::fromUtf8("editPosizione"));

        formLayout_4->setWidget(1, QFormLayout::FieldRole, editPosizione);

        checkPartecipazione = new QCheckBox(page_Evento);
        checkPartecipazione->setObjectName(QString::fromUtf8("checkPartecipazione"));

        formLayout_4->setWidget(2, QFormLayout::FieldRole, checkPartecipazione);

        label_13 = new QLabel(page_Evento);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        formLayout_4->setWidget(2, QFormLayout::LabelRole, label_13);


        horizontalLayout_9->addLayout(formLayout_4);

        stackedInterno->addWidget(page_Evento);

        verticalLayout_4->addWidget(stackedInterno);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        btnAnnulla = new QPushButton(page_AggMod);
        btnAnnulla->setObjectName(QString::fromUtf8("btnAnnulla"));

        horizontalLayout_11->addWidget(btnAnnulla);

        btnSalva = new QPushButton(page_AggMod);
        btnSalva->setObjectName(QString::fromUtf8("btnSalva"));

        horizontalLayout_11->addWidget(btnSalva);


        verticalLayout_4->addLayout(horizontalLayout_11);


        horizontalLayout_6->addLayout(verticalLayout_4);

        stackedPrincip->addWidget(page_AggMod);
        page_Info = new QWidget();
        page_Info->setObjectName(QString::fromUtf8("page_Info"));
        horizontalLayout_4 = new QHBoxLayout(page_Info);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        lbl_TitoloDet = new QLabel(page_Info);
        lbl_TitoloDet->setObjectName(QString::fromUtf8("lbl_TitoloDet"));

        verticalLayout_3->addWidget(lbl_TitoloDet);

        textDett = new QTextBrowser(page_Info);
        textDett->setObjectName(QString::fromUtf8("textDett"));

        verticalLayout_3->addWidget(textDett);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        btnElimina = new QPushButton(page_Info);
        btnElimina->setObjectName(QString::fromUtf8("btnElimina"));

        horizontalLayout_5->addWidget(btnElimina);

        btnModifica = new QPushButton(page_Info);
        btnModifica->setObjectName(QString::fromUtf8("btnModifica"));

        horizontalLayout_5->addWidget(btnModifica);


        verticalLayout_3->addLayout(horizontalLayout_5);


        horizontalLayout_4->addLayout(verticalLayout_3);

        stackedPrincip->addWidget(page_Info);
        page_Vuota = new QWidget();
        page_Vuota->setObjectName(QString::fromUtf8("page_Vuota"));
        verticalLayout_2 = new QVBoxLayout(page_Vuota);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(page_Vuota);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        stackedPrincip->addWidget(page_Vuota);

        horizontalLayout->addWidget(stackedPrincip);


        horizontalLayout_2->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btnNuovo->setText(QCoreApplication::translate("MainWindow", "Aggiungi", nullptr));
        btnImporta->setText(QCoreApplication::translate("MainWindow", "ImportaJson", nullptr));
        btnEsporta->setText(QCoreApplication::translate("MainWindow", "EsportaJson", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Titolo: ", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Materia: ", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Data: ", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Descrizione: ", nullptr));
        comboTipo->setItemText(0, QCoreApplication::translate("MainWindow", "Esame", nullptr));
        comboTipo->setItemText(1, QCoreApplication::translate("MainWindow", "Progetto", nullptr));
        comboTipo->setItemText(2, QCoreApplication::translate("MainWindow", "Evento", nullptr));

        label_6->setText(QCoreApplication::translate("MainWindow", "CFU: ", nullptr));
        checkSuperato->setText(QCoreApplication::translate("MainWindow", "Superato", nullptr));
        label_7->setText(QString());
        label_8->setText(QCoreApplication::translate("MainWindow", "Voto: ", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Numero Partecipanti:", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Link Repository: ", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Link Meeting:", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Link Posizione:", nullptr));
        checkPartecipazione->setText(QCoreApplication::translate("MainWindow", "Parteciperai?", nullptr));
        label_13->setText(QString());
        btnAnnulla->setText(QCoreApplication::translate("MainWindow", "Annulla", nullptr));
        btnSalva->setText(QCoreApplication::translate("MainWindow", "Salva", nullptr));
        lbl_TitoloDet->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        btnElimina->setText(QCoreApplication::translate("MainWindow", "Elimina", nullptr));
        btnModifica->setText(QCoreApplication::translate("MainWindow", "Modifica", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Seleziona una Attivit\303\240 o clicca Aggiungi", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
