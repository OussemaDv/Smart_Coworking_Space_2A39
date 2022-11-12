#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <iostream>
#include <string>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QMainWindow>
#include <QMessageBox>
#include <QApplication>
#include <QRegExpValidator>
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
#include "adherents.h"

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

private:
    Ui::MainWindow *ui;
    adherents a;
};
#endif // MAINWINDOW_H
