#ifndef MATERIELS_H
#define MATERIELS_H
#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QPrinter>
#include <QPixmap>
#include <QPainter>
#include <QPrintDialog>
#include <QPagedPaintDevice>
#include <QPdfWriter>
#include <QTableView>
#include <QDesktopServices>
#include <QtCharts/QAreaSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QPieSlice>
#include <QPieSeries>
#include <QChartView>

class Materiels
{

public:
    Materiels();
    Materiels(int, QString, int, QDate);
    int getid_materiel();
    QString gettype();
    int getnombre();
    QDate getdate_arriv();

    void setid_materiel(int);
    void settype(QString);
    void setnombre(int);
    void setdate_arriv(QDate);

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool update(int);

    void telechargerPDF();
    void recherche(QTableView * table, QString );
    QSqlQueryModel * tri_id();
    QSqlQueryModel * tri_nombre();
    QSqlQueryModel * tri_date();
    void recherchetype( QString rech);

private:
    int id_materiel;
    QString type;
    int nombre;
    QDate date_arriv;
};

#endif // MATERIELS_H
