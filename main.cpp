#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include <QSql>
#include "authentificationn.h"
#include "tache_a_faire.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
   tache_a_faire t;
    authentificationn u;
    Connection c;

    bool test=c.createconnect();
    if(test)
    {
        u.show();
        //w.show();
        //t.show();

        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



    return a.exec();
}
