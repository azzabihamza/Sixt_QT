#ifndef CONNEXION_H
#define CONNEXION_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSql>

using namespace std;
class Connexion
{
private:
    QSqlDatabase db;
public:
    Connexion();
    QSqlDatabase getDb();
    bool ouvrirConnexion();
    void fermerConnexion();
};

#endif // CONNEXION_H
