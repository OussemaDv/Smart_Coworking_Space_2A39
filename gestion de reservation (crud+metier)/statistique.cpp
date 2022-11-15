#include "statistique.h"
#include "ui_statistique.h"
#include "ui_mainwindow.h"
#include<iostream>
#include "mainwindow.h"
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
int statistique::Statistique_partie1()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("SELECT * FROM reservation WHERE extract(month from datte) BETWEEN 1 AND 6") ;
    while(requete.next())
    {
            count++ ;
    }return count ;}
int statistique::Statistique_partie2()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("SELECT * FROM reservation WHERE extract(month from datte) BETWEEN 7 AND 12") ;
    while(requete.next())
    {
            count++ ;
    }return count ;}

void statistique::paintEvent(QPaintEvent *)
{float nb,s1,s2;

    int a=Statistique_partie1();
    cout<<a<<endl ;
    int b=Statistique_partie2();
    cout<<b<<endl ;
    nb=a+b;
    s1=a*100;
    s2=b*100;
    float q1,q2;
    q1=s1/nb;
    q2=s2/nb;
    float y,m;
    y = (q1*360)/100 ;
    m = (q2*360)/100 ;
    QPainter painter(this);
       QRectF size=QRectF(350,150,this->width()-700,this->width()-700);

       painter.setBrush(Qt::red);

       painter.drawPie(size,0,16*y);
       ui->label_2->setText("(semestre 1)") ;
       painter.setBrush(Qt::blue);
       ui->label_3->setNum(q1) ;
       painter.drawPie(size,16*y,16*m);
       ui->label_4->setText("(semestre 2") ;
       ui->label_6->setNum(q2) ;


}
