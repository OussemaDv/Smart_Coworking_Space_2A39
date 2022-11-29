#ifndef AUTHENTIFICATIONN_H
#define AUTHENTIFICATIONN_H
#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include "connection.h"
#include "employe.h"
#include <QMainWindow>
#include <QSql>
#include <arduino.h>


namespace Ui {
class authentificationn;
}

class authentificationn : public QMainWindow
{
    Q_OBJECT

public:
    explicit authentificationn(QWidget *parent = nullptr);
    ~authentificationn();

private slots:
    void on_pushButton_clicked();
void rfid();
void on_pushButton_2_clicked();

private:
    Ui::authentificationn *ui;
    arduino ar;
    QByteArray data;

};

#endif // AUTHENTIFICATIONN_H
