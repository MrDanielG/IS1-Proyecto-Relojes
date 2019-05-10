#ifndef CREARCONTATO_H
#define CREARCONTATO_H

#include <QDialog>
#include <QSqlRecord>
namespace Ui {
class crearContato;
}

class crearContato : public QDialog
{
    Q_OBJECT

public:
    explicit crearContato(QWidget *parent = nullptr);
    ~crearContato();
    QSqlRecord getRecord() const;

private slots:
    void on_pushButton_clicked();

private:
    Ui::crearContato *ui;
};

#endif // CREARCONTATO_H
