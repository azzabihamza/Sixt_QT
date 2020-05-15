#include "interfacecontrat.h"
#include "ui_interfacecontrat.h"
#include "contratlocation.h"
#include <QString>
#include <QMessageBox>
#include <QPixmap>
#include <QFile>
#include <QTextStream>
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>
#include <QCalendarWidget>

interfaceContrat::interfaceContrat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::interfaceContrat)
{

    ui->setupUi(this);
    popUp = new popup();
    this->dateSystem = QDate::currentDate();
    ui->stackedWidget->setCurrentIndex(0);

    ui->currentDate->setText(QDate::currentDate().toString());

    QTimer *timer=new QTimer(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(UpadateTime()));
        timer->start(1000);

    // ************** PAGE ACCEUIL ************* //

    QPixmap logo(":/src/img/src/img/logo.png");
    QPixmap contrat(":/src/img/src/img/handshake.png");
    QPixmap assurance(":/src/img/src/img/insurance.png");
    QPixmap home(":/src/img/src/img/social-media.png");
    QPixmap historique(":/src/img/src/img/historique.png");
    QPixmap close(":/src/img/src/img/off.png");
    QPixmap bg(":/src/img/src/img/bg.png");

    ui->bgInterfaceContrat->setPixmap(bg);

    ui->logo->setPixmap(logo.scaled(150,150,Qt::KeepAspectRatio));

    ui->PBacceuil->setIcon(home);
    ui->PBacceuil->setIconSize(QSize(30,30));

    ui->PBacceuil_5->setIcon(home);
    ui->PBacceuil_5->setIconSize(QSize(30,30));

    ui->PBlocation->setIcon(contrat);
    ui->PBlocation->setIconSize(QSize(30,30));

    ui->PBassurance->setIcon(assurance);
    ui->PBassurance->setIconSize(QSize(30,30));

    ui->PBhistorique->setIcon(historique);
    ui->PBhistorique->setIconSize(QSize(30,30));

    ui->PBclose->setIcon(close);
    ui->PBclose->setIconSize(QSize(30,30));

    // ****** INTERFACE GESTION CONTRAT LOCATION ***********//

    ui->tableContratLocation->setModel(contratLocation.afficherContrat());
    loadHistorique();

    QSqlQueryModel* modal = new QSqlQueryModel();
    QSqlQueryModel* modalAgent = new QSqlQueryModel();
    QSqlQueryModel* modalReference = new QSqlQueryModel();
    QSqlQueryModel* modalClient = new QSqlQueryModel();

    modal->setQuery("select NUMERO from AGENCE");
    ui->comboBox_Idagence->setModel(modal);


    modalAgent->setQuery("select ID from AGENT");
    ui->comboBox_Idagent->setModel(modalAgent);

    modalReference->setQuery("select REF from VEHICULES");
    ui->comboBox_Reference->setModel(modalReference);

    modalClient->setQuery("select CIN from CLIENT");
    ui->comboBox_Idclient->setModel(modalClient);

    ui->dateEdit_debutLocation->setCalendarPopup(true);
    ui->dateEdit_finLocation->setCalendarPopup(true);
    ui->dateEdit_debutLocation->setDate(dateSystem);
    ui->dateEdit_finLocation->setDate(dateSystem);

    ui->label_8->setText("");

    //*********** INTERFACE GESTION CONTRAT ASSURANCE **********//

    QSqlQueryModel* modalMatricule = new QSqlQueryModel();
    ui->tableAssurance->setModel(contratAssurance.afficherAssurance());//refresh

    ui->comboBoxTypeAssurance->addItems({ "Assurance au tiers", "Assurance au tiers plus", "Assurance tous risques", "Assurance auto au kilomètre" });
    modalMatricule->setQuery("select PLAQUE from VEHICULES");
    ui->comboBoxMatriculeVehicule->setModel(modalMatricule);

    ui->DateDebutAssurance->setCalendarPopup(true);
    ui->DateDebutAssurance->setDate(dateSystem);
    ui->DateFinAssurance->setCalendarPopup(true);
    ui->DateFinAssurance->setDate(dateSystem);

    ui->PBacceuil_4->setIcon(home);
    ui->PBacceuil_4->setIconSize(QSize(30,30));
}

interfaceContrat::~interfaceContrat()
{
    delete ui;
}

void interfaceContrat::loadHistorique()
{
    QFile file ("E:\\Projects\\Projet QT\\Sixt_V2\\src\\Historique.txt");
        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::information(0,"info",file.errorString());
        }
        QTextStream in (&file);
        ui->Historique->setText(in.readAll());
}


// *********************************** ACTION DE GESTION LOCATION ******************************************//

