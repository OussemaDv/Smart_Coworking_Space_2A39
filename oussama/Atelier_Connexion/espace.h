#ifndef ESPACE_H
#define ESPACE_H

#include <QObject>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Espace
{
public:
    Espace();
    Espace(int,int,QString);
    void Setid(int);
    int Getid();
    void Setnb(int);
    int Getnb();
    void Setbloc(QString);
    QString Getbloc();

    bool ajouter();
    QSqlQueryModel * afficher();
    bool modifier();
    bool supprimer(int);

private:
    int id,nb;
    QString bloc;
};

#endif // ESPACE_H
