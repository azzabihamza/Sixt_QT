#ifndef VEHICULES_H
#define VEHICULES_H

#include "QString"
#include "QSqlQuery"
#include "QSqlQueryModel"

class vehicules
{
public:
    vehicules();
    vehicules(QString,QString,QString,QString,QString,QString,QString);
    QString get_REF();
    QString get_MARQUE();
    QString get_CARBURANT();
    QString get_PLAQUE();
    QString get_AGE();
    QString get_PRIX();
    QString get_ID_c();

    void set_REF(QString);
    void set_MARQUE(QString);
    void set_CARBURANT(QString);
    void set_PLAQUE(QString);
    void set_AGE(QString);
    void set_PRIX(QString);
    void set_ID_c(QString);


    bool ajouter_vehicules();
    QSqlQueryModel * afficher_vehicules();
    bool supprimer_vehicules(QString);
    bool modifier_vehicules(vehicules);
     QSqlQueryModel *rechercher(QSqlQuery);
     QSqlQueryModel * afficher_vehiculeslist();
     bool verif_id(QString);
     bool verif_nom(QString);

private:
    QString REF,MARQUE,CARBURANT,PLAQUE,AGE,PRIX,ID_C;

};

#endif // VEHICULES_H
