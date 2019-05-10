#ifndef VENTANAPEDIDOS_H
#define VENTANAPEDIDOS_H

#include <QWidget>
#include <QSqlTableModel>
#include <QDate>
#include <ventproductosrealizados.h>

namespace Ui {
class VentanaPedidos;
}

class VentanaPedidos : public QWidget
{
    Q_OBJECT

public:
    explicit VentanaPedidos(QWidget *parent = nullptr);
    ~VentanaPedidos();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_btnGuardarPedido_clicked();

    void on_btnMostrarPedidos_clicked();

private:
    Ui::VentanaPedidos *ui;
    ventproductosRealizados vProdRealizados;

};

#endif // VENTANAPEDIDOS_H