void interfaceContrat::on_pushButton_AjouterContrat_clicked()
{
    QDate DateDebut = ui->dateEdit_debutLocation->date();
    QDate DateFin = ui->dateEdit_finLocation->date();
    int IdAgence = ui->lineEdit_Idagence->text().toInt();
    QString IdAgent = ui->lineEdit_Idagent->text();
    QString referenceVehicule = ui->lineEdit_Reference->text();
    QString IdClient = ui->lineEdit_Idclient->text();

    ContratLocation location(DateDebut,DateFin,IdAgence,IdAgent,referenceVehicule,IdClient);

    if(DateDebut < dateSystem || DateFin < dateSystem || DateFin < DateDebut)
    {


        text="DATE SAISIE EST INCORRECT !";
        popUp->setPopupText(text);
        popUp->show("warning");

    }else if(IdAgence == NULL || IdAgent =="" || referenceVehicule=="" || IdClient=="")
    {

        text="LES CHAMPS SAISIE SONT INCORRECT !";
        popUp->setPopupText(text);
        popUp->show("warning");

    }else if(location.ajouterContratLocation())
    {
        QString date=dateSystem.toString();
        QString idagence=QString::number(IdAgence);
        QFile file("E:\\Projects\\Projet QT\\Sixt_V2\\src\\Historique.txt");
              if (!file.open(QIODevice::WriteOnly | QIODevice::Append |QIODevice::Text))
                  return;
              QTextStream cout(&file);
              QString message2="\n L'historique des Contrat à ajouter :"+date+" "+idagence+" "+IdAgent+" "+IdClient+"";
              cout << message2;
        loadHistorique();
        ui->tableContratLocation->setModel(contratLocation.afficherContrat());//refresh

        ui->dateEdit_debutLocation->clear();
        ui->dateEdit_finLocation->clear();
        ui->lineEdit_Idagence->clear();
        ui->lineEdit_Idagent->clear();
        ui->lineEdit_Reference->clear();
        ui->lineEdit_Idclient->clear();

        ui->label_8->setText("");

        text="LOCATION AJOUTER AVEC SUCCES";
        popUp->setPopupText(text);
        popUp->show("succes");



    }else
    {

        text="ERREUR !";
        popUp->setPopupText(text);
        popUp->show("error");


    }



}

void interfaceContrat::on_pushButton_ModifieContrat_clicked()
{
    int IdContrat = ui->label_8->text().toInt();
    QDate DateDebut = ui->dateEdit_debutLocation->date();
    QDate DateFin = ui->dateEdit_finLocation->date();
    int IdAgence = ui->lineEdit_Idagence->text().toInt();
    QString IdAgent = ui->lineEdit_Idagent->text();
    QString referenceVehicule = ui->lineEdit_Reference->text();
    QString IdClient = ui->lineEdit_Idclient->text();
    ContratLocation location(DateDebut,DateFin,IdAgence,IdAgent,referenceVehicule,IdClient);

    if(DateDebut < dateSystem || DateFin < dateSystem || DateFin < DateDebut)
    {

        text="DATE SAISIE EST INCORRECT !";
        popUp->setPopupText(text);
        popUp->show("warning");
    }else if(IdAgence == NULL || IdAgent =="" || referenceVehicule=="" || IdClient=="")
    {

        text="LES CHAMPS SAISIE SONT INCORRECT !";
        popUp->setPopupText(text);
        popUp->show("warning");
    }else if(location.modifierContratLocation(IdContrat))
    {
        ui->tableContratLocation->setModel(contratLocation.afficherContrat());//refresh
        ui->dateEdit_debutLocation->clear();
        ui->dateEdit_finLocation->clear();
        ui->lineEdit_Idagence->clear();
        ui->lineEdit_Idagent->clear();
        ui->lineEdit_Reference->clear();
        ui->lineEdit_Idclient->clear();
        ui->label_8->setText("");

        text="CONTRAT MODIFIER AVEC SUCCES";
        popUp->setPopupText(text);
        popUp->show("succes");

    }else
    {

        text="ERREUR !";
        popUp->setPopupText(text);
        popUp->show("error");

    }
}

void interfaceContrat::on_pushButton_supprimerContrat_clicked()
{
    int IdContrat = ui->label_8->text().toInt();

    if(IdContrat==0){

            text="ERREUR VEUILLEZ SELECTIONNER UN CONTRAT A SUPPRIMER !";
            popUp->setPopupText(text);
            popUp->show("error");
        }else
        {
            contratLocation.supprimerContratLocation(IdContrat);
            ui->tableContratLocation->setModel(contratLocation.afficherContrat());//refresh
            ui->dateEdit_debutLocation->clear();
            ui->dateEdit_finLocation->clear();
            ui->lineEdit_Idagence->clear();
            ui->lineEdit_Idagent->clear();
            ui->lineEdit_Reference->clear();
            ui->lineEdit_Idclient->clear();
            ui->label_8->setText("");

            text="CONTRAT SUPPRIMER AVEC SUCCES";
            popUp->setPopupText(text);
            popUp->show("succes");

        }

}

