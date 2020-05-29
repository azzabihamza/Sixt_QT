#include "agence.h"
#include <QSqlQuery>
#include <QPdfWriter>
#include <QPainter>

Agence::Agence()
{

}

Agence::Agence(int idagence,QString nomagence,int idchefagence, int budget, QString adresse , QString pays, QString ville, QString type)
{
    this->idagence=idagence;
    this->nomagence=nomagence;
    this->idchefagence=idchefagence;
    this->budget=budget;
    this->adresse=adresse;
    this->pays=pays;
    this->ville=ville;
    this->type=type;
}

bool Agence::ajouter_agence()
{
    QSqlQuery query;

    query.prepare("INSERT INTO AGENCE ( ID_AGENCE, NOMAGENCE ,ID_CHEFAGENCE, BUDGET, ADRESSE, PAYS, VILLE, TYPE) "
                        "VALUES (:idagence, :nomagence, :idchefagence, :budget, :adresse, :pays, :ville, :type)");

    query.bindValue(":idagence", idagence);
    query.bindValue(":nomagence", nomagence);
    query.bindValue(":idchefagence", idchefagence);
    query.bindValue(":budget", budget);
    query.bindValue(":adresse", adresse);
    query.bindValue(":pays", pays);
    query.bindValue(":ville", ville);
    query.bindValue(":type", type);
    return    query.exec();
}

bool Agence::modifier_agence()
{
    QSqlQuery query;
    query.prepare("UPDATE AGENCE SET ID_AGENCE=:idagence, NOMAGENCE =:nomagence, ID_CHEFAGENCE =:idchefagence, BUDGET=:budget, ADRESSE =:adresse , PAYS =:pays, VILLE =:ville, TYPE =:type where ID_AGENCE= :idagence ");
    query.bindValue(":idagence", idagence);
    query.bindValue(":nomagence", nomagence);
    query.bindValue(":idchefagence", idchefagence);
    query.bindValue(":budget", budget);
    query.bindValue(":adresse", adresse);
    query.bindValue(":pays", pays);
    query.bindValue(":ville", ville);
    query.bindValue(":type", type);
    return    query.exec();
}

bool Agence::supprimer_agence(int id)
{
    QSqlQuery query;
    query.prepare("Delete from AGENCE where ID_Agence=:id");
    query.bindValue(":id",id);
    return    query.exec();
}

QSqlQueryModel *Agence::afficher_agence()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from AGENCE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_AGENCE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMAGENCE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID_CHEFAGENCE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("BUDGET"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("PAYS"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("VILLE"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("TYPE"));
    return model;
}

QSqlQueryModel * Agence::rechercher(QSqlQuery q)
{
    QSqlQueryModel *model= new QSqlQueryModel();

    model->setQuery(q);
    return (model);
}

QSqlQueryModel *Agence::tricrois_agence()
{
    QSqlQuery* query = new QSqlQuery();

    QSqlQueryModel * model= new QSqlQueryModel();
    query->prepare("select * from AGENCE ORDER BY ID_AGENCE");
    query->exec();
    model->setQuery(*query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_AGENCE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMAGENCE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("BUDGET"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("PAYS"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("VILLE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("TYPE"));
    return model;
}

QSqlQueryModel *Agence::tridecrois_agence()
{
    QSqlQuery* query = new QSqlQuery();

    QSqlQueryModel * model= new QSqlQueryModel();
    query->prepare("select * from AGENCE ORDER BY ID_AGENCE DESC");
    query->exec();
    model->setQuery(*query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_AGENCE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMAGENCE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("BUDGET"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("PAYS"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("VILLE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("TYPE"));
    return model;
}

QSqlQueryModel *Agence::actualiser()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from AGENCE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_AGENCE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMAGENCE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID_CHEFAGENCE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("BUDGET"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("PAYS"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("VILLE"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("TYPE"));
    return model;
}


