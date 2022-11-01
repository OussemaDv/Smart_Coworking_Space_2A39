#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(a.afficher());

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
    ui->cin_sup->setValidator(cin_valider);
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

void MainWindow::on_ajouter_clicked(){

    //recuperation des information
    int cin=ui->cin->text().toInt();
    QString nom=ui->nom->text();
    QString prenom=ui->prenom->text();
    QString date=ui->date->text();
    QString email=ui->email->text();


    adherents a(cin,nom,prenom,date,email);

    bool test=a.ajouter();

    if(test){
        //refrech
        ui->tableView->setModel(a.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("ajout effectué.\n click Close to exit."),QMessageBox::Close);
    }else{
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("ajout non effectué.\n click Close to exit."),QMessageBox::Close);
    }
}

void MainWindow::on_supprimer_clicked(){
    //recuperation de cin a supprimer
    int cin=ui->cin_sup->text().toInt();
    bool test=a.supprimer(cin);

    if(test){
        //refrech
        ui->tableView->setModel(a.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("suppression effectuer.\n" "click Close to exit."),QMessageBox::Close);
    }else{
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("suppresssion non effectuer.\n" "click Close to exit."),QMessageBox::Close);
    }
}

void MainWindow::on_modifier_clicked(){
    //recuperation des informlation
    int cin=ui->mod_cin->text().toInt();
    QString nom=ui->mod_nom->text();
    QString prenom=ui->mod_pren->text();
    QString date=ui->mod_date->text();
    QString email=ui->mod_email->text();

    adherents a(cin,nom,prenom,date,email);

    bool test=a.modifier(cin);
        if(test)
        {
            //refrech
            ui->tableView->setModel(a.afficher());
            QMessageBox::information(nullptr, QObject::tr("ok"),QObject::tr("Modification avec succes.\n" "Click Close to exit."), QMessageBox::Close);
    }else
            QMessageBox::critical(nullptr, QObject::tr("not ok"),QObject::tr("Modification echoue.\n" "Click Close to exit."), QMessageBox::Close);
}

void MainWindow::on_croissant_clicked(){
    ui->tableView->setModel(a.ordre_croissant());
}

void MainWindow::on_decroissant_clicked(){
    ui->tableView->setModel(a.ordre_decroissant());
}

