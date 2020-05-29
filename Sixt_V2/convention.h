#ifndef CONVENTION_H
#define CONVENTION_H

#include <QString>
#include <QDate>
#include <QSqlQueryModel>
#include "smtp.h"
#include "qcustomplot.h"

class Convention
{
private:
    int c_code;
    QString c_nom;
    QString c_adresse;
    int c_numtel;
    QString c_email;
public:
    Convention();
    Convention(QString,QString,int,QString);

    int getCodeCon();
    QString getNomCon();
    QString getAdresseCon();
    int getNumtelCon();
    QString getEmailCon();

    bool ajoutConvention();
    bool modifierConvention(int);
    bool supprimerConvention(int);

    QSqlQueryModel *afficherConvention();
    QSqlQueryModel *rechercherConvention(int);

};

#endif // CONVENTION_H
