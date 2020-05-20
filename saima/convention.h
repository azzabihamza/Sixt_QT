#ifndef CONVENTION_H
#define CONVENTION_H

#include <QString>
#include <QDate>
#include <QSqlQueryModel>
#include "smtp.h"
#include "qcustomplot.h"

class Convention
{
public:
    Convention();
    Convention(int,QString,QString,int,QString);

    bool ajouter_convention();
    bool modifier_convention(QString);
    bool supprimer_convention(QString);
    QSqlQueryModel *afficher_convention();
    QSqlQueryModel *rechercher_convention(QString);
    QSqlQueryModel *tricrois_convention();
    QSqlQueryModel *tridecrois_convention();
    bool pdf_convention(QString);


private:
    int c_code;
    QString c_nom;
    QString c_adresse;
    int c_numtel;
    QString c_email;
};


#endif // CONVENTION_H
