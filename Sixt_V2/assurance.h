#ifndef ASSURANCE_H
#define ASSURANCE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

class Assurance
{
private:
    int Reference;
    QString Type;
    QString Assureur;
    double Tarif;
    QDate dateEmission;
    QDate dateExpiration;
    QString matriculeVehicule;
public:
    Assurance();
    Assurance(QString,QString,double,QDate,QDate,QString);

    int getReference();
    QString getType();
    QString getAssureur();
    double getTarif();
    QDate getDateEmission();
    QDate getDateExpiration();
    QString getMatriculeVehicule();

    bool ajoutAssurance();
    bool modifierAssurance(int);
    bool supprimerAssurance(int);

    QSqlQueryModel *afficherAssurance();
    QSqlQueryModel *rechercherAssurance(QString);

};

#endif // ASSURANCE_H
