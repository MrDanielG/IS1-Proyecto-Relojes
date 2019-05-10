#ifndef ACTUALIZACONTACTO_H
#define ACTUALIZACONTACTO_H

#include <QDialog>

namespace Ui {
class actualizaContacto;
}

class actualizaContacto : public QDialog
{
    Q_OBJECT

public:
    explicit actualizaContacto(QWidget *parent = nullptr);
    ~actualizaContacto();

private slots:
    void on_pushButton_clicked();

    void on_btnActualizar_clicked();

private:
    Ui::actualizaContacto *ui;
};

#endif // ACTUALIZACONTACTO_H
