#include "vehicules.h"
#include <QString>
#include "QSqlQuery"
#include "QSqlQueryModel"

vehicules::vehicules()
{

}
vehicules::vehicules(QString REF,QString MARQUE,QString CARBURANT,QString PLAQUE,QString AGE,QString PRIX,QString ID_C)
{
    this->REF=REF;
    this->MARQUE=MARQUE;
    this->CARBURANT=CARBURANT;
    this->PLAQUE=PLAQUE;
    this->AGE=AGE;
    this->PRIX=PRIX;
    this->ID_C=ID_C;
}


QString vehicules::get_REF(){return  REF;}
QString vehicules::get_MARQUE(){return  MARQUE;}
QString vehicules::get_CARBURANT(){return  CARBURANT;}
QString vehicules::get_PLAQUE(){return  PLAQUE;}
QString vehicules::get_AGE(){return AGE;}
QString vehicules::get_PRIX(){return PRIX;}
QString vehicules::get_ID_c(){return ID_C;}


void vehicules::set_REF(QString REF){this->REF=REF;};
void vehicules::set_MARQUE(QString MARQUE){this->MARQUE=MARQUE;};
void vehicules::set_CARBURANT(QString CARBURANT){this->CARBURANT=CARBURANT;};
void vehicules::set_PLAQUE(QString PLAQUE){this->PLAQUE=PLAQUE;};
void vehicules::set_AGE(QString AGE){this->AGE=AGE;};
void vehicules::set_PRIX(QString PRIX){this->PRIX=PRIX;};
void vehicules::set_ID_c(QString ID_C){this->ID_C=ID_C;};

bool vehicules::ajouter_vehicules()
{
    QSqlQuery query;
    query.prepare("INSERT INTO VEHICULES ( REF, MARQUE , CARBURANT , PLAQUE , AGE , PRIX , ID_C ) "
                        "VALUES (:ref, :marque, :carburant, :plaque,  :age , :prix  ,:id_c)");

    query.bindValue(":ref", REF);
    query.bindValue(":marque", MARQUE);
    query.bindValue(":carburant", CARBURANT);
    query.bindValue(":plaque", PLAQUE);
    query.bindValue(":age", AGE);
    query.bindValue(":prix", PRIX);
    query.bindValue(":id_c", ID_C);

    return    query.exec();

}


QSqlQueryModel * vehicules::afficher_vehicules()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from VEHICULES");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("MARQUE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("CARBURANT"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("PLAQUE"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("AGE"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("PRIX"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("ID_C"));

    return model;
}

bool vehicules::supprimer_vehicules(QString REF )
{
QSqlQuery query;
QString res= QString(REF);
query.prepare("Delete from VEHICULES where REF =:REF ");
query.bindValue(":REF", res);
return    query.exec();
}


bool vehicules::modifier_vehicules(vehicules p)
{
    QSqlQuery query;
    query.prepare("UPDATE VEHICULES set MARQUE=:m , CARBURANT=:n ,PLAQUE=:p, AGE=:a ,PRIX=:s ,ID_C=:i where REF =:ref ");
    query.bindValue(":ref",p.get_REF());
    query.bindValue(":m",p.get_MARQUE());
    query.bindValue(":n",p.get_CARBURANT());
    query.bindValue(":p",p.get_PLAQUE());
    query.bindValue(":a",p.get_AGE());
    query.bindValue(":s",p.get_PRIX());
    query.bindValue(":i",p.get_ID_c());

    return    query.exec();
}

QSqlQueryModel * vehicules::afficher_vehiculeslist()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select REF from VEHICULES");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF"));
        return model;
}


QSqlQueryModel * vehicules::rechercher(QSqlQuery q)
{
    QSqlQueryModel *model= new QSqlQueryModel();

    model->setQuery(q);//affichage
    return (model);
}


bool vehicules::verif_id(QString ch_id){
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
bool vehicules::verif_nom(QString nom){
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
