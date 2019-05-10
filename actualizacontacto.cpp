#include "actualizacontacto.h"
#include "ui_actualizacontacto.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>
#include <QSqlRecord>
#include <QSqlField>

actualizaContacto::actualizaContacto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::actualizaContacto)
{
    ui->setupUi(this);

}

actualizaContacto::~actualizaContacto()
{
    delete ui;
}

void actualizaContacto::on_pushButton_clicked()
{

}

void actualizaContacto::on_btnActualizar_clicked()
{
    QString nombre, paterno, materno, telefono, id;
    id = ui->spinBox->text();
    nombre = ui->lineEditNombreC->text();
    paterno = ui->lineEditPaternoC->text();
    materno = ui->lineEditMaternoC->text();
    telefono = ui->lineEditTelefonoC->text();

    qDebug() << id;
    qDebug() << nombre;
    qDebug() << paterno;
    qDebug() << materno;
    qDebug() << telefono;

    QSqlDatabase mDatabase = QSqlDatabase::database("ConexionPrincipal");
    if(!mDatabase.isOpen()){
        qDebug() <<"Error en la conexion";
        return;
    }
    else {
        QSqlQuery query1(mDatabase);
                    query1.prepare("UPDATE contacto SET nombre = '"+nombre+"', paterno = '"+paterno+"', materno = '"+materno+"', telefono = '"+telefono+"' WHERE id_contacto = "+id );
                    if(query1.exec()){
                    query1.finish();

                    QMessageBox msjAgrega;
                    msjAgrega.setText("Contacto Modificado");
                    msjAgrega.exec();
                    this->close();

                    }
                    else {
                        qDebug() << "Error querty";
                    }
    }
}
