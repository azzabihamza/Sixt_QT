#ifndef CONTRAVENTION_H
#define CONTRAVENTION_H

#include "QString"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include <QDate>

class contravention
{
public:
    contravention();
    contravention(QString,QDate,QString);
    QString get_id_c();
    QDate get_date_c();
    QString get_type_c();


    void set_id_c(QString);
    void set_date_c(QDate);
    void set_type_c(QString);



    bool ajouter_contravention();
    QSqlQueryModel * afficher_contravention();
    bool supprimer_contravention(QString);
    bool modifier_contravention(contravention);
     QSqlQueryModel *rechercher(QSqlQuery);
     QSqlQueryModel * afficher_contraventionlist();
     bool verif_id(QString);
     bool verif_nom(QString);

private:
    QString ID_C,TYPE;
    QDate DATE_C;
};

#endif // CONTRAVENTION_H
