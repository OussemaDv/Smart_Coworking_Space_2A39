#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "arduino.h"
#include "calculatrice.h"

// ****Fournisseur*****

#include "Fournisseur.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QPixmap>
// *********Materiels***

#include "materiels.h"
#include <QApplication>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QIntValidator>
#include <QMainWindow>
#include <QTableView>
#include <Qdate>
#include <QAbstractItemModel>
#include <QDesktopServices>
#include <QtCharts/QAreaSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QPieSlice>
#include <QPieSeries>
#include <QChartView>
#include <QFileDialog>
#include <QComboBox>

//

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
ui->tab_reservation_2->setModel(R.afficher());
    ui->tableView->setModel(a.afficher());
    ui->cin_supp->setModel(a.get_id());
    ui->mod_cin->setModel(a.get_id());
    ui->cin_qr->setModel(a.get_id());
    ui->cin_pdf->setModel(a.get_id());
    //********************************************************************************************************
    //conenxion arduino
    int ret=ar.connect_arduino(); // lancer la connexion à arduino
    switch(ret)
    {
    case(0):
        qDebug()<< "arduino is available and connected to : "<< ar.getarduino_port_name();

        break;
    case(1):
        qDebug() << "arduino is available but not connected to :" <<ar.getarduino_port_name();
        break;
    case(-1):
        qDebug() << "arduino is not available";
    }
    QObject::connect(ar.getserial(),SIGNAL(readyRead()),this,SLOT(dialog1())); // permet de lancer
    //le slot update_label suite à la reception du signal readyRead (reception des données).
    //********************************************************************************************************
    //email validator
    QRegExp email(valid_email);
    //chaine validator
    QRegExp chaine(valid_chaine);
    //date validator
    QRegExp date(valid_date);
    //email validator
    QRegExp mail(valid_email);

    //champ cin
    QIntValidator *cin_valider =new QIntValidator(0,99999999,this);
    ui->cin->setValidator(cin_valider);
    ui->mod_cin->setValidator(cin_valider);
    //champ nom et prenom
    QRegExpValidator *chaine_valider =new QRegExpValidator(chaine,this);
    ui->nom->setValidator(chaine_valider);
    ui->mod_nom->setValidator(chaine_valider);
    ui->prenom->setValidator(chaine_valider);
    ui->mod_pren->setValidator(chaine_valider);
    //champ date
    QRegExpValidator *date_valider =new QRegExpValidator(date,this);
    ui->date->setValidator(date_valider);
    ui->mod_date->setValidator(date_valider);
    //champ email
    QRegExpValidator *email_valider =new QRegExpValidator(mail,this);
    ui->email->setValidator(email_valider);
    ui->mod_email->setValidator(email_valider);

    ui->id_emp->setValidator(new QIntValidator(0, 99999999, this));
    ui->nom_emp->setValidator(new QRegExpValidator(QRegExp("[A-z]*")));
    ui->prenom_emp->setValidator(new QRegExpValidator(QRegExp("[A-z]*")));
    ui->tab_employe->setModel(e.afficher_emp());

    //******Fourn****


    ui->lineEdit_ID->setValidator(new QIntValidator(0,9999,this));
    ui->le_quantite->setValidator( new QIntValidator(0,9999, this) );
    ui->le_prix->setValidator( new QIntValidator(0, 9999, this) );
    ui->le_nom->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));
    ui->le_adresse->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));
    ui->tabE->setModel(Etmp.afficher(false,NULL));
    ui->comboBoxID->setModel(Etmp.afficherCB());

    ui->le_prix->clear();
    ui->le_nom->clear();
    ui->le_email->clear();
    ui->le_quantite->clear();
    ui->lineEdit_ID->clear();
    ui->le_adresse->clear();
    //
    //pdf/*
    /*
    QPixmap pixmap("pictures/pdf.png");
    QIcon ButtonIcon(pixmap);
    ui->pdfPb->setIcon(ButtonIcon);
    //email
    QPixmap m("pictures/gmail.png");
    QIcon e(m);
    ui->emailpb->setIcon(e);
    //what'app
    QPixmap app("pictures/whatsapp.png");
    QIcon what(app);
    ui->whatsapp_pb->setIcon(what);
    //flame
    QPixmap fla("pictures/fire.png");
    QIcon a(fla);
    ui->detection->setIcon(a);
    //Map
    QPixmap map("pictures/map.png");
    QIcon mapp(map);
    ui->map->setIcon(mapp);
*/
    //******Materiels*****
    ui->l1->setValidator(new QIntValidator(0,9999,this));
       ui->l2->addItem("table");
       ui->l2->addItem("chaise");
       ui->l2->addItem("tableau");
       ui->l2->addItem("climatiseur");
       ui->l2->addItem("prise");
       ui->l2->addItem("poubelle");
       ui->l2->addItem("lampe");
       ui->l2->addItem("camera");
       ui->l2->addItem("eau");
       ui->l2->addItem("jus");
       ui->l2->addItem("cafe");
       ui->l2->addItem("gateau");
       ui->l2->addItem("projecteur");
       ui->l2->addItem("the");
       ui->l2->addItem("multiprises");
       ui->l2->addItem("chauffage");
       ui->l3->setValidator(new QIntValidator(0,9999,this));
       ui->tab->setModel(M.afficher());
       //

    //*******************Espace*************************
       ui->tableAffich->setModel(Esp.afficher());
       ui->tableAffich->setSortingEnabled(true);
       ui->comboMap->setModel(Esp.afficher2());
       ui->combo_modifEsp->setModel(Esp.afficher2());
       ui->tableView->setModel(Esp.afficher3());
       ui->tableView->setSortingEnabled(true);
       setBusyList();
       setFreeList();
       ui->tableAffich->sortByColumn(1, Qt::AscendingOrder);
       for(int i=0;i<(ui->tableAffich->model()->rowCount());i++)
       {
           QGraphicsScene *scene = new QGraphicsScene;
           QVector <QGraphicsPixmapItem*> vector;
           int n=ui->tableAffich->model()->index(i,1).data().toInt();
           for(int j=0;j<n;j++)
           {
               QGraphicsPixmapItem* pic;
               QPixmap pix(free_list[j]);
               pic = scene->addPixmap(pix);
               pic->setFlag(QGraphicsItem::ItemIsMovable);
               pic->setFlag(QGraphicsItem::ItemIsSelectable);
               vector.push_back(pic);
           }
           scene_list.push_back(scene);
           pic_list.push_back(vector);
       }

       ui->graphicsView_map->setScene(scene_list[0]);

       //statistique();
       //statSalle();

      statSalle();
      statPlace();

}

MainWindow::~MainWindow()
{
    delete ui;
}

//button annuler
void MainWindow::on_reset_clicked()
{
    ui->cin->clear();
    ui->nom->clear();
    ui->prenom->clear();
    ui->date->clear();
    ui->email->clear();
    ui->genre->setCurrentIndex(0);
}

//button annuler
void MainWindow::on_reset_2_clicked()
{
    ui->mod_cin->clear();
    ui->mod_nom->clear();
    ui->mod_pren->clear();
    ui->mod_date->clear();
    ui->mod_email->clear();
    ui->mod_genre->setCurrentIndex(0);
}

//button ajouter
void MainWindow::on_ajouter_clicked()
{
    //recuperation des information
    int cin=ui->cin->text().toInt();
    QString nom=ui->nom->text();
    QString prenom=ui->prenom->text();
    QString date=ui->date->text();
    QString email=ui->email->text();
    QString genre=ui->genre->currentText();

    adherents a(cin,nom,prenom,date,email,genre);

    if(nom.isEmpty() || prenom.isEmpty() || date.isEmpty() || email.isEmpty() || cin==0 || ui->genre->currentIndex()==0)
    {
        QMessageBox::information(nullptr,QObject::tr("Erreur"),QObject::tr("Remplir les champs vide!"),QMessageBox::Close);
    }
    else
    {
        bool test=a.ajouter();

        if(test)
        {
            //refrech
            ui->tableView->setModel(a.afficher());
            ui->cin_supp->setModel(a.get_id());
            ui->mod_cin->setModel(a.get_id());
            ui->cin_qr->setModel(a.get_id());
            ui->cin_pdf->setModel(a.get_id());
            QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("ajout effectué.\n click Close to exit."),QMessageBox::Close);
            ui->cin->clear();
            ui->nom->clear();
            ui->prenom->clear();
            ui->date->clear();
            ui->email->clear();
            ui->genre->setCurrentIndex(0);
        }
        else
        {
            QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("ajout non effectué.\n click Close to exit."),QMessageBox::Close);
        }
    }
}

