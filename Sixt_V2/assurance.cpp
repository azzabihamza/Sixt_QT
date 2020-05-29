#include "assurance.h"
#include "connexion.h"

Assurance::Assurance()
{
    Reference=0;
    Type="";
    Assureur="";
    Tarif=NULL;
    dateEmission = QDate::currentDate();
    dateExpiration = QDate::currentDate();
    matriculeVehicule ="";
}

QDate Assurance::getDateEmission()
{
    return dateEmission;
}

QDate Assurance::getDateExpiration()
{
    return dateExpiration;
}

QString Assurance::getMatriculeVehicule()
{
    return matriculeVehicule;
}

Assurance::Assurance(QString type,QString assureur,double tarif,QDate dEmission, QDate dExpiration, QString matricule)
{
    this->Type = type;
    this->Assureur = assureur;
    this->Tarif = tarif;
    this->dateEmission = dEmission;
    this->dateExpiration = dExpiration;
    this->matriculeVehicule = matricule;
}

int Assurance::getReference()
{
    return Reference;
}

QString Assurance::getType()
{
    return Type;
}

QString Assurance::getAssureur()
{
    return Assureur;
}

double Assurance::getTarif()
{
    return Tarif;
}

bool Assurance::ajoutAssurance()
{
    QSqlQuery query;

    query.prepare("INSERT INTO ASSURANCE (TYPE, ASSUREUR, TARIF, DATEDEBUT, DATEFIN, MATRICULE) "
                        "VALUES (:type, :assureur, :tarif, :dd, :df, :matricule)");

    query.bindValue(":type", Type);
    query.bindValue(":assureur", Assureur);
    query.bindValue(":tarif", Tarif);
    query.bindValue(":dd", dateEmission);
    query.bindValue(":df", dateExpiration);
    query.bindValue(":matricule", matriculeVehicule);

    return    query.exec();
}

bool Assurance::modifierAssurance(int ref)
{
    QSqlQuery query;
    QString res= QString::number(ref);
    query.prepare("UPDATE ASSURANCE SET TYPE = :type, ASSUREUR = :assureur, TARIF = :tarif, DATEDEBUT = :dd, DATEFIN = :df, MATRICULE = :matricule where REFERENCE = :ref ");
    query.bindValue(":ref", res);
    query.bindValue(":type", Type);
    query.bindValue(":assureur", Assureur);
    query.bindValue(":tarif", Tarif);
    query.bindValue(":dd", dateEmission);
    query.bindValue(":df", dateExpiration);
    query.bindValue(":matricule", matriculeVehicule);
    return    query.exec();
}

bool Assurance::supprimerAssurance(int ref)
{
    QSqlQuery query;
    QString res= QString::number(ref);
    query.prepare("Delete from ASSURANCE where REFERENCE = :ref ");
    query.bindValue(":ref", res);
    return    query.exec();
}

QSqlQueryModel *Assurance::afficherAssurance()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from ASSURANCE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REFERENCE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ASSUREUR"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("TARIF"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE EMISSION"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("DATE EXPIRATION"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("MATRICULE"));
    return model;
}

QSqlQueryModel *Assurance::rechercherAssurance(QString ref)
{
    QSqlQuery* query = new QSqlQuery();

    QSqlQueryModel * model= new QSqlQueryModel();
    query->prepare("select * from ASSURANCE WHERE REFERENCE like '"+ref+"%'");
    query->exec();

    model->setQuery(*query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REFERENCE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ASSUREUR"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("TARIF"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE EMISSION"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("DATE EXPIRATION"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("MATRICULE"));
    return model;
}
