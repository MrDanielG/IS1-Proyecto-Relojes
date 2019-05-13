#ifndef VENTPRODUCTOSREALIZADOS_H
#define VENTPRODUCTOSREALIZADOS_H

#include <QDialog>
#include <QSqlTableModel>
#include <QDate>
#include <ventproductosrealizados.h>

class QSqlTableModel;
namespace Ui {
class ventproductosRealizados;
}

class ventproductosRealizados : public QDialog
{
    Q_OBJECT

public:
    explicit ventproductosRealizados(QWidget *parent = nullptr);
    ~ventproductosRealizados();

private slots:
    void on_btnRefresh_clicked();

private:
    Ui::ventproductosRealizados *ui;
    QSqlTableModel *infoPedidosTM;
    void configurar();
};

#endif // VENTPRODUCTOSREALIZADOS_H
