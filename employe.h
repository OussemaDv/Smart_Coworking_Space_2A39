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
    bool ajouter_emp();
    QSqlQueryModel * afficher_emp();
    bool modifier_emp(int id);
    bool supprimer_emp(int);
    QSqlQueryModel * tri_nom_c();
    QSqlQueryModel * tri_nom_dec();
    QSqlQueryModel * tri_id_c();
    QSqlQueryModel * rechercher_id_emp(int ID);
    QSqlQueryModel * rechercherID_emp(QString recherche);
    QSqlQueryModel * rechercher_ID_emp(QString rech,QString rech_1);

};

#endif // EMPLOYE_H
