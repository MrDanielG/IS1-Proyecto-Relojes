#include "crearcontato.h"
#include "ui_crearcontato.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>
#include <QSqlRecord>
#include <QSqlField>

crearContato::crearContato(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::crearContato)
{
    ui->setupUi(this);
}

crearContato::~crearContato()
{
    delete ui;
}

QSqlRecord crearContato::getRecord() const
{
    QSqlRecord record;
    record.append(QSqlField("id_contacto"));
    record.append(QSqlField("nombre"));
    record.append(QSqlField("paterno"));
    record.append(QSqlField("materno"));
    record.append(QSqlField("telefono"));
    record.setGenerated("id_contacto", true);
    record.setValue("nombre", ui->leNombre->text());
    record.setValue("paterno", ui->lePaterno->text());
    record.setValue("materno", ui->leMaterno->text());
    record.setValue("telefono", ui->leTelefono->text());
    return record;
}

void crearContato::on_pushButton_clicked()
{
    /*
    QString nombre, paterno, materno, telefono;
    nombre = ui->leNombre->text();
    paterno = ui->lePaterno->text();
    materno = ui->leMaterno->text();
    telefono = ui->leTelefono->text();

    qDebug() << nombre;
    qDebug() << paterno;
    qDebug() << materno;
    qDebug() << telefono;

    QMessageBox msjConfirmacion;

    QSqlDatabase mDatabase = QSqlDatabase::database("ConexionPrincipal");
    if(!mDatabase.isOpen()){
        qDebug() <<"Error en la conexion";
        return;
    }
    else {
        QSqlQuery query(mDatabase);

        if(query.exec("INSERT INTO CONTACTO(NOMBRE, PATERNO, MATERNO, TELEFONO) VALUES('"+nombre+"', '"+paterno+"', '"+materno+"', '"+telefono+"')")){
            msjConfirmacion.setText("Contacto Agregado");
            msjConfirmacion.exec();
            this->close();
        }


    }
    */

}
