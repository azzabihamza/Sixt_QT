#ifndef PUBLICITE_H
#define PUBLICITE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include"QDate"

class Publicite
{
public:
    Publicite();
    Publicite(int,QString,QDate);
    QString get_nom();
    QDate get_date_pub();
    int get_id();
    bool ajouter();
    QSqlQueryModel * afficher ();
    bool supprimer (int);
    bool modifier(Publicite);
    QSqlQueryModel * rechercher(QSqlQuery );
private :
    int id ;
    QString nom ;
    QDate date_pub ;

};

#endif // PUBLICITE_H
