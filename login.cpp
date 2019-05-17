#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include <QDebug>
login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked()
{
    QString contra = ui->lineEdit->text();

    if(contra == "hola123"){
        wMain = new MainWindow(this);
        wMain->show();

        //this->close();
    }

    else{
        qDebug() <<"Contraseña incorrecta";
    }
}
