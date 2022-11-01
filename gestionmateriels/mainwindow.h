#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "materiels.h"

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
    void on_bajouter_clicked();

    void on_bsupp_clicked();

    void on_bmodif_clicked();

private:
    Ui::MainWindow *ui;
    Materiels M;
};

#endif // MAINWINDOW_H
