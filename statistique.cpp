#include "statistique.h"
#include "ui_statistique.h"
#include "ui_mainwindow.h"
#include<iostream>
#include "mainwindow.h"
#include <QDialog>
#include <QColor>

statistique::statistique(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statistique)
{
ui->setupUi(this);
}

statistique::~statistique()
{
    delete ui;
}
int statistique::Statistique_partie2()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from employe where POSTE = 'Ingenieur' ") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;
}

int statistique::Statistique_partie3()
{
    QSqlQuery query;
    int count=0 ;
   QSqlQuery requete("select * from employe where POSTE = 'Directeur' ") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;
}

int statistique::Statistique_partie4()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from employe where POSTE = 'Chef de service' ") ;
    while(requete.next())
    {
            count++ ;
    }
    return count ;
    }

int statistique::Statistique_partie5()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from employe where POSTE = 'Assistant' ") ;
    while(requete.next())
    {
            count++ ;
    }
    return count ;
    }

void statistique::paintEvent(QPaintEvent *)
{

    int x=Statistique_partie2();
    cout<<x<<endl ;
    int y=Statistique_partie3();
    cout<<y<<endl ;
    int w=Statistique_partie3();
    cout<<w<<endl ;
    int z=Statistique_partie3();
    cout<<z<<endl ;

        float s2= x*100;
        float s3=y*100;
        float s4=w*100;
        float s5=z*100;
        float nb = x+y+w+z;
        float q2;
        q2 = s2/nb;
        float q3;
        q3=s3/nb;
        float q4;
        q4=s4/nb;
        float q5;
        q5=s5/nb;
        float r;
        r = (q2*360)/100;
        float m;
        m= (q3*360)/100;
        float n;
        n = (q4*360)/100;
        float o;
        o = (q5*360)/100;

    QPainter painter(this);
    QRectF size=QRectF(350,150,this->width()-700,this->width()-700);

    painter.setBrush(Qt::white);
    painter.drawPie(size,0,16*r);
    ui->label_2->setText("(Ingenieur)");
    ui->label_1->setNum(q2);

    painter.setBrush(Qt::yellow);
    painter.drawPie(size,16*r,16*m);
    ui->label_4->setText("(Directeur)");
    ui->label_3->setNum(q3);

    painter.setBrush(Qt::black);
    painter.drawPie(size,16*r+16*m,16*n);
    ui->label_6->setText("(Chef de service)");
    ui->label_5->setNum(q3);

    painter.setBrush(Qt::red);
    painter.drawPie(size,16*r+16*m+16*n,16*o);
    ui->label_8->setText("(Assistant)");
    ui->label_7->setNum(q3);

}
