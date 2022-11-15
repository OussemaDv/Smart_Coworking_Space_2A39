#include "authentificationn.h"
#include "ui_authentificationn.h"
#include "employe.cpp"
#include "employe.h"
#include <mainwindow.h>
#include <mainwindow.cpp>
#include <QMainWindow>
#include <QSqlDatabase>
#include <QString>
#include <QtDebug>
#include <QMessageBox>
#include <QIntValidator>
#include <QSqlQueryModel>




authentificationn::authentificationn(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::authentificationn)
{
    ui->setupUi(this);
}

authentificationn::~authentificationn()
{
    delete ui;
}

void authentificationn::on_pushButton_clicked()
{
authentificationn u;
MainWindow *CRUD;
employe e;
CRUD=new MainWindow();
QString ID=ui->le_login->text();
QString PWD=ui->le_pwd->text();
if (e.rechercher_ID(ID,PWD)->rowCount()!=0)
{
    CRUD->show();
    this->close();
}
else{
    QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                                      QObject::tr("ACCES IMPOSSIBLE"), QMessageBox::Cancel);
}}
