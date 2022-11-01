#ifndef MATERIELS_H
#define MATERIELS_H
#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Materiels
{
public:
    Materiels();
    Materiels(QString, QString, int, QDate);
    QString getid_materiel();
    QString gettype();
    int getnombre();
    QDate getdate_arriv();

    void setid_materiel(QString);
    void settype(QString);
    void setnombre(int);
    void setdate_arriv(QDate);

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
    bool update(QString);

private:
    QString id_materiel;
    QString type;
    int nombre;
    QDate date_arriv;
};

#endif // MATERIELS_H
