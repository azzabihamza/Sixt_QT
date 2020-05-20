#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <QDate>
#include <QSqlQueryModel>
#include "smtp.h"
#include "qcustomplot.h"

class Client
{
public:
    Client();
    Client(QString,QString,QDate,QString,int,QString,QString,QString,QDate,QDate,int);

    bool ajouter_client();
    bool modifier_client(QString);
    bool supprimer_client(QString);
    QSqlQueryModel *afficher_client();
    QSqlQueryModel *rechercher_client(QString);
    QSqlQueryModel *tricrois_client();
    QSqlQueryModel *tridecrois_client();
    bool pdf_client(QString);

private:
    QString code;
    QString nom;
    QString prenom;
    QDate date_naissance;
    QString adresse;
    int num_tel;
    QString email;
    QString type_permis;
    QString num_permis;
    QDate date_del;
    QDate datefin_del;
    int cin;


};

#endif // CLIENT_H
