#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "serverwindow.h"
#include "serverworker.h"
#include "chatserver.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /************Affichage********************/
    ui->tableView_affichage->setModel(Etmp.afficher());
    ui->tableView_affichage->sortByColumn(0, Qt::AscendingOrder);
    ui->comboBox_modification->setModel(Etmp.afficher2());
    ui->comboBox_map->setModel(Etmp.afficher2());
    ui->tableView_recherche->setModel(Etmp.afficher3());
    ui->tableView_recherche->setSortingEnabled(true);

    /************Controle de saisie********************/
    QValidator *validator = new QIntValidator(this);
    ui->lineEdit_ajout_id->setValidator(validator);
    ui->lineEdit_ajout_nb->setValidator(validator);
    ui->lineEdit_modification_nb->setValidator(validator);
    ui->lineEdit_ajout_id->setMaxLength(5);
    ui->lineEdit_ajout_bloc->setMaxLength(1);
    ui->lineEdit_modificatoin_bloc->setMaxLength(1);
    ui->dateEdit_ajout->setCalendarPopup(true);
    ui->dateEdit_modification->setCalendarPopup(true);

    /*************Pictures**********************************/
    QString const pic_free1 = ":/free/free/1.png";
    QString const pic_free2 = ":/free/free/2.png";
    QString const pic_free3 = ":/free/free/3.png";
    QString const pic_free4 = ":/free/free/4.png";
    QString const pic_free5 = ":/free/free/5.png";
    QString const pic_free6 = ":/free/free/6.png";
    QString const pic_free7 = ":/free/free/7.png";
    QString const pic_free8 = ":/free/free/8.png";
    QString const pic_free9 = ":/free/free/9.png";
    QString const pic_free10 = ":/free/free/10.png";
    QString const pic_free11= ":/free/free/11.png";
    QString const pic_free12 =":/free/free/12.png";
    QString const pic_free13= ":/free/free/13.png";
    QString const pic_free14= ":/free/free/14.png";
    QString const pic_free15= ":/free/free/15.png";
    QString const pic_free16= ":/free/free/16.png";
    QString const pic_free17= ":/free/free/17.png";
    QString const pic_free18= ":/free/free/18.png";
    QString const pic_free19= ":/free/free/19.png";
    QString const pic_free20= ":/free/free/20.png";
    QString const pic_free21 = ":/free/free/21.png";
    QString const pic_free22= ":/free/free/22.png";
    QString const pic_free23= ":/free/free/23.png";
    QString const pic_free24= ":/free/free/24.png";
    QString const pic_free25= ":/free/free/25.png";
    QString const pic_free26= ":/free/free/26.png";
    QString const pic_free27= ":/free/free/27.png";
    QString const pic_free28= ":/free/free/28.png";
    QString const pic_free29= ":/free/free/29.png";
    QString const pic_free30= ":/free/free/30.png";
    QString const pic_free31= ":/free/free/31.png";
    QString const pic_free32= ":/free/free/32.png";
    QString const pic_free33= ":/free/free/33.png";
    QString const pic_free34= ":/free/free/34.png";
    QString const pic_free35= ":/free/free/35.png";
    QString const pic_free36= ":/free/free/36.png";
    QString const pic_free37= ":/free/free/37.png";
    QString const pic_free38= ":/free/free/38.png";
    QString const pic_free39= ":/free/free/39.png";
    QString const pic_free40= ":/free/free/40.png";
    QString const pic_free41= ":/free/free/41.png";
    QString const pic_free42= ":/free/free/42.png";
    QString const pic_free43= ":/free/free/43.png";
    QString const pic_free44= ":/free/free/44.png";
    QString const pic_free45= ":/free/free/45.png";
    QString const pic_free46= ":/free/free/46.png";
    QString const pic_free47= ":/free/free/47.png";
    QString const pic_free48= ":/free/free/48.png";
    QString const pic_free49= ":/free/free/49.png";
    QString const pic_free50= ":/free/free/50.png";

    QString const pic_busy1 = ":/busy/busy/1.png";
    QString const pic_busy2 = ":/busy/busy/2.png";
    QString const pic_busy3 = ":/busy/busy/3.png";
    QString const pic_busy4 = ":/busy/busy/4.png";
    QString const pic_busy5 = ":/busy/busy/5.png";
    QString const pic_busy6 = ":/busy/busy/6.png";
    QString const pic_busy7 = ":/busy/busy/7.png";
    QString const pic_busy8 = ":/busy/busy/8.png";
    QString const pic_busy9 = ":/busy/busy/9.png";
    QString const pic_busy10 = ":/busy/busy/10.png";
    QString const pic_busy11= ":/busy/busy/11.png";
    QString const pic_busy12 =":/busy/busy/12.png";
    QString const pic_busy13= ":/busy/busy/13.png";
    QString const pic_busy14= ":/busy/busy/14.png";
    QString const pic_busy15= ":/busy/busy/15.png";
    QString const pic_busy16= ":/busy/busy/16.png";
    QString const pic_busy17= ":/busy/busy/17.png";
    QString const pic_busy18= ":/busy/busy/18.png";
    QString const pic_busy19= ":/busy/busy/19.png";
    QString const pic_busy20= ":/busy/busy/20.png";
    QString const pic_busy21 = ":/busy/busy/21.png";
    QString const pic_busy22= ":/busy/busy/22.png";
    QString const pic_busy23= ":/busy/busy/23.png";
    QString const pic_busy24= ":/busy/busy/24.png";
    QString const pic_busy25= ":/busy/busy/25.png";
    QString const pic_busy26= ":/busy/busy/26.png";
    QString const pic_busy27= ":/busy/busy/27.png";
    QString const pic_busy28= ":/busy/busy/28.png";
    QString const pic_busy29= ":/busy/busy/29.png";
    QString const pic_busy30= ":/busy/busy/30.png";
    QString const pic_busy31= ":/busy/busy/31.png";
    QString const pic_busy32= ":/busy/busy/32.png";
    QString const pic_busy33= ":/busy/busy/33.png";
    QString const pic_busy34= ":/busy/busy/34.png";
    QString const pic_busy35= ":/busy/busy/35.png";
    QString const pic_busy36= ":/busy/busy/36.png";
    QString const pic_busy37= ":/busy/busy/37.png";
    QString const pic_busy38= ":/busy/busy/38.png";
    QString const pic_busy39= ":/busy/busy/39.png";
    QString const pic_busy40= ":/busy/busy/40.png";
    QString const pic_busy41= ":/busy/busy/41.png";
    QString const pic_busy42= ":/busy/busy/42.png";
    QString const pic_busy43= ":/busy/busy/43.png";
    QString const pic_busy44= ":/busy/busy/44.png";
    QString const pic_busy45= ":/busy/busy/45.png";
    QString const pic_busy46= ":/busy/busy/46.png";
    QString const pic_busy47= ":/busy/busy/47.png";
    QString const pic_busy48= ":/busy/busy/48.png";
    QString const pic_busy49= ":/busy/busy/49.png";
    QString const pic_busy50= ":/busy/busy/50.png";

    busy_list.push_back(pic_busy1);
    busy_list.push_back(pic_busy2);
    busy_list.push_back(pic_busy3);
    busy_list.push_back(pic_busy4);
    busy_list.push_back(pic_busy5);
    busy_list.push_back(pic_busy6);
    busy_list.push_back(pic_busy7);
    busy_list.push_back(pic_busy8);
    busy_list.push_back(pic_busy9);
    busy_list.push_back(pic_busy10);
    busy_list.push_back(pic_busy11);
    busy_list.push_back(pic_busy12);
    busy_list.push_back(pic_busy13);
    busy_list.push_back(pic_busy14);
    busy_list.push_back(pic_busy15);
    busy_list.push_back(pic_busy16);
    busy_list.push_back(pic_busy17);
    busy_list.push_back(pic_busy18);
    busy_list.push_back(pic_busy19);
    busy_list.push_back(pic_busy20);
    busy_list.push_back(pic_busy21);
    busy_list.push_back(pic_busy22);
    busy_list.push_back(pic_busy23);
    busy_list.push_back(pic_busy24);
    busy_list.push_back(pic_busy25);
    busy_list.push_back(pic_busy26);
    busy_list.push_back(pic_busy27);
    busy_list.push_back(pic_busy28);
    busy_list.push_back(pic_busy29);
    busy_list.push_back(pic_busy30);
    busy_list.push_back(pic_busy31);
    busy_list.push_back(pic_busy32);
    busy_list.push_back(pic_busy33);
    busy_list.push_back(pic_busy34);
    busy_list.push_back(pic_busy35);
    busy_list.push_back(pic_busy36);
    busy_list.push_back(pic_busy37);
    busy_list.push_back(pic_busy38);
    busy_list.push_back(pic_busy39);
    busy_list.push_back(pic_busy40);
    busy_list.push_back(pic_busy41);
    busy_list.push_back(pic_busy42);
    busy_list.push_back(pic_busy43);
    busy_list.push_back(pic_busy44);
    busy_list.push_back(pic_busy45);
    busy_list.push_back(pic_busy46);
    busy_list.push_back(pic_busy47);
    busy_list.push_back(pic_busy48);
    busy_list.push_back(pic_busy49);
    busy_list.push_back(pic_busy50);

    free_list.push_back(pic_free1);
    free_list.push_back(pic_free2);
    free_list.push_back(pic_free3);
    free_list.push_back(pic_free4);
    free_list.push_back(pic_free5);
    free_list.push_back(pic_free6);
    free_list.push_back(pic_free7);
    free_list.push_back(pic_free8);
    free_list.push_back(pic_free9);
    free_list.push_back(pic_free10);
    free_list.push_back(pic_free12);
    free_list.push_back(pic_free13);
    free_list.push_back(pic_free14);
    free_list.push_back(pic_free15);
    free_list.push_back(pic_free16);
    free_list.push_back(pic_free17);
    free_list.push_back(pic_free18);
    free_list.push_back(pic_free19);
    free_list.push_back(pic_free20);
    free_list.push_back(pic_free21);
    free_list.push_back(pic_free22);
    free_list.push_back(pic_free23);
    free_list.push_back(pic_free24);
    free_list.push_back(pic_free25);
    free_list.push_back(pic_free26);
    free_list.push_back(pic_free27);
    free_list.push_back(pic_free28);
    free_list.push_back(pic_free29);
    free_list.push_back(pic_free30);
    free_list.push_back(pic_free31);
    free_list.push_back(pic_free32);
    free_list.push_back(pic_free33);
    free_list.push_back(pic_free34);
    free_list.push_back(pic_free35);
    free_list.push_back(pic_free36);
    free_list.push_back(pic_free37);
    free_list.push_back(pic_free38);
    free_list.push_back(pic_free39);
    free_list.push_back(pic_free40);
    free_list.push_back(pic_free41);
    free_list.push_back(pic_free42);
    free_list.push_back(pic_free42);
    free_list.push_back(pic_free43);
    free_list.push_back(pic_free44);
    free_list.push_back(pic_free45);
    free_list.push_back(pic_free46);
    free_list.push_back(pic_free47);
    free_list.push_back(pic_free48);
    free_list.push_back(pic_free49);
    free_list.push_back(pic_free50);

