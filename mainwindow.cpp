#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include <QString>
#include <QtDebug>
#include <QMessageBox>
#include <QIntValidator>
#include <QSqlQueryModel>
#include <QPdfWriter>
#include <QtDebug>
#include <QTextDocument>
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>
#include "statistique.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setValidator(new QIntValidator(0, 99999999, this));
       ui->lineEdit_2->setValidator(new QRegExpValidator(QRegExp("[A-z]*")));
       ui->lineEdit_3->setValidator(new QRegExpValidator(QRegExp("[A-z]*")));
       ui->tab_employe->setModel(e.afficher());

}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    int ID = ui->lineEdit->text().toInt();
          QString NOM = ui->lineEdit_2->text();
          QString PRENOM = ui->lineEdit_3->text();
          QString POSTE = ui->comboBox_poste->currentText();
          QString ADRESSE_EMP = ui->lineEdit_5->text();
          QString EMAIL_EMP = ui->lineEdit_6->text();
          QString PWD = ui->lineEdit_7->text();

          employe e(ID,NOM,PRENOM,POSTE,ADRESSE_EMP,EMAIL_EMP,PWD);
       bool test=e.ajouter();
           if(test)
           {
               QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Ajout effectué\n""Click Cancel to exit."));
               ui->tab_employe->setModel(e.afficher());
               ui->lineEdit->clear();
               ui->lineEdit_2->clear();
               ui->lineEdit_3->clear();
               ui->lineEdit_5->clear();
               ui->lineEdit_6->clear();
               ui->lineEdit_7->clear();

           }
           else
               QMessageBox::critical(nullptr, QObject::tr("NOT OK"), QObject::tr("Click Cancel to exit."), QMessageBox::Cancel);
   }

void MainWindow::on_Modifier_clicked()
{
    if ((ui->lineEdit->text().isEmpty())or(ui->lineEdit_2->text().isEmpty())or(ui->lineEdit_3->text().isEmpty())or(ui->comboBox_poste->currentText().isEmpty())or(ui->lineEdit_5->text().isEmpty())or(ui->lineEdit_6->text().isEmpty()))
   {
    QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("missing details\n""click to Cancel to exit."), QMessageBox::Cancel);

    }
    else
    {
    int ID = ui->lineEdit->text().toInt();
          QString NOM = ui->lineEdit_2->text();
          QString PRENOM = ui->lineEdit_3->text();
          QString POSTE = ui->comboBox_poste->currentText();
          QString Email_EMP = ui->lineEdit_5->text();
          QString ADRESSE_EMP = ui->lineEdit_6->text();
          QString PWD = ui->lineEdit_7->text();
          employe e1(ID,NOM,PRENOM,POSTE,Email_EMP,ADRESSE_EMP,PWD);
       bool test=e1.modifier(ID);
       if (test)
       {
           ui->tab_employe->setModel(e.afficher());
           QMessageBox::information(nullptr,QObject::tr("done"),QObject::tr("modification effectué\n""click to Cancel to exit."), QMessageBox::Cancel);
           ui->lineEdit->clear();
           ui->lineEdit_2->clear();
           ui->lineEdit_3->clear();
           ui->lineEdit_5->clear();
           ui->lineEdit_6->clear();
           ui->lineEdit_7->clear();
       }
       else
       QMessageBox::critical(nullptr, QObject::tr("not done"),QObject::tr("modification non effectué.\n" "click to cancel to exit."),QMessageBox::Cancel);
}
}

void MainWindow::on_pb_supprimer_clicked()
{


    int ID=ui->lineEdit_id_supp->text().toInt();
      QString recherche=ui->lineEdit_id_supp->text();

      if (e.rechercherID(recherche)->rowCount()!=0 and recherche.length()!=0)
      {
         bool test=e.supprimer(ID);
         QMessageBox::information(nullptr, QObject::tr("Succès"),
         QObject::tr("Suppression effectué.\n"
        "Cliquer sur Cancel to exit."), QMessageBox::Cancel);
        }
        else
            {QMessageBox::critical(nullptr, QObject::tr("ERREUR"),
                                  QObject::tr("Suppression non effectué !\n"
                                    "Cliquer sur Cancel to exit."), QMessageBox::Cancel);}



      ui->tab_employe->setModel(e.afficher());
      ui->lineEdit_id_supp->clear();
}



void MainWindow::on_pb_trier_clicked()
{
    ui->tab_employe->setModel(e.tri_nom_c());

}

void MainWindow::on_pb_trier_2_clicked()
{
    ui->tab_employe->setModel(e.tri_nom_dec());

}

void MainWindow::on_pb_recherche_clicked()
{
        int ID=ui->lineEdit->text().toInt();
       ui->tab_employe->setModel(e.rechercher_id(ID));
       ui->lineEdit->clear();
}

void MainWindow::on_pb_pdf_clicked()
{
    {
            QPdfWriter pdf("C:/Users/lenovo/Desktop/GESTIONN_EMPLOYEE/PDF.pdf");

                   QPainter painter(&pdf);


                  painter.setPen(Qt::red);
                  painter.setFont(QFont("Arial", 50));
                  painter.drawText(500,500,"LISTE DES EMPLOYES");
                  painter.drawRect(0,3000,9600,500);
                  painter.setPen(Qt::red);
                  painter.setFont(QFont("Arial", 11));
                  painter.drawText(500,3300,"ID");
                  painter.drawText(1500,3300,"NOM");
                  painter.drawText(3500,3300,"PRENOM");
                  painter.drawText(5000,3300,"POSTE");
                  painter.drawText(6500,3300,"EMAIL_EMP");
                  painter.drawText(7500,3300,"ADRESSE_EMP");




                  QSqlQuery query;
                  int i = 4000;

                   query.prepare("select * from employe");
                   query.exec();
                while (query.next())
                  {
                  painter.setPen(Qt::black);
                  painter.setFont(QFont("Arial", 9));
                  painter.drawText(500,i,query.value(0).toString());
                  painter.drawText(1800,i,query.value(1).toString());
                  painter.drawText(3500,i,query.value(2).toString());
                  painter.drawText(5000,i,query.value(3).toString());
                  painter.drawText(6500,i,query.value(4).toString());
                  painter.drawText(7500,i,query.value(5).toString());


                  i = i +500;
                                      }
            }

    }


void MainWindow::on_pushButton_2_clicked()
{
     ui->tab_employe->setModel(e.tri_id_c());
}

void MainWindow::on_pushButton_3_clicked()
{
   statistique s;
   s.exec();
}
