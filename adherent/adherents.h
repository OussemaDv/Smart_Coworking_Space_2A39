#ifndef ADHERENTS_H
#define ADHERENTS_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class adherents
{
QString nom,prenom,date,email;
int cin;

public:
//constructeur
adherents(){};
adherents(int,QString,QString,QString,QString);

//getters
QString getnom(){return nom;}
QString getprenom(){return prenom;}
int getcin(){return cin;}
QString getdate(){return date;}
QString getemail(){return email;}

//setters
void setnom(QString n){nom=n;}
void setprenom(QString p){prenom=p;}
void setcin(int c){cin=c;}
void setdate(QString d){date=d;}
void setemail(QString e){email=e;}

//functions
bool ajouter();
bool supprimer(int);
QSqlQueryModel * afficher();
bool modifier(int);
QSqlQueryModel * ordre_croissant();
QSqlQueryModel * ordre_decroissant();
};

#endif // ADHERENTS_H