//button supprimer
void MainWindow::on_supprimer_clicked()
{
    //recuperation de cin a supprimer
    int cin=ui->cin_supp->currentText().toInt();
    bool test=a.supprimer(cin);

    if(test)
    {
        //refrech
        ui->tableView->setModel(a.afficher());
        ui->cin_supp->setModel(a.get_id());
        ui->mod_cin->setModel(a.get_id());
        ui->cin_qr->setModel(a.get_id());
        ui->cin_pdf->setModel(a.get_id());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("suppression effectuer.\n" "click Close to exit."),QMessageBox::Close);
        ui->cin_supp->clear();
    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("suppresssion non effectuer.\n" "click Close to exit."),QMessageBox::Close);
    }
}

//button modifier
void MainWindow::on_modifier_clicked()
{
    //recuperation des informlation
    int cin=ui->mod_cin->currentText().toInt();
    QString nom=ui->mod_nom->text();
    QString prenom=ui->mod_pren->text();
    QString date=ui->mod_date->text();
    QString email=ui->mod_email->text();
    QString genre=ui->mod_genre->currentText();

    adherents a(cin,nom,prenom,date,email,genre);

    bool test=a.modifier(cin);
    if(test)
    {
        //refrech
        ui->tableView->setModel(a.afficher());
        QMessageBox::information(nullptr, QObject::tr("ok"),QObject::tr("Modification avec succes.\n" "Click Close to exit."), QMessageBox::Close);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok"),QObject::tr("Modification echoue.\n" "Click Close to exit."), QMessageBox::Close);
}

//modifier cin combobox
void MainWindow::on_mod_cin_currentIndexChanged()
{
    int cin=ui->mod_cin->currentText().toInt();
    QSqlQuery query;
    query.prepare("select * from adherent where cin=:cin");
    query.bindValue(":cin",cin);
    if(query.exec())
    {
        while(query.next())
        {
            ui->mod_nom->setText(query.value(1).toString());
            ui->mod_pren->setText(query.value(2).toString());
            ui->mod_date->setText(query.value(3).toString());
            ui->mod_email->setText(query.value(4).toString());
            ui->mod_genre->setCurrentText(query.value(5).toString());
        }
    }
}

//button rechercher
void MainWindow::on_rechercher_clicked()
{
    QString cin=ui->rech_cin->text();
    ui->tableView->setModel(a.recherche_cin(cin));
    ui->rech_cin->clear();
}

//tri combobox
void MainWindow::on_tri_activated()
{
    if(ui->tri->currentText()=="------------------------------")
        ui->tableView->setModel(a.afficher());
    else if(ui->tri->currentText()=="cin par ordre croissant")
        ui->tableView->setModel(a.tri_cin_croissant());
    else if(ui->tri->currentText()=="cin par ordre decroissant")
        ui->tableView->setModel(a.tri_cin_decroissant());
    else if(ui->tri->currentText()=="nom par ordre croissant")
        ui->tableView->setModel(a.tri_nom_croissant());
    else if(ui->tri->currentText()=="nom par ordre decroissant")
        ui->tableView->setModel(a.tri_nom_decroissant());
    else if(ui->tri->currentText()=="prenom par ordre croissant")
        ui->tableView->setModel(a.tri_prenom_croissant());
    else if(ui->tri->currentText()=="prenom par ordre decroissant")
        ui->tableView->setModel(a.tri_prenom_decroissant());
}

//combobox de qrcode
void MainWindow::on_cin_qr_currentIndexChanged()
{
    int rech=ui->cin_qr->currentText().toInt();
    QSqlQuery query;
    query.prepare("select * from adherent where cin=:cin");
    query.bindValue(":cin",rech);

    QString cin,nom,prenom,date,email,genre;

    if(query.exec())
    {
        while (query.next())
        {
            cin=query.value(0).toString();
            nom=query.value(1).toString();
            prenom=query.value(2).toString();
            date=query.value(3).toString();
            email=query.value(4).toString();
            genre=query.value(5).toString();
        }
    }
    QString width="350",height="350";
    QString info="Cin: "+cin+", Nom: "+nom+", Prenom: "+prenom+", Date de naissance: "+date+", Genre: "+genre+" ,Email: "+email+" ";
    QImage qr = QZXing::encodeData(info,QZXing::EncoderFormat_QR_CODE,QSize(width.toInt(), height.toInt()),QZXing::EncodeErrorCorrectionLevel_H);
    QGraphicsScene *qrcode = new QGraphicsScene(this);
    qrcode->addPixmap( QPixmap::fromImage(qr));
    ui->qrview->setScene(qrcode);
}

//combobox de pdf
void MainWindow::on_cin_pdf_currentIndexChanged()
{
    QString cin=ui->cin_pdf->currentText();

    QSqlQueryModel * info=new QSqlQueryModel();

    info->setQuery("select * from adherent where cin '"+cin+"'");

    info->setHeaderData(0,Qt::Horizontal,QObject::tr("Cin"));
    info->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    info->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
    info->setHeaderData(3,Qt::Horizontal,QObject::tr("Date de naissance"));
    info->setHeaderData(4,Qt::Horizontal,QObject::tr("Email"));
    info->setHeaderData(5,Qt::Horizontal,QObject::tr("Genre"));

    ui->pdfview->setModel(info);
}

//button upload
void MainWindow::on_photo_clicked()
{
    QString picpath=QFileDialog::getOpenFileName(this,tr("Open file"),"c://","JPG File(*.jpg);;PNG File(*.png)");
    int cin=ui->cin->text().toInt();
    QSqlQuery query;
    query.prepare("update adherent set pic=:picpath where cin=:cin");
    query.bindValue(":picpath",picpath);
    query.bindValue(":cin",cin);
    query.exec();
}

//images de ajout
void MainWindow::on_aff_clicked()
{
    QSqlQuery qry;
    int cin=ui->cin->text().toInt();
    qry.prepare("select * from adherent where cin=:cin");
    qry.bindValue(":cin",cin);
    if(qry.exec())
    {
        while(qry.next())
        {
            QPixmap photo;
            QString location=qry.value(6).toString();
            photo.load(location);
            ui->pic->setPixmap(photo);
            ui->pic->setScaledContents(true);
        }
    }
}

//button generer pdf
void MainWindow::on_pdf_clicked()
{
    //lemplacement de fichier a enregistrer
    QPdfWriter pdf("aziz.pdf");
    QPainter print(&pdf);

    //recherche des information a printer
    int rech=ui->cin_pdf->currentText().toInt();
    QSqlQuery query;
    query.prepare("select * from adherent where cin=:cin");
    query.bindValue(":cin",rech);

    QString cin,nom,prenom,date,email,genre;
    //ajout des donnee dans les variables
    if(query.exec())
    {
        while (query.next())
        {
            cin=query.value(0).toString();
            nom=query.value(1).toString();
            prenom=query.value(2).toString();
            date=query.value(3).toString();
            email=query.value(4).toString();
            genre=query.value(5).toString();
            qDebug()<<cin;
        }
    }
    //creation de design de fichier
    print.setBackgroundMode(Qt::OpaqueMode);
    //ajout dun image
    print.drawPixmap(QRect(7400,0,2000,2000),QPixmap("logo.png"));
    //contenu
    print.setPen(Qt::black);
    print.setFont(QFont("Arial", 20));
    print.drawText(3500,1000,"Fiche adherent");
    print.setFont(QFont("Arial", 10));
    print.setPen(Qt::black);
    print.drawText(3500,3000,"Cin:");
    print.setPen(Qt::black);
    print.drawText(3900,3000,cin);
    print.setPen(Qt::black);
    print.drawText(3500,3400,"Nom:");
    print.setPen(Qt::black);
    print.drawText(4100,3400,nom);
    print.setPen(Qt::black);
    print.drawText(3500,3800,"Prenom:");
    print.setPen(Qt::black);
    print.drawText(4200,3800,prenom);
    print.setPen(Qt::black);
    print.drawText(3500,4200,"Date de naissance:");
    print.setPen(Qt::black);
    print.drawText(5000,4200,date);
    print.setPen(Qt::black);
    print.drawText(3500,4600,"Adresse Email:");
    print.setPen(Qt::black);
    print.drawText(4800,4600,email);
    print.setPen(Qt::black);
    print.drawText(3500,5000,"Genre:");
    print.setPen(Qt::black);
    print.drawText(4100,5000,genre);
    print.setPen(Qt::black);
    print.drawRect(3200,2500,3000,3000);

    print.end();
}

//button statiqtique
void MainWindow::on_stat_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from adherent where genre='Male' ");
    int number1=model->rowCount(); //calculer la somme des adherent de genre male
    model->setQuery("select * from adherent where genre='Female' ");
    int number2=model->rowCount(); //calculer la somme des adherent de genre female

    //nombre des male*100/nombre des genres
    int total=number1+number2;
    QString a = QString("male  "+QString::number((number1*100)/total,'f',2)+"%");
    QString b = QString("female "+QString::number((number2*100)/total,'f',2)+"%");

    //charte pie style
    QPieSeries *series = new QPieSeries();
    series->append(a,number1); //te9sem charte graphique
    series->append(b,number2);

    if (number1!= 0)
    {
        //partie 1 de cercle
        QPieSlice *slice = series->slices().at(0);
        //affichage de pourcantage
        slice->setLabelVisible();
    }
    if (number2!=0)
    {
        //partie 2 de cercle
        QPieSlice *slice1 = series->slices().at(1);
        //affichage de pourcantage
        slice1->setLabelVisible();
    }
    //Create the chart widget
    QChart *chart = new QChart();
    //ajout des donnee et titre
    chart->addSeries(series);
    chart->setTitle("Pourcentage des genres");
    //afficher le charte avec sa parametre de taille
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(1000,500);
    chartView->show();
}

