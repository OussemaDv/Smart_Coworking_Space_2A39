#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "reservation.h"
#include <QIntValidator>
#include <qstring.h>
#include <QtDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_CIN->setValidator(new QIntValidator(1000,999999999,this));
    ui->tab_reservation->setModel(R.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pb_ajouter_clicked()
{
    int resID=ui->lineEdit_resID->text().toInt();
    QString datte=ui->lineEdit_datte->text();
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







void MainWindow::on_pushButton_afficher_clicked()
{
    ui->tab_reservation->setModel(R.afficher());
}

void MainWindow::on_pushButton_supprimer_clicked()
{
     Reservation R1;
     R1.SetresID(ui->lineEdit_resID_supp->text().toUInt());
     bool test=R1.supprimer(R1.GetresID());
     if (test)
     {QMessageBox::information(nullptr,QObject::tr("done"),QObject::tr("suppression effectué\n""click to Cancel to exit."), QMessageBox::Cancel);
     ui->tab_reservation->setModel(R.afficher());
     ui->lineEdit_resID_supp->clear();
     }
else
{QMessageBox::critical(nullptr, QObject::tr("not"),QObject::tr("supression non effectué.\n" "click to cancel to exit."),QMessageBox::Cancel);}


}

void MainWindow::on_pb_modifier_clicked()
{
    int resID=ui->lineEdit_modResID->text().toInt();
    QString datte=ui->lineEdit_modDatte->text();
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


