#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "service.h"
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
    void on_button_ajouter_clicked();

    void on_pbSupprimer_clicked();

    void on_updateBP_clicked();

private:
    Ui::MainWindow *ui;
    Service Etmp;
};

#endif // MAINWINDOW_H
