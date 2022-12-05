#ifndef CONNEXION_H
#define CONNEXION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class connection{
        QSqlDatabase db;
public:
    connection();
    bool createconnection();
    void closeconnection();
};

#endif // CONNEXION_H
