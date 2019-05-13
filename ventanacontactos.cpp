#include "ventanacontactos.h"
#include "ui_ventanacontactos.h"
#include <actualizacontacto.h>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlRecord>
#include <QMessageBox>
#include <QSqlQuery>
VentanaContactos::VentanaContactos(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VentanaContactos)
{
    ui->setupUi(this);

    QSqlDatabase mDatabase = QSqlDatabase::database("ConexionPrincipal");
    if(!mDatabase.isOpen()){
        qDebug() <<"Error en la conexion";
        return;
    }
    else {
        tm = new QSqlTableModel(this, mDatabase);
        tm->setTable("contacto");
        ui->tablaContactos->setModel(tm);
        tm->select();
    }
}

VentanaContactos::~VentanaContactos()
{
    delete ui;
}

void VentanaContactos::on_btnAgregarContacto_clicked()
{
    if(vCrearContacto.exec() == QDialog::Accepted){
        QSqlRecord rec = vCrearContacto.getRecord();
        if(tm->insertRecord(-1,rec)){
            QMessageBox msjAgrega;
            msjAgrega.setText("Contacto Agregado");
            msjAgrega.exec();
            tm->select();
        }
    }
}

void VentanaContactos::on_btnEliminarContacto_clicked()
{
    QMessageBox::StandardButton pregElimina;
    pregElimina = QMessageBox::question(this, "Confirmar Eliminacion",
                                        "¿Deseas eliminar el contacto seleccionado?",
                                        QMessageBox::Yes | QMessageBox::No);

    if(pregElimina == QMessageBox::Yes){
        tm->removeRow(ui->tablaContactos->currentIndex().row());
        QMessageBox msjEliminacion;
        msjEliminacion.setText("Contacto Eliminado");
        msjEliminacion.exec();
        tm->select();
    }
}

void VentanaContactos::on_btnModificarContacto_clicked()
{
    vContacto.exec();
    tm->select();
}

void VentanaContactos::on_btnActualiza_clicked()
{
    tm->select();
}

void VentanaContactos::on_btnBuscar_clicked()
{
    QString busqueda;
    //busqueda = ui->leBusqueda->text();
    qDebug() <<busqueda;

    tm->setFilter("name LIKE '%" + busqueda +"%'");
    /*
    QSqlDatabase mDatabase = QSqlDatabase::database("ConexionPrincipal");
    if(!mDatabase.isOpen()){
        qDebug() <<"Error en la conexion";
        return;
    }
    else {

        QSqlQuery query(mDatabase);
        //query.exec("SELECT * FROM CONTACTO WHERE nombre = 'Daniel' ");
        //query.finish();
        ui->tablaContactos->setModel(tm);
        tm->setFilter("name LIKE '%" + busqueda +"%'");
        tm->select();
    }
    */
}
