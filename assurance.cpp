#include "assurance.h"

Assurance::Assurance()
{
    Reference=0;
    Type="";
    Assureur="";
    Tarif=0;
}

Assurance::Assurance(QString type,QString assureur,float tarif)
{
    this->Type = type;
    this->Assureur = assureur;
    this->Tarif = tarif;
}

bool Assurance::ajoutAssurance()
{
    QSqlQuery query;

    query.prepare("INSERT INTO ASSURANCE (TYPE, ASSUREUR, TARIF) "
                        "VALUES (:type, :assureur, :tarif)");

    query.bindValue(":type", Type);
    query.bindValue(":assureur", Assureur);
    query.bindValue(":tarif", Tarif);

    return    query.exec();
}

bool Assurance::modifierAssurance(int ref)
{
    QSqlQuery query;
    QString res= QString::number(ref);
    query.prepare("UPDATE ASSURANCE SET TYPE = :type, ASSUREUR = :assureur, TARIF = :tarif where REFERENCE = :ref ");
    query.bindValue(":ref", res);
    query.bindValue(":type", Type);
    query.bindValue(":assureur", Assureur);
    query.bindValue(":tarif", Tarif);
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
    return model;
}