void MainWindow::dialog1()
{
    data=ar.read_from_arduino();
    qDebug()<<data;//affichage
    if(a.recherche_rfid(data)->rowCount()!=0)
    {
        QString nom;
        QSqlQuery qry;
        qry.prepare("select * from adherent where rfid LIKE '"+data+"'");
        if(qry.exec())
        {
            while(qry.next())
            {
                nom=qry.value(1).toString();
            }
        }
        QByteArray esem(nom.toUtf8(),6);
        qDebug()<<esem;//affichage
        ar.write_to_arduino(esem);
    }
    else
    {
        ar.write_to_arduino("nexiste pas!");
    }
    /* //temperature
    data=ar.read_from_arduino();
    qDebug()<<data;//affichage
    if(data=="1"){
        QMessageBox::information(nullptr, QObject::tr("Warning !"),QObject::tr("danger fumée"), QMessageBox::Close);
    }
    */
}

void MainWindow::on_home_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_gestion1_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_gestion2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_gestion3_clicked()
{
ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_gestion4_clicked()
{
ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_gestion5_clicked()
{//gestion reservation "a ne pas toucher"
ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_gestion6_clicked()
{
ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_ajout_emp_clicked()
{
    int ID = ui->id_emp->text().toInt();
    QString NOM = ui->nom_emp->text();
    QString PRENOM = ui->prenom_emp->text();
    QString POSTE = ui->comboBox_poste->currentText();
    QString ADRESSE_EMP = ui->adr_emp->text();
    QString EMAIL_EMP = ui->email_emp->text();
    QString PWD = ui->pass_emp->text();

    employe e(ID,NOM,PRENOM,POSTE,ADRESSE_EMP,EMAIL_EMP,PWD);
    bool test=e.ajouter_emp();
    if(test)
    {
        QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Ajout effectué\n""Click Cancel to exit."));
        ui->tab_employe->setModel(e.afficher_emp());
        ui->id_emp->clear();
        ui->nom_emp->clear();
        ui->prenom_emp->clear();
        ui->adr_emp->clear();
        ui->email_emp->clear();
        ui->pass_emp->clear();

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"), QObject::tr("Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_mod_emp_clicked()
{
    if ((ui->id_emp->text().isEmpty())or(ui->nom_emp->text().isEmpty())or(ui->prenom_emp->text().isEmpty())or(ui->comboBox_poste->currentText().isEmpty())or(ui->adr_emp->text().isEmpty())or(ui->email_emp->text().isEmpty()))
    {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("missing details\n""click to Cancel to exit."), QMessageBox::Cancel);

    }
    else
    {
        int ID = ui->id_emp->text().toInt();
        QString NOM = ui->nom_emp->text();
        QString PRENOM = ui->prenom_emp->text();
        QString POSTE = ui->comboBox_poste->currentText();
        QString Email_EMP = ui->email_emp->text();
        QString ADRESSE_EMP = ui->adr_emp->text();
        QString PWD = ui->pass_emp->text();
        employe e1(ID,NOM,PRENOM,POSTE,Email_EMP,ADRESSE_EMP,PWD);
        bool test=e1.modifier_emp(ID);
        if (test)
        {
            ui->tab_employe->setModel(e.afficher_emp());
            QMessageBox::information(nullptr,QObject::tr("done"),QObject::tr("modification effectué\n""click to Cancel to exit."), QMessageBox::Cancel);
            ui->id_emp->clear();
            ui->nom_emp->clear();
            ui->prenom_emp->clear();
            ui->adr_emp->clear();
            ui->email_emp->clear();
            ui->pass_emp->clear();
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("not done"),QObject::tr("modification non effectué.\n" "click to cancel to exit."),QMessageBox::Cancel);
    }
}

void MainWindow::on_pb_recherche_clicked()
{
    int ID=ui->id_emp->text().toInt();
    ui->tab_employe->setModel(e.rechercher_id_emp(ID));
    ui->id_emp->clear();
}

void MainWindow::on_tri_id_emp_clicked()
{
    ui->tab_employe->setModel(e.tri_id_c());
}

void MainWindow::on_pb_trier_clicked()
{
    ui->tab_employe->setModel(e.tri_nom_c());
}

void MainWindow::on_pb_trier_2_clicked()
{
    ui->tab_employe->setModel(e.tri_nom_dec());
}

void MainWindow::on_pb_supprimer_clicked()
{
    int ID=ui->lineEdit_id_supp->text().toInt();
    QString recherche=ui->lineEdit_id_supp->text();
    bool test=e.supprimer_emp(ID);

    if (e.rechercherID_emp(recherche)->rowCount()!=0 and recherche.length()!=0)
    {
        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("Succès"),
                                     QObject::tr("Suppression effectué.\n"
                                                 "Cliquer sur Cancel to exit."), QMessageBox::Cancel);
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("ERREUR"),
                                  QObject::tr("Suppression non effectué !\n"
                                              "Cliquer sur Cancel to exit."), QMessageBox::Cancel);
        }
    }



    ui->tab_employe->setModel(e.afficher_emp());
    ui->lineEdit_id_supp->clear();
}

void MainWindow::on_pb_pdf_clicked()
{
    QSqlQuery query;

    QPdfWriter pdf("pdfemp.pdf");
    QImage image("images/logo.png");
    QImage image1("date.png");

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


void MainWindow::on_sta_pb_clicked()
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
    {
        QPieSlice *slice = series->slices().at(0);
        slice->setLabelVisible();
        slice->setPen(QPen());
        slice->setColor(WHITENESS);
        slice->setLabelFont(QFont("Calibri",15));
        slice->setLabelColor(QColor(WHITENESS));
    }

    if ( y!=0)
    {
        QPieSlice *slice = series->slices().at(1);
        slice->setLabelVisible();
        slice->setPen(QPen());
        slice->setLabelFont(QFont("Calibri",15));
    }
    if (w!=0)
    {
        QPieSlice *slice = series->slices().at(2);
        slice->setLabelVisible();
        slice->setPen(QPen());
        slice->setLabelFont(QFont("Calibri",15));
    }

    if (z!=0)
    {
        QPieSlice *slice = series->slices().at(3);
        slice->setLabelVisible();
        slice->setPen(QPen());
        slice->setLabelFont(QFont("Calibri",15));
        slice->setColor(QColor(BLACK_BRUSH));
    }

    QChart *chart = new QChart();


    chart->addSeries(series);
    chart->setTitle("Pourcentage des postes à l'entreprise");
    chart->setTitleFont(QFont("Ariel",25));


    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(1500,900);
    chartView->show();
}

void MainWindow::on_pb_ajouter_res_clicked()
{//boutton ajouter reservation
    if ((ui->lineEdit_CIN_3->text().isEmpty())or(ui->lineEdit_resID_3->text().isEmpty())or( ui->lineEdit_poste_3->text().isEmpty()))
        {
            QMessageBox::information(nullptr,QObject::tr("not ok"),QObject::tr("missing details\n""click to Cancel to exit."), QMessageBox::Cancel);

        }
        else{
        int resID=ui->lineEdit_resID_3->text().toInt();
        QDate datte=ui->lineEdit_datte_3->date();
        int CIN=ui->lineEdit_CIN_3->text().toUInt();
        int poste=ui->lineEdit_poste_3->text().toUInt();



        Reservation R(CIN,resID,poste,datte);
        bool test=R.ajouter();
                if (test)
        {QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("ajout effectué\n""click to Cancel to exit."), QMessageBox::Cancel);
                ui->tab_reservation_2->setModel(R.afficher());
                ui->lineEdit_resID_3->clear();
                ui->lineEdit_datte_3->clear();
                ui->lineEdit_poste_3->clear();
                ui->lineEdit_CIN_3->clear();   }
                    else
                {QMessageBox::critical(nullptr, QObject::tr("not ok"),QObject::tr("ajout non effectué.\n" "click to cancel to exit."),QMessageBox::Cancel);}

                    }
}

void MainWindow::on_pb_reload_2_clicked()
{// reload affichage reservation tableau
    ui->tab_reservation_2->setModel(R.afficher());
    ui->lineEdit_recherer_2->clear();
}



void MainWindow::on_pushButton_supprimer_2_clicked()
{//push boutton suprimier une reservation selon id
    Reservation R1;
    if (ui->lineEdit_resID_supp_3->text().isEmpty())
        {
            QMessageBox::information(nullptr,QObject::tr("not ok"),QObject::tr("missing details\n""click to Cancel to exit."), QMessageBox::Cancel);

        }
        else{

        int id=ui->lineEdit_resID_supp_3->text().toInt();
        QString recherche=ui->lineEdit_resID_supp_3->text();



        if (R1.recherche_resID(recherche)->rowCount()!=0 and recherche.length()!=0)

        {

            bool test=R1.supprimer(id);
    if (test){ui->tab_reservation_2->setModel(R.afficher());
           QMessageBox::information(nullptr, QObject::tr("Succès"),

        QObject::tr("Suppression effectué.\n"

          "Cliquer sur Cancel to exit."), QMessageBox::Cancel);

          }

          else

              {QMessageBox::critical(nullptr, QObject::tr("ERREUR"),

                                    QObject::tr("Suppression non effectué !\n"

                                      "Cliquer sur Cancel to exit."), QMessageBox::Cancel);}
    ui->lineEdit_resID_supp_3->clear();
    ui->lineEdit_modResID_2->clear();
    ui->lineEdit_modDatte_2->clear();
    ui->lineEdit_modposte_2->clear();
    ui->lineEdit_modCIN_2->clear();
} else
           { QMessageBox::critical(nullptr, QObject::tr("ERREUR"),

                                                 QObject::tr("Suppression non effectué il ne !\n"

                                                   "Cliquer sur Cancel to exit."), QMessageBox::Cancel);}
               ui->lineEdit_resID_supp_3->clear();
             ui->lineEdit_modResID_2->clear();
             ui->lineEdit_modDatte_2->clear();
             ui->lineEdit_modposte_2->clear();
             ui->lineEdit_modCIN_2->clear();
           ui->tab_reservation_2->setModel(R.afficher());

}
}




void MainWindow::on_rechercher_pb_2_clicked()
{// rechercher selo le CIN
    if (ui->lineEdit_recherer_2->text().isEmpty())
        {
            QMessageBox::information(nullptr,QObject::tr("not ok"),QObject::tr("missing details\n""click to Cancel to exit."), QMessageBox::Cancel);

        }
        else{
        QString val = ui->lineEdit_recherer_2->text();
       ui->tab_reservation_2->setModel(R.recherche_CIN(val));
}}


void MainWindow::on_pb_tri_resID_d_2_clicked()
{//trix decroissant selon les resID de reservation
     ui->tab_reservation_2->setModel(R.tri_resID_d());
}


void MainWindow::on_pb_trier_CIN_d_2_clicked()
{//trix decroissant selon les cin de reservation
    ui->tab_reservation_2->setModel(R.tri_CIN_d());
}

void MainWindow::on_pushButton_2_clicked()
{//trix croissant selon les resID de reservation
     ui->tab_reservation_2->setModel(R.tri_resID());
}

void MainWindow::on_pb_tri_CIN_2_clicked()
{//trix croissant selon les cin de reservation
    ui->tab_reservation_2->setModel(R.tri_CIN());
}

void MainWindow::on_pb_datte_c_2_clicked()
{//trix croisson selon les date de reservation
    ui->tab_reservation_2->setModel(R.tri_date_c());
}


void MainWindow::on_pb_datte_d_2_clicked()
{//trix decroissant selon les date de reservation
    ui->tab_reservation_2->setModel(R.tri_date_d());
}

void MainWindow::on_tab_reservation_2_activated(const QModelIndex &index)
{// click sur une reservation dans le tableau -> les afficher sur tout les line edit
    QString val=ui->tab_reservation_2->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from reservation where resID LIKE '"+val+"'");

    if (qry.exec()){
 while (qry.next())
 {ui->lineEdit_modResID_2->setText(qry.value(0).toString());
 ui->lineEdit_modCIN_2->setText(qry.value(1).toString());
 ui->lineEdit_modposte_2->setText(qry.value(2).toString());
 ui->lineEdit_modDatte_2->setDate(qry.value(3).toDate());
 ui->lineEdit_resID_supp_3->setText(qry.value(0).toString());
 }
 }
    else {QMessageBox::critical(nullptr, QObject::tr("not done"),QObject::tr("echec affichage.\n" "click to cancel to exit."),QMessageBox::Cancel);}
}


void MainWindow::on_calendar_2_clicked(const QDate &date)
{
    ui->tableView_agenda_2->setModel(R.recherche_datte(date));
            /*QTableView tableView // il n'affiche pas une nouvelle fenetre jsp pk
                 tableView.setModel(R.recherche_datte(date));
                 tableView.show();*/
}

void MainWindow::on_pb_calculatrice_clicked()
{//afficher la calculatrice  dans une fenetre

    calculatrice c;
    c.exec();
}

void MainWindow::on_pb_pdf_reservation_clicked()
{//generer un pdf pour reservation
    QPdfWriter pdf("stat_reservation.pdf");

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


void MainWindow::on_pb_stat_reservation_clicked()
{// afficher les stat selon les semestre
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM reservation WHERE extract(month from datte) BETWEEN 1 AND 6 ");
    int number1=model->rowCount(); //calculer la somme des adherent de genre male
    model->setQuery("SELECT * FROM reservation WHERE extract(month from datte) BETWEEN 7 AND 12 ");
    int number2=model->rowCount(); //calculer la somme des adherent de genre female

    //nombre des male*100/nombre des genres
    int total=number1+number2;
    QString a = QString("semstre 1 est de  "+QString::number((number1*100)/total,'f',2)+"%");
    QString b = QString("semestre 2 est de  "+QString::number((number2*100)/total,'f',2)+"%");

    //charte pie style
    QPieSeries *series = new QPieSeries();
    series->append(a,number1); //te9sem charte graphique
    series->append(b,number2);

    if (number1!= 0)
    {
        //partie 1 de cercle
        QPieSlice *slice = series->slices().at(0);
        //affichage de pourcantage
        slice->setLabelVisible();
    }
    if (number2!=0)
    {
        //partie 2 de cercle
        QPieSlice *slice1 = series->slices().at(1);
        //affichage de pourcantage
        slice1->setLabelVisible();
    }
    //Create the chart widget
    QChart *chart = new QChart();
    //ajout des donnee et titre
    chart->addSeries(series);
    chart->setTitle("Pourcentage des reservation selon semstre");
    //afficher le charte avec sa parametre de taille
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(1000,500);
    chartView->show();
}


//********Fourniss***



void MainWindow::on_button_ajouter_clicked()
{

 int id=ui->lineEdit_ID->text().toInt();
 int quantite=ui->le_quantite->text().toInt();
 int prix=ui->le_prix->text().toInt();
 QString nom=ui->le_nom->text();
 QString email=ui->le_email->text();
 QString adresse=ui->le_adresse->text();
 Fournisseur s(id,quantite,prix,nom,adresse,email);
   bool test=s.ajouter();
   /*if(s.verifieremail(email)==false){
       test=false;
         QMessageBox::critical(nullptr,QObject::tr("email incorrect"),QObject::tr("ajout non effectue\n""click cancel to exit"),QMessageBox::Cancel);
   }*/

    if(test){
        //refresh
        ui->tabE->setModel(Etmp.afficher(false,NULL));
         ui->comboBoxID->setModel(Etmp.afficherCB());
         ui->le_prix->clear();
         ui->le_nom->clear();
         ui->le_email->clear();
         ui->le_quantite->clear();
         ui->lineEdit_ID->clear();
         ui->le_adresse->clear();
        QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("ajout effectue\n""click cancel to exit"),QMessageBox::Cancel);
    }else{
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("ajout non effectue\n""click cancel to exit"),QMessageBox::Cancel);
    }
}

