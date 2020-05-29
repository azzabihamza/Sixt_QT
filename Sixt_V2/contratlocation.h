#ifndef CONTRATLOCATION_H
#define CONTRATLOCATION_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QDate>
#include "connexion.h"

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

    QString code;
    QString dateD;
    QString dateF;
    QString agence;
    QString agent;
    QString reference;
    QString client;

    QString client_code;
    QString client_nom;
    QString client_prenom;
    QString client_date_naissance;
    QString client_adresse;
    QString client_num_tel;
    QString client_email;
    QString client_permis_type;
    QString client_permis_numero;
    QString client_date_del_permis;
    QString client_datefindel_permis;
    QString client_cin;

    QString marque;
    QString carburant;
    QString plaque;
    QString age;
    QString prix;



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
    QSqlQueryModel *rechercherContrat(QString);
    QSqlQueryModel *afficherContrat();
    QSqlQueryModel *triDateDec();
    QSqlQueryModel *triDateCroi();

    void ContratPDF(QString);
    QSqlTableModel *setTable();


};

#endif // CONTRATLOCATION_H
