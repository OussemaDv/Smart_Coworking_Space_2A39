#ifndef ESPACE_H
#define ESPACE_H

#include <QObject>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QVector>
#include <QMap>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QDate>
#include <qiterator.h>
#include <iterator>

class Espace
{
public:
    Espace();
    Espace(int,int,QString,QDate);
    void Setid(int);
    int Getid();
    void Setnb(int);
    int Getnb();
    void Setbloc(QString);
    QString Getbloc();

    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficher2();
    QSqlTableModel * afficher3();
    bool modifier();
    bool supprimer(int);


private:
    int id,nb;
    QString bloc;
    QDate date;
public:
    QMap<QGraphicsScene*,QVector<QGraphicsPixmapItem*>> map;
    QVector <QString> free_list;
    QVector <QString> busy_list;

};

#endif // ESPACE_H
