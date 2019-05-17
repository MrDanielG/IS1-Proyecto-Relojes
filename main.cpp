#include "mainwindow.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QTranslator>
#include <QLibraryInfo>
#include <login.h>
int main(int argc, char *argv[])
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC", "ConexionPrincipal");

    QTranslator idioma;
    idioma.load("qt_"+QLocale::system().name(), QLibraryInfo::location(QLibraryInfo::TranslationsPath));

    db.setDatabaseName("QTConection");
    QApplication a(argc, argv);
    a.installTranslator(&idioma);
    MainWindow w;
    //w.show();
    login wLog;
    wLog.show();

    return a.exec();
}
