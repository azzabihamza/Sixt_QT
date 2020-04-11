#ifndef CONTRATLOCATION_H
#define CONTRATLOCATION_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

using namespace std;

class ContratLocation
{
private:
    int ID_Contrat;
    QDate DateDebut;
    QDate DateFin;

    int ID_Agence;
    QString ID_Agent;
    QString ReferenceVehicule;
    QString ID_Client;


public:
    ContratLocation();
    ContratLocation(QDate,QDate,int,QString,QString,QString);

    // get
    int getIdContrat();
    QDate getDateDebut();
    QDate getDateFin();

    int getIdAgence();
    QString getIdAgent();
    QString getReferenceVehiule();
    QString getIdClient();

    // méthodes

    bool ajouterContratLocation();
    bool supprimerContratLocation(int);
    bool modifierContratLocation(int);
    QSqlQueryModel *rechercherContrat(int);
    QSqlQueryModel *afficherContrat();


};

#endif // CONTRATLOCATION_H
