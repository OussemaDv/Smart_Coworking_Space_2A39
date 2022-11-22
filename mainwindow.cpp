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
#include <QtCharts>
#include <QDesktopServices>
#include <QtCharts/QAreaSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QPieSlice>
#include <QPieSeries>
#include <QChartView>
#include <QColor>
#include "tache_a_faire.h"

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
    {                   QSqlQuery query;

            QPdfWriter pdf("C:/Users/lenovo/Desktop/GESTIONN_EMPLOYEE/PDF.pdf");
            QImage image("C:/Users/lenovo/Desktop/GESTIONN_EMPLOYEE/images/logo");
             QImage image1("C:/Users/lenovo/Desktop/GESTIONN_EMPLOYEE/images/date");

                  const QPoint imageCoordinates(100,50);
                  const QPoint image1Coordinates(7500,900);
                  QPainter painter(&pdf);
                  painter.drawImage(imageCoordinates,image);
                  painter.drawImage(image1Coordinates,image1);
                  painter.setPen(Qt::black);
                  painter.setFont(QFont("Brush Script MT", 30));
                  painter.drawText(3500,2400,"Liste des employés");
                  painter.drawRect(0,3000,9600,500);
                  painter.setBackground(QBrush(BLACKNESS));
                  painter.setPen(Qt::red);
                  painter.setFont(QFont("Comic Sans MS", 12));
                  painter.drawText(500,3300,"ID");
                  painter.drawText(1500,3300,"NOM");
                  painter.drawText(3000,3300,"PRENOM");
                  painter.drawText(5000,3300,"POSTE");
                  painter.drawText(6500,3300,"EMAIL_EMP");
                  painter.drawText(8000,3300,"ADRESSE_EMP");

                  int i = 4000;

                   query.prepare("select * from employe");
                   query.exec();
                while (query.next())
                  {
                  painter.setPen(Qt::black);
                  painter.setFont(QFont("Calibri", 10));
                  painter.drawText(500,i,query.value(0).toString());
                  painter.drawText(1500,i,query.value(1).toString());
                  painter.drawText(3000,i,query.value(2).toString());
                  painter.drawText(5000,i,query.value(3).toString());
                  painter.drawText(6500,i,query.value(4).toString());
                  painter.drawText(8000,i,query.value(5).toString());

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
    QSqlQueryModel * model= new QSqlQueryModel();
     QPainter painter(this);
                       model->setQuery("select * from EMPLOYE where POSTE = 'Ingenieur'");
                       float x=model->rowCount();

                       model->setQuery("select * from EMPLOYE where POSTE = 'Directeur'");
                       float y=model->rowCount();

                       model->setQuery("select * from EMPLOYE where POSTE = 'Chef de service'");
                       float w=model->rowCount();

                       model->setQuery("select * from EMPLOYE where POSTE = 'Assistant(e)'");
                       float z=model->rowCount();


                       float total=x+y+w+z;
                           QString a=QString("Ingenieur " +QString::number((x*100)/total,'f',2)+"%" );
                           QString b=QString("Directeur " +QString::number((y*100)/total,'f',2)+"%" );
                           QString c=QString("Chef de service " +QString::number((w*100)/total,'f',2)+"%" );
                           QString d=QString("Assistant(e) " +QString::number((z*100)/total,'f',2)+"%" );

                           QPieSeries *series = new QPieSeries();
                           series->append(a,x);
                           series->append(b,y);
                           series->append(c,w);
                           series->append(d,z);
                       if (x!=0)
                       {QPieSlice *slice = series->slices().at(0);
                           slice->setLabelVisible();
                           slice->setPen(QPen());
                             slice->setColor(WHITENESS);
                             slice->setLabelFont(QFont("Calibri",15));
                             slice->setLabelColor(QColor(WHITENESS));
                       }

                       if ( y!=0)
                       {QPieSlice *slice = series->slices().at(1);
                           slice->setLabelVisible();
                           slice->setPen(QPen());
                            slice->setLabelFont(QFont("Calibri",15));
                       }
                       if (w!=0)
                       {QPieSlice *slice = series->slices().at(2);
                           slice->setLabelVisible();
                           slice->setPen(QPen());
                           slice->setLabelFont(QFont("Calibri",15));
                           }

                       if (z!=0)
                       {QPieSlice *slice = series->slices().at(3);
                           slice->setLabelVisible();
                           slice->setPen(QPen());
                           slice->setLabelFont(QFont("Calibri",15));
                       slice->setColor(QColor(BLACK_BRUSH));}

                       QChart *chart = new QChart();


                       chart->addSeries(series);
                       chart->setTitle("Pourcentage des postes à l'entreprise");
                       chart->setTitleFont(QFont("Ariel",25));


                       QChartView *chartView = new QChartView(chart);
                       chartView->setRenderHint(QPainter::Antialiasing);
                       chartView->resize(1500,900);
                       chartView->show();
}



void MainWindow::on_pushButton_4_clicked()
{
 tache_a_faire t;
 t.show();
}
