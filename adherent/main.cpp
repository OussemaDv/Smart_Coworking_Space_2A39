#include "mainwindow.h"
#include "login.h"
#include "connexion.h"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connection c;
    login l;
    MainWindow w;

    bool test=c.createconnection();

    if(test)
    {
        w.show();
        QMessageBox::information(nullptr,QObject::tr("databaseis open"),QObject::tr("connection successful.\n click Close to exit."),QMessageBox::Close);
    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("database is not open"),QObject::tr("connection failed.\n click Close to exit."),QMessageBox::Close);
    }
    return a.exec();
}
