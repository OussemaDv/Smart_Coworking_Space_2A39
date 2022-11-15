#ifndef CONNECTION_H
#define CONNECTION_H
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlError>
#include <QtSql/QSqlQuery>


class Connection
{
public:
    QSqlDatabase db;
    Connection();
    bool createconnect();
    void closeConnection();
};

#endif // CONNECTION_H
