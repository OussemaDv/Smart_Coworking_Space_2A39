#include "Detecteur.h"
#include "ui_Detecteur.h"
#include <QMessageBox>
#include <QtDebug>
#include <QSqlQuery>

#include "arduino.h"
Detecteur::Detecteur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Detecteur)
{
    ui->setupUi(this);
    int ret=A.connect_arduino();
      switch (ret) {
      case(0):qDebug()<<"arduino is available and connected to :"<<A.getarduino_port_name();
          break;
      case(1):qDebug()<<"arduino is available but not connected to :"<<A.getarduino_port_name();
          break;
       case(-1):qDebug()<<"arduino is not available :"<<A.getarduino_port_name();
      }
      //QObject:: connect (A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));
       QObject:: connect (A.getserial(),SIGNAL(readyRead()),this,SLOT(ChercherFromArduino()));

}

Detecteur::~Detecteur()
{
    delete ui;
}


Detecteur::Detecteur(int id, int num){
    this->id=id;
    this->detecteur=num;


}

int Detecteur::getId(){
    return id;
}
int Detecteur::getdetecteur(){
    return detecteur;
}
void Detecteur::setDetecteur(int detecteur){
    this->detecteur=detecteur;
}
void Detecteur::setId(int id){
    this->id=id;
}

void Detecteur::on_pushButton_clicked()
{
 QSqlQuery query;
     int id=ui->numsalle->text().toInt();

     int detecteur=ui->numdetecteur->text().toInt();


      if(detecteur<2){
          query.prepare("INSERT INTO ESPACE (ID_SALLE,NUMDET)" "VALUES(:id,:det)");
          query.bindValue(":id",id);
           query.bindValue(":det",detecteur);
           if(query.exec()){
               //refresh

               /* ui->numsalle->clear();
                ui->numdetecteur->clear();*/
               QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("ajout effectue\n""click cancel to exit"),QMessageBox::Cancel);
           }else{
               QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("ajout non effectue\n""click cancel to exit"),QMessageBox::Cancel);
           }
      }else{
           QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("detecteur non valid\n"" choisir entre 1 et 0"),QMessageBox::Cancel);
      }


    }


void Detecteur::on_supprimer_clicked()
{
    QSqlQuery query;

    int sup= ui->numsalle->text().toInt();
    query.prepare("DELETE FROM ESPACE WHERE ID_SALLE = :id");
    query.bindValue(":id",sup);


     if(query.exec()){

         ui->numsalle->clear();
         ui->numdetecteur->clear();
         QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("Suppression effectues\n""click cancel to exit"),QMessageBox::Cancel);
     }else{
         QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("suppression non effectue\n""click cancel to exit"),QMessageBox::Cancel);
     }

}
void Detecteur::ChercherFromArduino(){
    d=A.read_from_arduino();
qDebug() << d;
     QSqlQuery query;
    query.prepare("SELECT * FROM ESPACE WHERE NUMDET=:num");
    query.bindValue(":num",d);
    QString salle =query.value(0).toString();
     qDebug() << salle;
    QMessageBox::information(nullptr,QString("check salle %1" ).arg(salle)
             , "gaz detected");


}
