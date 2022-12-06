#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "reservation.h"
#include <iostream>
#include <string>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QMainWindow>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>
#include <QMessageBox>
#include <QApplication>
#include <QRegExpValidator>
#include <QTextCodec>
#include <QPdfWriter>
#include <QPainter>
#include <QPrinter>
#include <QPrintDialog>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTextDocument>
#include <QTextStream>
#include <QPixmap>
#include <QFileDialog>
#include "QZXing/QZXing.h"
#include <QColor>
#include "adherents.h"
#include "arduino.h"
#include "employe.h"

//***Fourniss**
#include "Fournisseur.h"
#include "dialog.h"
#include "Detecteur.h"
#include "map.h"
#include <QDesktopServices>
#include <QUrl>
//
//********Materiels*****
#include <QMainWindow>
#include <QApplication>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "materiels.h"
#include <QPrinter>
#include <QPixmap>
#include <QPainter>
#include <QPrintDialog>
#include <QPagedPaintDevice>
#include <QTableView>
#include <QDesktopServices>
#include <QtCharts/QAreaSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QPieSlice>
#include <QPieSeries>
#include <QChartView>
#include "Detecteur.h"
#include"catalogue.h"
#include "exportexcelobject.h"
#include <QMessageBox>
//

//Espaces*******************************************************
#include <QMainWindow>
#include "espace.h"
#include <QMessageBox>
#include <QVector>
#include <QString>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QPieSlice>
#include <QBarSet>
#include <QBarSeries>
#include <QChar>
#include <math.h>
#include "serverwindow.h"
#include "serverworker.h"
#include "chatserver.h"
#include "chatclient.h"
#include "chatwindow.h"
#include <QTableView>
#include <QPrinter>
#include <QPainter>
#include <QPdfWriter>
#include <QDebug>
#include <QtDebug>
#include <QPrintDialog>
#include <QFileDialog>
//**********************************************************************


using namespace std;

#define valid_email "^[_a-z0-9-]+(\\.[_a-z0-9-]+)*@[a-z0-9-]+(\\.[a-z0-9-]+)*(\\.[a-z]{2,4})$"
#define valid_chaine "([A-Z][a-z]*)([\\s\\\'-][A-Z][a-z]*)*"
#define valid_nombre "[0-9]+"
#define valid_date "^(0?[1-9]|[12][0-9]|3[01])[\\/\\-](0?[1-9]|1[012])[\\/\\-]\\d{4}$"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //****************************Espace************************************

    void statistique();

    QChart * statSalle();
    QChart * statPlace();
    void setBusyList();

    void setFreeList();
    //***********************************************************************


private slots:

    void on_ajouter_clicked();
    void on_supprimer_clicked();
    void on_modifier_clicked();
    void on_reset_clicked();
    void on_reset_2_clicked();
    void on_rechercher_clicked();
    void on_mod_cin_currentIndexChanged();
    void on_tri_activated();
    void on_pdf_clicked();
    void on_cin_qr_currentIndexChanged();
    void on_cin_pdf_currentIndexChanged();
    void on_photo_clicked();
    void on_aff_clicked();
    void on_stat_clicked();
    void on_home_clicked();
    void on_gestion1_clicked();
    void on_gestion2_clicked();
    void on_gestion3_clicked();
    void on_gestion4_clicked();
    void on_gestion5_clicked();
    void on_gestion6_clicked();
    void dialog1();

    void on_ajout_emp_clicked();
    void on_mod_emp_clicked();
    void on_pb_recherche_clicked();
    void on_tri_id_emp_clicked();
    void on_pb_trier_clicked();
    void on_pb_trier_2_clicked();
    void on_pb_supprimer_clicked();
    void on_pb_pdf_clicked();
    void on_sta_pb_clicked();

    void on_pb_ajouter_res_clicked();

    void on_pb_reload_2_clicked();

    void on_pushButton_supprimer_2_clicked();

    void on_rechercher_pb_2_clicked();

    void on_pb_tri_resID_d_2_clicked();

    void on_pb_trier_CIN_d_2_clicked();

    void on_pushButton_2_clicked();

    void on_pb_tri_CIN_2_clicked();

    void on_pb_datte_c_2_clicked();

    void on_pb_datte_d_2_clicked();

    void on_tab_reservation_2_activated(const QModelIndex &index);



    void on_calendar_2_clicked(const QDate &date);
    void on_pb_calculatrice_clicked();

    void on_pb_pdf_reservation_clicked();



    void on_pb_stat_reservation_clicked();

    //*********Fourn*******
    void on_button_ajouter_clicked();

       void on_pbSupprimer_clicked();

       void on_updateBP_clicked();

       void on_comboBoxID_currentIndexChanged(const QString &arg1);

       void on_pdfPb_clicked();

       void on_emailpb_clicked();

       void on_rechercherpb_clicked();


       void on_check_quantite_clicked();

       void on_check_prix_clicked();

       void on_check_ID_clicked();

       void on_whatsapp_pb_clicked();

       void on_map_clicked();

       void on_afficher_clicked();

       void on_detection_clicked();
       //
       //*********Materiels*******

       void on_bajouter_clicked();

           void on_bsupprimer_clicked();

           void on_bmodifier_clicked();

           void on_bpdf_clicked();

           void on_lrecherche_textChanged(const QString &arg1);

           void on_tridate_clicked();

           void on_trinombre_clicked();

           void on_triid_clicked();

          // void on_bstat_clicked();

           void on_pushButton_clicked();

           void on_bcatalogue_clicked();

           void on_bexcel_clicked();

       //

           void on_pbAjoutEsp_clicked();

           void on_pbModifEsp_clicked();

           void on_combo_modifEsp_currentIndexChanged(const QString &arg1);

           void on_pbSuppr_clicked();

           void on_comboMap_currentIndexChanged(const QString &arg1);

           void on_comboMap_currentIndexChanged(int index);

           void on_pbGauche_clicked();

           void on_pbDroite_clicked();

           void on_pbBusy_clicked();

           void on_pbFree_clicked();

           void on_pbPDFEsp_clicked();

           void on_pbServer_clicked();

           void on_pbChat_clicked();

           void on_pbTrier_clicked();

           void on_pbRechercher_clicked();

           void on_pbActualiserEsp_clicked();

private:
    Ui::MainWindow *ui;

    adherents a;
    arduino ar;
    QByteArray data;
    Reservation R;
    //
    employe e;
    QListView* m_pwPending = nullptr;
    QListView* m_pwCompleted = nullptr;

    QAction* m_pActAdd = nullptr;
    QAction* m_pActRemove = nullptr;
//
    Fournisseur Etmp;
       dialog *Di ;
       Detecteur *E;
       Map *m;
       //
       Materiels M;
         // Espace *E;
          catalogue *C;

          espace Esp;
          QVector<QString> free_list;
          QVector<QString> busy_list;
          QVector<QGraphicsScene*> scene_list;
          QVector<QVector<QGraphicsPixmapItem*>> pic_list;
          bool l=false,l2=false;
          QChartView * chartview;

};
#endif // MAINWINDOW_H
