#include "interfacepersonel.h"
#include "ui_interfacepersonel.h"

InterfacePersonel::InterfacePersonel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InterfacePersonel)
{
    ui->setupUi(this);
}

InterfacePersonel::~InterfacePersonel()
{
    delete ui;
}


void InterfacePersonel::on_pushButton_ajouter_clicked()
{
    int id=ui->id->text().toInt();
    QString nom=ui->nom->text();
    QString prenom=ui->prenom->text();
    QDate datenaissance=ui->datenaissance->date();
    QDate dateembauche=ui->dateembauche->date();
    QString adresse=ui->adresse->text();
    QString tel=ui->tel->text();
    QString email=ui->email->text();
    QString role=ui->role->text();
    int codepostal=ui->codepostal->text().toInt();
    QString ville=ui->ville->text();
    QString pays=ui->pays->text();

    Personnel p(id,nom,prenom,datenaissance,dateembauche,adresse,tel,email,role,codepostal,ville,pays);
    if (datenaissance > dateembauche){
                text="DATE SAISIE EST INCORRECT !";
                popUp->setPopupText(text);
                popUp->show("warning");
    }
    else if (id == NULL || nom=="" || prenom=="" || adresse=="" || tel=="" || email=="" || role=="" || codepostal==NULL || ville=="" || pays==""){
                text="REMPLIR TOUS LES CHAMPS !";
                popUp->setPopupText(text);
                popUp->show("warning");
    }else if (p.ajouter_Personnel()){
        ui->table_personnel->setModel(personnel.afficher_Personnel());
        ui->id->clear();
        ui->nom->clear();
        ui->prenom->clear();
        ui->adresse->clear();
        ui->tel->clear();
        ui->email->clear();
        ui->role->clear();
        ui->codepostal->clear();
        ui->ville->clear();
        ui->pays->clear();
        text="PERSONNEL AJOUTE AVEC SUCCES";
        popUp->setPopupText(text);
        popUp->show("succes");

    }else
    {

        text="ERREUR !";
        popUp->setPopupText(text);
        popUp->show("error");
    }
}


void InterfacePersonel::on_pushButton_modifier_clicked()
{
    int id=ui->id->text().toInt();
    QString nom=ui->nom->text();
    QString prenom=ui->prenom->text();
    QDate datenaissance=ui->datenaissance->date();
    QDate dateembauche=ui->dateembauche->date();
    QString adresse=ui->adresse->text();
    QString tel=ui->tel->text();
    QString email=ui->email->text();
    QString role=ui->role->text();
    int codepostal=ui->codepostal->text().toInt();
    QString ville=ui->ville->text();
    QString pays=ui->pays->text();

    Personnel p(id,nom,prenom,datenaissance,dateembauche,adresse,tel,email,role,codepostal,ville,pays);

    if (datenaissance > dateembauche){
                text="DATE SAISIE EST INCORRECT !";
                popUp->setPopupText(text);
                popUp->show("warning");
    }
    else if (id == NULL || nom=="" || prenom=="" || adresse=="" || tel=="" || email=="" || role=="" || codepostal==NULL || ville=="" || pays==""){
                text="REMPLIR TOUS LES CHAMPS !";
                popUp->setPopupText(text);
                popUp->show("warning");
    }else if(id>0){
        bool test=false;
        test=p.modifier_Personnel();
        ui->table_personnel->setModel(personnel.afficher_Personnel());
        ui->id->clear();
        ui->nom->clear();
        ui->prenom->clear();
        ui->adresse->clear();
        ui->tel->clear();
        ui->email->clear();
        ui->role->clear();
        ui->codepostal->clear();
        ui->ville->clear();
        ui->pays->clear();
        text="PERSONNEL MODIFIER AVEC SUCCES ";
        popUp->setPopupText(text);
        popUp->show("succes");

    }else
    {
        text="ERREUR !";
        popUp->setPopupText(text);
        popUp->show("error");
    }
}

void InterfacePersonel::on_pushButton_supprimer_clicked()
{
    int id = ui->id_2->text().toInt();
    if (id==0){
                    text="ERREUR VEUILLEZ SELECTIONNER UN PERSONNEL A SUPPRIMER !";
                    popUp->setPopupText(text);
                    popUp->show("error");
    }else
    {
        personnel.supprimer_Personnel(id);
        ui->table_personnel->setModel(personnel.afficher_Personnel());
        ui->id->clear();
        ui->id_2->clear();
        ui->nom->clear();
        ui->prenom->clear();
        ui->adresse->clear();
        ui->tel->clear();
        ui->email->clear();
        ui->role->clear();
        ui->codepostal->clear();
        ui->ville->clear();
        ui->pays->clear();
        text="PERSONNEL SUPPRIMER AVEC SUCCES !";
        popUp->setPopupText(text);
        popUp->show("succes");

    }
}

void InterfacePersonel::on_id_2_textEdited()
{
    QSqlQueryModel * model= new QSqlQueryModel();
        QSqlQuery q;
        q.prepare("select * from PERSONNEL WHERE ID like '"+ui->id_2->text()+"' ");
             personnel.rechercher(q) ;
               q.exec();
               model->setQuery(q);
               ui->table_personnel->setModel(personnel.rechercher(q));

}
void InterfacePersonel::on_id_3_textEdited()
{
    QSqlQueryModel * model= new QSqlQueryModel();
        QSqlQuery q;
        q.prepare("select * from AGENCE WHERE ID_AGENCE like '"+ui->id_3->text()+"' ");
             agence.rechercher(q) ;
               q.exec();
               model->setQuery(q);
               ui->table_agence->setModel(agence.rechercher(q));

}

