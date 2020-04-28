#include "interfacecontrat.h"
#include "ui_interfacecontrat.h"
#include "contratlocation.h"
#include <QString>
#include <QMessageBox>
#include <QPixmap>

interfaceContrat::interfaceContrat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::interfaceContrat)
{

    ui->setupUi(this);
    this->dateSystem = QDate::currentDate();
    ui->tableContratLocation->setModel(contratLocation.afficherContrat());
    ui->message->hide();




    ui->label_8->setText("-");
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

    if(DateDebut < dateSystem || DateFin < dateSystem || DateFin < DateDebut)
    {
        ui->message->show();
        text="DATE SAISIE EST INCORRECT !";
        ui->message->setTextFormat(Qt::RichText);
        ui->message->setText("<img src=:/src/img/src/img/warning.png align=middle > " + text);
        ui->message->setStyleSheet("QLabel { border: 1px solid;margin: 10px 0px;padding: 15px 10px 15px 50px;background-repeat: no-repeat;background-position: 10px center;color: #4F8A10;background-color: #DFF2BF;}");
    }else if(IdAgence == NULL || IdAgent =="" || referenceVehicule=="" || IdClient=="")
    {
        ui->message->show();
        text="LES CHAMPS SAISIE SONT INCORRECT !";
        ui->message->setTextFormat(Qt::RichText);
        ui->message->setText("<img src=:/src/img/src/img/warning.png align=middle > " + text);
        ui->message->setStyleSheet("QLabel { border: 1px solid;margin: 10px 0px;padding: 15px 10px 15px 50px;background-repeat: no-repeat;background-position: 10px center;color: #4F8A10;background-color: #DFF2BF;}");
    }else if(location.ajouterContratLocation())
    {
        ui->tableContratLocation->setModel(contratLocation.afficherContrat());//refresh
        ui->dateEdit_debutLocation->clear();
        ui->dateEdit_finLocation->clear();
        ui->lineEdit_Idagence->clear();
        ui->lineEdit_Idagent->clear();
        ui->lineEdit_Reference->clear();
        ui->lineEdit_Idclient->clear();
        ui->label_8->setText("-");
        ui->message->show();
        text="LOCATION AJOUTER AVEC SUCCES";
        ui->message->setTextFormat(Qt::RichText);
        ui->message->setText("<img src=:/src/img/src/img/succes.png align=middle > " + text);
        ui->message->setStyleSheet("QLabel { border: 1px solid;margin: 10px 0px;padding: 15px 10px 15px 50px;background-repeat: no-repeat;background-position: 10px center;color: #4F8A10;background-color: #DFF2BF;}");


    }else
    {
        ui->message->show();
        text="ERREUR !";
        ui->message->setTextFormat(Qt::RichText);
        ui->message->setText("<img src=:/src/img/src/img/error.png align=middle > " + text);
        ui->message->setStyleSheet("QLabel { border: 1px solid;margin: 10px 0px;padding: 15px 10px 15px 50px;background-repeat: no-repeat;background-position: 10px center;color: #D8000C;background-color: #FFBABA;}");

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
        ui->message->show();
        text="DATE SAISIE EST INCORRECT !";
        ui->message->setTextFormat(Qt::RichText);
        ui->message->setText("<img src=:/src/img/src/img/warning.png align=middle > " + text);
        ui->message->setStyleSheet("QLabel { border: 1px solid;margin: 10px 0px;padding: 15px 10px 15px 50px;background-repeat: no-repeat;background-position: 10px center;color: #4F8A10;background-color: #DFF2BF;}");
    }else if(IdAgence == NULL || IdAgent =="" || referenceVehicule=="" || IdClient=="")
    {
        ui->message->show();
        text="LES CHAMPS SAISIE SONT INCORRECT !";
        ui->message->setTextFormat(Qt::RichText);
        ui->message->setText("<img src=:/src/img/src/img/warning.png align=middle > " + text);
        ui->message->setStyleSheet("QLabel { border: 1px solid;margin: 10px 0px;padding: 15px 10px 15px 50px;background-repeat: no-repeat;background-position: 10px center;color: #4F8A10;background-color: #DFF2BF;}");
    }else if(location.modifierContratLocation(IdContrat))
    {
        ui->tableContratLocation->setModel(contratLocation.afficherContrat());//refresh
        ui->dateEdit_debutLocation->clear();
        ui->dateEdit_finLocation->clear();
        ui->lineEdit_Idagence->clear();
        ui->lineEdit_Idagent->clear();
        ui->lineEdit_Reference->clear();
        ui->lineEdit_Idclient->clear();
        ui->label_8->setText("-");
        ui->message->show();
        text="CONTRAT MODIFIER AVEC SUCCES";
        ui->message->setTextFormat(Qt::RichText);
        ui->message->setText("<img src=:/src/img/src/img/succes.png align=middle > " + text);
        ui->message->setStyleSheet("QLabel { border: 1px solid;margin: 10px 0px;padding: 15px 10px 15px 50px;background-repeat: no-repeat;background-position: 10px center;color: #4F8A10;background-color: #DFF2BF;}");

    }else
    {
        ui->message->show();
        text="ERREUR !";
        ui->message->setTextFormat(Qt::RichText);
        ui->message->setText("<img src=:/src/img/src/img/error.png align=middle > " + text);
        ui->message->setStyleSheet("QLabel { border: 1px solid;margin: 10px 0px;padding: 15px 10px 15px 50px;background-repeat: no-repeat;background-position: 10px center;color: #D8000C;background-color: #FFBABA;}");

    }
}

void interfaceContrat::on_pushButton_supprimerContrat_clicked()
{
    int IdContrat = ui->label_8->text().toInt();

    if(contratLocation.supprimerContratLocation(IdContrat))
    {
        ui->tableContratLocation->setModel(contratLocation.afficherContrat());//refresh
        ui->dateEdit_debutLocation->clear();
        ui->dateEdit_finLocation->clear();
        ui->lineEdit_Idagence->clear();
        ui->lineEdit_Idagent->clear();
        ui->lineEdit_Reference->clear();
        ui->lineEdit_Idclient->clear();
        ui->label_8->setText("-");
        ui->message->show();
        text="CONTRAT SUPPRIMER AVEC SUCCES";
        ui->message->setTextFormat(Qt::RichText);
        ui->message->setText("<img src=:/src/img/src/img/succes.png align=middle > " + text);
        ui->message->setStyleSheet("QLabel { border: 1px solid;margin: 10px 0px;padding: 15px 10px 15px 50px;background-repeat: no-repeat;background-position: 10px center;color: #4F8A10;background-color: #DFF2BF;}");

    }
    else
        ui->message->show();
        text="ERREUR !";
        ui->message->setTextFormat(Qt::RichText);
        ui->message->setText("<img src=:/src/img/src/img/error.png align=middle > " + text);
        ui->message->setStyleSheet("QLabel { border: 1px solid;margin: 10px 0px;padding: 15px 10px 15px 50px;background-repeat: no-repeat;background-position: 10px center;color: #D8000C;background-color: #FFBABA;}");


}

void interfaceContrat::on_pushButton_clicked()
{
    QString IdContrat = ui->lineEdit_rechercherContrat->text();
    ui->tableContratLocation->setModel(contratLocation.rechercherContrat(IdContrat));
}

void interfaceContrat::on_tableContratLocation_activated(const QModelIndex &index)
{

    ui->message->hide();
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
