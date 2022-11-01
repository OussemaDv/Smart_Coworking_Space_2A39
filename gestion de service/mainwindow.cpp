#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "service.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_ID->setValidator(new QIntValidator(0,9999,this));
    ui->le_quantite->setValidator( new QIntValidator(0,9999, this) );
    ui->le_prix->setValidator( new QIntValidator(0, 9999, this) );
    ui->up_ID->setValidator( new QIntValidator(0, 9999, this) );
    ui->up_prix->setValidator( new QIntValidator(0, 9999, this) );
    ui->up_quantite->setValidator( new QIntValidator(0, 9999, this) );
    ui->tabE->setModel(Etmp.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button_ajouter_clicked()
{
 int id=ui->lineEdit_ID->text().toInt();
 int quantite=ui->le_quantite->text().toInt();
 int prix=ui->le_prix->text().toInt();
 QString type=ui->le_type->text();
    Service s(id,quantite,prix,type);
   bool test=s.ajouter();
    if(test){
        //refresh
        ui->tabE->setModel(Etmp.afficher());
        QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("ajout effectue\n""click cancel to exit"),QMessageBox::Cancel);
    }else{
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("ajout non effectue\n""click cancel to exit"),QMessageBox::Cancel);
    }
}

void MainWindow::on_pbSupprimer_clicked()
{
    int sup=ui->le_IDsup->text().toInt();
    bool test=Etmp.supprimer(sup);
    if(test){
         ui->tabE->setModel(Etmp.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("Suppression effectues\n""click cancel to exit"),QMessageBox::Cancel);
    }else{
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("suppression non effectue\n""click cancel to exit"),QMessageBox::Cancel);
    }


}

void MainWindow::on_updateBP_clicked()
{
    int up=ui->up_ID->text().toInt();
    int quantite=ui->up_quantite->text().toInt();
    int prix=ui->up_prix->text().toInt();
    QString type=ui->up_type->text();
    Service s(up,quantite,prix,type);
    bool test=s.update(up);
    if(test){
         ui->tabE->setModel(Etmp.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("update effectues\n""click cancel to exit"),QMessageBox::Cancel);
    }else{
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("update non effectue\n""click cancel to exit"),QMessageBox::Cancel);
    }
}
