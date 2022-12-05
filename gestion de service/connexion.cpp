#include "connexion.h"

connection::connection() {}

bool connection::createconnection()
{
    db=QSqlDatabase::addDatabase("QODBC");
    bool test=false;
    db.setDatabaseName("source_projet2A");
       db.setUserName("arij");
       db.setPassword("root");

    if(db.open())
    {
        test=true;
    }
    return test;
}

void connection::closeconnection()
{
    db.close();
}

