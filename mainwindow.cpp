#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QActionGroup>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ventanaAC = new QActionGroup(this);
    ventanaAC->addAction(ui->actionPedidos);
    ventanaAC->addAction(ui->actionContactos);
    ventanaAC->addAction(ui->actionInventario);
    //ventanaAC->addAction(ui->actionPedidosRealizados);

    this->on_menuToolbar_actionTriggered(ui->actionInventario);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_menuToolbar_actionTriggered(QAction *action)
{
    if(action == ui->actionInventario){
        ui->stackedWidget->setCurrentIndex(0);
        ui->actionInventario->setChecked(true);
    }

    if(action == ui->actionContactos){
        ui->stackedWidget->setCurrentIndex(1);
        ui->actionContactos->setChecked(true);
    }

    if(action == ui->actionPedidos){
        ui->stackedWidget->setCurrentIndex(2);
        ui->actionPedidos->setChecked(true);
    }
/*
    if(action == ui->actionPedidosRealizados){
        ui->stackedWidget->setCurrentIndex(3);
        ui->actionPedidos->setChecked(true);
    }*/
}
