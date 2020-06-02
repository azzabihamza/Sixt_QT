#include "connection.h"

Connection::Connection()
{

}

bool Connection::ouvrirConnexion()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("wissmck");
db.setUserName("system");//inserer nom de l'utilisateur
db.setPassword("wissemmcharek123");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;




    return  test;
}
void Connection::fermerConnexion()
{db.close();}
