#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class Connection
{
public:
    Connection();
    bool ouvrirConnexion();
    void fermerConnexion();
private:
    QSqlDatabase db ;
};

#endif // CONNECTION_H
