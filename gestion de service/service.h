#ifndef Service_H
#define Service_H
#include <QString>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include <QSqlQueryModel>
class Service
{
public:
    //constructeurs
    Service();
    Service(int,int,float,QString);
    //getters
    int getId();
    QString getType();
    int getQuantite();
    int getPrix();
    //setters
    void setId(int);
    void setType(QString);
    void setQuantite(int);
     void setPrix(int);
    //fonctionnalites de Base relatives a l'entite Service
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool update(int);
private:
    int id,quantite;
    QString type;
   int prix;
};

#endif // Service_H
