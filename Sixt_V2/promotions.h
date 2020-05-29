#ifndef PROMOTIONS_H
#define PROMOTIONS_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Promotions
{
public:
    Promotions();
    Promotions(QString,QString,int);

    QString get_nomp();
    int get_pourcentage();
    QString get_idpromo();
    bool ajouter_p();
    QSqlQueryModel * afficher_p ();
    bool supprimer_p (int);
     bool modifier_p(Promotions);
     QSqlQueryModel * rechercher_m(QSqlQuery );
     QSqlQueryModel * actualiser();
private :
    QString idpromo ;
    QString nomp ;
    int pourcentage ;
};

#endif // PROMOTIONS_H