void interfaceContrat::on_pushButton_clicked()
{
    QString IdContrat = ui->lineEdit_rechercherContrat->text();
    ui->tableContratLocation->setModel(contratLocation.rechercherContrat(IdContrat));
}

void interfaceContrat::on_radioButton_new_clicked()
{
    ui->tableContratLocation->setModel(contratLocation.triDateDec());
}

void interfaceContrat::on_radioButton_old_clicked()
{
    ui->tableContratLocation->setModel(contratLocation.triDateCroi());
}


void interfaceContrat::on_tableContratLocation_activated(const QModelIndex &index)
{


    QString val=ui->tableContratLocation->model()->data(index).toString();

    QSqlQuery query;
    query.prepare("select * from CONTRATLOCATION where IDCONTRAT like '"+val+"' or DATEDEBUT like '"+val+"' or DATEFIN like '"+val+"' or IDAGENT like '"+val+"' or IDAGENCE like '"+val+"' or REFERENCEVEHICULE like '"+val+"' or IDCLIENT like '"+val+"' ");

    if(query.exec())
    {
        while(query.next())
        {

            ui->label_8->setText(query.value(0).toString());
            ui->dateEdit_debutLocation->setDate(query.value(1).toDate());
            ui->dateEdit_finLocation->setDate(query.value(2).toDate());
            ui->lineEdit_Idagent->setText(query.value(3).toString());
            ui->lineEdit_Idagence->setText(query.value(4).toString());
            ui->lineEdit_Reference->setText(query.value(5).toString());
            ui->lineEdit_Idclient->setText(query.value(6).toString());
        }
    }
}

void interfaceContrat::on_pushButton_2_clicked()
{
    loadHistorique();
}

void interfaceContrat::on_imprimer_clicked()
{
    QPrinter printer;
        printer.setPrinterName("Contrat");
        QPrintDialog dialog(&printer,this);
        if(dialog.exec()== QDialog::Rejected) return;//cntrl de voir si ca marche ou pas
        ui->Historique->print(&printer);
}

void interfaceContrat::on_PBlocation_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void interfaceContrat::on_PBassurance_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void interfaceContrat::on_PBhistorique_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void interfaceContrat::on_PBacceuil_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void interfaceContrat::on_PBacceuil_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void interfaceContrat::on_PBacceuil_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void interfaceContrat::on_comboBox_Idagence_activated(const QString &arg1)
{
    ui->lineEdit_Idagence->setText(arg1);
}

void interfaceContrat::on_comboBox_Idagent_activated(const QString &arg1)
{
    ui->lineEdit_Idagent->setText(arg1);
}

void interfaceContrat::on_comboBox_Reference_activated(const QString &arg1)
{
    ui->lineEdit_Reference->setText(arg1);
}

void interfaceContrat::on_comboBox_Idclient_activated(const QString &arg1)
{
    ui->lineEdit_Idclient->setText(arg1);
}



// *********************************** ACTION DE GESTION ASSURANCE ******************************************//


void interfaceContrat::on_pushButton_AjouterAssurance_clicked()
{
    QString type = ui->comboBoxTypeAssurance->currentText();
    QString assureur = ui->lineEdit_Assureur->text();
    float tarif = ui->lineEdit_Tarif->text().toFloat();
    QDate dateEmission = ui->DateDebutAssurance->date();
    QDate dateExpiration = ui->DateFinAssurance->date();
    QString matricule = ui->comboBoxMatriculeVehicule->currentText();

    Assurance assurance(type,assureur,tarif,dateEmission,dateExpiration,matricule);

    if (type=="" || assureur=="" || tarif == NULL || matricule == "")
    {
        text="VERRIFIEZ LES CHAMPS SI ILS SONT CORRECT !";
        popUp->setPopupText(text);
        popUp->show("warning");
    }else if (assurance.ajoutAssurance())
    {
        ui->tableAssurance->setModel(contratAssurance.afficherAssurance());//refresh
        text="LOCATION AJOUTER AVEC SUCCES";
        popUp->setPopupText(text);
        popUp->show("succes");
    }
}

void interfaceContrat::on_pushButton_ModifierAssurance_clicked()
{

}

void interfaceContrat::on_pushButton_SupprimerAssurance_clicked()
{

}

void interfaceContrat::on_pushButton_RechercherAssurance_clicked()
{

}

void interfaceContrat::on_PBclose_clicked()
{
    close();
}

void interfaceContrat::UpadateTime()
{
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm:ss");

    ui->time->setText(text);
}


