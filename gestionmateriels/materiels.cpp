#include "materiels.h"
#include <QString>
#include <QApplication>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QObject>
#include <QTableView>

Materiels::Materiels()
{
  id_materiel="";
  type="";
  nombre=0;
  date_arriv={0,0,0};
}
Materiels ::Materiels(QString id_materiel, QString type, int nombre, QDate date_arriv)
{
    this->id_materiel=id_materiel;
    this->type=type;
    this->nombre=nombre;
    this->date_arriv=date_arriv;
}
QString Materiels ::getid_materiel()
{
    return id_materiel;
}
QString Materiels ::gettype()
{
    return type;
}
int Materiels ::getnombre()
{
    return nombre;
}
QDate Materiels ::getdate_arriv()
{
    return date_arriv;
}
void Materiels ::setid_materiel(QString id_materiel)
{
    this->id_materiel=id_materiel;
}
void Materiels ::settype(QString type)
{
    this->type=type;
}
void Materiels ::setnombre(int nombre)
{
    this->nombre=nombre;
}
void Materiels ::setdate_arriv(QDate date_arriv)
{
    this->date_arriv=date_arriv;
}
bool Materiels::ajouter()
{
    QSqlQuery query;
    QString res= QString ::number(nombre);
    query.prepare("INSERT INTO GESTION_MATERIELS(ID_MATERIEL, TYPE, NOMBRE, DATE_ARRIV)"" VALUES (:ID_MATERIEL, :TYPE, :NOMBRE, :DATE_ARRIV)");
    query.bindValue(":ID_MATERIEL",id_materiel);
    query.bindValue(":TYPE",type);
    query.bindValue(":NOMBRE",res);
    query.bindValue(":DATE_ARRIV",date_arriv);
    return query.exec();
}
bool Materiels ::supprimer(QString id_materiel)
{
    QSqlQuery query;
    query.prepare("DELETE FROM GESTION_MATERIELS WHERE ID_MATERIEL=:id_materiel");
    query.bindValue(":id_materiel",id_materiel);
    return query.exec();
}

QSqlQueryModel * Materiels:: afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel;
    model->setQuery("SELECT * FROM GESTION_MATERIELS");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_MATERIELS"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("NOMBRE"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("DATE_ARRIV"));
    return model;
}
bool Materiels::update(QString id_materiel)
{
    QSqlQuery query;
    QString res=QString::number(nombre);
    query.prepare("UPDATE GESTION_MATERIELS SET ID_MATERIEL= :id_materiel,TYPE= :type, NOMBRE= :nombre,DATE_ARRIV = :date_arriv WHERE ID_MATERIEL = :id_materiel");
    query.bindValue(":id_materiel",id_materiel);
    query.bindValue(":type",type);
     query.bindValue(":nombre",nombre);
      query.bindValue(":date_arriv",date_arriv);
    return query.exec();
}