ui->tableView_recherche->sortByColumn(0, Qt::AscendingOrder);

    for (int i=0;i<(ui->tableView_recherche->model()->rowCount());i++)
    {
        QGraphicsScene *scene= new QGraphicsScene;
        QVector <QGraphicsPixmapItem*> vector;
        for(int j=0;j<(ui->tableView_recherche->model()->index(i,1).data().toInt());j++)
        {
            QGraphicsPixmapItem* pic;
            QPixmap pix(free_list[j]);
            pic = scene->addPixmap(pix);
            pic->setFlag(QGraphicsItem::ItemIsMovable);
            pic->setFlag(QGraphicsItem::ItemIsSelectable);

            vector.push_back(pic);
        }
        E.map.insert(scene,vector);
    }
    //ui->graphicsView_map->setScene(E.map.end().key());
    ui->graphicsView_map->setScene(E.map.lastKey());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_ajouter_clicked()
{
    int id=ui->lineEdit_ajout_id->text().toInt();
    int nb=ui->lineEdit_ajout_nb->text().toInt();
    QString bloc=ui->lineEdit_ajout_bloc->text();
    QDate date=ui->dateEdit_ajout->date();

    Espace E(id,nb,bloc,date);

    bool test=E.ajouter();

    if(test)
    {
        ui->tableView_affichage->setModel(Etmp.afficher());
        ui->comboBox_map->setModel(Etmp.afficher2());
        ui->comboBox_modification->setModel(Etmp.afficher2());
        ui->tableView_recherche->setModel(Etmp.afficher3());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout effectue\n"
                                             "Click Cancel to exit."), QMessageBox::Ok);
        ui->lineEdit_ajout_id->clear();
        ui->lineEdit_ajout_nb->clear();
        ui->lineEdit_ajout_bloc->clear();
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                              QObject::tr("Ajout non effectue.\n"
                                       "Click Cancel to exit."), QMessageBox::Ok);
}

