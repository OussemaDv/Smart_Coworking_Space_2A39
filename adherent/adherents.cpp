#include "adherents.h"

adherents::adherents(int cin,QString nom,QString prenom,QString date,QString email,QString genre)
{
    this->cin=cin;
    this->nom=nom;
    this->prenom=prenom;
    this->date=date;
    this->email=email;
    this->genre=genre;
}

bool adherents::ajouter()
{
    QSqlQuery query;
    QString res= QString::number(cin);

    //requette sql
    query.prepare("insert into adherent(cin,nom,prenom,date_naissance,email,genre)" "values(:cin,:nom,:prenom,:date,:email,:genre)");

    //saisir de donnee
    query.bindValue(":cin",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":date",date);
    query.bindValue(":email",email);
    query.bindValue(":genre",genre);

    //execution de la requette
    return query.exec();
}

bool adherents::supprimer(int cin)
{
    QSqlQuery query;
    QString res=QString::number(cin);

    //requette sql
    query.prepare("Delete from adherent where cin=:cin");

    //saisir de donnee
    query.bindValue(":cin",cin);

    //execution de requette
    return query.exec();
}

bool adherents::modifier(int cin)
{
    QSqlQuery query;
    QString res= QString::number(cin);

    //requette sql
    query.prepare("UPDATE adherent set nom=:nom,prenom=:prenom,date_naissance=:date,email=:email where cin=:cin");

    //saisir de donnee
    query.bindValue(":cin",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":date",date);
    query.bindValue(":email",email);

    //execution de la requette
    return query.exec();
}

QSqlQueryModel * adherents::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from adherent");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Cin"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Date de naissance"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Email"));

    return model;
}

QSqlQueryModel * adherents::tri_cin_croissant()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from adherent  order by cin ASC" );

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Cin"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Date de naissance"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Email"));

    return model;
}

QSqlQueryModel * adherents::tri_cin_decroissant()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from adherent  order by cin DESC" );

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Cin"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Date de naissance"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Email"));

    return model;
}

QSqlQueryModel * adherents::tri_nom_croissant()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from adherent  order by nom ASC" );

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Cin"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Date de naissance"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Email"));

    return model;
}

QSqlQueryModel * adherents::tri_nom_decroissant()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from adherent  order by nom DESC" );

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Cin"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Date de naissance"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Email"));

    return model;
}

QSqlQueryModel * adherents::tri_prenom_croissant()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from adherent order by prenom ASC" );

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Cin"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Date de naissance"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Email"));

    return model;
}

QSqlQueryModel * adherents::tri_prenom_decroissant()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from adherent order by prenom DESC" );

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Cin"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Date de naissance"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Email"));

    return model;
}

QSqlQueryModel * adherents::get_id()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select cin from adherent");
    return model;
}

QSqlQueryModel * adherents::recherche_cin(QString cin)
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from adherent where cin LIKE '"+cin+"'");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Cin"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Date de naissance"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Email"));

    return model;
}
