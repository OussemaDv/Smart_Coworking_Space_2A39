#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(a.afficher());
    ui->cin_supp->setModel(a.get_id());
    ui->mod_cin->setModel(a.get_id());
    ui->cin_qr->setModel(a.get_id());
    ui->cin_pdf->setModel(a.get_id());

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
     QString rech=ui->cin_pdf->currentText();

     QSqlQueryModel * info=new QSqlQueryModel();

     info->setQuery("select * from adherent where cin LIKE '"+rech+"'");

     info->setHeaderData(0,Qt::Horizontal,QObject::tr("Cin"));
     info->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
     info->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
     info->setHeaderData(3,Qt::Horizontal,QObject::tr("Date de naissance"));
     info->setHeaderData(4,Qt::Horizontal,QObject::tr("Email"));
     info->setHeaderData(5,Qt::Horizontal,QObject::tr("Genre"));

     ui->pdfview->setModel(info);
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
    QPdfWriter pdf("C:/Users/azizs/Desktop/aziz.pdf");
    QPainter print(&pdf);

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

    print.setPen(Qt::black);
    print.drawText(100,100,"adherent");
    print.setPen(Qt::blue);
    print.drawText(1000,100,400,145,0,cin);
    print.setPen(Qt::blue);
    print.drawText(1000,300,400,145,0,nom);
    print.setPen(Qt::blue);
    print.drawText(1000,600,400,145,0,prenom);
    print.setPen(Qt::blue);
    print.drawText(1000,900,400,145,0,date);
    print.setPen(Qt::blue);
    print.drawText(1000,1200,400,145,0,email);
    print.setPen(Qt::blue);
    print.drawText(1000,1200,400,145,0,genre);
    print.drawRect(1,3,40,34);
    //print.drawPixmap(QRect(0,0,1440,1440),QPixmap("C:/Users/azizs/Desktop/adherent/images/logo.png"));

    print.end();
}
//button statiqtique
void MainWindow::on_stat_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("select * from adherent where genre='Male' ");
     int number1=model->rowCount(); // calculer la somme des adherent de genre male
     model->setQuery("select * from adherent where genre='Female' ");
     int number2=model->rowCount(); // calculer la somme des adherent de genre female

     int total=number1+number2;
     QString a = QString("male  "+QString::number((number1*100)/total,'f',2)+"%");
     QString b = QString("female "+QString::number((number2*100)/total,'f',2)+"%");

     QPieSeries *series = new QPieSeries();
     series->append(a,number1); // te9sem charte graphique
     series->append(b,number2);

     if (number1!= 0)
     {
         QPieSlice *slice = series->slices().at(0); //bib doura
         slice->setLabelVisible();
         slice->setPen(QPen());
     }
     if (number2!=0)
     {
              // Add label, explode and define brush for 2nd slice
              QPieSlice *slice1 = series->slices().at(1);
              //slice1->setExploded();
              slice1->setLabelVisible();
     }
             // Create the chart widget
             QChart *chart = new QChart();
             // Add data to chart with title and hide legend
             chart->addSeries(series);
             chart->setTitle("pourcentage des genres");
             chart->legend()->hide();
             // Used to display the chart
             QChartView *chartView = new QChartView(chart);
             chartView->setRenderHint(QPainter::Antialiasing);
             chartView->resize(1000,500);
             chartView->show();
}
