#ifndef VENTANAINVENTARIO_H
#define VENTANAINVENTARIO_H

#include <QWidget>
#include <QSqlTableModel>
#include <crearproducto.h>
#include <actualizarproducto.h>

namespace Ui {
class VentanaInventario;
}

class VentanaInventario : public QWidget
{
    Q_OBJECT

public:
    explicit VentanaInventario(QWidget *parent = nullptr);
    ~VentanaInventario();

private slots:
    void on_btnAgregarProducto_clicked();

    void on_btnEliminarProducto_clicked();

    void on_btnModificarProducto_clicked();

private:
    Ui::VentanaInventario *ui;
    QSqlTableModel *tm;
    crearProducto vCrearProducto;
    actualizarProducto vActualizarProducto;
};

#endif // VENTANAINVENTARIO_H
