#include "ventanapedidos.h"
#include "ui_ventanapedidos.h"
#include <ventproductosrealizados.h>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlRecord>
#include <QMessageBox>
#include <QSqlQuery>
#include <QFile>
VentanaPedidos::VentanaPedidos(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VentanaPedidos)
{
    ui->setupUi(this);

    QSqlDatabase mDatabase = QSqlDatabase::database("ConexionPrincipal");
    if(!mDatabase.isOpen()){
        qDebug() <<"Error en la conexion";
        return;
    }
    else {
        QSqlQuery queryc(mDatabase);
        queryc.exec("SELECT id_contacto FROM contacto");

        //Esto es para que muestre el id y el nombre, pero luego no podemos extraer el id para futuras operaciones, puesto que tambien jala el nombre

        //queryc.exec("SELECT concat(id_contacto,'  -  ', nombre)  FROM contacto");
        while(queryc.next()){
            ui->boxContacto->addItem(queryc.value(0).toString());
        }
        queryc.finish();

        QSqlQuery queryp(mDatabase);
        queryp.exec("SELECT id_producto FROM producto");
        while (queryp.next()) {
            ui->comboBox->addItem(queryp.value(0).toString());
            ui->comboBox_2->addItem(queryp.value(0).toString());
            ui->comboBox_3->addItem(queryp.value(0).toString());
            ui->comboBox_4->addItem(queryp.value(0).toString());
            ui->comboBox_5->addItem(queryp.value(0).toString());
        }
        queryp.finish();

    }

    ui->label_3->hide();
    ui->label_4->hide();
    ui->label_5->hide();
    ui->label_6->hide();
    ui->label_8->hide();
    ui->label_9->hide();
    ui->label_10->hide();
    ui->label_11->hide();

    ui->comboBox_2->hide();
    ui->comboBox_3->hide();
    ui->comboBox_4->hide();
    ui->comboBox_5->hide();

    ui->spinBox_2->hide();
    ui->spinBox_3->hide();
    ui->spinBox_4->hide();
    ui->spinBox_5->hide();

    ui->pushButton_3->hide();
    ui->pushButton_4->hide();
    ui->pushButton_5->hide();
}

VentanaPedidos::~VentanaPedidos()
{
    delete ui;
}

void VentanaPedidos::on_pushButton_2_clicked()
{
    ui->label_3->show();
    ui->comboBox_2->show();
    ui->label_8->show();
    ui->spinBox_2->show();
    ui->pushButton_3->show();
    ui->pushButton_2->hide();
}

void VentanaPedidos::on_pushButton_3_clicked()
{
    ui->label_4->show();
    ui->comboBox_3->show();
    ui->label_9->show();
    ui->spinBox_3->show();
    ui->pushButton_4->show();
    ui->pushButton_3->hide();
}

void VentanaPedidos::on_pushButton_4_clicked()
{
    ui->label_5->show();
    ui->comboBox_4->show();
    ui->label_10->show();
    ui->spinBox_4->show();
    ui->pushButton_5->show();
    ui->pushButton_4->hide();
}

void VentanaPedidos::on_pushButton_5_clicked()
{
    ui->label_6->show();
    ui->comboBox_5->show();
    ui->label_11->show();
    ui->spinBox_5->show();
}

