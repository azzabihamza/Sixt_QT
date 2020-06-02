#include "promotions.h"
#include <QString>
#include <QMessageBox>
promotions::promotions()
{
idpromo="";
pourcentage=0;
nomp="";
}

promotions::promotions(QString idpromo , QString nomp ,int pourcentage)
{
    this->idpromo=idpromo ;
    this->nomp=nomp ;
    this->pourcentage=pourcentage ;


}
QString  promotions::get_nomp()
{ return nomp ;}
int promotions::get_pourcentage()
{return pourcentage;}
QString promotions::get_idpromo()
{return idpromo ;}

bool promotions::ajouter_p()
{

    QSqlQuery query ;

    query.prepare("INSERT INTO promo (idpromo,nomp,pourcentage)" "VALUES (:idpromo , :nomp , :pourcentage)");
    query.bindValue(":idpromo",idpromo);
    query.bindValue(":nomp",nomp);
    query.bindValue(":pourcentage",pourcentage);
    return query.exec();

}
QSqlQueryModel * promotions::afficher_p()
{
QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("select *from promo");
model->setHeaderData(0,Qt::Horizontal ,QObject::tr("idpromo"));
model->setHeaderData(1,Qt::Horizontal ,QObject::tr("nomp"));
model->setHeaderData(2,Qt::Horizontal ,QObject::tr("pourcentage"));

return model ;
}
bool promotions::supprimer_p(int idpromo)
{
    QSqlQuery query;
    QString res=QString::number(idpromo);
    query.prepare("delete from promo where IDPROMO=:idpromo");
    query.bindValue(":idpromo",idpromo);
    return query.exec();

}

bool promotions::modifier_p(promotions p)
{
    QSqlQuery query;


    query.prepare("UPDATE promo SET nomp= :nomp,pourcentage = :pourcentage WHERE idpromo= :idpromo");
    query.bindValue(":idpromo",p.get_idpromo());
    query.bindValue(":pourcentage",p.get_pourcentage());
    query.bindValue(":nomp",p.get_nomp());
    return query.exec();
}


QSqlQueryModel * promotions::rechercher_m(QSqlQuery q)
{
    QSqlQueryModel *model= new QSqlQueryModel();

    model->setQuery(q);
    return (model);
}
QSqlQueryModel * promotions::actualiser()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from PROMO");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDPROMO"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMP"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("POURCENTAGE"));

    return model;
}
