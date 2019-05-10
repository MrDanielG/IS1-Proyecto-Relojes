#include "mainwindow.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlTableModel>

int main(int argc, char *argv[])
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC", "ConexionPrincipal");


    db.setDatabaseName("QTConection");
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
