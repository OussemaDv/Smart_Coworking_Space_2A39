#ifndef ADHERENTS_H
#define ADHERENTS_H
#include <iostream>
#include <string>
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

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
QSqlQueryModel * recherche_cin(QString);
QSqlQueryModel * tri_cin_croissant();
QSqlQueryModel * tri_cin_decroissant();
QSqlQueryModel * tri_nom_croissant();
QSqlQueryModel * tri_nom_decroissant();
QSqlQueryModel * get_id();
};

#endif // ADHERENTS_H
