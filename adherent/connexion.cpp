#include "connexion.h"

connection::connection(){}

bool connection::createconnection(){
    db=QSqlDatabase::addDatabase("QODBC");
    bool test=false;
    db.setDatabaseName("source_projet2A");
    db.setUserName("aziz");
    db.setPassword("esprit39");

    if(db.open()){
        test=true;
    }
    return test;
}

void connection::closeconnection(){
    db.close();
}

