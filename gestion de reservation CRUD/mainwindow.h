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

    void on_pushButton_afficher_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pb_modifier_clicked();

private:
    Ui::MainWindow *ui;
    Reservation R;
};

#endif // MAINWINDOW_H
