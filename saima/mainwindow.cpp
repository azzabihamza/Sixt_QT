#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlQueryModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_5_clicked() //AJOUT
{
    QString code,nom,prenom,date_naissance,adresse,cp,num_tel,email,type_permis,num_permis,date_del,datefin_del,cin;
    code=ui->client_code->text();
    nom=ui->client_nom->text();
    prenom=ui->client_prenom->text();
    date_naissance=ui->client_date_naissance->text();
    adresse=ui->client_adresse->text();
    cp=ui->client_cp->text();
    num_tel=ui->client_num_tel->text();
    email=ui->client_email->text();
    type_permis=ui->client_permis_type->text();
    num_permis=ui->client_permis_numero->text();
    date_del=ui->client_date_del_permis->text();
    datefin_del=ui->client_datefindel_permis->text();
    cin=ui->client_cin->text();

    QSqlQuery qry;
    qry.prepare("INSERT into CLIENT (CODE,NOM,PRENOM,DATE_NAISSANCE,ADRESSE,CP,NUM_TEL,EMAIL,TYPE_PERMIS,NUM_PERMIS,DATE_DEL,DATEFIN_DEL,CIN) values ('"+cin+"','"+nom+"','"+prenom+"','"+date_naissance+"','"+adresse+"','"+cp+"','"+num_tel+"','"+email+"','"+type_permis+"','"+num_permis+"','"+date_del+"','"+datefin_del+"','"+cin+"')");
    if (qry.exec())
    {

    QMessageBox::information(this,tr("Done"),tr("Ajout avec succès"));}
    else
    {QMessageBox::critical(this,tr("Sorry"),tr("Error"));}
}


void MainWindow::on_pushButton_7_clicked() //AFFICHER
{
    QSqlQueryModel  *modal = new QSqlQueryModel();
    QSqlQuery* qry = new QSqlQuery();
    qry->prepare("Select * from CLIENT");
    qry->exec();
    modal->setQuery(*qry);
    ui->table->setModel(modal);
}


void MainWindow::on_pushButton_3_clicked() //MODIFIER
{
        QString code,nom,prenom,date_naissance,adresse,cp,num_tel,email,type_permis,num_permis,date_del,datefin_del,cin;
        code=ui->client_code2->text();
        nom=ui->client_nom2->text();
        prenom=ui->client_prenom2->text();
        date_naissance=ui->client_date_naissance2->text();
        adresse=ui->client_adresse2->text();
        cp=ui->client_cp2->text();
        num_tel=ui->client_num_tel2->text();
        email=ui->client_email2->text();
        type_permis=ui->client_permis_type2->text();
        num_permis=ui->client_permis_numero2->text();
        date_del=ui->client_date_del_permis2->text();
        datefin_del=ui->client_datefindel_permis2->text();
        cin=ui->client_cin2->text();
        QSqlQuery qry;
        qry.prepare("UPDATE CLIENT set CODE='"+code+"',NOM='"+nom+"',PRENOM='"+prenom+"',DATE_NAISSANCE='"+date_naissance+"',ADRESSE='"+adresse+"',CP='"+cp+"',NUM_TEL='"+num_tel+"',EMAIL='"+email+"',TYPE_PERMIS='"+type_permis+"',NUM_PERMIS='"+num_permis+"',DATE_DEL='"+date_del+"',DATEFIN_DEL='"+datefin_del+"',CIN='"+cin+"' where CODE='"+code+"'");

        if (qry.exec())
        {
        QMessageBox::information(this,tr("Done"),tr("Modifié avec succès"));}
        else
        {QMessageBox::critical(this,tr("Sorry"),tr("Error"));}
}

void MainWindow::on_pushButton_clicked() //SUPPRIMER
{
        QString code,nom,prenom,date_naissance,adresse,cp,num_tel,email,type_permis,num_permis,date_del,datefin_del,cin;
        code=ui->client_code3->text();
        QSqlQuery qry;
        qry.prepare("Delete from CLIENT where CODE='"+code+"'");

        if (qry.exec())
        {
        QMessageBox::information(this,tr("Done"),tr("Supprimé avec succès"));}
        else
        {QMessageBox::critical(this,tr("Sorry"),tr("Error"));}
}
