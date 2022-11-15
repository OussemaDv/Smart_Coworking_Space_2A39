#ifndef AUTHENTIFICATIONN_H
#define AUTHENTIFICATIONN_H
#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include "connection.h"
#include "employe.h"
#include <QMainWindow>
#include <QSql>

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

private:
    Ui::authentificationn *ui;
};

#endif // AUTHENTIFICATIONN_H
