#include "espaces.h"

Espace::Espace(){}
Espace::Espace(int id,int nb,QString bloc,QDate date)
{
    this->id = id;
    this->nb = nb;
    this->bloc = bloc;
    this->date = date;
}
void Espace::Setid(int id){this->id = id;}
int Espace::Getid(){return id;}
void Espace::Setnb(int nb){this->nb = nb;}
int Espace::Getnb(){return nb;}
void Espace::Setbloc(QString bloc){this->bloc = bloc;}
QString Espace::Getbloc(){return bloc;}


QSqlQueryModel * Espace::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();


    model->setQuery("select * from espaces");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NB"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Bloc"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("DATE"));



    return model;
}

QSqlQueryModel * Espace::afficher2()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select id from espaces");
    return model;
}
QSqlTableModel * Espace::afficher3()
{
    QSqlTableModel * model=new QSqlTableModel();
    model->setTable("espaces");
    model->select();
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NB"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("BLOC"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("DATE"));
    return model;
}

bool Espace::modifier()
{
    QSqlQuery query;
    QString id_string=QString::number(id);
    QString nb_string=QString::number(nb);

    query.prepare("Update espaces set NB= :nb, BLOC= :bloc, DATE_CR= :date where ID= :id");
    query.bindValue(":id",id_string);
    query.bindValue(":nb",nb_string);
    query.bindValue(":bloc",bloc);
    query.bindValue(":date",date);

    return query.exec();
}

bool Espace::ajouter()
{
    QSqlQuery query;

    QString id_string = QString::number(id);
    QString nb_string = QString::number(nb);

    query.prepare("INSERT INTO espaces (id,nb,bloc, date_cr)" "VALUES (:id, :nb, :bloc, :date)");

    query.bindValue(":id",id_string);
    query.bindValue(":nb",nb_string);
    query.bindValue(":bloc",bloc);
    query.bindValue(":date",date);

    return query.exec();
}

bool Espace::supprimer(int id)
{
    QSqlQuery query;
    QString id_string=QString::number(id);

    query.prepare("Delete from espaces where ID= :id");
    query.bindValue(":id",id_string);

    return query.exec();
}
