#ifndef Fournisseur_H
#define Fournisseur_H
#include <QString>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include <QSqlQueryModel>
class Fournisseur
{
public:
    //constructeurs
    Fournisseur();
    Fournisseur(int,int,int,QString,QString,QString);

    //getters
    int getId();
    QString getAdresse();
    QString getEmail();
    QString getNom();
    int getQuantite();
    int getPrix();
    //setters
    void setId(int);
    void setAdresse(QString);
    void setEmail(QString);
    void setNom(QString);
    void setQuantite(int);
     void setPrix(int);
    //fonctionnalites de Base relatives a l'entite Fournisseur
    bool ajouter();
    //QSqlQueryModel * afficher(bool,QString,QString);
    QSqlQueryModel * afficher(bool clicked,QString search);
    QSqlQueryModel * triID();
    QSqlQueryModel * triQuantite();
    QSqlQueryModel * triPrix();
    bool supprimer(int);
    bool update(int);
    bool pdf();
   bool verifieremail(QString);
    QSqlQueryModel * afficherCB();
private:
    int id,quantite;
    QString adresse,email,nom;
   int prix;
};

#endif // Fournisseur_H