void MainWindow::on_pbSupprimer_clicked()
{
    int sup=ui->lineEdit_ID->text().toInt();
    bool test=Etmp.supprimer(sup);
    if(test){
         ui->tabE->setModel(Etmp.afficher(false,NULL));
          ui->comboBoxID->setModel(Etmp.afficherCB());
          ui->le_prix->clear();
          ui->le_nom->clear();
          ui->le_email->clear();
          ui->le_quantite->clear();
          ui->lineEdit_ID->clear();
          ui->le_adresse->clear();
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("Suppression effectues\n""click cancel to exit"),QMessageBox::Cancel);
    }else{
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("suppression non effectue\n""click cancel to exit"),QMessageBox::Cancel);
    }


}

void MainWindow::on_updateBP_clicked()
{
    int up=ui->lineEdit_ID->text().toInt();
    int quantite=ui->le_quantite->text().toInt();
    int prix=ui->le_prix->text().toInt();
    QString nom=ui->le_nom->text();
    QString email=ui->le_email->text();
    QString adresse=ui->le_adresse->text();
    Fournisseur s(up,quantite,prix,nom,adresse,email);
    bool test=s.update(up);
    if(test){
         ui->tabE->setModel(Etmp.afficher(false,NULL));
ui->le_prix->clear();
ui->le_adresse->clear();
ui->le_email->clear();
ui->le_quantite->clear();
ui->lineEdit_ID->clear();
ui->le_nom->clear();
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("update effectues\n""click cancel to exit"),QMessageBox::Cancel);
    }else{
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("update non effectue\n""click cancel to exit"),QMessageBox::Cancel);
    }
}

