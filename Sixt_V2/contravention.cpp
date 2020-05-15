#include "contravention.h"
#include <QString>
#include "QSqlQuery"
#include "QSqlQueryModel"
#include <QDate>

contravention::contravention()
{

}
contravention::contravention(QString ID_C,QDate DATE_C,QString TYPE)
{
    this->ID_C=ID_C;
    this->TYPE=TYPE;
    this->DATE_C=DATE_C;
}


QString contravention::get_id_c(){return  ID_C;}
QString contravention::get_type_c(){return  TYPE;}
QDate contravention::get_date_c(){return  DATE_C;}




void contravention::set_id_c(QString ID_C){this->ID_C=ID_C;}
void contravention::set_type_c(QString TYPE){this->TYPE=TYPE;}
void contravention::set_date_c(QDate DATE_C){this->DATE_C=DATE_C;}


bool contravention::ajouter_contravention()
{
    QSqlQuery query;
    query.prepare("INSERT INTO CONTRAVENTION ( ID_C, DATE_C , TYPE  ) "
                        "VALUES (:id, :date, :type)");

    query.bindValue(":id", ID_C);
     query.bindValue(":date", DATE_C);
    query.bindValue(":type", TYPE);

    return    query.exec();

}


QSqlQueryModel * contravention::afficher_contravention()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from CONTRAVENTION");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_C"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_C"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));

    return model;
}

bool contravention::supprimer_contravention(QString ID_C )
{
QSqlQuery query;
QString res= QString(ID_C);
query.prepare("Delete from CONTRAVENTION where ID_C =:ID_C ");
query.bindValue(":ID_C", res);
return    query.exec();
}


bool contravention::modifier_contravention(contravention p)
{
    QSqlQuery query;
    query.prepare("UPDATE CONTRAVENTION set DATE_C=:date , TYPE=:type where ID_C =:id ");
    query.bindValue(":id", p.get_id_c());
     query.bindValue(":date", p.get_date_c());
    query.bindValue(":type", p.get_type_c());

    return    query.exec();
}

QSqlQueryModel * contravention::afficher_contraventionlist()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select ID_C from CONTRAVENTION");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_C"));
        return model;
}


QSqlQueryModel * contravention::rechercher(QSqlQuery q)
{
    QSqlQueryModel *model= new QSqlQueryModel();

    model->setQuery(q);
    return (model);
}


bool contravention::verif_id(QString ch_id){
   bool test=true;
   int i;
   if(ch_id.length()!=8){
      test=false;
      return  test;
   }else{
       for(i=0;i<ch_id.length();i++){
           if(!((ch_id[i]>='0')&&(ch_id[i]<='9'))){
               test=false;
               return  test;
       }
       }
   }
return test;}
bool contravention::verif_nom(QString nom){
    bool test=true;
    int i;
    if(nom.length()>20){
       test=false;
       return  test;
    }else{
        for(i=0;i<nom.length();i++){
            if(!(((nom[i]>='A')&&(nom[i]<='Z'))||((nom[i]>='a')&&(nom[i]<='z')))){
                test=false;
                return  test;
        }
    }
  }
    return  test;
}
