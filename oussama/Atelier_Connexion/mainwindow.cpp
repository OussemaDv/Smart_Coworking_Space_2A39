#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "espace.h"
#include <qmessagebox.h>
#include<QMessageBox>
#include <QSqlQuery>
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(Etmp.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int id=ui->le_id->text().toInt();
    int nb=ui->le_nb->text().toInt();
    QString bloc=ui->le_bloc->text();
    Espace E(id,nb,bloc);

    bool test=E.ajouter();

    if(test)
    {
        ui->tableView->setModel(Etmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout effectue\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                              QObject::tr("Ajout non effectue.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_supprimer_clicked()
{
    int id =ui->le_supprimer->text().toInt();
    bool test=Etmp.supprimer(id);

    if (test)
    {
        ui->tableView->setModel(Etmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Suppression effectuee\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                              QObject::tr("Suppression non effectuee.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pb_modifier_clicked()
{
    int id =ui->le_id_modifier->text().toInt();
    int nb =ui->le_nb_modifier->text().toInt();
    QString bloc =ui->le_bloc_modifier->text();
    Espace Etmp(id,nb,bloc);

    bool test=Etmp.modifier();
    if (test)
    {
        ui->tableView->setModel(Etmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Modification effectuee\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                              QObject::tr("Modification non effectuee.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}
