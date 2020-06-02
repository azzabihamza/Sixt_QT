#include "personnel.h"
#include <QSqlQuery>
#include <QPdfWriter>
#include <QPainter>

Personnel::Personnel()
{

}

Personnel::Personnel(int id,QString nom,QString prenom,QDate datenaissance,QDate datembauche,QString adresse,QString tel,QString email, QString role,int codepostal,QString ville,QString pays)
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->datenaissance=datenaissance;
    this->datembauche=datembauche;
    this->adresse=adresse;
    this->tel=tel;
    this->email=email;
    this->role=role;
    this->codepostal=codepostal;
    this->ville=ville;
    this->pays=pays;

}

bool Personnel::ajouter_Personnel()
{
    QSqlQuery query;

    query.prepare("INSERT INTO PERSONNEL (ID, NOM, PRENOM, DATENAISSANCE, DATEEMBAUCHE, ADRESSE, TEL, EMAIL, ROLE, CODEPOSTAL, VILLE, PAYS) "
                        "VALUES (:id, :nom, :prenom, :datenaissance, :datembauche, :adresse, :tel, :email, :role, :codepostal, :ville, :pays)");

    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":datenaissance", datenaissance);
    query.bindValue(":datembauche", datembauche);
    query.bindValue(":adresse", adresse);
    query.bindValue(":tel", tel);
    query.bindValue(":email", email);
    query.bindValue(":role", role);
    query.bindValue(":codepostal", codepostal);
    query.bindValue(":ville", ville);
    query.bindValue(":pays", pays);


    return    query.exec();
}

bool Personnel::modifier_Personnel()
{
    QSqlQuery query;
    query.prepare("UPDATE PERSONNEL SET ID= :id ,NOM = :nom, PRENOM = :prenom , DATENAISSANCE = :datenaissance, DATEEMBAUCHE = :datembauche, ADRESSE= :adresse,TEL= :tel,EMAIL= :email,ROLE =:role,CODEPOSTAL= :codepostal,VILLE= :ville,PAYS= :pays where ID=:id");
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":datenaissance", datenaissance);
    query.bindValue(":datembauche", datembauche);
    query.bindValue(":adresse", adresse);
    query.bindValue(":tel", tel);
    query.bindValue(":email", email);
    query.bindValue(":role", role);
    query.bindValue(":codepostal", codepostal);
    query.bindValue(":ville", ville);
    query.bindValue(":pays", pays);

    return    query.exec();
}

bool Personnel::supprimer_Personnel(int id)
{
    QSqlQuery query;
    query.prepare("Delete from PERSONNEL where ID=:id");
    query.bindValue(":id",id);
    return    query.exec();
}

QSqlQueryModel *Personnel::afficher_Personnel()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from PERSONNEL");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATENAISSANCE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATEEMBAUCHE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("TEL"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("EMAIL"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("ROLE"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("CODEPOSTAL"));
    model->setHeaderData(10, Qt::Horizontal, QObject::tr("VILLE"));
    model->setHeaderData(11, Qt::Horizontal, QObject::tr("PAYS"));

    return model;
}

QSqlQueryModel * Personnel::rechercher(QSqlQuery q)
{
    QSqlQueryModel *model= new QSqlQueryModel();

    model->setQuery(q);
    return (model);
}

QSqlQueryModel * Personnel::actualiser()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from PERSONNEL");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATENAISSANCE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATEEMBAUCHE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("TEL"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("EMAIL"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("ROLE"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("CODEPOSTAL"));
    model->setHeaderData(10, Qt::Horizontal, QObject::tr("VILLE"));
    model->setHeaderData(11, Qt::Horizontal, QObject::tr("PAYS"));

    return model;
}

QSqlQueryModel *Personnel::tricrois_Personnel()
{
    QSqlQuery* query = new QSqlQuery();

    QSqlQueryModel * model= new QSqlQueryModel();
    query->prepare("select * from PERSONNEL ORDER BY ID");
    query->exec();
    model->setQuery(*query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATENAISSANCE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATEEMBAUCHE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("TEL"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("EMAIL"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("ROLE"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("CODEPOSTAL"));
    model->setHeaderData(10, Qt::Horizontal, QObject::tr("VILLE"));
    model->setHeaderData(11, Qt::Horizontal, QObject::tr("PAYS"));
    return model;
}

QSqlQueryModel *Personnel::tridecrois_Personnel()
{
    QSqlQuery* query = new QSqlQuery();
    QSqlQueryModel * model= new QSqlQueryModel();
    query->prepare("select * from PERSONNEL ORDER BY ID DESC");
    query->exec();
    model->setQuery(*query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATENAISSANCE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATEEMBAUCHE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("TEL"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("EMAIL"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("ROLE"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("CODEPOSTAL"));
    model->setHeaderData(10, Qt::Horizontal, QObject::tr("VILLE"));
    model->setHeaderData(11, Qt::Horizontal, QObject::tr("PAYS"));
    return model;
}

