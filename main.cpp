#include "mainwindow.h"
#include "login.h"
#include "connexion.h"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connection c;

    bool test=c.createconnection();
    MainWindow w;
    login l;

    if(test)
    {
        l.show();
        w.setWindowTitle("Smart WorkSpace");
        l.setWindowTitle("Smart WorkSpace");
        QMessageBox::information(nullptr,QObject::tr("databaseis open"),QObject::tr("connection successful.\n click Close to exit."),QMessageBox::Close);
    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("database is not open"),QObject::tr("connection failed.\n click Close to exit."),QMessageBox::Close);
    }
    return a.exec();
}
