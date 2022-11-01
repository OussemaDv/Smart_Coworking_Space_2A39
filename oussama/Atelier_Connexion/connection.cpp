#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Projet2A");
db.setUserName("oussama");//inserer nom de l'utilisateur
db.setPassword("Oussema");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;
    return  test;
}

void Connection::closeConnection(){db.close();}
