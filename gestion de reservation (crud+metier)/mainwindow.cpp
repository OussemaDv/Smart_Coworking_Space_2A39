#include "mainwindow.h"
#include "QComboBox"
#include "calculatrice.h"
#include "statistique.h"
#include<iostream>
#include "ui_mainwindow.h"
#include "reservation.h"
#include <QIntValidator>
#include <qstring.h>
#include <QtDebug>
#include <QDebug>
#include <QMessageBox>
#include <QDate>
#include <qstring.h>
#include <qsqlquery.h>
#include <qpdfwriter.h>
#include <qtextdocument.h>
#include <QPrinter>
#include <QPrintDialog>
#include <qprinter.h>
#include <QPainter>
#include <QAbstractItemModel>
#include <QTableWidgetItem>
#include <qtableview.h>
#include <QSqlTableModel>
#include <QObject>
#include <QBarSet>
#include <QtCharts>
#include <QBarSeries>
#include <QtGlobal>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   ui->lineEdit_CIN->setValidator(new QIntValidator(0,999999,this));
    ui->tab_reservation->setModel(R.afficher());

    //ui->lineEdit_poste->setValidator(new QRegExpValidator(QRegExp("[A-z]*")));

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pb_calcul_prix_clicked()
{ int nb_h; float prix;
    if (ui->lineEdit_nb_h->text().isEmpty())
        {
            QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("missing details\n""click to Cancel to exit."), QMessageBox::Cancel);

        }
        else{ nb_h=ui->lineEdit_nb_h->text().toInt();
        prix=nb_h*3;
        QMessageBox::information(nullptr,QObject::tr("calcul prix"), QObject::tr("le prix est %1").arg(prix));
}
}

void MainWindow::on_pb_ajouter_clicked()
{ if ((ui->lineEdit_CIN->text().isEmpty())or(ui->lineEdit_resID->text().isEmpty())or( ui->lineEdit_poste->text().isEmpty()))
    {
        QMessageBox::information(nullptr,QObject::tr("not ok"),QObject::tr("missing details\n""click to Cancel to exit."), QMessageBox::Cancel);

    }
    else{
    int resID=ui->lineEdit_resID->text().toInt();
    QDate datte=ui->lineEdit_datte->date();
    int CIN=ui->lineEdit_CIN->text().toUInt();
    int poste=ui->lineEdit_poste->text().toUInt();



    Reservation R(CIN,resID,poste,datte);
    bool test=R.ajouter();
            if (test)
    {QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("ajout effectué\n""click to Cancel to exit."), QMessageBox::Cancel);
            ui->tab_reservation->setModel(R.afficher());
            ui->lineEdit_resID->clear();
            ui->lineEdit_datte->clear();
            ui->lineEdit_poste->clear();
            ui->lineEdit_CIN->clear();   }
                else
            {QMessageBox::critical(nullptr, QObject::tr("not ok"),QObject::tr("ajout non effectué.\n" "click to cancel to exit."),QMessageBox::Cancel);}

                }
}



void MainWindow::on_pushButton_supprimer_clicked()
{
     Reservation R1;
     if (ui->lineEdit_resID_supp->text().isEmpty())
         {
             QMessageBox::information(nullptr,QObject::tr("not ok"),QObject::tr("missing details\n""click to Cancel to exit."), QMessageBox::Cancel);

         }
         else{

         int id=ui->lineEdit_resID_supp->text().toInt();
         QString recherche=ui->lineEdit_resID_supp->text();



         if (R1.recherche_resID(recherche)->rowCount()!=0 and recherche.length()!=0)

         {

             bool test=R1.supprimer(id);
     if (test){
            QMessageBox::information(nullptr, QObject::tr("Succès"),

         QObject::tr("Suppression effectué.\n"

           "Cliquer sur Cancel to exit."), QMessageBox::Cancel);

           }

           else

               {QMessageBox::critical(nullptr, QObject::tr("ERREUR"),

                                     QObject::tr("Suppression non effectué !\n"

                                       "Cliquer sur Cancel to exit."), QMessageBox::Cancel);}
     ui->lineEdit_resID_supp->clear();
     ui->lineEdit_modResID->clear();
     ui->lineEdit_modDatte->clear();
     ui->lineEdit_modposte->clear();
     ui->lineEdit_modCIN->clear();
} else
            { QMessageBox::critical(nullptr, QObject::tr("ERREUR"),

                                                  QObject::tr("Suppression non effectué il ne !\n"

                                                    "Cliquer sur Cancel to exit."), QMessageBox::Cancel);}
                ui->lineEdit_resID_supp->clear();
              ui->lineEdit_modResID->clear();
              ui->lineEdit_modDatte->clear();
              ui->lineEdit_modposte->clear();
              ui->lineEdit_modCIN->clear();
            ui->tab_reservation->setModel(R.afficher());

}
}




