#include "materiels.h"
#include <QString>
#include <QApplication>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QObject>
#include <QTableView>
#include <QPrinter>
#include <QPixmap>
#include <QPainter>
#include <QPrintDialog>
#include <QPagedPaintDevice>
#include <QPdfWriter>
#include <QPieSeries>
#include <QPieSlice>
#include <QDesktopServices>
#include <QtCharts/QAreaSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QPieSlice>
#include <QPieSeries>
#include <QChartView>

Materiels::Materiels()
{
  id_materiel=0;
  type="";
  nombre=0;
  date_arriv={0,0,0};
}
Materiels ::Materiels(int id_materiel, QString type, int nombre, QDate date_arriv)
{
    this->id_materiel=id_materiel;
    this->type=type;
    this->nombre=nombre;
    this->date_arriv=date_arriv;
}
int Materiels ::getid_materiel()
{
    return id_materiel;
}
QString Materiels ::gettype()
{
    return type;
}
int Materiels ::getnombre()
{
    return nombre;
}
QDate Materiels ::getdate_arriv()
{
    return date_arriv;
}
void Materiels ::setid_materiel(int id_materiel)
{
    this->id_materiel=id_materiel;
}
void Materiels ::settype(QString type)
{
    this->type=type;
}
void Materiels ::setnombre(int nombre)
{
    this->nombre=nombre;
}
void Materiels ::setdate_arriv(QDate date_arriv)
{
    this->date_arriv=date_arriv;
}
bool Materiels::ajouter()
{
    QSqlQuery query;
    QString res= QString ::number(id_materiel);
    QString res1= QString ::number(nombre);
    query.prepare("INSERT INTO MATERIELS(ID_MATERIEL, TYPE, NOMBRE, DATE_ARRIV)"" VALUES (:ID_MATERIEL, :TYPE, :NOMBRE, :DATE_ARRIV)");
    query.bindValue(":ID_MATERIEL",res);
    query.bindValue(":TYPE",type);
    query.bindValue(":NOMBRE",res1);
    query.bindValue(":DATE_ARRIV",date_arriv);
    return query.exec();
}
bool Materiels ::supprimer(int id_materiel)
{
    QSqlQuery query;
    QString res= QString ::number(id_materiel);
    query.prepare("DELETE FROM MATERIELS WHERE ID_MATERIEL=:id_materiel");
    query.bindValue(":id_materiel",res);
    return query.exec();
}

QSqlQueryModel * Materiels:: afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel;
    model->setQuery("SELECT * FROM MATERIELS");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_MATERIELS"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("NOMBRE"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("DATE_ARRIV"));
    return model;
}
bool Materiels::update(int id_materiel)
{
    QSqlQuery query;
    QString res= QString ::number(id_materiel);
    QString res1=QString::number(nombre);
    query.prepare("UPDATE MATERIELS SET ID_MATERIEL= :id_materiel,TYPE= :type, NOMBRE= :nombre,DATE_ARRIV = :date_arriv WHERE ID_MATERIEL = :id_materiel");
    query.bindValue(":id_materiel",res);
    query.bindValue(":type",type);
     query.bindValue(":nombre",res1);
      query.bindValue(":date_arriv",date_arriv);
    return query.exec();
}
void  Materiels :: telechargerPDF()
{
    QPdfWriter pdf("C:/Users/Slim/Desktop/eya/2eme/projetCpp/oracle/pdf/materiels.pdf");
    QPainter painter(&pdf);
    painter.setFont(QFont("Century Gothic",35,QFont::Bold));
    painter.drawText(2000,1500,"LISTES DES MATERIELS");
    int i = 4000;

    QPixmap pixmapl("C:/Users/Slim/Desktop/eya/projetCpp/logoesprit");
    QPixmap pixmapl2("C:/Users/Slim/Desktop/eya/projetCpp/logoesprit");

    painter.setPen(Qt::blue);
    painter.setPen(Qt::black);
    painter.drawRect(300,2700,9000,500);
    painter.setFont(QFont("Calibri",14,QFont::Bold));
    painter.drawText(700,3000,"REFERENCE");
    painter.drawText(3000,3000,"TYPE");
    painter.drawText(5000,3000,"NOMBRE");
    painter.drawText(7000,3000,"DATE D'ARRIVAGE");
    painter.drawPixmap(50,100,1500,500,pixmapl);
    painter.drawPixmap(8000,100,1500,500,pixmapl2);

    QString s = QDate::currentDate().toString();
    painter.setFont(QFont("Calibri",15,QFont::Bold));
    painter.drawText(4000,2000,s);

    QSqlQuery query;

    query.prepare("select * from MATERIELS");
    query.exec();
    while (query.next())
    {
      painter.setFont(QFont("Calibri",13));
      painter.drawText(700,i,query.value(0).toString());
      painter.drawText(3000,i,query.value(1).toString());
      painter.drawText(5000,i,query.value(2).toString());
      painter.drawText(7000,i,query.value(3).toString());

      i = i + 500;

    }
}
void Materiels::recherche(QTableView * table, QString rech)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from MATERIELS where id_materiel like '%"+rech+"%' or type like '%"+rech+"%' or nombre like '%"+rech+"%' or date_arriv like '%"+rech+"%';");
    query->exec();
    model->setQuery(*query);
    table->setModel(model);
    table->show();
}
QSqlQueryModel * Materiels :: tri_id()
{
   QSqlQueryModel *model= new QSqlQueryModel();
   model->setQuery("SELECT * FROM MATERIELS ORDER BY ID_MATERIEL");
   model->setHeaderData(0,Qt::Horizontal,QObject::tr("identifiant"));
   model->setHeaderData(1,Qt::Horizontal,QObject::tr("type"));
   model->setHeaderData(2,Qt::Horizontal,QObject::tr("nombre"));
   model->setHeaderData(3,Qt::Horizontal,QObject::tr("date d'arrivage"));
   return model;
}
QSqlQueryModel * Materiels :: tri_nombre()
{
    QSqlQueryModel *model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM MATERIELS ORDER BY NOMBRE");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("identifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("type"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("nombre"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("date d'arrivage"));
    return model;
}
QSqlQueryModel * Materiels :: tri_date()
{
    QSqlQueryModel *model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM MATERIELS ORDER BY DATE_ARRIV");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("identifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("type"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("nombre"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("date d'arrivage"));
    return model;
}
void Materiels::recherchetype (QString rech)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from MATERIELS where type like '%"+rech+"%';");
    query->exec();
    model->setQuery(*query);
}
