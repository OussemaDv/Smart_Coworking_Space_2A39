#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_loggin_clicked()
{
    login u;
    MainWindow *CRUD;
    employe e;
    CRUD=new MainWindow();
    QString ID=ui->user->text();
    QString PWD=ui->pass->text();
    if (e.rechercher_ID_emp(ID,PWD)->rowCount()!=0)
    {
        CRUD->show();
        this->close();
    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),QObject::tr("ACCES IMPOSSIBLE"), QMessageBox::Cancel);
    }
}
