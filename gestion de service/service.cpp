#include "service.h"
#include<QtDebug>
#include <QSqlQuery>
Service::Service()
{
  id=0;
  type=" ";
  quantite=2;
  prix=0;
  
     
}

Service::Service(int id,int quantite,float prix,QString type){
    this->id=id;
    this->quantite=quantite;
    this->type=type;
    this->prix=prix;

}

int Service::getId(){
    return id;
}
int Service::getQuantite(){
    return quantite;
}
int Service::getPrix(){
    return prix;
}
QString Service::getType(){
    return type;
}
void Service::setId(int id){
    this->id=id;
}
void Service::setType(QString type) {
    this->type=type;
}
void Service::setPrix(int prix){
    this->prix=prix;
}
void Service::setQuantite(int quantite){
    this->quantite=quantite;
}


bool Service::ajouter(){

    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("INSERT INTO SERVICE (TYPE,ID,QUANTITE,PRIX)" "VALUES(:type,:id,:quantite,:prix)");
    query.bindValue(":id",res);
     query.bindValue(":type",type);
      query.bindValue(":quantite",quantite);
       query.bindValue(":prix",prix);


return query.exec();
}

QSqlQueryModel * Service::afficher(){
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM SERVICE");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Type"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Quantite"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Prix"));

    return model;
    }
bool Service::supprimer(int id){
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("DELETE FROM SERVICE WHERE ID = :id");
    query.bindValue(":id",res);
    return query.exec();
}
bool Service::update(int id){
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("UPDATE SERVICE SET TYPE= :type,ID= :id,QUANTITE= :quantite,PRIX = :prix WHERE ID = :id");
    query.bindValue(":id",res);
    query.bindValue(":type",type);
     query.bindValue(":quantite",quantite);
      query.bindValue(":prix",prix);
    return query.exec();
}

