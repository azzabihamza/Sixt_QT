#ifndef PERSONNEL_H
#define PERSONNEL_H

#include <QString>
#include <QDate>
#include <QSqlQueryModel>
#include "smtp.h"
#include "qcustomplot.h"

class Personnel
{
public:
    Personnel();
    Personnel(int,QString,QString,QDate,QDate,QString,QString,QString,QString,int,QString,QString);

    bool ajouter_Personnel();
    bool modifier_Personnel();
    bool supprimer_Personnel(int);
    QSqlQueryModel *afficher_Personnel();
    QSqlQueryModel *rechercher(QSqlQuery );
    QSqlQueryModel *actualiser();
    QSqlQueryModel *tricrois_Personnel();
    QSqlQueryModel *tridecrois_Personnel();



private:
    int id;
    int mdp;
    int ID_Agence;
    QString nom;
    QString prenom;
    QDate datenaissance;
    QDate datembauche;
    QString adresse;
    QString tel;
    QString email;
    QString role;
    int codepostal;
    QString ville;
    QString pays;
};


#endif // PERSONNEL_H
