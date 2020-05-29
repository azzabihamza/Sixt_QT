#include "connexion.h"
#include <QtSql/QSqlError>
using namespace std;
Connexion::Connexion()
{
}

QSqlDatabase Connexion::getDb()
{
    return db;
}
bool Connexion::ouvrirConnexion()
{
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
                           db.setDatabaseName("Source_Projet2A");
                           db.setUserName("Azzabi");
                           db.setPassword("Admin");

if (db.open())
    test=true;

else throw QString ("Erreur Paramétres"+db.lastError().text());
return  test;
}
void Connexion::fermerConnexion()
{
    db.close();
}
