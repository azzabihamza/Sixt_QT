#include "client.h"
#include "ui_client.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QPdfWriter>
#include <QPainter>

Client::Client(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Client)
{
    ui->setupUi(this);
}

Client::~Client()
{
    delete ui;
}

void Client::on_pushButton_5_clicked() //AJOUT
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


void Client::on_pushButton_3_clicked() //MODIFIER
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
    qry.prepare("UPDATE CLIENT set CODE='"+code+"',NOM='"+nom+"',PRENOM='"+prenom+"',DATE_NAISSANCE='"+date_naissance+"',ADRESSE='"+adresse+"',CP='"+cp+"',NUM_TEL='"+num_tel+"',EMAIL='"+email+"',TYPE_PERMIS='"+type_permis+"',NUM_PERMIS='"+num_permis+"',DATE_DEL='"+date_del+"',DATEFIN_DEL='"+datefin_del+"',CIN='"+cin+"' where CODE='"+code+"'");

    if (qry.exec())
    {
    QMessageBox::information(this,tr("Done"),tr("Modifié avec succès"));}
    else
    {QMessageBox::critical(this,tr("Sorry"),tr("Error"));}
}

void Client::on_pushButton_clicked() //SUPPRIMER
{
    QString code,nom,prenom,date_naissance,adresse,cp,num_tel,email,type_permis,num_permis,date_del,datefin_del,cin;
    code=ui->client_code2->text();
    QSqlQuery qry;
    qry.prepare("Delete from CLIENT where CODE='"+code+"'");

    if (qry.exec())
    {
    QMessageBox::information(this,tr("Done"),tr("Supprimé avec succès"));}
    else
    {QMessageBox::critical(this,tr("Sorry"),tr("Error"));}
}


void Client::on_pushButton_7_clicked() //AFFICHER
{
    QSqlQueryModel  *modal = new QSqlQueryModel();
    QSqlQuery* qry = new QSqlQuery();
    qry->prepare("Select * from CLIENT ORDER BY CODE");
    qry->exec();
    modal->setQuery(*qry);
    ui->table->setModel(modal);
}


void Client::on_tridesc_clicked() // TRI DESC
{
    QSqlQueryModel  *modal = new QSqlQueryModel();
    QSqlQuery* qry = new QSqlQuery();
    qry->prepare("Select * from CLIENT ORDER BY CODE DESC");
    qry->exec();
    modal->setQuery(*qry);
    ui->table->setModel(modal);
}


void Client::on_rech_clicked() //RECHERCHE
{
    QSqlQueryModel  *modal = new QSqlQueryModel();
    QSqlQuery* qry = new QSqlQuery();
    QString coderech;
    coderech=ui->client_code2->text();
    qry->prepare("Select * from CLIENT where CODE like '"+coderech+"%'");
    qry->exec();
    modal->setQuery(*qry);
    ui->table->setModel(modal);
}


void Client::on_table_activated(const QModelIndex &index) //ID POUR PDF
{
    QString val=ui->table->model()->data(index).toString();
                QSqlQuery q;
                q.prepare("select * from CLIENT where CODE='"+val+"'");
                if(q.exec())
                {
                    while (q.next())
                    {
                    ui->client_code2->setText(q.value(0).toString());
                    }
                }
}


void Client::on_pdf_clicked() //ENREGISTRER EN PDF
{
    QPdfWriter pdf("C:/Users/asus/Documents/Qt/PDFs/clients.pdf");
            QPainter painter;
            if (! painter.begin(&pdf))
            {
                // failed to open file
                                qWarning("failed to open file, is it writable?");

            }
            QString id =ui->client_code2->text();
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
                        QString client_cp = query.value(5).toString();
                        QString client_num_tel = query.value(6).toString();
                        QString client_email = query.value(7).toString();
                        QString client_permis_type = query.value(8).toString();
                        QString client_permis_numero = query.value(9).toString();
                        QString client_date_del_permis = query.value(10).toString();
                        QString client_datefindel_permis = query.value(11).toString();
                        QString client_cin = query.value(12).toString();


                painter.drawText(2200,3500,client_code);
                painter.drawText(2200,4000,client_nom);
                painter.drawText(2200,4500,client_prenom);
                painter.drawText(2200,5000,client_date_naissance);
                painter.drawText(2200,5500,client_adresse);
                painter.drawText(2200,6000,client_cp);
                painter.drawText(2200,6500,client_num_tel);
                painter.drawText(2200,7000,client_email);
                painter.drawText(2200,7500,client_permis_type);
                painter.drawText(2200,8000,client_permis_numero);
                painter.drawText(2600,8500,client_date_del_permis);
                painter.drawText(2800,9000,client_datefindel_permis);
                painter.drawText(2200,9500,client_cin);



                painter.setPen(Qt::blue);
                painter.setPen(Qt::black);
                painter.drawText(500,2000,asctime(localtime(&ctt)));
                painter.drawText(500,3500,"Code:");
                painter.drawText(500,4000,"Nom :");
                painter.drawText(500,4500,"Prenom:");
                painter.drawText(500,5000,"Date de naissance:");
                painter.drawText(500,5500,"Adresse :");
                painter.drawText(500,6000,"Code postal:");
                painter.drawText(500,6500,"Numero de telephone :");
                painter.drawText(500,7000,"Email :");
                painter.drawText(500,7500,"Type du permis :");
                painter.drawText(500,8000,"Numero du permis :");
                painter.drawText(500,8500,"Date de deliverance du permis :");
                painter.drawText(500,9000,"Date de fin de deliverance du permis :");
                painter.drawText(500,9500,"N° CIN :");

            }
                     QMessageBox::information (this,"PDF","Export fait avec succès!");
}



void Client::on_sendBtn_clicked() //ENVOYER MAIL
{
    QString mail = ui->comboBox_mail->currentText();

        Smtp* smtp = new Smtp(ui->uname->text(), ui->paswd->text(), ui->server->text(), ui->port->text().toUShort());
        connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
        smtp->sendMail(ui->uname->text(), ui->comboBox_mail->currentText() , ui->subject->text(),ui->msg->toPlainText());
}

void Client::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}













