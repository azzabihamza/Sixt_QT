#include "client.h"
#include <QSqlQuery>
#include <QPdfWriter>
#include <QPainter>

Client::Client()
{
    code="";
    nom="";
    prenom="";
    date_naissance=QDate::currentDate();
    adresse="";
    num_tel=0;
    email="";
    type_permis="";
    num_permis="";
    date_del=QDate::currentDate();
    datefin_del=QDate::currentDate();
    cin=0;
}

Client::Client(QString nom, QString prenom, QDate date_naissance, QString adresse, int num_tel, QString email, QString type_permis, QString num_permis, QDate date_del, QDate datefin_del, int cin)
{
    this->nom=nom;
    this->prenom=prenom;
    this->date_naissance=date_naissance;
    this->adresse=adresse;
    this->num_tel=num_tel;
    this->email=email;
    this->type_permis=type_permis;
    this->num_permis=num_permis;
    this->date_del=date_del;
    this->datefin_del=datefin_del;
    this->cin=cin;
}

bool Client::ajouter_client()
{
    QSqlQuery query;

    query.prepare("INSERT INTO CLIENT ( NOM, PRENOM, DATE_NAISSANCE, ADRESSE, NUM_TEL, EMAIL, TYPE_PERMIS, NUM_PERMIS, DATE_DEL, DATEFIN_DEL, CIN) "
                        "VALUES (:nom, :prenom, :date_naissance, :adresse, :num_tel, :email, :type_permis, :num_permis, :date_del, :datefin_del, :cin)");

    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":date_naissance", date_naissance);
    query.bindValue(":adresse", adresse);
    query.bindValue(":num_tel", num_tel);
    query.bindValue(":email", email);
    query.bindValue(":type_permis", type_permis);
    query.bindValue(":num_permis", num_permis);
    query.bindValue(":date_del", date_del);
    query.bindValue(":datefin_del", datefin_del);
    query.bindValue(":cin", cin);
    return    query.exec();
}

bool Client::modifier_client(QString code2)
{
    QSqlQuery query;
    query.prepare("UPDATE CLIENT SET NOM = :nom, PRENOM = :prenom, DATE_NAISSANCE = :date_naissance, ADRESSE = :adresse , NUM_TEL = :num_tel, EMAIL = :email, :TYPE_PERMIS = :type_permis, NUM_PERMIS = :num_permis, DATE_DEL = :date_del, DATEFIN_DEL = :datefin_del, CIN= :cin   where CODE = :code2 ");
    query.bindValue(":code", code2);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":date_naissance", date_naissance);
    query.bindValue(":adresse", adresse);
    query.bindValue(":num_tel", num_tel);
    query.bindValue(":email", email);
    query.bindValue(":type_permis", type_permis);
    query.bindValue(":num_permis", num_permis);
    query.bindValue(":date_del", date_del);
    query.bindValue(":datefin_del", datefin_del);
    query.bindValue(":cin", cin);
    return    query.exec();
}

bool Client::supprimer_client(QString code2)
{
    QSqlQuery query;
    query.prepare("Delete from CLIENT where CODE = :code2 ");
    query.bindValue(":code", code2);
    return    query.exec();
}

