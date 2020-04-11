#include "interfacecontrat.h"
#include "ui_interfacecontrat.h"
#include "contratlocation.h"
#include <QString>
#include <QMessageBox>

interfaceContrat::interfaceContrat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::interfaceContrat)
{
    ui->setupUi(this);
    ui->tableContratLocation->setModel(contratLocation.afficherContrat());
}

interfaceContrat::~interfaceContrat()
{
    delete ui;
}

void interfaceContrat::on_pushButton_AjouterContrat_clicked()
{
    QDate DateDebut = ui->dateEdit_debutLocation->date();
    QDate DateFin = ui->dateEdit_finLocation->date();
    int IdAgence = ui->lineEdit_Idagence->text().toInt();
    QString IdAgent = ui->lineEdit_Idagent->text();
    QString referenceVehicule = ui->lineEdit_Reference->text();
    QString IdClient = ui->lineEdit_Idclient->text();

    ContratLocation location(DateDebut,DateFin,IdAgence,IdAgent,referenceVehicule,IdClient);

    if(location.ajouterContratLocation())
    {
        ui->tableContratLocation->setModel(contratLocation.afficherContrat());//refresh
        QMessageBox::information(nullptr, QObject::tr("Ajouter uncontrat de location"),
                    QObject::tr("LOCATION AJOUTER AVEC SUCCES.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }else
    {
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un contrat de location "),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }



}

void interfaceContrat::on_pushButton_ModifieContrat_clicked()
{
    int IdContrat = ui->lineEdit_IdcontratM->text().toInt();
    QDate DateDebut = ui->dateEdit_debutLocation_2->date();
    QDate DateFin = ui->dateEdit_finLocation_2->date();
    int IdAgence = ui->lineEdit_Idagence_2->text().toInt();
    QString IdAgent = ui->lineEdit_Idagent_2->text();
    QString referenceVehicule = ui->lineEdit_Reference_2->text();
    QString IdClient = ui->lineEdit_Idclient_2->text();
    ContratLocation location(DateDebut,DateFin,IdAgence,IdAgent,referenceVehicule,IdClient);

    if(location.modifierContratLocation(IdContrat))
    {
        ui->tableContratLocation->setModel(contratLocation.afficherContrat());//refresh
        QMessageBox::information(nullptr, QObject::tr("Modifier un contrat de location"),
                    QObject::tr("MODIFICATION EFFECUTER AVEC SUCCES.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }else
    {
        QMessageBox::critical(nullptr, QObject::tr("Modifier un contrat de location "),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
}

void interfaceContrat::on_pushButton_supprimerContrat_clicked()
{
    int IdContrat = ui->lineEdit_IdcontratSupprimer->text().toInt();

    if(contratLocation.supprimerContratLocation(IdContrat))
    {
        ui->tableContratLocation->setModel(contratLocation.afficherContrat());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un contrat de location "),
                    QObject::tr("CONTRAT SUPPRIMER.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un contrat de location"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