void VentanaPedidos::on_btnGuardarPedido_clicked()
{
    QSqlDatabase mDatabase = QSqlDatabase::database("ConexionPrincipal");
    if(!mDatabase.isOpen()){
        qDebug() <<"Error en la conexion";
        return;
    }
    else {

        QString idContacto = ui->boxContacto->currentText();
        QString fechaEntrega = QDate::currentDate().toString("yyyy/MM/dd");
        QString tipoPago = ui->comboBox_6->currentText();

        QSqlQuery query(mDatabase);
        query.exec("INSERT INTO pedido(contacto_id_contacto, fecha_entrega, tipo_pago) values('"+idContacto+"', '"+fechaEntrega+"', '"+tipoPago+"' )");

        if(ui->spinBox->value() > 0){
            QString idPedido = query.lastInsertId().toString();
            QString idProducto = ui->comboBox->currentText();
            QString cantProducto = ui->spinBox->text();
            QSqlQuery qInsert(mDatabase);
            qInsert.exec("INSERT INTO linea_pedido(id_pedido, id_producto, cantidad) values('"+idPedido+"', '"+idProducto+"', '"+cantProducto+"')");
        }

        if(ui->spinBox_2->value() > 0){
            QString idPedido = query.lastInsertId().toString();
            QString idProducto = ui->comboBox_2->currentText();
            QString cantProducto = ui->spinBox_2->text();
            QSqlQuery qInsert(mDatabase);
            qInsert.exec("INSERT INTO linea_pedido(id_pedido, id_producto, cantidad) values('"+idPedido+"', '"+idProducto+"', '"+cantProducto+"')");
        }

        if(ui->spinBox_3->value() > 0){
            QString idPedido = query.lastInsertId().toString();
            QString idProducto = ui->comboBox_3->currentText();
            QString cantProducto = ui->spinBox_3->text();
            QSqlQuery qInsert(mDatabase);
            qInsert.exec("INSERT INTO linea_pedido(id_pedido, id_producto, cantidad) values('"+idPedido+"', '"+idProducto+"', '"+cantProducto+"')");
        }

        if(ui->spinBox_4->value() > 0){
            QString idPedido = query.lastInsertId().toString();
            QString idProducto = ui->comboBox_4->currentText();
            QString cantProducto = ui->spinBox_4->text();
            QSqlQuery qInsert(mDatabase);
            qInsert.exec("INSERT INTO linea_pedido(id_pedido, id_producto, cantidad) values('"+idPedido+"', '"+idProducto+"', '"+cantProducto+"')");
        }

        if(ui->spinBox_5->value() > 0){
            QString idPedido = query.lastInsertId().toString();
            QString idProducto = ui->comboBox_5->currentText();
            QString cantProducto = ui->spinBox_5->text();
            QSqlQuery qInsert(mDatabase);
            qInsert.exec("INSERT INTO linea_pedido(id_pedido, id_producto, cantidad) values('"+idPedido+"', '"+idProducto+"', '"+cantProducto+"')");
        }



        QMessageBox msjGuardado;
        msjGuardado.setText("Pedido Guardado");
        msjGuardado.exec();

        //Guardando Quertys en variables
        QString idContactoFile,
                nombreContactoFile,
                apellidoContactoFile,
                idPedidoFile,
                fechaEntregaFile,
                tipoPagoFile,
                cantidadFile,
                modeloFile,
                marcaFile,
                precioFile,
                totalFile;

        QSqlQuery queryFile(mDatabase);
        queryFile.exec("SELECT id_contacto FROM infoPedido WHERE id_contacto="+idContacto+"");
        while (queryFile.next()) {
            idContactoFile = queryFile.value(0).toString();
        }
        qDebug()<<idContactoFile;

        //Nombre Contacto
        queryFile.exec("SELECT nombre FROM infoPedido WHERE id_contacto="+idContacto+"");
        while (queryFile.next()) {
            nombreContactoFile = queryFile.value(0).toString();
        }
        qDebug()<<nombreContactoFile;

        //Apellido Contacto
        queryFile.exec("SELECT paterno FROM infoPedido WHERE id_contacto="+idContacto+"");
        while (queryFile.next()) {
            apellidoContactoFile = queryFile.value(0).toString();
        }
        qDebug()<<apellidoContactoFile;

        //ID Pedido
        queryFile.exec("SELECT id_pedido FROM infoPedido WHERE id_contacto="+idContacto+"");
        while (queryFile.next()) {
            idPedidoFile = queryFile.value(0).toString();
        }
        qDebug()<<idPedidoFile;

        //Fecha
        queryFile.exec("SELECT fecha_entrega FROM infoPedido WHERE id_contacto="+idContacto+"");
        while (queryFile.next()) {
            fechaEntregaFile = queryFile.value(0).toString();
        }
        qDebug()<<fechaEntregaFile;

        //Tipo Pago
        queryFile.exec("SELECT tipo_pago FROM infoPedido WHERE id_contacto="+idContacto+"");
        while (queryFile.next()) {
            tipoPagoFile = queryFile.value(0).toString();
        }
        qDebug()<<tipoPagoFile;

        //Cantidad
        queryFile.exec("SELECT cantidad FROM infoPedido WHERE id_contacto="+idContacto+"");
        while (queryFile.next()) {
            cantidadFile = queryFile.value(0).toString();
        }
        qDebug()<<cantidadFile;

        //Modelo
        queryFile.exec("SELECT modelo FROM infoPedido WHERE id_contacto="+idContacto+"");
        while (queryFile.next()) {
            modeloFile = queryFile.value(0).toString();
        }
        qDebug()<<modeloFile;

        //Marca
        queryFile.exec("SELECT marca FROM infoPedido WHERE id_contacto="+idContacto+"");
        while (queryFile.next()) {
            marcaFile = queryFile.value(0).toString();
        }
        qDebug()<<marcaFile;

        //Precio
        queryFile.exec("SELECT precio FROM infoPedido WHERE id_contacto="+idContacto+"");
        while (queryFile.next()) {
            precioFile = queryFile.value(0).toString();
        }
        qDebug()<<precioFile;

        //Total
        queryFile.exec("SELECT Total FROM infoPedido WHERE id_contacto="+idContacto+"");
        while (queryFile.next()) {
            totalFile = queryFile.value(0).toString();
        }
        qDebug()<<totalFile;

        //Haciendo Archivo de Texto de Pedidos
        QFile file("C:/xampp/htdocs/GitHub/IS1-Proyecto-Relojes/reporte.txt");
        if(!file.open(QFile::WriteOnly | QFile::Text)){
            QMessageBox::warning(this, "Titulo", "Archivo no abierto");
        }

        QTextStream out(&file);
        out<<"--------------------------------"<<endl;
        out<<"ID Reporte: "<<idPedidoFile<<endl;
        out<<"--------------------------------"<<endl;
        out<<"Fecha de Pedido: "<<fechaEntregaFile<<endl;
        out<<"Tipo de Pago: "<<tipoPagoFile<<endl;
        out<<"ID de Contacto: "<<idContactoFile<<endl;
        out<<"Nombre Contacto: "<<nombreContactoFile<<endl;
        out<<"Apellido: "<<apellidoContactoFile<<endl;
        out<<"Cantidad de Productos: "<<cantidadFile<<endl;
        out<<"Marca Producto: "<<marcaFile<<endl;
        out<<"Modelo Producto: "<<modeloFile<<endl;
        out<<"Precio Producto: "<<precioFile<<endl;
        out<<"--------------------------------"<<endl;
        out<<"TOTAL: "<<totalFile<<endl;
        out<<"--------------------------------"<<endl;

        file.flush();
        file.close();
    }
}

void VentanaPedidos::on_btnMostrarPedidos_clicked()
{
    vProdRealizados.show();
}
