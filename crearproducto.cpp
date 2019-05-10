#include "crearproducto.h"
#include "ui_crearproducto.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>
#include <QSqlRecord>
#include <QSqlField>
crearProducto::crearProducto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::crearProducto)
{
    ui->setupUi(this);
}

crearProducto::~crearProducto()
{
    delete ui;
}

QSqlRecord crearProducto::getRecord() const
{
    QSqlRecord record;
    record.append(QSqlField("id_producto"));
    record.append(QSqlField("marca"));
    record.append(QSqlField("modelo"));
    record.append(QSqlField("precio"));
    record.append(QSqlField("descripcion"));
    record.setGenerated("id_producto", true);
    record.setValue("marca", ui->leMarca->text());
    record.setValue("modelo", ui->leModelo->text());
    record.setValue("precio", ui->lePrecio->text());
    record.setValue("descripcion", ui->leDescripcion->text());
    return record;
}


void crearProducto::on_btnCrearProd_clicked()
{

}

void crearProducto::on_pushButton_clicked(){

}
