#ifndef CREARPRODUCTO_H
#define CREARPRODUCTO_H

#include <QDialog>
#include <QSqlRecord>
namespace Ui {
class crearProducto;
}

class crearProducto : public QDialog
{
    Q_OBJECT

public:
    explicit crearProducto(QWidget *parent = nullptr);
    ~crearProducto();
    QSqlRecord getRecord() const;

private slots:
    void on_pushButton_clicked();

    void on_btnCrearProd_clicked();

private:
    Ui::crearProducto *ui;
};

#endif // CREARPRODUCTO_H
