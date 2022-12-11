#include "reservation.h"
#include <QSqlQuery>
#include <QSqlError>
#include <iostream>
#include <qobject.h>
#include<QDate>
#include <QDebug>
Reservation::Reservation()
{   CIN=0;
    resID=0;
    poste=0;

}
Reservation::Reservation(int CIN, int resID, int poste, QDate datte){

    this->CIN=CIN;
    this->resID=resID;
    this->poste=poste;
    this->datte=datte;
}
QString Reservation::returnposte(QString id){
    QSqlQuery q("select * from reservation where resID='"+id+"'");
    while(q.next())
        return q.value(2).toString();
    return "";
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
QSqlQueryModel * Reservation::recherche_CIN(QString val)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from reservation where CIN LIKE '"+val+"'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID reservation"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("CIN du client"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("poste n°"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("datte"));

    return model;
}
QSqlQueryModel * Reservation::recherche_resID(QString val)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from reservation where resID LIKE '"+val+"'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID reservation"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("CIN du client"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("poste n°"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("datte"));

    return model;
}
QSqlQueryModel * Reservation::tri_resID()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from reservation  order by resID ASC" );
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID reservation"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("CIN du client"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("poste n°"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("datte"));

    return model;
}
QSqlQueryModel * Reservation::tri_resID_d()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from reservation  order by resID DESC" );
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID reservation"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("CIN du client"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("poste n°"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("datte"));

    return model;
}
QSqlQueryModel * Reservation::tri_CIN()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from reservation  order by CIN ASC" );
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID reservation"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("CIN du client"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("poste n°"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("datte"));

    return model;
}
QSqlQueryModel * Reservation::tri_CIN_d()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from reservation  order by CIN DESC" );
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID reservation"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("CIN du client"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("poste n°"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("datte"));

    return model;
}
QSqlQueryModel * Reservation::tri_date_c()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from reservation  order by datte ASC" );
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID reservation"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("CIN du client"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("poste n°"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("datte"));

    return model;
}
QSqlQueryModel * Reservation::tri_date_d()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from reservation  order by datte DESC" );
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID reservation"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("CIN du client"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("poste n°"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("datte"));

    return model;
}
QSqlQueryModel * Reservation::recherche_datte(QDate val)
{QString vall=val.toString("dd-MMM-yy").toUpper();
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from reservation where datte LIKE '"+vall+"'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID reservation"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("CIN du client"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("poste n°"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("datte"));

    return model;
}