void MainWindow::on_comboBoxID_currentIndexChanged(const QString &arg1)
{
    int id=ui->comboBoxID->currentText().toInt();
     QSqlQuery query;
     query.prepare("SELECT * FROM Fournisseur WHERE ID=:id");
     query.bindValue(":id",id);
   if(query.exec()){
       while(query.next()){
          QString id=query.value(0).toString();
            QString quantite =query.value(4).toString();
              QString prix=query.value(5).toString();
                QString nom=query.value(1).toString();
                  QString adresse=query.value(3).toString();
                    QString email=query.value(2).toString();
           ui->lineEdit_ID->setText(id);
            ui->le_nom->setText(nom);
            ui->le_prix->setText(prix);
            ui->le_quantite->setText(quantite);
            ui->le_email->setText(email);
            ui->le_adresse->setText(adresse);
       }
   }


}

void MainWindow::on_pdfPb_clicked()
{
    bool test= Etmp.pdf();
    if(test){

        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("pdf generated\n""click cancel to exit"),QMessageBox::Cancel);
    }else{
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("pdf not generated\n""click cancel to exit"),QMessageBox::Cancel);
    }


}



void MainWindow::on_emailpb_clicked()
{
    Di = new dialog(this);
    Di->show();
}

void MainWindow::on_rechercherpb_clicked()
{
   QString search= ui->le_recherche->text();

    ui->tabE->setModel(Etmp.afficher(true,search));
}






void MainWindow::on_check_quantite_clicked()
{
    if(ui->check_quantite->isChecked()){
        ui->tabE->setModel(Etmp.triQuantite());
        ui->tabE->show();
        QMessageBox::information(nullptr,QString("tri done"),QObject::tr("tri by quantite done \n""click cancel to exit"),QMessageBox::Cancel);

    }else{
        ui->tabE->setModel(Etmp.afficher(false,NULL));
        QMessageBox::information(nullptr,QString("bye"),QObject::tr("released \n""click cancel to exit"),QMessageBox::Cancel);
    }
}

void MainWindow::on_check_prix_clicked()
{
    if(ui->check_prix->isChecked()){
        ui->tabE->setModel(Etmp.triPrix());
        ui->tabE->show();
        QMessageBox::information(nullptr,QString("tri done"),QObject::tr("tri by PRI done \n""click cancel to exit"),QMessageBox::Cancel);

    }else{
        ui->tabE->setModel(Etmp.afficher(false,NULL));
        QMessageBox::information(nullptr,QString("bye"),QObject::tr("released \n""click cancel to exit"),QMessageBox::Cancel);
    }
}



void MainWindow::on_check_ID_clicked()
{

       if(ui->check_ID->isChecked()){
           ui->tabE->setModel(Etmp.triID());
           ui->tabE->show();
           QMessageBox::information(nullptr,QString("tri done "),QObject::tr("tri by id done \n""click cancel to exit"),QMessageBox::Cancel);

       }else{
           ui->tabE->setModel(Etmp.afficher(false,NULL));
           QMessageBox::information(nullptr,QString("bye"),QObject::tr("released \n""click cancel to exit"),QMessageBox::Cancel);
       }
}








void MainWindow::on_map_clicked()
{
    m=new Map(this);
    m->show();

}

void MainWindow::on_afficher_clicked()
{ui->tabE->setModel(Etmp.afficher(false,NULL));
}

void MainWindow::on_detection_clicked()
{E = new Detecteur(this);
    E->show();

}

void MainWindow::on_whatsapp_pb_clicked()
{
    QDesktopServices::openUrl(QUrl("https://wa.me/+21655029116", QUrl::TolerantMode));
}


//******Materiels*******


void MainWindow::on_bajouter_clicked()
{
    int id_materiel=ui->l1->text().toInt();
    QString type=ui->l2->currentText();
    int nombre=ui->l3->text().toInt();
    QDate date_arriv=ui->l4->date();
    Materiels M (id_materiel, type, nombre, date_arriv);
    bool test=M.ajouter();
    if (test)
    {
        QMessageBox :: information(nullptr, QObject ::tr("ok"),QObject::tr("ajout effectue, click cancel to exit."), QMessageBox::Cancel );
        ui->tab->setModel(M.afficher());
        ui->l1->clear();
        ui->l3->clear();

    }
    else
    {
        QMessageBox :: critical(nullptr, QObject ::tr("not ok"),QObject::tr("ajout non effectue, click cancel to exit."), QMessageBox::Cancel );
    }
}


void MainWindow::on_bsupprimer_clicked()
{

    int idM =ui->l1->text().toInt();
    bool test=M.supprimer(idM);
    if (test)
    {
        QMessageBox :: information(nullptr, QObject ::tr("ok"),QObject::tr("suppression effectue, click cancel to exit."), QMessageBox::Cancel );
        ui->tab->setModel(M.afficher());
        ui->l1->clear();
    }
    else
    {
        QMessageBox :: critical(nullptr, QObject ::tr("not ok"),QObject::tr("suppression non effectue, click cancel to exit."), QMessageBox::Cancel );
    }

}

void MainWindow::on_bmodifier_clicked()
{
        int id_materiel=ui->l1->text().toInt();
        QString type=ui->l2->currentText();
        int nombre=ui->l3->text().toInt();
        QDate date_arriv=ui->l4->date();
        Materiels M(id_materiel,type,nombre,date_arriv);
        bool test=M.update(id_materiel);
        if(test)
        {
            ui->tab->setModel(M.afficher());
            QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("update effectues\n""click cancel to exit"),QMessageBox::Cancel);
            ui->l1->clear();
            ui->l3->clear();
        }
        else
        {
            QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("update non effectue\n""click cancel to exit"),QMessageBox::Cancel);
        }
}


void MainWindow::on_bpdf_clicked()
{
    M.telechargerPDF();
    QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Téléchargement terminé"), QMessageBox::Cancel);
}

void MainWindow::on_lrecherche_textChanged(const QString &arg1)
{
    QString rech = ui->lrecherche->text();
                     M.recherche(ui->tab,rech);
                     if (ui->lrecherche->text().isEmpty())
                     {
                         ui->tab->setModel(M.afficher());
                     }
}

void MainWindow::on_tridate_clicked()
{
    ui->tab->setModel(M.tri_date());
}

void MainWindow::on_trinombre_clicked()
{
   ui->tab->setModel(M.tri_nombre());
}

void MainWindow::on_triid_clicked()
{
    ui->tab->setModel(M.tri_id());
}



/*void MainWindow::on_bstat_clicked()
{
    QMessageBox::information(nullptr,QObject::tr("OK stat"),QObject::tr("Téléchargement terminé"), QMessageBox::Cancel);
    QSqlQueryModel * model= new QSqlQueryModel();
          model->setQuery("select * from MATERIELS where salaire >= 1000");
          float dispo1=model->rowCount();

          model->setQuery("select * from MATERIELS where salaire <1000");
          float dispo=model->rowCount();

          float total=dispo1+dispo;
              QString a=QString("Cadre . " +QString::number((dispo1*100)/total,'f',2)+"%" );
              QString b=QString("employee .  "+QString::number((dispo*100)/total,'f',2)+"%" );
              QPieSeries *series = new QPieSeries();
              series->append(a,dispo1);
              series->append(b,dispo);
          if (dispo1!=0)
          {
              QPieSlice *slice = series->slices().at(0);
              slice->setLabelVisible();
              slice->setPen(QPen());}
          if ( dispo!=0)
          {
              QPieSlice *slice1 = series->slices().at(1);
              slice1->setLabelVisible();
          }

          QChart *chart = new QChart();


          chart->addSeries(series);
          chart->setTitle("Salaire des employes :Nb employes: "+ QString::number(total));



          QChartView *chartView = new QChartView(chart);
          chartView->setRenderHint(QPainter::Antialiasing);
          chartView->resize(1000,500);
          chartView->show();

   }*/



void MainWindow::on_pushButton_clicked()
{
    E=new Detecteur(this);
    E->show();
}


void MainWindow::on_bcatalogue_clicked()
{
    C=new catalogue(this);
    C->show();
}

