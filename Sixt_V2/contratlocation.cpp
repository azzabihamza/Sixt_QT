#include "contratlocation.h"
#include "connexion.h"
#include <QString>
#include <QDebug>
#include <QDate>
#include <QDateTime>
#include <QPushButton>
#include <QPdfWriter>
#include <QPrinter>
#include <QTextDocument>

ContratLocation::ContratLocation()
{

    ID_Contrat=0;
    DateDebut = QDate::currentDate();
    DateFin = QDate::currentDate();
    ID_Agence = 0;
    ID_Agent = "";
    ReferenceVehicule ="";
    ID_Client ="";

}

ContratLocation::ContratLocation(QDate dateDebut ,QDate dateFin , int idAgence ,QString idAgent,QString referenceVehicule, QString idClient)
{
    this->DateDebut=dateDebut;
    this->DateFin=dateFin;
    this->ID_Agence=idAgence;
    this->ID_Agent=idAgent;
    this->ReferenceVehicule=referenceVehicule;
    this->ID_Client=idClient;
}

int ContratLocation::getIdContrat(){return ID_Contrat;}
QDate ContratLocation::getDateDebut(){return DateDebut;}
QDate ContratLocation::getDateFin(){return DateFin;}
int ContratLocation::getIdAgence(){return ID_Agence;}
QString ContratLocation::getIdAgent(){return ID_Agent;}
QString ContratLocation::getReferenceVehiule(){return ReferenceVehicule;}
QString ContratLocation::getIdClient(){return ID_Client;}

bool ContratLocation::ajouterContratLocation()
{
    QSqlQuery query;

    query.prepare("INSERT INTO CONTRATLOCATION (DATEDEBUT, DATEFIN, IDAGENCE, IDAGENT, REFERENCEVEHICULE, IDCLIENT) "
                        "VALUES (:db, :df, :idagence, :idagent, :ref, :idclient)");

    query.bindValue(":db", DateDebut);
    query.bindValue(":df", DateFin);
    query.bindValue(":idagence", ID_Agence);
    query.bindValue(":idagent", ID_Agent);
    query.bindValue(":ref", ReferenceVehicule);
    query.bindValue(":idclient", ID_Client);
    return    query.exec();
}

bool ContratLocation::supprimerContratLocation(int id)
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("Delete from CONTRATLOCATION where IDCONTRAT = :id ");
    query.bindValue(":id", res);
    return    query.exec();
}

bool ContratLocation::modifierContratLocation(int id)
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("UPDATE CONTRATLOCATION SET DATEDEBUT = :db, DATEFIN = :df, IDAGENCE = :idagence, IDAGENT = :idagent , REFERENCEVEHICULE = :ref, IDCLIENT = :idclient   where IDCONTRAT = :id ");
    query.bindValue(":id", res);
    query.bindValue(":db", DateDebut);
    query.bindValue(":df", DateFin);
    query.bindValue(":idagence", ID_Agence);
    query.bindValue(":idagent", ID_Agent);
    query.bindValue(":ref", ReferenceVehicule);
    query.bindValue(":idclient", ID_Client);
    return    query.exec();
}

QSqlQueryModel* ContratLocation::afficherContrat()
{

    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from CONTRATLOCATION");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID CONTRAT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE DEBUT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE FIN"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID AGENCE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID AGENT"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("REFERENCE VEHICULE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("ID CLIENT"));

    return model;
}

