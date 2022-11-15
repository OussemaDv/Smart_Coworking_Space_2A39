#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "reservation.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();



    void on_pushButton_supprimer_clicked();

    void on_pb_modifier_clicked();

    void on_tab_reservation_activated(const QModelIndex &index);





    void on_pb_pdf_clicked();




    void on_rechercher_pb_clicked();

    void on_pb_reload_clicked();

    void on_pushButton_clicked();

    void on_pb_tri_CIN_clicked();



    void on_calendar_clicked(const QDate &date);



    void on_pb_tri_resID_d_clicked();

    void on_pb_trier_CIN_d_clicked();

    void on_pb_datte_c_clicked();

    void on_pb_datte_d_clicked();



    void on_pb_stat_clicked();

    void on_pb_calcul_prix_clicked();

    void on_pb_calculatrice_clicked();

private:
    Ui::MainWindow *ui;
    Reservation R;
};

#endif // MAINWINDOW_H