void MainWindow::on_bexcel_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                    tr("Excel Files (*.xls)"));
    if (fileName.isEmpty())
        return;

    ExportExcelObject obj(fileName, "mydata", ui->tab);

    //colums to export
    obj.addField(0, "entier", "char(20)");
    obj.addField(1, "reel", "char(20)");
    obj.addField(2, "combobox", "char(20)");
    obj.addField(3, "lineedit", "char(20)");
    obj.addField(4, "textedit", "char(20)");
    obj.addField(5, "dateedit", "char(20)");
    obj.addField(5, "timeedit", "char(20)");


    int retVal = obj.export2Excel();
    if( retVal > 0)
    {
        QMessageBox::information(this, tr("Done"),
                                 QString(tr("%1 records exported!")).arg(retVal)
                                 );
    }
}


//

void MainWindow::on_pbAjoutEsp_clicked()
{
    int id=ui->id_ajoutEsp->text().toInt();
    int nb=ui->nb_ajoutEsp->text().toInt();
    QString bloc=ui->bloc_ajoutEsp->text();
    QDate date=ui->date_ajoutEsp->date();

    espace e(id,nb,bloc,date);

    bool test=e.ajouter();

    if(test)
    {
        ui->tableAffich->setModel(Esp.afficher());
        ui->combo_modifEsp->setModel(Esp.afficher2());
        ui->comboMap->setModel(Esp.afficher2());
        QGraphicsScene *scene = new QGraphicsScene;
        QVector<QGraphicsPixmapItem*> vector;
        for(int i=0;i<Esp.getNb();i++)
        {
            QPixmap pix(free_list[i]);
            QGraphicsPixmapItem *pic;
            pic = scene->addPixmap(pix);
            vector.push_back(pic);
        }
        ui->tableAffich->sortByColumn(1, Qt::AscendingOrder);
        int index;
        for(index = 0;index<ui->tableAffich->model()->rowCount();index++)
        {
            if(ui->tableAffich->model()->index(index,0).data().toInt() == index)
                break;
        }
        qDebug() << "done";
        pic_list.insert(pic_list.begin()+index,vector);
        scene_list.insert(scene_list.begin()+index,scene);

        //chartview = statSalle();
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout effectue\n"
                                             "Click Cancel to exit."), QMessageBox::Ok);
        ui->id_ajoutEsp->clear();
        ui->nb_ajoutEsp->clear();
        ui->bloc_ajoutEsp->clear();
    }

}
void MainWindow::statistique()
{
    QBarSet *set0 = new QBarSet("bloc a");
    QBarSet *set1 = new QBarSet("bloc b");
    QBarSet *set2 = new QBarSet("bloc c");
    QBarSet *set3 = new QBarSet("bloc d");

    *set0 << 30;
    *set1 << 40;
    *set2 << 60;
    *set3 << 40;

    QBarSet *set02 = new QBarSet("bloc ;");
    QBarSet *set12 = new QBarSet("bloc j");
    QBarSet *set22 = new QBarSet("bloc i");
    QBarSet *set32 = new QBarSet("bloc d");

    *set02 << 70;
    *set12 << 56;
    *set22 << 50;
    *set32 << 58;

    QBarSeries *series = new QBarSeries();
    series->append(set0);
    series->append(set1);
    series->append(set2);
    series->append(set3);

    QBarSeries *series2 = new QBarSeries();
    series2->append(set02);
    series2->append(set12);
    series2->append(set22);
    series2->append(set32);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("nombre de salle selon bloc");

    chart->setAnimationOptions(QChart::SeriesAnimations);

    QChart *chart2 = new QChart();
    chart2->addSeries(series2);
    chart2->setTitle("nombre de salle selon bloc");



    QChartView *chartView = new QChartView(chart);
    QChartView *chartView2 = new QChartView(chart2);

    //chartView->setParent(ui->horizontalFrame);
    //chartView2->setParent(ui->horizontalFrame_2);
}

