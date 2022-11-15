#ifndef ADHERENTS_H
#define ADHERENTS_H
#include <iostream>
#include <string>
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QDate>

using namespace std;

class adherents
{
QString nom,prenom,date,email,genre;
int cin;

public:
//constructeur
adherents(){};
adherents(int,QString,QString,QString,QString,QString);

//getters
QString getnom(){return nom;}
QString getprenom(){return prenom;}
int getcin(){return cin;}
QString getdate(){return date;}
QString getemail(){return email;}
QString getgenre(){return genre;}

//setters
void setnom(QString n){nom=n;}
void setprenom(QString p){prenom=p;}
void setcin(int c){cin=c;}
void setdate(QString d){date=d;}
void setemail(QString e){email=e;}
void setgenre(QString g){email=g;}

//functions
bool ajouter();
bool supprimer(int);
bool modifier(int);
QSqlQueryModel * afficher();
QSqlQueryModel * recherche_cin(QString);
QSqlQueryModel * tri_cin_croissant();
QSqlQueryModel * tri_cin_decroissant();
QSqlQueryModel * tri_nom_croissant();
QSqlQueryModel * tri_nom_decroissant();
QSqlQueryModel * tri_prenom_croissant();
QSqlQueryModel * tri_prenom_decroissant();
QSqlQueryModel * get_id();
};

#endif // ADHERENTS_H
