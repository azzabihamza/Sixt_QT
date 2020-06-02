#ifndef AGENCE_H
#define AGENCE_H

#include <QString>
#include <QDate>
#include <QSqlQueryModel>
#include "smtp.h"
#include "qcustomplot.h"

class Agence
{
public:
    Agence();
    Agence(int,QString,int,int,QString,QString,QString,QString);

    bool ajouter_agence();
    bool modifier_agence();
    bool supprimer_agence(int);
    QSqlQueryModel *afficher_agence();
    QSqlQueryModel *rechercher(QSqlQuery );
    QSqlQueryModel *tricrois_agence();
    QSqlQueryModel *tridecrois_agence();
    QSqlQueryModel *actualiser();
    //bool pdf_client(QString);

private:
    int idagence;
    QString nomagence;
    int idchefagence;
    int budget;
    QString adresse;
    QString pays;
    QString ville;
    QString type;
};

#endif // AGENCE_H
