#include "interfaceclient.h"
#include "ui_interfaceclient.h"
#include <QSqlQuery>
#include "client.h"
#include "convention.h"

interfaceClient::interfaceClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::interfaceClient)
{
    ui->setupUi(this);
    popUp = new popup();
    ui->table_client->setModel(client.afficher_client());
}

interfaceClient::~interfaceClient()
{
    delete ui;
}

void interfaceClient::on_pushButton_ajouter_clicked()
{
    QString nom=ui->client_nom->text();
    QString prenom=ui->client_prenom->text();
    QDate date_naissance=ui->client_date_naissance->date();
    QString adresse=ui->client_adresse->text();
    int num_tel=ui->client_num_tel->text().toInt();
    QString email=ui->client_email->text();
    QString type_permis=ui->client_permis_type->text();
    QString num_permis=ui->client_permis_numero->text();
    QDate date_del=ui->client_date_del->date();
    QDate datefin_del=ui->client_datefin_del->date();
    int cin=ui->client_cin->text().toUInt();
    Client nouvclient(nom,prenom,date_naissance,adresse,num_tel,email,type_permis,num_permis,date_del,datefin_del,cin);

    if(nouvclient.ajouter_client())
    {
        text="Client ajouté avec succès";
        popUp->setPopupText(text);
        popUp->show("succes");
    }
}


void interfaceClient::on_pushButton_modifier_clicked()
{
    QString code = ui->code->text();

    QString nom=ui->client_nom->text();
    QString prenom=ui->client_prenom->text();
    QDate date_naissance=ui->client_date_naissance->date();
    QString adresse=ui->client_adresse->text();
    int num_tel=ui->client_num_tel->text().toInt();
    QString email=ui->client_email->text();
    QString type_permis=ui->client_permis_type->text();
    QString num_permis=ui->client_permis_numero->text();
    QDate date_del=ui->client_date_del->date();
    QDate datefin_del=ui->client_datefin_del->date();
    int cin=ui->client_cin->text().toUInt();

    Client nouvclient(nom,prenom,date_naissance,adresse,num_tel,email,type_permis,num_permis,date_del,datefin_del,cin);

    if(nouvclient.modifier_client(code))
    {
        text="Client modifié avec succès";
        popUp->setPopupText(text);
        popUp->show("succes");
    }
}

void interfaceClient::on_table_client_activated(const QModelIndex &index)
{
    QString val=ui->table_client->model()->data(index).toString();

    QSqlQuery query;
    query.prepare("select * from CLIENT where CODE like '"+val+"' or NOM like '"+val+"' or PRENOM like '"+val+"' or DATE_NAISSANCE like '"+val+"' or ADRESSE like '"+val+"' or NUM_TEL like '"+val+"' or EMAIL like '"+val+"' or TYPE_PERMIS like '"+val+"' or NUM_PERMIS like '"+val+"' or DATE_DEL like '"+val+"' or DATEFIN_DEL like '"+val+"' or CIN like '"+val+"' ");

    if(query.exec())
    {
        while(query.next())
        {

            ui->code->setText(query.value(0).toString());
            ui->client_nom->setText(query.value(1).toString());
            ui->client_prenom->setText(query.value(2).toString());
            ui->client_date_naissance->setDate(query.value(3).toDate());
            ui->client_adresse->setText(query.value(4).toString());
            ui->client_num_tel->setText(query.value(5).toString());
            ui->client_email->setText(query.value(6).toString());
            ui->client_permis_type->setText(query.value(7).toString());
            ui->client_permis_numero->setText(query.value(8).toString());
            ui->client_date_del->setDate(query.value(9).toDate());
            ui->client_datefin_del->setDate(query.value(10).toDate());
            ui->client_cin->setText(query.value(11).toString());
        }
    }
}

