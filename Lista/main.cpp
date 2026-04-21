#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile f(":/tema/darkstyle.qss");
    if (f.open(QFile::ReadOnly | QFile::Text)) {
        QTextStream ts(&f);
        a.setStyleSheet(ts.readAll());
        f.close();
    } else {
        qDebug() << "Impossibile caricare il foglio di stile.";
    }

    MainWindow w;
    w.setWindowTitle("Gestore Attività Universitarie");
    w.resize(900, 600);
    w.show();

    return a.exec();
}
