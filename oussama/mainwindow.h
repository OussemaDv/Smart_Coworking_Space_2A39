#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableView>
#include "espaces.h"
#include "ui_mainwindow.h"
#include <qmessagebox.h>
#include<QMessageBox>
#include <QSqlQuery>
#include <QtDebug>
#include <QtSql>
#include <QPixmap>
#include "connection.h"
#include "serverwindow.h"
#include "chatwindow.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QVector>
#include <QString>
#include <QMap>
#include <qiterator.h>
#include <iterator>

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
    void on_pushButton_ajouter_clicked();

    void on_pushButton_modifier_clicked();

    void on_pushButton_supprimer_clicked();

    void on_comboBox_modification_currentIndexChanged(const QString &arg1);

    void on_pushButton_server_clicked();

    void on_pushButton_chat_clicked();

    void on_pushButton_tri_clicked();

    void on_pushButton_rechercher_clicked();

    void on_comboBox_map_currentIndexChanged(const QString &arg1);

    void on_pushButton_rotation_droite_clicked();

    void on_pushButton_marquer_occupee_clicked();

private:
    Ui::MainWindow *ui;
    Espace Etmp;
    ServerWindow *serverWin;
    ChatWindow *chatWin;
    ChatWindow *chatWin2;
    Espace E;
    QVector <QString> free_list;
    QVector <QString> busy_list;
};
#endif // MAINWINDOW_H
