#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include "connection.h"
#include "employe.h"
#include <QMainWindow>
#include <QSql>

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
    void on_pushButton_clicked();

    void on_Modifier_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_trier_clicked();

    void on_pb_trier_2_clicked();

    void on_pb_recherche_clicked();

    void on_pb_pdf_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    employe e;
};

#endif // MAINWINDOW_H
