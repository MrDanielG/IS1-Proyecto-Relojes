#include "actualizarproducto.h"
#include "ui_actualizarproducto.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>
#include <QSqlRecord>
#include <QSqlField>
actualizarProducto::actualizarProducto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::actualizarProducto)
{
    ui->setupUi(this);
}

actualizarProducto::~actualizarProducto()
{
    delete ui;
}

void actualizarProducto::on_btnActualizar_clicked()
{
    QString marca, modelo, precio, descripcion, id;
    id = ui->spinBox->text();
    marca = ui->leMarca->text();
    modelo = ui->leModelo->text();
    precio = ui->lePrecio->text();
    descripcion = ui->leDescripcion->text();

    qDebug() <<marca;
    qDebug() <<modelo;
    qDebug() <<precio;
    qDebug() <<descripcion;

    QSqlDatabase mDatabase = QSqlDatabase::database("ConexionPrincipal");
    if(!mDatabase.isOpen()){
        qDebug() <<"Error en la conexion";
        return;
    }
    else {
        QSqlQuery query1(mDatabase);
                    query1.prepare("UPDATE producto SET marca = '"+marca+"', modelo = '"+modelo+"', precio = '"+precio+"', descripcion = '"+descripcion+"' WHERE id_producto = "+id );
                    if(query1.exec()){
                    query1.finish();

                    QMessageBox msjAgrega;
                    msjAgrega.setText("Producto Modificado");
                    msjAgrega.exec();
                    this->close();

                    }
                    else {
                        qDebug() << "Error querty";
                    }
    }

}