void InterfacePersonel::on_pushButton_actualiser_clicked()
{
    if(personnel.actualiser())
    {
        ui->table_personnel->setModel(personnel.actualiser());
        text="ACTUALISER";
        popUp->setPopupText(text);
        popUp->show("succes");
    }
}
void InterfacePersonel::on_pushButton_triasc_clicked()
{
    if(personnel.tricrois_Personnel())
    {
        ui->table_personnel->setModel(personnel.tricrois_Personnel());
        text="TRIE CROISSANT";
        popUp->setPopupText(text);
        popUp->show("succes");
    }
}

void InterfacePersonel::on_pushButton_trides_clicked(){

    if(personnel.tridecrois_Personnel())
    {
        ui->table_personnel->setModel(personnel.tridecrois_Personnel());
        text="TRIE DECROISSANT";
        popUp->setPopupText(text);
        popUp->show("succes");
    }
}

void InterfacePersonel::on_pushButton_ajouter2_clicked()
{
    int id=ui->idagence->text().toInt();
    QString nomagence=ui->nomagence->text();
    int idchefagence=ui->idchef->text().toInt();
    int budget=ui->budget->text().toInt();
    QString adresse=ui->adresse_2->text();
    QString pays=ui->pays_2->text();
    QString ville=ui->ville_2->text();
    QString type=ui->type->text();

    Agence a(id,nomagence,idchefagence,budget,adresse,pays,ville,type);

    if (id==NULL || nomagence=="" || idchefagence==NULL || budget==NULL || adresse=="" || pays=="" || ville=="" || type==""){
        text="REMPLIR TOUS LES CHAMPS !";
        popUp->setPopupText(text);
        popUp->show("warning");
    }else if (a.ajouter_agence()){
        ui->table_agence->setModel(agence.afficher_agence());
        ui->idagence->clear();
        ui->nomagence->clear();
        ui->idchef->clear();
        ui->budget->clear();
        ui->adresse_2->clear();
        ui->pays_2->clear();
        ui->ville_2->clear();
        ui->type->clear();
        text="AGENCE AJOUTE AVEC SUCCES ";
        popUp->setPopupText(text);
        popUp->show("succes");

    }else
    {
        text="ERREUR !";
        popUp->setPopupText(text);
        popUp->show("error");

    }
}


void InterfacePersonel::on_pushButton_modifier2_clicked()
{
    int id=ui->idagence->text().toInt();
    QString nomagence=ui->nomagence->text();
    int idchefagence=ui->idchef->text().toInt();
    int budget=ui->budget->text().toInt();
    QString adresse=ui->adresse_2->text();
    QString pays=ui->pays_2->text();
    QString ville=ui->ville_2->text();
    QString type=ui->type->text();

    Agence a(id,nomagence,idchefagence,budget,adresse,pays,ville,type);

    if (id==NULL || nomagence=="" || idchefagence==NULL || budget==NULL || adresse=="" || pays=="" || ville=="" || type==""){
        text="REMPLIR TOUS LES CHAMPS !";
        popUp->setPopupText(text);
        popUp->show("warning");
    }
    else if (id>0){
        bool test=false;
        test=a.modifier_agence();
        ui->table_agence->setModel(agence.afficher_agence());
        ui->idagence->clear();
        ui->nomagence->clear();
        ui->idchef->clear();
        ui->budget->clear();
        ui->adresse_2->clear();
        ui->pays_2->clear();
        ui->ville_2->clear();
        ui->type->clear();
        text="AGENCE A ETE MODIFIER AVEC SUCCES";
        popUp->setPopupText(text);
        popUp->show("succes");

    }else{
        text="ERREUR !";
        popUp->setPopupText(text);
        popUp->show("error");
    }
}

void InterfacePersonel::on_pushButton_supprimer2_clicked()
{
    int id = ui->id_3->text().toInt();

    if(id==0){
            text="ERREUR VEUILLEZ SELECTIONNER UN AGENCE A SUPPRIMER !";
            popUp->setPopupText(text);
            popUp->show("error");
            }
    else
    {
        agence.supprimer_agence(id);
        ui->table_agence->setModel(agence.afficher_agence());
        ui->id_3->clear();
        ui->idagence->clear();
        ui->nomagence->clear();
        ui->idchef->clear();
        ui->budget->clear();
        ui->adresse_2->clear();
        ui->pays_2->clear();
        ui->ville_2->clear();
        ui->type->clear();
        text="AGENCE SUPPRIMER AVEC SUCCES";
        popUp->setPopupText(text);
        popUp->show("succes");

    }
}

void InterfacePersonel::on_pushButton_triasc2_clicked()
{
    if(agence.tricrois_agence())
    {
        ui->table_agence->setModel(agence.tricrois_agence());
        text="TRIE CROISSANT";
        popUp->setPopupText(text);
        popUp->show("succes");
    }
}

void InterfacePersonel::on_pushButton_trides2_clicked(){

    if(agence.tridecrois_agence())
    {
        ui->table_agence->setModel(agence.tridecrois_agence());
        text="TRIE DECROISSANT";
        popUp->setPopupText(text);
        popUp->show("succes");
    }
}

void InterfacePersonel::on_pushButton_actualiser2_clicked()
{
    if(agence.actualiser())
    {
        ui->table_agence->setModel(agence.actualiser());
        text="ACTUALISER";
        popUp->setPopupText(text);
        popUp->show("succes");
    }
}




