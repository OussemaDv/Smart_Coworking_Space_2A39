#include "employe.h"
#include <QString>
#include <QSqlQuery>
#include <QtDebug>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QObject>
#include <connection.h>


employe::employe()
{
id=0; nom=""; prenom=""; poste=""; email=""; adresse=""; pwd="";
}
employe::employe(int id, QString nom,QString prenom, QString poste, QString email, QString adresse, QString pwd)
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->poste=poste;
    this->email=email;
    this->adresse=adresse;
    this->pwd=pwd;
}
int employe::getid(){return id;}
QString employe::getnom(){return nom;}
QString employe::getprenom(){return prenom;}
QString employe::getposte(){return poste;}
QString employe::getemail(){return email;}
QString employe::getadresse(){return adresse;}
QString employe::getpwd(){return pwd;}
void employe::setid(int id){this->id=id;}
void employe::setnom(QString nom){this->nom=nom;}
void employe::setprenom(QString prenom){this->prenom=prenom;}
void employe::setposte(QString poste){this->poste=poste;}
void employe::setemail(QString email){this->email=email;}
void employe::setadresse(QString adresse){this->adresse=adresse;}
void employe::setpwd(QString pwd){this->pwd=pwd;}


bool employe::ajouter()
{
    QString id_string=QString::number(id);
    QSqlQuery query;
         query.prepare("INSERT INTO employe (ID, NOM, PRENOM, POSTE,EMAIL_EMP,ADRESSE_EMP,PWD) " "VALUES (:ID, :NOM, :PRENOM, :POSTE, :EMAIL_EMP, :ADRESSE_EMP, :PWD)");
         query.bindValue(":ID", id_string);
         query.bindValue(":NOM", nom);
         query.bindValue(":PRENOM", prenom);
         query.bindValue(":POSTE", poste);
         query.bindValue(":EMAIL_EMP", email);
         query.bindValue(":ADRESSE_EMP", adresse);
         query.bindValue(":PWD", pwd);
         return  query.exec();

}


bool employe::supprimer(int id)
{

    QSqlQuery query;
        QString id_string=QString::number(id);
        query.prepare("delete FROM employe WHERE ID= :ID");
        query.bindValue(":ID",id_string);

        return query.exec();
    }

bool employe::modifier(int id)
{ QSqlQuery query;
    QString res= QString::number(id);
           query.prepare("update employe SET NOM=:NOM,PRENOM=:PRENOM,POSTE=:POSTE,EMAIL_EMP=:EMAIL_EMP,ADRESSE_EMP=:ADRESSE_EMP,PWD=:PWD WHERE ID=:ID");
           query.bindValue(":ID",res);
            query.bindValue(":NOM", nom);
             query.bindValue(":PRENOM", prenom);
             query.bindValue(":POSTE", poste);
             query.bindValue(":EMAIL_EMP", email);
             query.bindValue(":ADRESSE_EMP", adresse);
             query.bindValue(":PWD", pwd);

           return    query.exec();

   }


QSqlQueryModel * employe::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from employe");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("POSTE"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("EMAIL_EMP"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("ADRESSE_EMP"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("PWD"));
    return model;


}

QSqlQueryModel * employe::tri_nom_c()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from employe  order by nom ASC");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("POSTE"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Email_EMP"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("ADRESSE_EMP"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("PWD"));

    return model;
}
QSqlQueryModel * employe::tri_nom_dec()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from employe  order by nom DESC");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("POSTE"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Email_EMP"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("ADRESSE_EMP"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("PWD"));

    return model;
}
QSqlQueryModel * employe::tri_id_c()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from employe  order by ID ASC");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("POSTE"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Email_EMP"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("ADRESSE_EMP"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("PWD"));

    return model;
}
QSqlQueryModel * employe::rechercher_id(int ID)
{
    QSqlQueryModel * model=new QSqlQueryModel();
QString res= QString::number(ID);
    model->setQuery("select * from employe where ID LIKE '"+res+"'");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("POSTE"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("EMAIL_EMP"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("ADRESSE_EMP"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("PWD"));

    return model;
}
QSqlQueryModel * employe::rechercher_ID(QString rech, QString rech_1)
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * FROM employe where ID LIKE '"+rech+"' and PWD like '"+rech_1+"'");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("POSTE"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("EMAIL_EMP"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("ADRESSE_EMP"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("PWD"));


    return model;

}
QSqlQueryModel* employe::rechercherID(QString recherche)
{
    QSqlQueryModel* model=new QSqlQueryModel();


    model->setQuery("SELECT * FROM employe where ID LIKE '"+recherche+"%'  OR LOWER(ID) LIKE '"+recherche+"%' OR UPPER(ID) LIKE '"+recherche+"%'");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("POSTE"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("EMAIL_EMP"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("ADRESSE_EMP"));
    return model;
}
QSqlQueryModel* employe::rechercherRFID(QString rfid)
{
QSqlQueryModel* model= new QSqlQueryModel();

model->setQuery("SELECT* From EMPLOYE Where RFID LIKE '"+rfid+"'");
return  model;




}
