QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    DialogAggiungi.cpp \
    Model/Attivita.cpp \
    Model/AttivitaPersone.cpp \
    Model/Appuntamento.cpp \
    Model/MeetingVirtuale.cpp \
    Model/Scadenza.cpp \
    Model/Task.cpp \
    Model/CostruttAttivita.cpp

HEADERS += \
    mainwindow.h \
    DialogAggiungi.h \
    Model/Attivita.h \
    Model/AttivitaPersone.h \
    Model/Appuntamento.h \
    Model/MeetingVirtuale.h \
    Model/Scadenza.h \
    Model/Task.h \
    Model/CostruttAttivita.h \
    Model/AttivitaVisitatore.h \
    Model/Observer.h

FORMS += \
    mainwindow.ui \
    DialogAggiungi.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
