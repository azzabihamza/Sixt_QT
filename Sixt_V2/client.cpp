#include "client.h"
#include <QSqlQuery>
#include <QPdfWriter>
#include <QPainter>
#include "connexion.h"
#include <QString>
#include <QDebug>
#include <QDate>
#include <QDateTime>
#include <QPushButton>

Client::Client()
{
    client_code=0;
    client_nom="";
    client_prenom="";
    client_date_nai = QDate::currentDate();
    client_adresse="";
    client_numtel=0;

    client_email="";
    client_typepermis="";
    client_numpermis="";
    client_datedel=QDate::currentDate();
    client_datefindel=QDate::currentDate();
    client_cin=0;
}

Client::Client(QString client_nom ,QString client_prenom,QDate client_date_nai,QString client_adresse,int client_numtel,QString client_email,QString client_typepermis,QString client_numpermis,QDate client_datedel,QDate client_datefindel,int client_cin)
{

    this->client_nom=client_nom;
    this->client_prenom=client_prenom;
    this->client_date_nai=client_date_nai;
    this->client_adresse=client_adresse;
    this->client_numtel=client_numtel;
    this->client_email=client_email;

    this->client_typepermis=client_typepermis;
    this->client_numpermis=client_numpermis;
    this->client_datedel=client_datedel;
    this->client_datefindel=client_datefindel;
    this->client_cin=client_cin;
}

int Client::getCodeClient(){return client_code;}

QString Client::getNomClient(){return client_nom;}
QString Client::getPrenomClient(){return client_prenom;}
QDate Client::getDatenaiClient(){return client_date_nai;}
QString Client::getAdresseClient(){return client_adresse;}
int Client::getNumtelClient(){return client_numtel;}

QString Client::getEmailClient(){return client_email;}
QString Client::getTypepermisClient(){return client_typepermis;}
QString Client::getNumpermisClient(){return client_numpermis;}
QDate Client::getDatedelClient(){return client_datedel;}
QDate Client::getDatefindelClient(){return client_datefindel;}
int Client::getCinClient(){return client_cin;}

bool Client::ajouterClient()
{
    QSqlQuery query;

    query.prepare("INSERT INTO CLIENT (NOM, PRENOM, DATE_NAISSANCE, ADRESSE, NUM_TEL, EMAIL, TYPE_PERMIS, NUM_PERMIS, DATE_DEL, DATEFIN_DEL, CIN) "
                        "VALUES (:nom, :prenom, :date_naissance, :adresse, :num_tel, :email, :type_permis, :num_permis, :date_del, :datefin_del, :cin)");

    query.bindValue(":nom", client_nom);
    query.bindValue(":prenom", client_prenom);
    query.bindValue(":date_naissance", client_date_nai);
    query.bindValue(":adresse", client_adresse);
    query.bindValue(":num_tel", client_numtel);
    query.bindValue(":email", client_email);
    query.bindValue(":type_permis",client_typepermis);
    query.bindValue(":num_permis",client_numpermis);
    query.bindValue(":date_del",client_datedel);
    query.bindValue(":datefin_del",client_datefindel);
    query.bindValue(":cin",client_cin);
    return    query.exec();
}

bool Client::supprimerClient(int id)
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("Delete from CLIENT where CODE = :id ");
    query.bindValue(":id", res);
    return    query.exec();
}

bool Client::modifierClient(int id)
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("UPDATE CLIENT SET NOM = :nom, PRENOM = :prenom, DATE_NAISSANCE = :date_naissance, ADRESSE = :adresse , NUM_TEL = :num_tel, EMAIL = :email, TYPE_PERMIS = :type_permis, NUM_PERMIS = :num_permis, DATE_DEL = :date_del, DATEFIN_DEL = :datefin_del, CIN = :cin   where CODE = :id ");
    query.bindValue(":id", res);
    query.bindValue(":nom", client_nom);
    query.bindValue(":prenom", client_prenom);
    query.bindValue(":date_naissance", client_date_nai);
    query.bindValue(":adresse", client_adresse);
    query.bindValue(":num_tel", client_numtel);
    query.bindValue(":email", client_email);
    query.bindValue(":type_permis",client_typepermis);
    query.bindValue(":num_permis",client_numpermis);
    query.bindValue(":date_del",client_datedel);
    query.bindValue(":datefin_del",client_datefindel);
    query.bindValue(":cin",client_cin);
    return    query.exec();
}

QSqlQueryModel* Client::afficherClient()
{

    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from CLIENT");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CODE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("D.DE NAISSANCE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("NUM. TELEPHONE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("EMAIL"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("TYPE PERMIS"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("NUM PERMIS"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("D. DELIVERANCE"));
    model->setHeaderData(10, Qt::Horizontal, QObject::tr("D. FIN DELIVERANCE"));
    model->setHeaderData(11, Qt::Horizontal, QObject::tr("CIN"));
    return model;
}

QSqlQueryModel *Client::triCodeDec()
{
    QSqlQuery* query = new QSqlQuery();

    QSqlQueryModel * model= new QSqlQueryModel();
    query->prepare("select * from CLIENT ORDER BY CODE DESC");
    query->exec();
    model->setQuery(*query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CODE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("D.DE NAISSANCE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("NUM. TELEPHONE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("EMAIL"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("TYPE PERMIS"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("NUM PERMIS"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("D. DELIVERANCE"));
    model->setHeaderData(10, Qt::Horizontal, QObject::tr("D. FIN DELIVERANCE"));
    model->setHeaderData(11, Qt::Horizontal, QObject::tr("CIN"));
    return model;
}

QSqlQueryModel *Client::triCodeCroi()
{
    QSqlQuery* query = new QSqlQuery();

    QSqlQueryModel * model= new QSqlQueryModel();
    query->prepare("select * from CLIENT ORDER BY CODE");
    query->exec();

    model->setQuery(*query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CODE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("D.DE NAISSANCE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("NUM. TELEPHONE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("EMAIL"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("TYPE PERMIS"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("NUM PERMIS"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("D. DELIVERANCE"));
    model->setHeaderData(10, Qt::Horizontal, QObject::tr("D. FIN DELIVERANCE"));
    model->setHeaderData(11, Qt::Horizontal, QObject::tr("CIN"));
    return model;
}

QSqlQueryModel* Client::rechercherClient(int id) //MARCHE PAS
{
    QString res= QString::number(id);
    QSqlQuery* query = new QSqlQuery();
    QSqlQueryModel * model= new QSqlQueryModel();
    query->prepare("select * from CLIENT WHERE CODE = '"+res+"'");
    query->exec();
    model->setQuery(*query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CODE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("D.DE NAISSANCE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("NUM. TELEPHONE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("EMAIL"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("TYPE PERMIS"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("NUM PERMIS"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("D. DELIVERANCE"));
    model->setHeaderData(10, Qt::Horizontal, QObject::tr("D. FIN DELIVERANCE"));
    model->setHeaderData(11, Qt::Horizontal, QObject::tr("CIN"));
    return model;
}

QSqlQueryModel* Client::rechercherClientCin(int cin)
{
    QString res= QString::number(cin);
    QSqlQuery* query = new QSqlQuery();
    QSqlQueryModel * model= new QSqlQueryModel();
    query->prepare("select * from CLIENT WHERE CIN = '"+res+"'");
    query->exec();
    model->setQuery(*query);
    return model;
}


