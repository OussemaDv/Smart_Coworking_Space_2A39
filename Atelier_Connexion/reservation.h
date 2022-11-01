#ifndef RESERVATION_H
#define RESERVATION_H
#include <qstring.h>
#include <QSqlQueryModel>
class Reservation
{
public :
    bool ajouter();
    Reservation();
    Reservation(int,int,int,QString);
    int GetresID() { return resID; }
           void SetresID(int val) { resID = val; }
           int GetCIN() { return CIN; }
           void SetCIN(int val) { CIN = val; }
           int Getposte() { return poste; }
           void Setposte(int val) { poste = val; }
           QString Getdatte() { return datte; }
           void setdatte(QString val){datte=val;}
    QSqlQueryModel* afficher();
    bool supprimer(int);

    bool modifier(int resID);
private:
    int CIN;
    int resID;
    int poste;
    QString datte;
};

#endif // RESERVATION_H
