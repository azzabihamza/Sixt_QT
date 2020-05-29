#include <QSqlQuery>
#include "interfaceclient.h"
#include "ui_interfaceclient.h"
#include "client.h"
#include "convention.h"
#include <QString>
#include <QMessageBox>
#include <QTextStream>
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>
#include "smtp.h"
#include "qcustomplot.h"

interfaceClient::interfaceClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::interfaceClient)
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
        QPixmap close(":/src/img/src/img/off.png");
        QPixmap bg(":/src/img/src/img/bg.png");
        QPixmap home(":/src/img/src/img/social-media.png");

        ui->logo->setPixmap(logo.scaled(150,150,Qt::KeepAspectRatio));
        ui->bgInterfaceContrat->setPixmap(bg);

        ui->PBacceuil->setIcon(home);
        ui->PBacceuil->setIconSize(QSize(30,30));
        ui->PBacceuil_2->setIcon(home);
        ui->PBacceuil_2->setIconSize(QSize(30,30));
        ui->PBacceuil_3->setIcon(home);
        ui->PBacceuil_3->setIconSize(QSize(30,30));

        ui->PBclose->setIcon(close);
        ui->PBclose->setIconSize(QSize(30,30));

    ui->table_client->setModel(client.afficherClient());
}

interfaceClient::~interfaceClient()
{
    delete ui;
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














/*
void interfaceContrat::on_pushButton_ModifieContrat_clicked()
{


  if(IdAgence == NULL || IdAgent =="" || referenceVehicule=="" || IdClient=="")
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

void interfaceClient::on_ajouter_clicked()
{
    LES CONTROLES DE SAISIE
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

*/






//
void interfaceClient::on_ajouter_clicked()
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

    if(nouvclient.ajouterClient())
    {
        ui->table_client->setModel(nouvclient.afficherClient());//Refresh
        text="Client ajouté avec succès";
        popUp->setPopupText(text);
        popUp->show("succes");
    }
}