QChart * MainWindow::statSalle()
{
    QMap <QChar,int> blocs;
    bool exist=false;
    //qDebug() << ui->tableAffich->model()->rowCount();
    for(int i=0;i<ui->tableAffich->model()->rowCount();i++)
    {
        QMap<QChar,int>::iterator it;
        for(it=blocs.begin();it!=blocs.end();++it)
        {
            if(ui->tableAffich->model()->index(i,2).data().toString()[0]==it.key())
                exist = true;
        }
        if(exist)
        {
            blocs[ui->tableAffich->model()->index(i,2).data().toString()[0]]++;
            exist = false;
        }
        else
        {
            QChar ch= ui->tableAffich->model()->index(i,2).data().toString()[0];
            blocs.insert(ch,1);
        }
    }
    //QChar ch= ui->tableAffich->model()->index(0,2).data().toString()[0];
    int salles=0;
    QMap<QChar,int>::iterator it;
    for(it=blocs.begin();it!=blocs.end();++it)
    {
        salles+=it.value();
    }

    QVector<QBarSet*> sets;
    for(it=blocs.begin();it!=blocs.end();++it)
    {
        float stat;
        stat = (it.value()*100/salles);
        qDebug() << stat;
        QBarSet *set = new QBarSet(QString(it.key()));
        *set << stat;
        sets.push_back(set);
    }

    QBarSeries *series = new QBarSeries();

    for(int i=0;i<sets.size();i++)
    {
        series->append(sets[i]);
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Pourcentage de salles par bloc.");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    //QBarCategoryAxis *axis = new QBarCategoryAxis();
    chart->createDefaultAxes();
    QChartView *chartView = new QChartView(chart);
    chartView->setParent(ui->horizontalFrame_salles);

    return chart;
}

QChart * MainWindow::statPlace()
{
    QMap <QChar,int> blocs;
    bool exist=false;
    //qDebug() << ui->tableAffich->model()->rowCount();
    for(int i=0;i<ui->tableAffich->model()->rowCount();i++)
    {
        QMap<QChar,int>::iterator it;
        for(it=blocs.begin();it!=blocs.end();++it)
        {
            if(ui->tableAffich->model()->index(i,2).data().toString()[0]==it.key())
                exist = true;
        }
        if(exist)
        {
            blocs[ui->tableAffich->model()->index(i,2).data().toString()[0]]+=ui->tableAffich->model()->index(i,1).data().toInt();
            exist = false;
        }
        else
        {
            QChar ch= ui->tableAffich->model()->index(i,2).data().toString()[0];
            blocs.insert(ch,ui->tableAffich->model()->index(i,1).data().toInt());
        }
    }
    //QChar ch= ui->tableAffich->model()->index(0,2).data().toString()[0];
    int places=0;
    QMap<QChar,int>::iterator it;
    for(it=blocs.begin();it!=blocs.end();++it)
    {
        places+=it.value();
    }

    QVector<QBarSet*> sets;
    for(it=blocs.begin();it!=blocs.end();++it)
    {
        float stat;
        stat = (it.value()*100/places);
        qDebug() << stat;
        QBarSet *set = new QBarSet(QString(it.key()));
        *set << stat;
        sets.push_back(set);
    }

    QBarSeries *series = new QBarSeries();

    for(int i=0;i<sets.size();i++)
    {
        series->append(sets[i]);
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Pourcentage de places par bloc.");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    //QBarCategoryAxis *axis = new QBarCategoryAxis();
    chart->createDefaultAxes();
    QChartView *chartView = new QChartView(chart);
    chartView->setParent(ui->horizontalFrame_places);

    return chart;
}

void MainWindow::setBusyList()
{
    QString const pix1_busy =":/busy/busy/1.png";
    QString const pix2_busy  =":/busy/busy/2.png";
    QString const pix3_busy  =":/busy/busy/3.png";
    QString const pix4_busy  =":/busy/busy/4.png";
    QString const pix5_busy =":/busy/busy/5.png";
    QString const pix6_busy =":/busy/busy/6.png";
    QString const pix7_busy =":/busy/busy/7.png";
    QString const pix8_busy =":/busy/busy/8.png";
    QString const pix9_busy =":/busy/busy/9.png";
    QString const pix10_busy =":/busy/busy/10.png";
    QString const pix11_busy =":/busy/busy/11.png";
    QString const pix12_busy =":/busy/busy/12.png";
    QString const pix13_busy =":/busy/busy/13.png";
    QString const pix14_busy =":/busy/busy/14.png";
    QString const pix15_busy =":/busy/busy/15.png";
    QString const pix16_busy =":/busy/busy/16.png";
    QString const pix17_busy =":/busy/busy/17.png";
    QString const pix18_busy =":/busy/busy/18.png";
    QString const pix19_busy =":/busy/busy/19.png";
    QString const pix20_busy =":/busy/busy/20.png";
    QString const pix21_busy =":/busy/busy/21.png";
    QString const pix22_busy =":/busy/busy/22.png";
    QString const pix23_busy =":/busy/busy/23.png";
    QString const pix24_busy =":/busy/busy/24.png";
    QString const pix25_busy =":/busy/busy/25.png";
    QString const pix26_busy =":/busy/busy/26.png";
    QString const pix27_busy =":/busy/busy/27.png";
    QString const pix28_busy =":/busy/busy/28.png";
    QString const pix29_busy =":/busy/busy/29.png";
    QString const pix30_busy =":/busy/busy/30.png";


    busy_list.push_back(pix1_busy);
    busy_list.push_back(pix2_busy);
    busy_list.push_back(pix3_busy);
    busy_list.push_back(pix4_busy);
    busy_list.push_back(pix5_busy);
    busy_list.push_back(pix6_busy);
    busy_list.push_back(pix8_busy);
    busy_list.push_back(pix9_busy);
    busy_list.push_back(pix10_busy);
    busy_list.push_back(pix12_busy);
    busy_list.push_back(pix13_busy);
    busy_list.push_back(pix14_busy);
    busy_list.push_back(pix15_busy);
    busy_list.push_back(pix16_busy);
    busy_list.push_back(pix17_busy);
    busy_list.push_back(pix18_busy);
    busy_list.push_back(pix19_busy);
    busy_list.push_back(pix20_busy);
    busy_list.push_back(pix21_busy);
    busy_list.push_back(pix22_busy);
    busy_list.push_back(pix23_busy);
    busy_list.push_back(pix24_busy);
    busy_list.push_back(pix25_busy);
    busy_list.push_back(pix26_busy);
    busy_list.push_back(pix27_busy);
    busy_list.push_back(pix28_busy);
    busy_list.push_back(pix29_busy);
    busy_list.push_back(pix30_busy);
}

void MainWindow::setFreeList()
{
    QString const pix1_free = ":/free/free/1.png";
    QString const pix2_free =":/free/free/2.png";
    QString const pix3_free=":/free/free/3.png";
    QString const pix4_free =":/free/free/4.png";
    QString const pix5_free =":/free/free/5.png";
    QString const pix6_free =":/free/free/6.png";
    QString const pix7_free =":/free/free/7.png";
    QString const pix8_free =":/free/free/8.png";
    QString const pix9_free =":/free/free/9.png";
    QString const pix10_free =":/free/free/10.png";
    QString const pix11_free =":/free/free/11.png";
    QString const pix12_free =":/free/free/12.png";
    QString const pix13_free =":/free/free/13.png";
    QString const pix14_free =":/free/free/14.png";
    QString const pix15_free =":/free/free/15.png";
    QString const pix16_free =":/free/free/16.png";
    QString const pix17_free =":/free/free/17.png";
    QString const pix18_free =":/free/free/18.png";
    QString const pix19_free =":/free/free/19.png";
    QString const pix20_free =":/free/free/20.png";
    QString const pix21_free =":/free/free/21.png";
    QString const pix22_free =":/free/free/22.png";
    QString const pix23_free =":/free/free/23.png";
    QString const pix24_free =":/free/free/24.png";
    QString const pix25_free =":/free/free/25.png";
    QString const pix26_free =":/free/free/26.png";
    QString const pix27_free =":/free/free/27.png";
    QString const pix28_free =":/free/free/28.png";
    QString const pix29_free =":/free/free/29.png";
    QString const pix30_free =":/free/free/30.png";




    free_list.push_back(pix1_free);
    free_list.push_back(pix2_free);
    free_list.push_back(pix3_free);
    free_list.push_back(pix4_free);
    free_list.push_back(pix5_free);
    free_list.push_back(pix6_free);
    free_list.push_back(pix7_free);
    free_list.push_back(pix8_free);
    free_list.push_back(pix9_free);
    free_list.push_back(pix10_free);
    free_list.push_back(pix11_free);
    free_list.push_back(pix12_free);
    free_list.push_back(pix13_free);
    free_list.push_back(pix14_free);
    free_list.push_back(pix15_free);
    free_list.push_back(pix16_free);
    free_list.push_back(pix17_free);
    free_list.push_back(pix18_free);
    free_list.push_back(pix19_free);
    free_list.push_back(pix20_free);
    free_list.push_back(pix21_free);
    free_list.push_back(pix22_free);
    free_list.push_back(pix23_free);
    free_list.push_back(pix24_free);
    free_list.push_back(pix25_free);
    free_list.push_back(pix26_free);
    free_list.push_back(pix27_free);
    free_list.push_back(pix28_free);
    free_list.push_back(pix29_free);
    free_list.push_back(pix30_free);
}

void MainWindow::update(){
QString data1;
   // data1=a.read_from_arduino();
    //serialbuffer +=QString::fromStdString(data.toStdString());
      //qDebug() << serialbuffer;
    qDebug()<<data1;


  //delete from base where serial buffer exsist
      QSqlQuery query;
      query.prepare("delete from reservation where resID=:data1");
      query.bindValue(0,data1);
      if (query.exec()==false){
        //a.write_to_arduino("1");
      qDebug()<<"done" ;}
      else if (query.exec()==true)
      {//a.write_to_arduino("0");
         qDebug()<<"not done";
      }


    //data.toStdString();

    //if (data.size()==4)
    //{

    //}
}

void MainWindow::on_pbModifEsp_clicked()
{
    int ancien_nb=Esp.getNb();
    int id =ui->combo_modifEsp->currentText().toInt();
    int nb =ui->nb_modifEsp->text().toInt();
    QString bloc =ui->bloc_modifEsp->text();
    QDate date = ui->date_modifEsp->date();
    for(int i=0;i<ui->tableAffich->model()->rowCount();i++)
    {
        if(ui->tableAffich->model()->index(i,0).data().toInt()==id)
            ancien_nb=ui->tableAffich->model()->index(i,1).data().toInt();
    }

    espace e(id,nb,bloc,date);

    bool test=e.modifier();
    if (test)
    {
        ui->tableAffich->setModel(Esp.afficher());
        ui->comboMap->setModel(Esp.afficher2());
        ui->combo_modifEsp->setModel(Esp.afficher2());

        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Modification effectuee\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
        if(ancien_nb!=nb)
        {
            ui->tableAffich->sortByColumn(1, Qt::AscendingOrder);
            int index;
            for(index=0;index<ui->tableAffich->model()->rowCount();index++)
            {
                if(ui->tableAffich->model()->index(index,0).data().toInt()==id)
                    break;
            }
            QVector<QGraphicsPixmapItem*> vector;
            for(int i=0;i<pic_list[index].size();i++)
            {
                QPixmap pix(free_list[i]);
                QGraphicsPixmapItem* pic;
                pic = scene_list[index]->addPixmap(pix);
                vector.push_back(pic);
                pic_list[index] = vector;
            }
        }
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                              QObject::tr("Modification non effectuee.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_combo_modifEsp_currentIndexChanged(const QString &arg1)
{
    QString id_string = ui->combo_modifEsp->currentText();

    QSqlQuery qry;
    qry.prepare("select * from espaces where id='"+id_string+"'");
    if(qry.exec())
    {
        while(qry.next())
        {
            ui->nb_modifEsp->setText(qry.value(1).toString());
            ui->bloc_modifEsp->setText(qry.value(2).toString());
        }
    }
}

void MainWindow::on_pbSuppr_clicked()
{
    int id =ui->combo_modifEsp->currentText().toInt();
    bool test=Esp.supprimer(id);
    if (test)
    {
        ui->tableAffich->setModel(Esp.afficher());
        ui->comboMap->setModel(Esp.afficher2());
        ui->combo_modifEsp->setModel(Esp.afficher2());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Suppression effectuee\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
        int n= ui->combo_modifEsp->currentIndex();
        scene_list.erase(scene_list.begin()+n);
        pic_list.erase(pic_list.begin()+n);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                              QObject::tr("Suppression non effectuee.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_comboMap_currentIndexChanged(int index)
{
    if (l)
    {
        ui->graphicsView_map->setScene(scene_list[index]);
        QString id_string = ui->comboMap->currentText();
        QString places;
        QSqlQuery query;
        query.prepare("Select * from espaces where ID='"+id_string+"'");
        if(query.exec()){
            while(query.next())
            {
                places=query.value(4).toString();
            }

        }

    for(int i=0;i<pic_list[index].size();i++)
    {



       // QString places = ui->tableAffich->model()->index(index,4).data().toString();
        if(places[i]=='n')
        {
            QPixmap pix(busy_list[i]);
            pic_list[index][i]->setPixmap(pix);
        }
        else
        {
            QPixmap pix(free_list[i]);
            pic_list[index][i]->setPixmap(pix);
        }
    }
    }
    l=true;
}

void MainWindow::on_pbGauche_clicked()
{
    int n = ui->comboMap->currentIndex();
    QVector<QGraphicsPixmapItem*> vector= pic_list[n];


    for(int i=0;i<pic_list[n].size();i++)
    {
        if(pic_list[n][i]->isSelected())
        {
            pic_list[n][i]->setRotation(pic_list[n][i]->rotation()+45);
        }
    }
}

void MainWindow::on_pbDroite_clicked()
{
    int n = ui->comboMap->currentIndex();


    for(int i=0;i<pic_list[n].size();i++)
    {
        if(pic_list[n][i]->isSelected())
        {
            pic_list[n][i]->setRotation(pic_list[n][i]->rotation()-45);
        }
    }
}

void MainWindow::on_pbBusy_clicked()
{
    int n = ui->comboMap->currentIndex();
    for(int i=0;i<pic_list[n].size();i++)
    {
        if(pic_list[n][i]->isSelected())
        {
            QByteArray led;
            led.setNum(i);
            //a.write_to_arduino(led);
            QPixmap pix(busy_list[i]);
            pic_list[n][i]->setPixmap(pix);
            ui->tableAffich->sortByColumn(1, Qt::AscendingOrder);
            QString id_string = ui->comboMap->currentText();
            QString places;
            QSqlQuery query;
            query.prepare("Select * from espaces where ID='"+id_string+"'");
            if(query.exec()){
                while(query.next())
                {
                    places=query.value(4).toString();
                }

            }

            qDebug() << places;
            places[i]='n';
            qDebug() << places;
            //QSqlQuery query;
            query.prepare("Update espaces set places=:places where ID= :id");
            query.bindValue(":id",id_string);
            query.bindValue(":places",places);
            query.exec();
            ui->tableAffich->setModel(Esp.afficher());
            qDebug() << ui->tableAffich->model()->index(n,4).data();

        }
    }
}

void MainWindow::on_pbFree_clicked()
{
    int n = ui->comboMap->currentIndex();
    for(int i=0;i<pic_list[n].size();i++)
    {
        if(pic_list[n][i]->isSelected())
        {
            QByteArray led;
            led.setNum(i+5);
            //a.write_to_arduino(led);

            ui->tableAffich->sortByColumn(1, Qt::AscendingOrder);
            QString id_string = ui->comboMap->currentText();
            QString places;
            QSqlQuery query;
            query.prepare("Select * from espaces where ID='"+id_string+"'");
            if(query.exec()){
                while(query.next())
                {
                    places=query.value(4).toString();
                }

            }

            qDebug() << places;
            places[i]='o';
            qDebug() << places;
            //QSqlQuery query;
            query.prepare("Update espaces set places=:places where ID= :id");
            query.bindValue(":id",id_string);
            query.bindValue(":places",places);
            query.exec();
            ui->tableAffich->setModel(Esp.afficher());
            qDebug() << ui->tableAffich->model()->index(n,4).data();
        }
    }
}

void MainWindow::on_pbPDFEsp_clicked()
{
    //lemplacement de fichier a enregistrer
    QString filePath;
    filePath = QFileDialog::AcceptSave;
    filePath = QFileDialog::Directory;
    filePath= QFileDialog::getOpenFileName(this,tr("Emplacement du PDF"),
                                                    "C:/Users/Oussema/Desktop",
                                                    "PDF files (*.pdf);; All files (*.*)");
    QString _1,_2;
    _1="espace";
    _2=".pdf";

    QPdfWriter pdf(filePath+_1+ui->combo_modifEsp->currentText()+_2);
    QPainter print(&pdf);
    print.setRenderHint(QPainter::Antialiasing);

    //recherche des information a printer
    int id=ui->combo_modifEsp->currentText().toInt();
    QSqlQuery query;
    query.prepare("select * from espaces where id=:id");
    query.bindValue(":id",id);

    //QString cin,nom,prenom,date,email,genre;
    QString id_string,nb_string,bloc,date;
    //ajout des donnee dans les variables
    if(query.exec())
    {
            while (query.next())
            {
                id_string=query.value(0).toString();
                nb_string=query.value(1).toString();
                bloc=query.value(2).toString();
                date=query.value(3).toString();
            }
     }
    //creation de design de fichier
    print.setBackgroundMode(Qt::OpaqueMode);
    //ajout dun image
    print.drawPixmap(QRect(7400,0,2000,2000),QPixmap(":/img/logo.png"));
    //contenu
    print.setPen(Qt::black);
    print.setFont(QFont("Arial", 20));
    QString str = "Fiche espace ";
    print.drawText(3500,1000,str+ui->combo_modifEsp->currentText());
    print.setFont(QFont("Arial", 10));
    print.setPen(Qt::black);
    print.drawText(3500,3000,"ID:");
    print.setPen(Qt::black);
    print.drawText(3900,3000,id_string);
    print.setPen(Qt::black);
    print.drawText(3500,3400,"Nombre de places:");
    print.setPen(Qt::black);
    print.drawText(5000,3400,nb_string);
    print.setPen(Qt::black);
    print.drawText(3500,3800,"Bloc:");
    print.setPen(Qt::black);
    print.drawText(3900,3800,bloc);
    print.setPen(Qt::black);
    print.drawText(3500,4200,"Date:");
    print.setPen(Qt::black);
    print.drawText(4000,4200,date);
    print.setPen(Qt::black);
    print.drawRect(3200,2500,5000,3000);

    print.end();
}

void MainWindow::on_pbServer_clicked()
{
    ServerWindow * serverWin = new ServerWindow(nullptr);
    serverWin->show();
}

void MainWindow::on_pbChat_clicked()
{
    ChatWindow* chatWin = new ChatWindow(nullptr);
    chatWin->show();
}

void MainWindow::on_pbTrier_clicked()
{
    if(ui->cbTri->currentIndex()==0){
    if(ui->checkBox->isChecked())
    {
        if(ui->checkBox_2->isChecked())
        {
            if(ui->checkBox_3->isChecked())
            {
                ui->tableView->sortByColumn(2, Qt::AscendingOrder);
            }
            ui->tableView->sortByColumn(1, Qt::AscendingOrder);
        }
        else if(ui->checkBox_3->isChecked())
        {
            ui->tableView->sortByColumn(3, Qt::AscendingOrder);
        }
        ui->tableView->sortByColumn(0, Qt::AscendingOrder);
    }
    else if(ui->checkBox_2->isChecked())
    {

        if(ui->checkBox_3->isChecked())
        {
            ui->tableView->sortByColumn(2, Qt::AscendingOrder);
        }
        ui->tableView->sortByColumn(1, Qt::AscendingOrder);
    }
    else if(ui->checkBox_3->isChecked())
    {
        ui->tableView->sortByColumn(2, Qt::AscendingOrder);
    }
    }
    else if(ui->cbTri->currentIndex()==1)
    {
        if(ui->checkBox->isChecked())
        {
            if(ui->checkBox_2->isChecked())
            {
                if(ui->checkBox_3->isChecked())
                {
                    ui->tableView->sortByColumn(2, Qt::DescendingOrder);
                }
                ui->tableView->sortByColumn(1, Qt::DescendingOrder);
            }
            else if(ui->checkBox_3->isChecked())
            {
                ui->tableView->sortByColumn(3, Qt::DescendingOrder);
            }
            ui->tableView->sortByColumn(0, Qt::DescendingOrder);
        }
        else if(ui->checkBox_2->isChecked())
        {

            if(ui->checkBox_3->isChecked())
            {
                ui->tableView->sortByColumn(2, Qt::DescendingOrder);
            }
            ui->tableView->sortByColumn(1, Qt::DescendingOrder);
        }
        else if(ui->checkBox_3->isChecked())
        {
            ui->tableView->sortByColumn(2, Qt::DescendingOrder);
        }
    }
}

void MainWindow::on_pbRechercher_clicked()
{
    bool found = false;
    int taille =  ui->tableView->model()->rowCount();
    for(int i=0; i<taille ; i++)
    {
        if(ui->tableView->model()->index(i,0).data().toString() == ui->leRechercher->text())
        {
            ui->tableView->selectRow(i);
            found = true;
        }
    }
    if (!found)
    {
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                              QObject::tr("Inexistant!.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pbActualiserEsp_clicked()
{
    int index=ui->comboMap->currentIndex();
    ui->graphicsView_map->setScene(scene_list[index]);
    QString id_string = ui->comboMap->currentText();
    QString places;
    QSqlQuery query;
    query.prepare("Select * from espaces where ID='"+id_string+"'");
    if(query.exec()){
        while(query.next())
        {
            places=query.value(4).toString();
        }

    }

for(int i=0;i<pic_list[index].size();i++)
{



   // QString places = ui->tableAffich->model()->index(index,4).data().toString();
    if(places[i]=='n')
    {
        QByteArray led;
        led.setNum(1);
        //a.write_to_arduino(led);
        QPixmap pix(busy_list[i]);
        pic_list[index][i]->setPixmap(pix);
    }
    else
    {
        //a.write_to_arduino(ledOff[i]);
        QPixmap pix(free_list[i]);
        pic_list[index][i]->setPixmap(pix);
    }
}
}
