#ifndef ESPACE_H
#define ESPACE_H
#include <QDate>
#include <QSqlQuery>
#include <QtSql>
#include <QSqlQueryModel>
#include <QString>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPixmap>


class espace
{
public:
    espace();
    espace(int id,int nb,QString bloc,QDate date);
    int getId(){return id;}
    int getNb(){return nb;}
    QString getBloc(){return bloc;}
    QDate getDate(){return date;}


    bool ajouter();
    bool modifier();
    bool supprimer(int id);
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficher2();
    void changeState(int,QString);
    QSqlTableModel * afficher3();


private:
    int id,nb;
    QString bloc;
    QDate date;
    QString places;
};

#endif // ESPACE_H
