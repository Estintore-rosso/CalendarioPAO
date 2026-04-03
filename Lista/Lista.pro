QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# --- AGGIUNGI QUESTA RIGA ---
INCLUDEPATH += $$PWD/codice

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    codice/Attivita.cpp \
    codice/Esame.cpp \
    codice/Evento.cpp \
    codice/Gestore.cpp \
    codice/Progetto.cpp

HEADERS += \
    mainwindow.h \
    codice/Attivita.h \
    codice/Esame.h \
    codice/Evento.h \
    codice/Gestore.h \
    codice/Progetto.h \
    codice/Visitatore.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
