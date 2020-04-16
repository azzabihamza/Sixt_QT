
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



/*#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QMediaPlayer>
class Connection
{
public:
    Connection();
    bool createconnect();
    QSqlDatabase mydb;
};

#endif // CONNECTION_H*/