void interfaceClient::on_modifier_clicked()
{
    int code = ui->code->text().toInt();

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

    if(nouvclient.modifierClient(code))
    {
        ui->table_client->setModel(nouvclient.afficherClient());//refresh
        ui->client_nom->clear();
        ui->client_prenom->clear();
        ui->client_date_naissance->clear();
        ui->client_adresse->clear();
        ui->client_num_tel->clear();
        ui->client_email->clear();
        ui->client_permis_type->clear();
        ui->client_permis_numero->clear();
        ui->client_date_del->clear();
        ui->client_datefin_del->clear();
        ui->client_cin->clear();
        ui->code->setText("");

        text="CLIENT MODIFIE AVEC SUCCES";
        popUp->setPopupText(text);
        popUp->show("succes");
    }else
        {
            text="ERREUR !";
            popUp->setPopupText(text);
            popUp->show("error");
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

void interfaceClient::on_supprimer_clicked()
{
    int IdClient = ui->code->text().toInt();

    if(IdClient==0){

            text="ERREUR VEUILLEZ SELECTIONNER UN CLIENT A SUPPRIMER !";
            popUp->setPopupText(text);
            popUp->show("error");
        }else
        {
            client.supprimerClient(IdClient);
            ui->table_client->setModel(client.afficherClient());//refresh
            ui->client_nom->clear();
            ui->client_prenom->clear();
            ui->client_date_naissance->clear();
            ui->client_adresse->clear();
            ui->client_num_tel->clear();
            ui->client_email->clear();
            ui->client_permis_type->clear();
            ui->client_permis_numero->clear();
            ui->client_date_del->clear();
            ui->client_datefin_del->clear();
            ui->client_cin->clear();
            ui->code->setText("");

            text="CLIENT SUPPRIME AVEC SUCCES";
            popUp->setPopupText(text);
            popUp->show("succes");
        }
}
//***********************************CONVENTION*******************************************
void interfaceClient::on_ajouter2_clicked()
{
    QString c_nom=ui->c_nom->text();
    QString c_adresse=ui->c_adresse->text();
    int c_numtel=ui->c_numtel->text().toInt();
    QString c_email=ui->c_email->text();

    Convention nouvconvention (c_nom,c_adresse,c_numtel,c_email);
    if(nouvconvention.ajoutConvention())
    {
        ui->table_client_2->setModel(convention.afficherConvention());//Refresh
        text="Convention ajoutée avec succès";
        popUp->setPopupText(text);
        popUp->show("succes");
    }
}

void interfaceClient::on_modifier2_clicked()
{
    int c_code = ui->c_code->text().toInt();
    QString c_nom=ui->c_nom->text();
    QString c_adresse=ui->c_adresse->text();
    int c_numtel=ui->c_numtel->text().toInt();
    QString c_email=ui->c_email->text();

    Convention nouvconvention (c_nom,c_adresse,c_numtel,c_email);

    if(nouvconvention.modifierConvention(c_code))
    {
        ui->table_client_2->setModel(convention.afficherConvention());//refresh
        ui->c_nom->clear();
        ui->c_adresse->clear();
        ui->c_numtel->clear();
        ui->c_email->clear();
        ui->c_code->setText("");

        text="CONVENTION MODIFIEE AVEC SUCCES";
        popUp->setPopupText(text);
        popUp->show("succes");
    }else
        {
            text="ERREUR !";
            popUp->setPopupText(text);
            popUp->show("error");
        }
}

void interfaceClient::on_table_client_2_activated(const QModelIndex &index)
{
    QString val=ui->table_client_2->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("select * from CONVENTION where C_CODE like '"+val+"' or C_NOM like '"+val+"'  or C_ADRESSE like '"+val+"' or C_NUMTEL like '"+val+"' or EMAIL like '"+val+"' ");
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

void interfaceClient::on_supprimer2_clicked()
{
    int IdConv = ui->c_code->text().toInt();

    if(IdConv==0){
            text="ERREUR VEUILLEZ SELECTIONNER UNE CONVENTION A SUPPRIMER !";
            popUp->setPopupText(text);
            popUp->show("error");
        }else
        {
            convention.supprimerConvention(IdConv);
            ui->table_client_2->setModel(convention.afficherConvention());//refresh
            ui->c_nom->clear();
            ui->c_adresse->clear();
            ui->c_numtel->clear();
            ui->c_email->clear();
            ui->c_code->setText("");

            text="CONVENTION SUPPRIMEE AVEC SUCCES";
            popUp->setPopupText(text);
            popUp->show("succes");
        }

}

//AUTRE
void interfaceClient::on_rechercher_clicked()
{
    int IdClient= ui->client_code2->text().toInt();
    ui->table_client->setModel(client.rechercherClient(IdClient));
}

//***********************************IMPRESSION*************************************************
void interfaceClient::on_imprimer_clicked() //PDF CLIENT
{
    QPdfWriter pdf("C:/Users/asus/Documents/Qt/PDFs/clients.pdf");
            QPainter painter;
            if (! painter.begin(&pdf))
            {
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
                     QMessageBox::information (this,"PDF","Export fait avec succès!");
}

void interfaceClient::on_imprimer2_clicked() //PDF CONVENTION
{
    QPdfWriter pdf("C:/Users/asus/Documents/Qt/PDFs/conventions.pdf");
            QPainter painter;
            if (! painter.begin(&pdf))
            {
                                qWarning("failed to open file, is it writable?");
            }
            QString id =ui->c_code2->text();
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
                     QMessageBox::information (this,"PDF","Export fait avec succès!");
}

//*************************************MAILING*********************************************
void interfaceClient::on_envoyer_clicked()
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

void interfaceClient::on_PBclient_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void interfaceClient::on_PBconvention_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void interfaceClient::on_PBcontact_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void interfaceClient::on_PBclose_clicked()
{
    close();
}

void interfaceClient::on_PBacceuil_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void interfaceClient::on_PBacceuil_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void interfaceClient::on_PBacceuil_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void interfaceClient::on_ajouterClient_clicked()
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
    QSqlQueryModel *existe=nouvclient.rechercherClientCin(cin);

        if(nouvclient.ajouterClient()){
            ui->table_client->setModel(nouvclient.afficherClient());//Refresh
            text="Client ajouté avec succès";
            popUp->setPopupText(text);
            popUp->show("succes");
        }


}

void interfaceClient::UpadateTime()
{
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm:ss");

    ui->time->setText(text);
}
