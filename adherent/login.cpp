#include "login.h"
#include "ui_login.h"

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
    QString select="select * from user where username='"+ui->user->text()+"'and password='"+ui->pass->text()+"'";

    QSqlQuery req;

    if(req.exec(select))
    {
        int count=0;
        while(req.next())
        {
            count++;
        }
        if(count==1){
            this->hide();
            login log;
            log.setModal(true);
            log.exec();
        }
        if(count>1){
            QMessageBox::information(nullptr,QObject::tr("Erreur"),QObject::tr("Username or password is incorrect!"),QMessageBox::Close);
        }
        if(count<1){
            QMessageBox::information(nullptr,QObject::tr("Erreur"),QObject::tr("Username or password is incorrect!"),QMessageBox::Close);
        }
    }
}
