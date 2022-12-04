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

private:
    Ui::MainWindow *ui;

    adherents a;
    arduino ar;
    QByteArray data;
    Reservation R;
    employe e;
    QListView* m_pwPending = nullptr;
    QListView* m_pwCompleted = nullptr;

    QAction* m_pActAdd = nullptr;
    QAction* m_pActRemove = nullptr;



};
#endif // MAINWINDOW_H
