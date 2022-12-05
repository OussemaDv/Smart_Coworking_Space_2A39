#include "Fournisseur.h"
#include<QtDebug>
#include <QSqlQuery>
#include <QPdfWriter>
#include <QPainter>
#include <QMessageBox>
Fournisseur::Fournisseur()
{
  id=0;
  adresse=" ";
  quantite=2;
  prix=0;
  email=" ";
  nom=" ";
  
     
}

Fournisseur::Fournisseur(int id, int quantite,int prix, QString nom,QString adresse,QString email){
    this->id=id;
    this->quantite=quantite;
    this->adresse=adresse;
    this->prix=prix;
    this->email=email;
    this->nom=nom;

}

int Fournisseur::getId(){
    return id;
}
int Fournisseur::getQuantite(){
    return quantite;
}
int Fournisseur::getPrix(){
    return prix;
}
QString Fournisseur::getAdresse(){
    return adresse;
}
QString Fournisseur::getEmail(){
    return email;
}
QString Fournisseur::getNom(){
    return nom;
}
void Fournisseur::setId(int id){
    this->id=id;
}
void Fournisseur::setAdresse(QString adresse) {
    this->adresse=adresse;
}
bool Fournisseur::verifieremail(QString email)
{
 int temail= email.length(),iAT=0;
bool test=false;
 for (int i=0;i<(temail-3);i++)
  {
      if (email[i]=='@' and iAT==0)
        iAT=1;//vrai
  }
 if ((email[temail-4]=='.' or email[temail-3]=='.') and iAT==1 )
   {
     return test;//vrai
 }else {
return test;

}

//faux
}
void Fournisseur::setEmail(QString email) {
   // if(verifieremail(email))
    this->email=email;
}
void Fournisseur::setNom(QString nom){
    this->nom=nom;
}
void Fournisseur::setPrix(int prix){
    this->prix=prix;
}
void Fournisseur::setQuantite(int quantite){
    this->quantite=quantite;
}


bool Fournisseur::ajouter(){

    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("INSERT INTO FOURNISSEUR (ID,NOM,EMAIL,ADRESSE,QUANTITE,PRIX)" "VALUES(:id,:nom,:email,:adresse,:quantite,:prix)");
    query.bindValue(":id",res);
     query.bindValue(":adresse",adresse);
      query.bindValue(":quantite",quantite);
       query.bindValue(":prix",prix);
       query.bindValue(":email",email);
       query.bindValue(":nom",nom);


return query.exec();
}

/*QSqlQueryModel * Fournisseur::afficher(bool clicked,QString search,QString condition){
    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery;
    if((clicked) && (search!=NULL)){
        QString adresse=search;
        query->prepare("SELECT * FROM Fournisseur WHERE adresse LIKE '%"+search+"%'  OR ID LIKE '%"+search+"%' OR QUANTITE LIKE '%"+search+"%' OR PRIX LIKE'%"+search+"%' OR EMAIL LIKE '%"+search+"%' OR FOURNISSEUR LIKE '%"+search+"%'");
        query->exec();
        model->setQuery(*query);
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("adresse"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("id"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("Quantite"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("Prix"));
         model->setHeaderData(4,Qt::Horizontal,QObject::tr("Email"));
          model->setHeaderData(5,Qt::Horizontal,QObject::tr("Fournisseur"));
          return model;
    }else if ((clicked) && (search==NULL)){

        query->prepare("SELECT * FROM Fournisseur ORDER BY '%"+condition+"%' ");
        if(query->exec()){
            QMessageBox::information(nullptr,QObject::tr("im from afficher"),QObject::tr("done \n"),QMessageBox::Cancel);
        }else{
            QMessageBox::critical(nullptr,QObject::tr("rawaaah"),QObject::tr("not done \n"),QMessageBox::Cancel);
        }
        model->setQuery(*query);
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("adresse"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("id"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("Quantite"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("Prix"));
         model->setHeaderData(4,Qt::Horizontal,QObject::tr("Email"));
          model->setHeaderData(5,Qt::Horizontal,QObject::tr("Fournisseur"));

          return model;
   }
 else{


    model->setQuery("SELECT * FROM Fournisseur");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("adresse"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Quantite"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Prix"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("Email"));
      model->setHeaderData(5,Qt::Horizontal,QObject::tr("Fournisseur"));
      return model;
}

    }*/
