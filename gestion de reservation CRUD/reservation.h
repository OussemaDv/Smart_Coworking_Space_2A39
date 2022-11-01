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
    Reservation(int,int,int,QDate);
    int GetresID() { return resID; }
           void SetresID(int val) { resID = val; }
           int GetCIN() { return CIN; }
           void SetCIN(int val) { CIN = val; }
           int Getposte() { return poste; }
           void Setposte(int val) { poste = val; }
           QDate Getdatte() { return datte; }
           void setdatte(QDate val){datte=val;}
    QSqlQueryModel* afficher();
    bool supprimer(int);

    bool modifier(int resID);
private:
    int CIN;
    int resID;
    int poste;
    QDate datte;
};

#endif // RESERVATION_H