QSqlQueryModel *Client::afficher_client()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from CLIENT");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CODE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE DE NAISSANCE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("NUMERO DE TELEPHONE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("EMAIL"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("TYPE DU PERMIS"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("NUMERO DU PERMIS"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("DATE DE DELIVERANCE"));
    model->setHeaderData(10, Qt::Horizontal, QObject::tr("DATE D'EXPIRATION"));
    model->setHeaderData(11, Qt::Horizontal, QObject::tr("CIN"));
    return model;
}

QSqlQueryModel *Client::rechercher_client(QString code2)
{
    QSqlQuery* query = new QSqlQuery();

    QSqlQueryModel * model= new QSqlQueryModel();
    query->prepare("select * from CLIENT WHERE CODE like '"+code2+"%'");
    query->exec();
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CODE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE DE NAISSANCE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("NUMERO DE TELEPHONE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("EMAIL"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("TYPE DU PERMIS"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("NUMERO DU PERMIS"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("DATE DE DELIVERANCE"));
    model->setHeaderData(10, Qt::Horizontal, QObject::tr("DATE D'EXPIRATION"));
    model->setHeaderData(11, Qt::Horizontal, QObject::tr("CIN"));

    return model;
}

QSqlQueryModel *Client::tricrois_client()
{
    QSqlQuery* query = new QSqlQuery();

    QSqlQueryModel * model= new QSqlQueryModel();
    query->prepare("select * from CLIENT ORDER BY CODE");
    query->exec();

    model->setQuery(*query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CODE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE DE NAISSANCE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("NUMERO DE TELEPHONE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("EMAIL"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("TYPE DU PERMIS"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("NUMERO DU PERMIS"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("DATE DE DELIVERANCE"));
    model->setHeaderData(10, Qt::Horizontal, QObject::tr("DATE D'EXPIRATION"));
    model->setHeaderData(11, Qt::Horizontal, QObject::tr("CIN"));

    return model;
}

QSqlQueryModel *Client::tridecrois_client()
{
    QSqlQuery* query = new QSqlQuery();

    QSqlQueryModel * model= new QSqlQueryModel();
    query->prepare("select * from CLIENT ORDER BY CODE DESC");
    query->exec();

    model->setQuery(*query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CODE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE DE NAISSANCE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("NUMERO DE TELEPHONE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("EMAIL"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("TYPE DU PERMIS"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("NUMERO DU PERMIS"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("DATE DE DELIVERANCE"));
    model->setHeaderData(10, Qt::Horizontal, QObject::tr("DATE D'EXPIRATION"));
    model->setHeaderData(11, Qt::Horizontal, QObject::tr("CIN"));

    return model;
}

bool Client::pdf_client(QString code2)
{
    QPdfWriter pdf("C:/Users/asus/Documents/Qt/PDFs/clients.pdf");
            QPainter painter;
            if (! painter.begin(&pdf))
            {
                // failed to open file
                                qWarning("failed to open file, is it writable?");

            }
            QString id =code2;
            const time_t ctt = time(0);
            QSqlQuery query;
            query.exec("SELECT * from CLIENT where CODE = '"+id+"'");

                    while (query.next())
                          {

                        QString client_code = query.value(0).toString();
                        QString client_nom = query.value(1).toString();
                        QString client_prenom = query.value(2).toString();
                        QString client_date_naissance = query.value(3).toString();
                        QString client_adresse = query.value(4).toString();
                        QString client_num_tel = query.value(5).toString();
                        QString client_email = query.value(6).toString();
                        QString client_permis_type = query.value(7).toString();
                        QString client_permis_numero = query.value(8).toString();
                        QString client_date_del_permis = query.value(9).toString();
                        QString client_datefindel_permis = query.value(10).toString();
                        QString client_cin = query.value(11).toString();


                painter.drawText(2200,3500,client_code);
                painter.drawText(2200,4000,client_nom);
                painter.drawText(2200,4500,client_prenom);
                painter.drawText(2200,5000,client_date_naissance);
                painter.drawText(2200,5500,client_adresse);
                painter.drawText(2200,6000,client_num_tel);
                painter.drawText(2200,6500,client_email);
                painter.drawText(2200,7000,client_permis_type);
                painter.drawText(2200,7500,client_permis_numero);
                painter.drawText(2600,8000,client_date_del_permis);
                painter.drawText(2800,8500,client_datefindel_permis);
                painter.drawText(2200,9000,client_cin);

                painter.setPen(Qt::blue);
                painter.setPen(Qt::black);
                painter.drawText(500,2000,asctime(localtime(&ctt)));
                painter.drawText(500,3500,"Code:");
                painter.drawText(500,4000,"Nom :");
                painter.drawText(500,4500,"Prenom:");
                painter.drawText(500,5000,"Date de naissance:");
                painter.drawText(500,5500,"Adresse :");
                painter.drawText(500,6000,"Numero de telephone :");
                painter.drawText(500,6500,"Email :");
                painter.drawText(500,7000,"Type du permis :");
                painter.drawText(500,7500,"Numero du permis :");
                painter.drawText(500,8000,"Date de deliverance du permis :");
                painter.drawText(500,8500,"Date de fin de deliverance du permis :");
                painter.drawText(500,9000,"N° CIN :");

            }
}

