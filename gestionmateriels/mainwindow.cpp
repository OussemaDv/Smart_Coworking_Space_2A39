#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "materiels.h"
#include <QApplication>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QIntValidator>
#include <QMainWindow>
#include <QTableView>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->l2->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));
    ui->l3->setValidator(new QIntValidator(0,9999,this));
    ui->table->setModel(M.afficher());


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_bajouter_clicked()
{
    QString id_materiel=ui->l1->text();
    QString type=ui->l2->text();
    int nombre=ui->l3->text().toInt();
    QDate date_arriv=ui->l4->date();
    Materiels M (id_materiel, type, nombre, date_arriv);
    bool test=M.ajouter();
    if (test)
    {
        QMessageBox :: information(nullptr, QObject ::tr("ok"),QObject::tr("ajout effectue, click cancel to exit."), QMessageBox::Cancel );
        ui->table->setModel(M.afficher());
    }
    else
    {
        QMessageBox :: critical(nullptr, QObject ::tr("not ok"),QObject::tr("ajout non effectue, click cancel to exit."), QMessageBox::Cancel );
    }
}


void MainWindow::on_bsupp_clicked()
{

    QString idM =ui->lsupp->text();
    bool test=M.supprimer(idM);
    if (test)
    {
        QMessageBox :: information(nullptr, QObject ::tr("ok"),QObject::tr("suppression effectue, click cancel to exit."), QMessageBox::Cancel );
        ui->table->setModel(M.afficher());
    }
    else
    {
        QMessageBox :: critical(nullptr, QObject ::tr("not ok"),QObject::tr("suppression non effectue, click cancel to exit."), QMessageBox::Cancel );
    }

}

void MainWindow::on_bmodif_clicked()
{
        QString id_materiel=ui->l21->text();
        QString type=ui->l22->text();
        int nombre=ui->l23->text().toInt();
        QDate date_arriv=ui->l24->date();
        Materiels M(id_materiel,type,nombre,date_arriv);
        bool test=M.update(id_materiel);
        if(test){
             ui->table->setModel(M.afficher());
            QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("update effectues\n""click cancel to exit"),QMessageBox::Cancel);
        }else{
            QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("update non effectue\n""click cancel to exit"),QMessageBox::Cancel);
        }
}