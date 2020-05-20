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

Convention::Convention(QString c_nom,QString c_adresse, int c_numtel, QString c_email)
{
    this->c_nom=c_nom;
    this->c_adresse=c_adresse;
    this->c_numtel=c_numtel;
    this->c_email=c_email;
}

bool Convention::ajouter_convention()
{
    QSqlQuery query;

    query.prepare("INSERT INTO CONVENTION ( C_NOM, C_ADRESSE, C_NUMTEL, C_EMAIL) "
                        "VALUES (:c_nom, :c_adresse, :c_numtel, :c_email)");

    query.bindValue(":c_nom", c_nom);
    query.bindValue(":c_adresse", c_adresse);
    query.bindValue(":c_numtel", c_numtel);
    query.bindValue(":c_email", c_email);
    return    query.exec();
}

bool Convention::modifier_convention(QString c_code2)
{
    QSqlQuery query;
    query.prepare("UPDATE CONVENTION SET C_NOM = :c_nom, C_ADRESSE = :c_adresse , C_NUMTEL = :c_numtel, C_EMAIL = :c_email  where C_CODE = :c_code2 ");
    query.bindValue(":c_code", c_code2);
    query.bindValue(":c_nom", c_nom);
    query.bindValue(":c_adresse", c_adresse);
    query.bindValue(":c_numtel", c_numtel);
    query.bindValue(":c_email", c_email);
    return    query.exec();
}

bool Convention::supprimer_convention(QString c_code2)
{
    QSqlQuery query;
    query.prepare("Delete from CONVENTION where C_CODE = :c_code2 ");
    query.bindValue(":code", c_code2);
    return    query.exec();
}

QSqlQueryModel *Convention::afficher_convention()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from CONVENTION");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CODE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NUMERO DE TELEPHONE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("EMAIL"));
    return model;
}

QSqlQueryModel *Convention::rechercher_convention(QString c_code2)
{
    QSqlQuery* query = new QSqlQuery();

    QSqlQueryModel * model= new QSqlQueryModel();
    query->prepare("select * from CONVENTION WHERE C_CODE like '"+c_code2+"%'");
    query->exec();
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CODE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NUMERO DE TELEPHONE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("EMAIL"));
    return model;
}

QSqlQueryModel *Convention::tricrois_convention()
{
    QSqlQuery* query = new QSqlQuery();

    QSqlQueryModel * model= new QSqlQueryModel();
    query->prepare("select * from CONVENTION ORDER BY C_CODE");
    query->exec();
    model->setQuery(*query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CODE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NUMERO DE TELEPHONE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("EMAIL"));
    return model;
}

QSqlQueryModel *Convention::tridecrois_convention()
{
    QSqlQuery* query = new QSqlQuery();
    QSqlQueryModel * model= new QSqlQueryModel();
    query->prepare("select * from CONVENTION ORDER BY C_CODE DESC");
    query->exec();
    model->setQuery(*query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CODE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NUMERO DE TELEPHONE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("EMAIL"));
    return model;
}

bool Convention::pdf_convention(QString c_code2)
{
    QPdfWriter pdf("C:/Users/asus/Documents/Qt/PDFs/clients.pdf");
            QPainter painter;
            if (! painter.begin(&pdf))
            {
                // failed to open file
                                qWarning("failed to open file, is it writable?");

            }
            QString id =c_code2;
            const time_t ctt = time(0);
            QSqlQuery query;
            query.exec("SELECT * from CONVENTION where C_CODE = '"+id+"'");

                    while (query.next())
                          {

                        QString c_code = query.value(0).toString();
                        QString c_nom = query.value(1).toString();
                        QString c_adresse = query.value(2).toString();
                        QString c_numtel = query.value(3).toString();
                        QString c_email = query.value(4).toString();

                painter.drawText(2200,3500,c_code);
                painter.drawText(2200,4000,c_nom);
                painter.drawText(2200,4500,c_adresse);
                painter.drawText(2200,5000,c_numtel);
                painter.drawText(2200,5500,c_email);


                painter.setPen(Qt::blue);
                painter.setPen(Qt::black);
                painter.drawText(500,2000,asctime(localtime(&ctt)));
                painter.drawText(500,3500,"Code:");
                painter.drawText(500,4000,"Nom :");
                painter.drawText(500,4500,"Adresse :");
                painter.drawText(500,5000,"Numero de telephone :");
                painter.drawText(500,5500,"Email :");

            }
}
