#ifndef ACTUALIZARPRODUCTO_H
#define ACTUALIZARPRODUCTO_H

#include <QDialog>

namespace Ui {
class actualizarProducto;
}

class actualizarProducto : public QDialog
{
    Q_OBJECT

public:
    explicit actualizarProducto(QWidget *parent = nullptr);
    ~actualizarProducto();

private slots:
    void on_btnActualizar_clicked();

private:
    Ui::actualizarProducto *ui;
};

#endif // ACTUALIZARPRODUCTO_H
