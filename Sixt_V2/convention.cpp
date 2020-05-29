#include "convention.h"
#include <QSqlQuery>
#include <QPdfWriter>
#include <QPainter>

Convention::Convention()
{
    c_code=0;
    c_nom="";
    c_adresse="";
    c_numtel=0;
    c_email="";
}

QString Convention::getNomCon()
{
    return c_nom;
}

Convention::Convention(QString c_nom,QString c_adresse,int c_numtel, QString c_email)
{
    this->c_nom = c_nom;
    this->c_adresse = c_adresse;
    this->c_numtel = c_numtel;
    this->c_email = c_email;
}

int Convention::getCodeCon()
{
    return c_code;
}

QString Convention::getEmailCon()
{
    return c_email;
}

int Convention::getNumtelCon()
{
    return c_numtel;
}

QString Convention::getAdresseCon()
{
    return c_adresse;
}

bool Convention::ajoutConvention()
{
    QSqlQuery query;

    query.prepare("INSERT INTO CONVENTION (C_NOM, C_ADRESSE, C_NUMTEL, C_EMAIL) "
                        "VALUES (:c_nom, :c_adresse, :c_numtel, :c_email)");

    query.bindValue(":c_nom", c_nom);
    query.bindValue(":c_adresse", c_adresse);
    query.bindValue(":c_numtel", c_numtel);
    query.bindValue(":c_email", c_email);
    return    query.exec();
}

bool Convention::modifierConvention(int ref)
{
    QSqlQuery query;
    query.prepare("UPDATE CONVENTION SET C_NOM = :c_nom, C_ADRESSE = :c_adresse, C_NUMTEL = :c_numtel, C_EMAIL = :c_email where C_CODE = :ref ");
    query.bindValue(":ref", ref);
    query.bindValue(":c_nom", c_nom);
    query.bindValue(":c_adresse", c_adresse);
    query.bindValue(":c_numtel", c_numtel);
    query.bindValue(":c_email", c_email);
    return    query.exec();
}

bool Convention::supprimerConvention(int ref)
{
    QSqlQuery query;

    query.prepare("Delete from CONVENTION where C_CODE = :ref ");
    query.bindValue(":ref", ref);
    return    query.exec();
}

QSqlQueryModel *Convention::afficherConvention()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from CONVENTION");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CODE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NUM DE TELEPHONE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("EMAIL"));
    return model;
}

QSqlQueryModel *Convention::rechercherConvention(int ref)
{

    QString res= QString::number(ref);
    QSqlQuery* query = new QSqlQuery();
    QSqlQueryModel * model= new QSqlQueryModel();
    query->prepare("select * from CONVENTION WHERE C_CODE = '"+res+"'");

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