QSqlQueryModel * Fournisseur::afficher(bool clicked,QString search){
    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery;
    if((clicked) && (search!=NULL)){
        QString adresse=search;
        query->prepare("SELECT * FROM FOURNISSEUR WHERE ADRESSE LIKE '%"+search+"%'  OR ID LIKE '%"+search+"%' OR QUANTITE LIKE '%"+search+"%' OR PRIX LIKE'%"+search+"%' OR EMAIL LIKE '%"+search+"%' OR NOM LIKE '%"+search+"%'");
        query->exec();
        model->setQuery(*query);
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("email"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("adresse"));
         model->setHeaderData(4,Qt::Horizontal,QObject::tr("quantite"));
          model->setHeaderData(5,Qt::Horizontal,QObject::tr("prix"));
          return model;
    }else{
    model->setQuery("SELECT * FROM FOURNISSEUR");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("email"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("adresse"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("quantite"));
      model->setHeaderData(5,Qt::Horizontal,QObject::tr("prix"));
      return model;
    }
}
QSqlQueryModel * Fournisseur::triID(){
    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery;
    query->prepare("SELECT * FROM FOURNISSEUR ORDER BY ID ");
    query->exec();
    model->setQuery(*query);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("email"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("adresse"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("quantite"));
      model->setHeaderData(5,Qt::Horizontal,QObject::tr("prix"));
      return model;
}
QSqlQueryModel *  Fournisseur::triQuantite(){
    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery;
    query->prepare("SELECT * FROM FOURNISSEUR ORDER BY QUANTITE ");
    query->exec();
    model->setQuery(*query);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("email"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("adresse"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("quantite"));
      model->setHeaderData(5,Qt::Horizontal,QObject::tr("prix"));
      return model;
}
QSqlQueryModel *  Fournisseur::triPrix(){
    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery;
    query->prepare("SELECT * FROM FOURNISSEUR ORDER BY PRIX ");
    query->exec();
    model->setQuery(*query);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("email"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("adresse"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("quantite"));
      model->setHeaderData(5,Qt::Horizontal,QObject::tr("prix"));
      return model;
}
bool Fournisseur::supprimer(int id){
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("DELETE FROM FOURNISSEUR WHERE ID = :id");
    query.bindValue(":id",res);
    return query.exec();
}
bool Fournisseur::update(int id){
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("UPDATE FOURNISSEUR SET ID= :id,NOM= :nom,EMAIL = :email,ADRESSE= :adresse,QUANTITE= :quantite,PRIX = :prix WHERE ID = :id");
    query.bindValue(":id",res);
    query.bindValue(":nom",nom);
     query.bindValue(":quantite",quantite);
      query.bindValue(":prix",prix);
      query.bindValue(":email",email);
      query.bindValue(":adresse",adresse);
    return query.exec();
}
QSqlQueryModel * Fournisseur::afficherCB(){
    QSqlQuery query;
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("SELECT ID FROM FOURNISSEUR");
    query.exec();
    return model;
}
bool Fournisseur::pdf(){
    bool test= false;
    QPdfWriter pdf("C:/Users/kittie/OneDrive/Desktop/PDFPROJET/Fournisseur.pdf");
        QPainter painter(&pdf);
                              painter.setFont(QFont("Century Gothic",35,QFont::Bold));
                             painter.drawText(2000,1500,"LISTES DES FOURNISSEURS");




                            int i = 4000;

                            QPixmap pixmapl("C:/Users/kittie/OneDrive/Desktop/QTapps/Atelier_Connexion/pictures/logoprojet.png");
                            QPixmap pixmapl2("C:/Users/kittie/OneDrive/Desktop/QTapps/Atelier_Connexion/pictures/logoesprit.png");

                                 painter.setPen(Qt::blue);
                             painter.setPen(Qt::black);
                             painter.drawRect(0,2700,9600,500);
                             painter.setFont(QFont("Calibri",14,QFont::Bold));
                             painter.drawText(200,3000,"ID");
                             painter.drawText(900,3000,"NOM");
                             painter.drawText(2100,3000,"QUANTITE");
                             painter.drawText(3900,3000,"PRIX");
                              painter.drawText(5000,3000,"EMAIL");
                               painter.drawText(7200,3000,"ADRESSE");
                             painter.drawPixmap(50,50,900,900,pixmapl);
                             painter.drawPixmap(7900,140,1500,500,pixmapl2);



                             QSqlQuery query;

                             query.prepare("SELECT * FROM FOURNISSEUR");
                             if(query.exec()){
                             while (query.next())
                             {
                                    painter.setFont(QFont("Calibri",13));
                                 painter.drawText(200,i,query.value(0).toString());
                                 painter.drawText(900,i,query.value(1).toString());
                                 painter.drawText(2100,i,query.value(4).toString());
                                 painter.drawText(3900,i,query.value(5).toString());
                                   painter.drawText(5000,i,query.value(2).toString());
                                     painter.drawText(7200,i,query.value(3).toString());




                                i = i + 500;
                             }
                             test=true;}
                             return test;

}


