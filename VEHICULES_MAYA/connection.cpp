
#include "connection.h"

Connection::Connection()
{

}

bool Connection::ouvrirConnexion()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Projet2A");
db.setUserName("Maya");//inserer nom de l'utilisateur
db.setPassword("admin");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
void Connection::fermerConnexion()
{db.close();
}



/*#include "connection.h"
#include <QMediaPlayer>
Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Projet2A");
db.setUserName("Maya");//inserer nom de l'utilisateur
db.setPassword("admin");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}*/