QSqlQueryModel *ContratLocation::triDateDec()
{
    QSqlQuery* query = new QSqlQuery();

    QSqlQueryModel * model= new QSqlQueryModel();
    query->prepare("select * from CONTRATLOCATION ORDER BY IDCONTRAT DESC");
    query->exec();

    model->setQuery(*query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID CONTRAT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE DEBUT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE FIN"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID AGENCE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID AGENT"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("REFERENCE VEHICULE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("ID CLIENT"));
    return model;
}

QSqlQueryModel *ContratLocation::triDateCroi()
{
    QSqlQuery* query = new QSqlQuery();

    QSqlQueryModel * model= new QSqlQueryModel();
    query->prepare("select * from CONTRATLOCATION ORDER BY IDCONTRAT");
    query->exec();

    model->setQuery(*query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID CONTRAT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE DEBUT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE FIN"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID AGENCE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID AGENT"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("REFERENCE VEHICULE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("ID CLIENT"));
    return model;
}

void ContratLocation::ContratPDF(QString IdContrat)
{
    QString fileName = "E:\\Projects\\Projet QT\\Sixt_V2\\src\\contrat_location.pdf";

    QSqlQuery query;
    QSqlQuery query2;
    QSqlQuery query3;
    query.exec("select * from CONTRATLOCATION WHERE IDCONTRAT like '"+IdContrat+"%'");
    while (query.next()){
    code = query.value(0).toString();
    dateD = query.value(1).toString();
    dateF = query.value(2).toString();
    agence = query.value(3).toString();
    agent = query.value(4).toString();
    reference = query.value(5).toString();
    client = query.value(6).toString();


    query2.exec("SELECT * from CLIENT where CIN = '"+client+"'");
                while (query2.next()){
                client_code = query2.value(0).toString();
                client_nom = query2.value(1).toString();
                client_prenom = query2.value(2).toString();
                client_date_naissance = query2.value(3).toString();
                client_adresse = query2.value(4).toString();
                client_num_tel = query2.value(5).toString();
                client_email = query2.value(6).toString();
                client_permis_type = query2.value(7).toString();
                client_permis_numero = query2.value(8).toString();
                client_date_del_permis = query2.value(9).toString();
                client_datefindel_permis = query2.value(10).toString();
                client_cin = query2.value(11).toString();


        query.exec("select * from VEHICULES WHERE REF like '"+reference+"%'");

        while (query3.next()){
        marque = query3.value(1).toString();
        carburant = query3.value(2).toString();
        plaque = query3.value(3).toString();
        age = query3.value(4).toString();
        prix = query3.value(5).toString();
        }
       }
      }

        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4);
        printer.setOutputFileName(fileName);

        QTextDocument doc;
        doc.setHtml("    <center><p><strong>&nbsp;&nbsp;&nbsp; </strong><strong><span style=\"color: #ff6600;\">CONTRAT DE LOCATION VEHICULE SIXT </span><br /></strong></p></center>"
               " <p><br /></p>"
               " <p><strong>Contrat n</strong><strong>&deg;</strong><strong> : '"+code+"'</strong><span style=\"font-weight: 400;\"> <br /></span></p>"
                "<p>&nbsp;</p>"
                "<p><span style=\"font-weight: 400;\">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; </span><span style=\"font-weight: 400;\">Mr : '"+client_prenom+"' '"+client_nom+"'<br /></span></p>"
                "<p><span style=\"font-weight: 400;\">&nbsp;&nbsp;&nbsp; </span><span style=\"font-weight: 400;\">&nbsp;&nbsp;&nbsp; </span><span style=\"font-weight: 400;\">Numero de la carte d\'identite national : '"+client_cin+"'<br /></span></p>"
                "<p><span style=\"font-weight: 400;\">&nbsp;&nbsp;&nbsp; </span><span style=\"font-weight: 400;\">&nbsp;&nbsp;&nbsp; </span><span style=\"font-weight: 400;\">Adresse : '"+client_adresse+"'<br /></span></p>"
                "<p><span style=\"font-weight: 400;\">&nbsp;&nbsp;&nbsp; </span><span style=\"font-weight: 400;\">&nbsp;&nbsp;&nbsp; </span><span style=\"font-weight: 400;\">email : '"+client_email+"'<br /></span></p>"
                "<p><span style=\"font-weight: 400;\">&nbsp;&nbsp;&nbsp; </span><span style=\"font-weight: 400;\">&nbsp;&nbsp;&nbsp; </span><span style=\"font-weight: 400;\">T&eacute;l : '"+client_num_tel+"'<br /></span></p>"
                "<p>&nbsp;</p>"
                " <p><strong>Information sur le vehicule </strong><strong>&deg;</strong><strong> : </strong><span style=\"font-weight: 400;\"> <br /></span></p>"
                "<p>&nbsp;</p>"
                " <p><span style=\"font-weight: 400;\">&nbsp;&nbsp;&nbsp; </span><span style=\"font-weight: 400;\">&nbsp;&nbsp;&nbsp; </span><span style=\"font-weight: 400;\">Reference du v&eacute;hicule : '"+reference+"'</span></p>"
                "<p><span style=\"font-weight: 400;\">&nbsp;&nbsp;&nbsp; </span><span style=\"font-weight: 400;\">&nbsp;&nbsp;&nbsp; </span><span style=\"font-weight: 400;\">Marque </span><span style=\"font-weight: 400;\">&nbsp;&nbsp;&nbsp; </span><span style=\"font-weight: 400;\">&nbsp;&nbsp;&nbsp; </span><span style=\"font-weight: 400;\">&nbsp;&nbsp;&nbsp; </span>: '"+marque+"'</p>"
                "<p><span style=\"font-weight: 400;\">&nbsp;&nbsp;&nbsp; </span><span style=\"font-weight: 400;\">&nbsp;&nbsp;&nbsp; </span><span style=\"font-weight: 400;\">Type</span><span style=\"font-weight: 400;\">&nbsp;&nbsp;&nbsp; </span><span style=\"font-weight: 400;\">&nbsp;&nbsp;&nbsp; </span><span style=\"font-weight: 400;\">&nbsp;&nbsp;&nbsp; </span><span style=\"font-weight: 400;\">&nbsp;&nbsp;&nbsp;&nbsp;</span> : '"+carburant+"'</p>"
                "<p><span style=\"font-weight: 400;\">&nbsp;&nbsp;&nbsp; </span><span style=\"font-weight: 400;\">&nbsp;&nbsp;&nbsp; </span><span style=\"font-weight: 400;\">Age du vehicule </span><span style=\"font-weight: 400;\">&nbsp;&nbsp;&nbsp; </span><span style=\"font-weight: 400;\">&nbsp;&nbsp;&nbsp; </span><span style=\"font-weight: 400;\">&nbsp;&nbsp;&nbsp;&nbsp;</span>&nbsp;&nbsp; : '"+age+"'</p>"
                "<p><span style=\"font-weight: 400;\">&nbsp;&nbsp;&nbsp; </span><span style=\"font-weight: 400;\">&nbsp;&nbsp;&nbsp; </span><span style=\"font-weight: 400;\">Immatriculation </span><span style=\"font-weight: 400;\">&nbsp; </span><span style=\"font-weight: 400;\">: '"+plaque+"'</span></p>"
                "<p>&nbsp;</p>"
                " <p><strong>Duree de la location  </strong><strong>&deg;</strong><strong> : </strong><span style=\"font-weight: 400;\"> <br /></span></p>"
                "<p>&nbsp;</p>"
                "<p><span style=\"font-weight: 400;\">&nbsp;&nbsp;&nbsp; </span><span style=\"font-weight: 400;\">&nbsp;&nbsp;&nbsp; </span><span style=\"font-weight: 400;\">La location débute du '"+dateD+"' au '"+dateF+"'</span></p>"
                "<p><span style=\"font-weight: 400;\">&nbsp;&nbsp;&nbsp; </span><span style=\"font-weight: 400;\">&nbsp;&nbsp;&nbsp; </span><span style=\"font-weight: 400;\">Le contrat prend fin à la date d'expiration sans préavis écrit.</span></p>"
                 "<p>&nbsp;</p>"
                 "<p style=\"text-align: right;\"><span style=\"font-weight: 400;\">Fait &agrave; l'agence num&eacute;ro :&nbsp; '"+agence+" , le&nbsp;&nbsp; '"+QDate::currentDate().toString()+"' <br /></span></p>"
                "<p>&nbsp;</p>");
        doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
        doc.print(&printer);

}

QSqlTableModel *ContratLocation::setTable()
{
         /*QSqlTableModel *model = new QSqlTableModel(this, database);
         model->setTable("CONTRATLOCATION");
         model->setEditStrategy(QSqlTableModel::OnManualSubmit);
         model->select();*/
}

QSqlQueryModel* ContratLocation::rechercherContrat(QString id)
{

    QSqlQuery* query = new QSqlQuery();

    QSqlQueryModel * model= new QSqlQueryModel();
    query->prepare("select * from CONTRATLOCATION WHERE IDCONTRAT like '"+id+"%'");
    query->exec();

    model->setQuery(*query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID CONTRAT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE DEBUT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE FIN"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID AGENCE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID AGENT"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("REFERENCE VEHICULE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("ID CLIENT"));
    return model;
}

