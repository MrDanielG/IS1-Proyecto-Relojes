#include "ventanainventario.h"
#include "ui_ventanainventario.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlRecord>
#include <QMessageBox>
#include <QSqlQuery>

VentanaInventario::VentanaInventario(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VentanaInventario)
{
    ui->setupUi(this);

    QSqlDatabase mDatabase = QSqlDatabase::database("ConexionPrincipal");
    if(!mDatabase.isOpen()){
        qDebug() <<"Error en la conexion";
        return;
    }
    else {
        tm = new QSqlTableModel(this, mDatabase);
        tm->setTable("producto");
        ui->tablaInventario->setModel(tm);
        tm->select();
    }
}

VentanaInventario::~VentanaInventario()
{
    delete ui;
}

void VentanaInventario::on_btnAgregarProducto_clicked()
{
    if(vCrearProducto.exec() == QDialog::Accepted){
        QSqlRecord rec = vCrearProducto.getRecord();
        if(tm->insertRecord(-1,rec)){
            QMessageBox msjAgrega;
            msjAgrega.setText("Producto Agregado");
            msjAgrega.exec();
            tm->select();
        }
    }
}

void VentanaInventario::on_btnEliminarProducto_clicked()
{
    QMessageBox::StandardButton pregElimina;
    pregElimina = QMessageBox::question(this, "Confirmar Eliminacion",
                                        "¿Deseas eliminar el contacto seleccionado?",
                                        QMessageBox::Yes | QMessageBox::No);

    if(pregElimina == QMessageBox::Yes){
        tm->removeRow(ui->tablaInventario->currentIndex().row());
        QMessageBox msjEliminacion;
        msjEliminacion.setText("Contacto Eliminado");
        msjEliminacion.exec();
        tm->select();
    }
}

void VentanaInventario::on_btnModificarProducto_clicked()
{
    vActualizarProducto.exec();
    tm->select();
}
