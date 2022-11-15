#ifndef RESERVATION_H
#define RESERVATION_H
#include <qstring.h>
#include <QSqlQueryModel>
#include <QDate>

class Reservation
{
public :
    bool ajouter();
    Reservation();

    int GetresID() { return resID; }
           void SetresID(int val) { resID = val; }
           int GetCIN() { return CIN; }
           void SetCIN(int val) { CIN = val; }
           int Getposte() { return poste; }
           void Setposte(int val) { poste = val; }
           QDate Getdatte() { return datte; }

           void setdatte(QDate val){datte=val;}
           QSqlQueryModel* recherche_datte(QDate);
           QSqlQueryModel* recherche_CIN(QString);
           QSqlQueryModel* recherche_resID(QString);
    QSqlQueryModel* afficher();
    QSqlQueryModel*tri_resID();
    QSqlQueryModel*tri_CIN();
    QSqlQueryModel *tri_CIN_d();
    QSqlQueryModel * tri_date_c();
    QSqlQueryModel * tri_date_d();

    bool supprimer(int);

    bool modifier(int resID);
    QSqlQueryModel *tri_resID_d();
    Reservation(int,int,int,QDate);

private:
    int CIN;
    int resID;
    int poste;
    QDate datte;

};

#endif // RESERVATION_H
