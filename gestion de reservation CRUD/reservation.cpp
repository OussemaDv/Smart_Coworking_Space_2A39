#include "reservation.h"
#include <QSqlQuery>
#include <QSqlError>
#include <iostream>
#include <qobject.h>
Reservation::Reservation()
{   CIN=0;
    resID=0;
    poste=0;

}
Reservation::Reservation(int CIN,int resID,int poste,QDate datte){
    this->CIN=CIN;
    this->resID=resID;
    this->poste=poste;
    this->datte=datte;
}
bool Reservation::ajouter()
{
    QSqlQuery query;
    QString res =QString::number(resID);
    QString res1 =QString::number(CIN);
    QString res2 =QString::number(poste);
    query.prepare("insert into reservation(CIN,datte,resID,poste)" "values (:CIN,:datte,:resID,:poste)");
    query.bindValue(":resID",res);
     query.bindValue(":CIN",res1);
      query.bindValue(":datte",datte);
       query.bindValue(":poste",res2);
    return query.exec();
}
QSqlQueryModel * Reservation ::afficher(){
    QSqlQueryModel * model =new QSqlQueryModel();
    model->setQuery("SELECT* FROM reservation");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID reservation"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("CIN du client"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("poste n°"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("datte"));
    return model;}
bool Reservation::supprimer(int resID){
    QSqlQuery query;


    query.prepare("delete from reservation where resID=:resID");
    query.bindValue(0,resID);

    return query.exec();
}

bool Reservation::modifier(int resID){

    QSqlQuery query;
    QString res =QString::number(resID);
    QString res1 =QString::number(CIN);
    QString res2 =QString::number(poste);
    query.prepare("update reservation set datte=:datte,poste=:poste,CIN=:CIN where resID=:resID");
    query.bindValue(":resID",res);
    query.bindValue(":CIN",res1);
    query.bindValue(":poste",res2);
    query.bindValue(":datte",datte);
    return query.exec();
}
