#include "connexion.h"

Connection::Connection()
{

}

bool Connection::ouvrirConnexion()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("PRO");
db.setUserName("system");//inserer nom de l'utilisateur
db.setPassword("123");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;




    return  test;
}
void Connection::fermerConnexion()
{db.close();}
