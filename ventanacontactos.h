#ifndef VENTANACONTACTOS_H
#define VENTANACONTACTOS_H

#include <QWidget>
#include <QSqlTableModel>
#include <actualizacontacto.h>
#include <crearcontato.h>
namespace Ui {
class VentanaContactos;
}

class VentanaContactos : public QWidget
{
    Q_OBJECT

public:
    explicit VentanaContactos(QWidget *parent = nullptr);
    ~VentanaContactos();

private slots:
    void on_btnAgregarContacto_clicked();

    void on_btnEliminarContacto_clicked();

    void on_btnModificarContacto_clicked();

    void on_btnActualiza_clicked();

    void on_btnBuscar_clicked();

private:
    Ui::VentanaContactos *ui;
    QSqlTableModel *tm;
    actualizaContacto vContacto;
    crearContato vCrearContacto;
};

#endif // VENTANACONTACTOS_H