void MainWindow::on_pushButton_modifier_clicked()
{
    int id =ui->comboBox_modification->currentText().toInt();
    int nb =ui->lineEdit_modification_nb->text().toInt();
    QString bloc =ui->lineEdit_modificatoin_bloc->text();
    QDate date = ui->dateEdit_modification->date();

    Espace Etmp(id,nb,bloc,date);

    bool test=Etmp.modifier();
    if (test)
    {
        ui->tableView_affichage->setModel(Etmp.afficher());
        ui->tableView_recherche->setModel(Etmp.afficher3());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Modification effectuee\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                              QObject::tr("Modification non effectuee.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_supprimer_clicked()
{
    int id =ui->comboBox_modification->currentText().toInt();
    bool test=Etmp.supprimer(id);
    if (test)
    {
        ui->tableView_affichage->setModel(Etmp.afficher());
        ui->comboBox_map->setModel(Etmp.afficher2());
        ui->comboBox_modification->setModel(Etmp.afficher2());
        ui->tableView_recherche->setModel(Etmp.afficher3());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Suppression effectuee\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                              QObject::tr("Suppression non effectuee.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_comboBox_modification_currentIndexChanged(const QString &arg1)
{
    QString id_string = ui->comboBox_modification->currentText();

    QSqlQuery qry;
    qry.prepare("select * from espaces where id='"+id_string+"'");
    if(qry.exec())
    {
        while(qry.next())
        {
            ui->lineEdit_modification_nb->setText(qry.value(1).toString());
            ui->lineEdit_modificatoin_bloc->setText(qry.value(2).toString());
        }
    }
}

void MainWindow::on_pushButton_server_clicked()
{
    serverWin = new ServerWindow(nullptr);
    serverWin->show();
}

void MainWindow::on_pushButton_chat_clicked()
{
    chatWin = new ChatWindow(nullptr);
    chatWin->show();
}

void MainWindow::on_pushButton_tri_clicked()
{
    if(ui->comboBox_recherche->currentIndex()==0){
    if(ui->checkBox_id->isChecked())
    {
        if(ui->checkBox_nb->isChecked())
        {
            if(ui->checkBox_bloc->isChecked())
            {
                ui->tableView_recherche->sortByColumn(2, Qt::AscendingOrder);
            }
            ui->tableView_recherche->sortByColumn(1, Qt::AscendingOrder);
        }
        else if(ui->checkBox_bloc->isChecked())
        {
            ui->tableView_recherche->sortByColumn(3, Qt::AscendingOrder);
        }
        ui->tableView_recherche->sortByColumn(0, Qt::AscendingOrder);
    }
    else if(ui->checkBox_nb->isChecked())
    {

        if(ui->checkBox_bloc->isChecked())
        {
            ui->tableView_recherche->sortByColumn(2, Qt::AscendingOrder);
        }
        ui->tableView_recherche->sortByColumn(1, Qt::AscendingOrder);
    }
    else if(ui->checkBox_bloc->isChecked())
    {
        ui->tableView_recherche->sortByColumn(2, Qt::AscendingOrder);
    }
    }
    else if(ui->comboBox_recherche->currentIndex()==1)
    {
        if(ui->checkBox_id->isChecked())
        {
            if(ui->checkBox_nb->isChecked())
            {
                if(ui->checkBox_bloc->isChecked())
                {
                    ui->tableView_recherche->sortByColumn(2, Qt::DescendingOrder);
                }
                ui->tableView_recherche->sortByColumn(1, Qt::DescendingOrder);
            }
            else if(ui->checkBox_bloc->isChecked())
            {
                ui->tableView_recherche->sortByColumn(3, Qt::DescendingOrder);
            }
            ui->tableView_recherche->sortByColumn(0, Qt::DescendingOrder);
        }
        else if(ui->checkBox_nb->isChecked())
        {

            if(ui->checkBox_bloc->isChecked())
            {
                ui->tableView_recherche->sortByColumn(2, Qt::DescendingOrder);
            }
            ui->tableView_recherche->sortByColumn(1, Qt::DescendingOrder);
        }
        else if(ui->checkBox_bloc->isChecked())
        {
            ui->tableView_recherche->sortByColumn(2, Qt::DescendingOrder);
        }
    }
}

void MainWindow::on_pushButton_rechercher_clicked()
{
    bool found = false;
    int taille =  ui->tableView_recherche->model()->rowCount();
    for(int i=0; i<taille ; i++)
    {
        if(ui->tableView_recherche->model()->index(i,0).data().toString() == ui->lineEdit_rechercher->text())
        {
            ui->tableView_recherche->selectRow(i);
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

void MainWindow::on_comboBox_map_currentIndexChanged(const QString &arg1)
{
    int n = ui->comboBox_map->currentIndex();
    int d=0;
   QMap<QGraphicsScene*,QVector<QGraphicsPixmapItem*>>::iterator it;
   /* for(it=map.begin() ;  it!=map.end() ;  ++it)
    {
        if(d==n)
            break;
        else
            d++;
    }*/
   // QGraphicsScene *scene = it.key();

}

void MainWindow::on_pushButton_rotation_droite_clicked()
{

}

void MainWindow::on_pushButton_marquer_occupee_clicked()
{
   /* QGraphicsScene *scene = ui->graphicsView->scene();
    QVector<QGraphicsPixmapItem*> vector=E.map[scene];
    for (int i=0;i<5;i++)
    {


        QPixmap pix(busy_list[i]);


        if(vector[i]->isSelected())
        {
            vector[i]->setPixmap(pix);
        }
    }*/
}