void MainWindow::on_pb_modifier_clicked()
{
    int resID=ui->lineEdit_modResID->text().toInt();
    QDate datte=ui->lineEdit_modDatte->date();
    int CIN=ui->lineEdit_modCIN->text().toUInt();
    int poste=ui->lineEdit_modposte->text().toUInt();
    Reservation R(CIN,resID,poste,datte);
    bool test = R.modifier(resID);
            if (test)
           {ui->tab_reservation->setModel(R.afficher());
            QMessageBox::information(nullptr,QObject::tr("done"),QObject::tr("modification effectué\n""click to Cancel to exit."), QMessageBox::Cancel);
            ui->tab_reservation->setModel(R.afficher());
            ui->lineEdit_modResID->clear();
            ui->lineEdit_modCIN->clear();
            ui->lineEdit_modDatte->clear();
            ui->lineEdit_modposte->clear();
            }
else
{QMessageBox::critical(nullptr, QObject::tr("not done"),QObject::tr("modification non effectué.\n" "click to cancel to exit."),QMessageBox::Cancel);}
}
void MainWindow::on_tab_reservation_activated(const QModelIndex &index)
{
   QString val=ui->tab_reservation->model()->data(index).toString();
   QSqlQuery qry;
   qry.prepare("select * from reservation where resID LIKE '"+val+"'");

   if (qry.exec()){
while (qry.next())
{ui->lineEdit_modResID->setText(qry.value(0).toString());
ui->lineEdit_modCIN->setText(qry.value(1).toString());
ui->lineEdit_modposte->setText(qry.value(2).toString());
ui->lineEdit_modDatte->setDate(qry.value(3).toDate());
ui->lineEdit_resID_supp->setText(qry.value(0).toString());
}
}
   else {QMessageBox::critical(nullptr, QObject::tr("not done"),QObject::tr("echec affichage.\n" "click to cancel to exit."),QMessageBox::Cancel);}}





void MainWindow::on_pb_pdf_clicked()
{
    QPdfWriter pdf("C:/Users/ahmed/Desktop/Atelier_Connexion/stat_reservation.pdf");

        QPainter painter(&pdf);
        int i = 4100;


               QColor dateColor(0x4a5bcf);
               painter.setPen(dateColor);

               painter.setFont(QFont("Montserrat SemiBold", 11));
               QDate cd = QDate::currentDate();
               painter.drawText(8400,250,cd.toString("Tunis"));
               painter.drawText(8100,500,cd.toString("dd/MM/yyyy"));

               QColor titleColor(0x341763);
               painter.setPen(titleColor);
               painter.setFont(QFont("Montserrat SemiBold", 25));

               painter.drawText(3000,2700,"Liste des reservation");

               painter.setPen(Qt::black);
               painter.setFont(QFont("Time New Roman", 15));

               painter.drawRect(100,3300,9400,500);

               painter.setFont(QFont("Montserrat SemiBold", 10));

               painter.drawText(1875,3600,"resID");
               painter.drawText(3750,3600,"CIN");
               painter.drawText(5625,3600,"poste");
                painter.drawText(7500,3600,"date");



               painter.setFont(QFont("Montserrat", 10));
               painter.drawRect(100,3300,9400,9000);

               QSqlQuery query;
               query.prepare("select * from reservation");
               query.exec();
               int y=4300;
               while (query.next())
               {
                   painter.drawLine(100,y,9490,y);
                   y+=500;
                   painter.drawText(1875,i,query.value(0).toString());
                   painter.drawText(3750,i,query.value(1).toString());
                   painter.drawText(5625,i,query.value(2).toString());
                   painter.drawText(7500,i,query.value(3).toString());



                  i = i + 500;
               }
               QMessageBox::information( nullptr, tr( "pdf" ), tr( "pdf generer!\n\n" ) );
    }






void MainWindow::on_rechercher_pb_clicked()
{if (ui->lineEdit_recherer->text().isEmpty())
    {
        QMessageBox::information(nullptr,QObject::tr("not ok"),QObject::tr("missing details\n""click to Cancel to exit."), QMessageBox::Cancel);

    }
    else{
    QString val = ui->lineEdit_recherer->text();
   ui->tab_reservation->setModel(R.recherche_CIN(val));
}}

void MainWindow::on_pb_reload_clicked()
{
    ui->tab_reservation->setModel(R.afficher());
    ui->lineEdit_recherer->clear();
}

void MainWindow::on_pushButton_clicked()
{
    ui->tab_reservation->setModel(R.tri_resID());
}

void MainWindow::on_pb_tri_CIN_clicked()
{
    ui->tab_reservation->setModel(R.tri_CIN());
}




void MainWindow::on_calendar_clicked(const QDate &date)
{
 qInfo()<<date;
    ui->tableView_agenda->setModel(R.recherche_datte(date));


}

void MainWindow::on_pb_tri_resID_d_clicked()
{
    ui->tab_reservation->setModel(R.tri_resID_d());
}

void MainWindow::on_pb_trier_CIN_d_clicked()
{
    ui->tab_reservation->setModel(R.tri_CIN_d());
}

void MainWindow::on_pb_datte_c_clicked()
{
    ui->tab_reservation->setModel(R.tri_date_c());
}

void MainWindow::on_pb_datte_d_clicked()
{
    ui->tab_reservation->setModel(R.tri_date_d());
}



void MainWindow::on_pb_stat_clicked()
{statistique s;

        s.exec();
    }



void MainWindow::on_pb_calculatrice_clicked()
{
calculatrice c;
c.exec();
}
