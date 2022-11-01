#include "espace.h"
#include "connection.h"
Espace::Espace()
{

}
Espace::Espace(int id,int nb,QString bloc)
{
    this->id = id;
    this->nb = nb;
    this->bloc = bloc;
}

void Espace::Setid(int id)
{
    this->id = id;
}
int Espace::Getid()
{
    return id;
}
void Espace::Setnb(int nb)
{
    this->nb = nb;
}
int Espace::Getnb()
{
    return nb;
}
void Espace::Setbloc(QString bloc)
{
    this->bloc = bloc;
}
QString Espace::Getbloc()
{
    return bloc;
}

bool Espace::ajouter()
{
    QSqlQuery query;

    QString id_string = QString::number(id);
    QString nb_string = QString::number(nb);

    query.prepare("INSERT INTO espaces (id,nb,bloc)" "VALUES (:id, :nb, :bloc)");

    query.bindValue(":id",id_string);
    query.bindValue(":nb",nb_string);
    query.bindValue(":bloc",bloc);

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

QSqlQueryModel * Espace::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from espaces");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NB"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Bloc"));

    return model;
}

bool Espace::modifier()
{
    QSqlQuery query;
    QString id_string=QString::number(id);
    QString nb_string=QString::number(nb);

    query.prepare("Update espaces set NB= :nb where ID= :id");
    query.bindValue(":id",id_string);
    query.bindValue(":nb",nb_string);

    return query.exec();
}
