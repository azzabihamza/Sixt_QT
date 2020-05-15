#include "contratlocation.h"
#include "connexion.h"
#include <QString>
#include <QDebug>
#include <QDate>
#include <QDateTime>
#include <QPushButton>

ContratLocation::ContratLocation()
{

    ID_Contrat=0;
    DateDebut = QDate::currentDate();
    DateFin = QDate::currentDate();
    ID_Agence = 0;
    ID_Agent = "";
    ReferenceVehicule ="";
    ID_Client ="";

}

ContratLocation::ContratLocation(QDate dateDebut ,QDate dateFin , int idAgence ,QString idAgent,QString referenceVehicule, QString idClient)
{

    this->DateDebut=dateDebut;
    this->DateFin=dateFin;
    this->ID_Agence=idAgence;
    this->ID_Agent=idAgent;
    this->ReferenceVehicule=referenceVehicule;
    this->ID_Client=idClient;
}

int ContratLocation::getIdContrat(){return ID_Contrat;}
QDate ContratLocation::getDateDebut(){return DateDebut;}
QDate ContratLocation::getDateFin(){return DateFin;}
int ContratLocation::getIdAgence(){return ID_Agence;}
QString ContratLocation::getIdAgent(){return ID_Agent;}
QString ContratLocation::getReferenceVehiule(){return ReferenceVehicule;}
QString ContratLocation::getIdClient(){return ID_Client;}

bool ContratLocation::ajouterContratLocation()
{
    QSqlQuery query;

    query.prepare("INSERT INTO CONTRATLOCATION (DATEDEBUT, DATEFIN, IDAGENCE, IDAGENT, REFERENCEVEHICULE, IDCLIENT) "
                        "VALUES (:db, :df, :idagence, :idagent, :ref, :idclient)");

    query.bindValue(":db", DateDebut);
    query.bindValue(":df", DateFin);
    query.bindValue(":idagence", ID_Agence);
    query.bindValue(":idagent", ID_Agent);
    query.bindValue(":ref", ReferenceVehicule);
    query.bindValue(":idclient", ID_Client);
    return    query.exec();
}

bool ContratLocation::supprimerContratLocation(int id)
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("Delete from CONTRATLOCATION where IDCONTRAT = :id ");
    query.bindValue(":id", res);
    return    query.exec();
}

bool ContratLocation::modifierContratLocation(int id)
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("UPDATE CONTRATLOCATION SET DATEDEBUT = :db, DATEFIN = :df, IDAGENCE = :idagence, IDAGENT = :idagent , REFERENCEVEHICULE = :ref, IDCLIENT = :idclient   where IDCONTRAT = :id ");
    query.bindValue(":id", res);
    query.bindValue(":db", DateDebut);
    query.bindValue(":df", DateFin);
    query.bindValue(":idagence", ID_Agence);
    query.bindValue(":idagent", ID_Agent);
    query.bindValue(":ref", ReferenceVehicule);
    query.bindValue(":idclient", ID_Client);
    return    query.exec();
}

QSqlQueryModel* ContratLocation::afficherContrat()
{
    QPushButton *delButton;
    delButton = new QPushButton();
    delButton->setText("Supprimer");
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from CONTRATLOCATION");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID CONTRAT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE DEBUT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE FIN"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID AGENCE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID AGENT"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("REFERENCE VEHICULE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("ID CLIENT"));

    return model;
}

QSqlQueryModel *ContratLocation::triDateDec()
{
    QSqlQuery* query = new QSqlQuery();

    QSqlQueryModel * model= new QSqlQueryModel();
    query->prepare("select * from CONTRATLOCATION ORDER BY IDCONTRAT DESC");
    query->exec();

    model->setQuery(*query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID CONTRAT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE DEBUT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE FIN"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID AGENCE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID AGENT"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("REFERENCE VEHICULE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("ID CLIENT"));
    return model;
}

QSqlQueryModel *ContratLocation::triDateCroi()
{
    QSqlQuery* query = new QSqlQuery();

    QSqlQueryModel * model= new QSqlQueryModel();
    query->prepare("select * from CONTRATLOCATION ORDER BY IDCONTRAT");
    query->exec();

    model->setQuery(*query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID CONTRAT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE DEBUT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE FIN"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID AGENCE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID AGENT"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("REFERENCE VEHICULE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("ID CLIENT"));
    return model;
}

QSqlQueryModel* ContratLocation::rechercherContrat(QString id)
{

    QSqlQuery* query = new QSqlQuery();

    QSqlQueryModel * model= new QSqlQueryModel();
    query->prepare("select * from CONTRATLOCATION WHERE IDCONTRAT like '"+id+"%'");
    query->exec();

    model->setQuery(*query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID CONTRAT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE DEBUT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE FIN"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID AGENCE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID AGENT"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("REFERENCE VEHICULE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("ID CLIENT"));
    return model;
}
