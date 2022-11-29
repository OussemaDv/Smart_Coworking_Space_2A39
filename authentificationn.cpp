#include "authentificationn.h"
#include "ui_authentificationn.h"
#include "employe.cpp"
#include "employe.h"
#include "mainwindow.h"
#include <QMainWindow>
#include <QSqlDatabase>
#include <QString>
#include <QtDebug>
#include <QMessageBox>
#include <QIntValidator>
#include <QSqlQueryModel>
#include <arduino.h>




authentificationn::authentificationn(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::authentificationn)
{
    ui->setupUi(this);
    int ret=ar.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< ar.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<ar.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     QObject::connect(ar.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
     //le slot update_label suite à la reception du signal readyRead (reception des données).

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
void authentificationn::rfid()
{
    MainWindow *CRUD;
    CRUD=new MainWindow();
    employe e;
    data=ar.read_from_arduino();
    qDebug()<<data;
    if (e.rechercherRFID(data)->rowCount()!=0)
    {

        CRUD->show();
        this->close();

       QString nom;
       QSqlQuery query;
       query.prepare("SELECT * FROM EMPLOYE where RFID LIKE '"+data+"'");
       if(query.exec())
       {

               while (query.next())
       {

               nom=query.value(1).toString();
    }

    }
               QByteArray name(nom.toUtf8(),6);
               qDebug()<<name;
               ar.write_to_arduino(name);

}else{
       ar.write_to_arduino("introuvable");
       QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                                         QObject::tr("ACCES IMPOSSIBLE"), QMessageBox::Cancel);
    }
}


void authentificationn::on_pushButton_2_clicked()
{
    rfid();
}