/*bool isCharacter(const char Character)
{
    return ( (Character >= 'a' && Character <= 'z') || (Character >= 'A' && Character <= 'Z'));
    //Checks if a Character is a Valid A-Z, a-z Character, based on the ascii value
}
bool isNumber(const char Character)
{
    return ( Character >= '0' && Character <= '9');
    //Checks if a Character is a Valid 0-9 Number, based on the ascii value
}
bool isValidEmailAddress(const char * EmailAddress)
{
    if(!EmailAddress) // If cannot read the Email Address...
        return 0;
    if(!isCharacter(EmailAddress[0])) // If the First character is not A-Z, a-z
        return 0;
    int AtOffset = -1;
    int DotOffset = -1;
    unsigned int Length = strlen(EmailAddress); // Length = StringLength (strlen) of EmailAddress
    for(unsigned int i = 0; i < Length; i++)
    {
        if(EmailAddress[i] == '@') // If one of the characters is @, store it's position in AtOffset
            AtOffset = (int)i;
        else if(EmailAddress[i] == '.') // Same, but with the dot
            DotOffset = (int)i;
    }
    if(AtOffset == -1 || DotOffset == -1) // If cannot find a Dot or a @
        return 0;
    if(AtOffset > DotOffset) // If the @ is after the Dot
        return 0;
    return !(DotOffset >= ((int)Length-1)); //Chech there is some other letters after the Dot
}
*/

void interfaceClient::on_pushButton_supprimer_clicked()
{
    QString code = ui->code->text();

    /*if(code==0){
            text="ERREUR VEUILLEZ SELECTIONNER UN CONTRAT A SUPPRIMER !";
            popUp->setPopupText(text);
            popUp->show("error");
        }*/
    if(client.supprimer_client(code))
    {
        text="Client supprimé avec succès";
        popUp->setPopupText(text);
        popUp->show("succes");
    }
}



void interfaceClient::on_pushButton_ajouter_2_clicked()
{
    QString c_nom=ui->c_nom->text();
    QString c_adresse=ui->c_adresse->text();
    int c_numtel=ui->c_numtel->text().toInt();
    QString c_email=ui->c_email->text();

    Convention nouvconvention(c_nom,c_adresse,c_numtel,c_email);

    if(nouvconvention.ajouter_convention())
    {
        text="Convention ajoutée avec succès";
        popUp->setPopupText(text);
        popUp->show("succes");
    }
}

void interfaceClient::on_pushButton_modifier_2_clicked()
{
    int c_code = ui->c_code2->text().toInt();

    QString nom=ui->client_nom->text();
    QString c_adresse=ui->c_adresse->text();
    int c_numtel=ui->c_numtel->text().toInt();
    QString c_email=ui->c_email->text();

    Convention nouvconvention(c_nom,c_adresse,c_numtel,c_email);

    if(nouvconvention.modifier_convention(c_code))
    {
        text="Convention modifiée avec succès";
        popUp->setPopupText(text);
        popUp->show("succes");
    }
}

void interfaceClient::on_table_client_2_activated(const QModelIndex &index)
{
    QString val=ui->table_client_2->model()->data(index).toString();

    QSqlQuery query;
    query.prepare("select * from CONVENTION where C_CODE like '"+val+"' or C_NOM like '"+val+"'  or C_ADRESSE like '"+val+"' or C_NUMTEL like '"+val+"' or EMAIL like '"+val+"'");

    if(query.exec())
    {
        while(query.next())
        {

            ui->c_code->setText(query.value(0).toString());
            ui->c_nom->setText(query.value(1).toString());
            ui->c_adresse->setText(query.value(2).toString());
            ui->c_numtel->setText(query.value(3).toString());
            ui->c_email->setText(query.value(4).toString());
        }
    }
}

void interfaceClient::on_pushButton_supprimer_2_clicked()
{
    QString c_code = ui->c_code->text();

    /*if(code==0){
            text="ERREUR VEUILLEZ SELECTIONNER UN CONTRAT A SUPPRIMER !";
            popUp->setPopupText(text);
            popUp->show("error");
        }*/
    if(convention.supprimer_convention(c_code))
    {
        text="Convention supprimée avec succès";
        popUp->setPopupText(text);
        popUp->show("succes");
    }
}

void interfaceClient::on_sendBtn_clicked()
{
    QString mail = ui->comboBox_mail->currentText();

        Smtp* smtp = new Smtp(ui->uname->text(), ui->paswd->text(), ui->server->text(), ui->port->text().toUShort());
        connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
        smtp->sendMail(ui->uname->text(), ui->comboBox_mail->currentText() , ui->subject->text(),ui->msg->toPlainText());
}

void interfaceClient::sendMail()
{
    QString mail = ui->comboBox_mail->currentText();

    Smtp* smtp = new Smtp(ui->uname->text(), ui->paswd->text(), ui->server->text(), ui->port->text().toUShort());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
    smtp->sendMail(ui->uname->text(), ui->comboBox_mail->currentText() , ui->subject->text(),ui->msg->toPlainText());
}
