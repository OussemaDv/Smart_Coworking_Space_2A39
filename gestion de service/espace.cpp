#include "espace.h"
espace::espace()
{

}

espace::espace(int id,int nb,QString bloc,QDate date)
{
    this->id=id;
    this->nb=nb;
    this->bloc=bloc;
    this->date=date;
}

bool espace::ajouter()
{
    QSqlQuery query;


    QString id_string = QString::number(id);
    QString nb_string = QString::number(nb);
    bloc = bloc.toUpper();

    for(int i=0;i<nb;i++)
    {
        places += "o";
    }

    query.prepare("INSERT INTO espaces (id,nb,bloc,date_cr,places)" "VALUES (:id, :nb, :bloc, :date, :places)");

    query.bindValue(":id",id_string);
    query.bindValue(":nb",nb_string);
    query.bindValue(":bloc",bloc);
    query.bindValue(":date",date);
    query.bindValue(":places",places);


    return query.exec();
}

bool espace::modifier()
{
    QSqlQuery query;
    QString id_string=QString::number(id);
    QString nb_string=QString::number(nb);
    bloc = bloc.toUpper();


    query.prepare("Update espaces set NB= :nb, BLOC= :bloc, DATE_CR= :date where ID= :id");
    query.bindValue(":id",id_string);
    query.bindValue(":nb",nb_string);
    query.bindValue(":bloc",bloc);
    query.bindValue(":date",date);

    return query.exec();
}

bool espace::supprimer(int id)
{
    QSqlQuery query;
    QString id_string=QString::number(id);

    query.prepare("Delete from espaces where ID= :id");
    query.bindValue(":id",id_string);

    return query.exec();
}

QSqlQueryModel * espace::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();


    model->setQuery("select * from espaces");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NB"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Bloc"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Date"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("places"));



    return model;
}

QSqlQueryModel * espace::afficher2()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select id from espaces");
    return model;
}

void espace::changeState(int p,QString id_string)
{

}


QSqlTableModel * espace::afficher3()
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
