#include "publicite.h"
#include <QString>
#include <QMessageBox>


Publicite::Publicite()
{


}
Publicite::Publicite(int id , QString nom ,QDate date_pub)
{
    this->id=id ;
    this->nom=nom ;
    this->date_pub=date_pub ;




}
QString  Publicite::get_nom()
{ return nom ;}
QDate Publicite::get_date_pub()
{return date_pub;}
int Publicite::get_id()
{return id ;}

bool Publicite::ajouter()
{

    QSqlQuery query ;
    QString res= QString::number(id);
    query.prepare("INSERT INTO Publicite (id,nom,date_pub)" "VALUES (:id , :nom , :date_pub)");
    query.bindValue(":id",res);
    query.bindValue(":nom",nom);
    query.bindValue(":date_pub",date_pub);
    return query.exec();

}
QSqlQueryModel * Publicite::afficher()
{
QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("select *from Publicite");
model->setHeaderData(0,Qt::Horizontal ,QObject::tr("ID"));
model->setHeaderData(1,Qt::Horizontal ,QObject::tr("NOM"));
model->setHeaderData(2,Qt::Horizontal ,QObject::tr("DATE"));

return model ;
}
bool Publicite::supprimer(int id)
{
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("delete from Publicite where ID=:id");
    query.bindValue(":id",id);
    return query.exec();

}

bool Publicite::modifier(Publicite e)
{
    QSqlQuery query;


    query.prepare("UPDATE Publicite SET nom= :nom, date_pub= :date_pub WHERE id= :id");
    query.bindValue(":id",e.get_id());
    query.bindValue(":date_pub",e.get_date_pub());
    query.bindValue(":nom",e.get_nom());
    return query.exec();
}


QSqlQueryModel * Publicite::rechercher(QSqlQuery q)
{
    QSqlQueryModel *model= new QSqlQueryModel();

    model->setQuery(q);
    return (model);
}
