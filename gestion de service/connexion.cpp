#include "connexion.h"

connection::connection() {}

bool connection::createconnection()
{
    db=QSqlDatabase::addDatabase("QODBC");
    bool test=false;
    db.setDatabaseName("projet2a");
       db.setUserName("eya");
       db.setPassword("eyoutta2002");

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

