#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <QDate>
#include <QSqlQueryModel>
#include "smtp.h"
#include "qcustomplot.h"
#include <QSqlQuery>


using namespace std;

class Client
{
private:
    int client_code;
    QString client_nom;
    QString client_prenom;
    QDate client_date_nai;
    QString client_adresse;
    int client_numtel;

    QString client_email;
    QString client_typepermis;
    QString client_numpermis;
    QDate client_datedel;
    QDate client_datefindel;
    int client_cin;


public:
    Client();
    Client(QString,QString,QDate,QString,int,QString,QString,QString,QDate,QDate,int);

    // get
    int getCodeClient();
    QString getNomClient();
    QString getPrenomClient();
    QDate getDatenaiClient();
    QString getAdresseClient();
    int getNumtelClient();

    QString getEmailClient();
    QString getTypepermisClient();
    QString getNumpermisClient();
    QDate getDatedelClient();
    QDate getDatefindelClient();
    int getCinClient();

    // méthodes

    bool ajouterClient();
    bool supprimerClient(int);
    bool modifierClient(int);
    QSqlQueryModel *rechercherClient(int);
    QSqlQueryModel *rechercherClientCin(int);
    QSqlQueryModel *afficherClient();
    QSqlQueryModel *triCodeDec();
    QSqlQueryModel *triCodeCroi();
};

#endif // CLIENT_H
