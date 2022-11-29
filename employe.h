#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include <QtDebug>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSql>
class employe
{
    int id;
    QString nom;
    QString prenom;
    QString poste;
    QString email;
    QString adresse;
    QString pwd;


public:
    employe();
    employe(int,QString,QString,QString,QString,QString,QString);
    int getid();
    QString getnom();
    QString getprenom();
    QString getposte();
    QString getemail();
    QString getadresse();
    QString getpwd();
    void setid(int);
    void setnom(QString);
    void setprenom(QString);
    void setposte(QString);
    void setemail(QString);
    void setadresse(QString);
    void setpwd(QString);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool modifier(int id);
    bool supprimer(int);
    QSqlQueryModel * tri_nom_c();
    QSqlQueryModel * tri_nom_dec();
    QSqlQueryModel * tri_id_c();
    QSqlQueryModel * rechercher_id(int ID);
    QSqlQueryModel * rechercherID(QString recherche);
    QSqlQueryModel * rechercher_ID(QString rech,QString rech_1);
    QSqlQueryModel * rechercherRFID(QString rfid);

};

#endif // EMPLOYE_H
