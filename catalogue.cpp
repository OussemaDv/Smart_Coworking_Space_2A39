#include "catalogue.h"
#include "ui_catalogue.h"
#include "materiels.h"
catalogue::catalogue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::catalogue)
{
    ui->setupUi(this);
    ui->bcatalogue2->addItem("table");
    ui->bcatalogue2->addItem("chaise");
    ui->bcatalogue2->addItem("tableau");
    ui->bcatalogue2->addItem("climatiseur");
    ui->bcatalogue2->addItem("prise");
    ui->bcatalogue2->addItem("poubelle");
    ui->bcatalogue2->addItem("lampe");
    ui->bcatalogue2->addItem("camera");
    ui->bcatalogue2->addItem("eau");
    ui->bcatalogue2->addItem("jus");
    ui->bcatalogue2->addItem("cafe");
    ui->bcatalogue2->addItem("gateau");
    ui->bcatalogue2->addItem("projecteur");
    ui->bcatalogue2->addItem("the");
    ui->bcatalogue2->addItem("multiprises");
    ui->bcatalogue2->addItem("chauffage");
    ui->bcatalogue2->addItem("");
    ui->bcatalogue2->setModel(afficherCB());
}
catalogue::~catalogue()
{
    delete ui;
}
QSqlQueryModel * catalogue :: afficherCB()
{
    QSqlQuery query;
    QSqlQueryModel * model=new QSqlQueryModel;
    model->setQuery("SELECT TYPE FROM MATERIELS");
    query.exec();
    return model;
}
/*void catalogue::on_bcatalogue2_currentTextChanged(const QString &arg1)
{
   QString typem = ui->bcatalogue2->currentText();
   M.recherchetype(typem);
   if (ui->bcatalogue2->currentText().isEmpty())
   {
       QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("type available"), QMessageBox::Cancel);
   }
   else
   {
       QMessageBox::information(nullptr,QObject::tr("non"),QObject::tr("type not available"), QMessageBox::Cancel);
   }
}*/
