#include "ventproductosrealizados.h"
#include "ui_ventproductosrealizados.h"
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>
#include <QSqlRecord>
#include <QSqlField>
ventproductosRealizados::ventproductosRealizados(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ventproductosRealizados)
{
    ui->setupUi(this);

    //configurar();
    QSqlDatabase mInfoPedido = QSqlDatabase::database("ConexionPrincipal");
    infoPedidosTM = new QSqlTableModel(this, mInfoPedido);

    infoPedidosTM->setTable("infoPedido");
    infoPedidosTM->setEditStrategy(QSqlTableModel::OnManualSubmit);

    infoPedidosTM->select();
    ui->tablaInfoPedido->setModel(infoPedidosTM);
}

ventproductosRealizados::~ventproductosRealizados()
{
    delete ui;
}

void ventproductosRealizados::configurar()
{
    QSqlDatabase mInfoPedido = QSqlDatabase::database();
    infoPedidosTM = new QSqlTableModel(this, mInfoPedido);
    infoPedidosTM->setTable("contacto");
    infoPedidosTM->select();
    ui->tablaInfoPedido->setModel(infoPedidosTM);
    infoPedidosTM->setEditStrategy(QSqlTableModel::OnManualSubmit);
}

void ventproductosRealizados::on_btnRefresh_clicked(){
    infoPedidosTM->select();
}
