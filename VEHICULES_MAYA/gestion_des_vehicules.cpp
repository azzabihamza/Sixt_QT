#include "gestion_des_vehicules.h"
#include "ui_gestion_des_vehicules.h"
#include <QMessageBox>
#include <QString>
#include <QDate>
#include <QFile>
#include <QTextStream>
#include <QPrinter>
#include <QPrintDialog>
#include "statistiques.h"

gestion_des_vehicules::gestion_des_vehicules(QWidget *parent) ://pour tous ce qui est dyna
    QDialog(parent),
    ui(new Ui::gestion_des_vehicules)
{
    ui->setupUi(this);
    ui->table->setModel(tmpv.afficher_vehicules());//refresh
    ui->comboBox->setModel(tmpv.afficher_vehiculeslist());
    ui->table1->setModel(tmpc.afficher_contravention());//refresh
     ui->comboBox_2->setModel(tmpc.afficher_contraventionlist());
}

gestion_des_vehicules::~gestion_des_vehicules()
{
    delete ui;
}

void gestion_des_vehicules::on_pushButton_modif_clicked()
{
    QString REF = ui->ref->text();
    QString MARQUE = ui->marque->text();
    QString CARBURANT = ui->carbu->text();
    QString PLAQUE = ui->plaque->text();
    QString AGE = ui->age->text();
    QString PRIX = ui->prix->text();
    QString ID_C = ui->id_cc->text();


 vehicules p(REF,MARQUE,CARBURANT,PLAQUE,AGE,PRIX,ID_C);

bool test=tmpv.modifier_vehicules(p);//tmpv var men classe vehicules
if(test)
{
    ui->table->setModel(tmpv.afficher_vehicules());//refresh
    ui->comboBox->setModel(tmpv.afficher_vehiculeslist());//affiche id dans combo box
}
else
{
    QMessageBox::critical(nullptr, QObject::tr("modifier un Vehicule"),
                QObject::tr("Vehicule non valide  !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}
}

void gestion_des_vehicules::on_pushButton_clicked()
{
     QString REF = ui->ref->text();
     QString MARQUE = ui->marque->text();
     QString CARBURANT = ui->carbu->text();
     QString PLAQUE = ui->plaque->text();
     QString AGE = ui->age->text();
     QString PRIX = ui->prix->text();
     QString ID_C = ui->id_cc->text();


  vehicules p(REF,MARQUE,CARBURANT,PLAQUE,AGE,PRIX,ID_C);

  bool test=p.ajouter_vehicules();
   if(test)
   {
       QFile file("C:\\Users\\kamel\\Desktop\\Qt\\vehicules\\historique.txt");
             if (!file.open(QIODevice::WriteOnly | QIODevice::Append |QIODevice::Text))
                 return;
             QTextStream cout(&file);
             QString message2="\n L'historique des Vehicules à ajouter :"+REF+" "+MARQUE+" "+CARBURANT+" "+PLAQUE+" "+AGE+" "+PRIX+" "+ID_C+"";
             cout << message2;
       ui->table->setModel(tmpv.afficher_vehicules());//refresh
        ui->comboBox->setModel(tmpv.afficher_vehiculeslist());
   }
     else{
         QMessageBox::critical(nullptr, QObject::tr("Ajouter un Vehicule"),
                     QObject::tr("Vehicule existe deja  !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

 }
}

/*void gestion_des_vehicules::on_pushButton_2_clicked()
{

}*/

void gestion_des_vehicules::on_pushButton_5_clicked()
{
    statistiques *s = new statistiques();
    setWindowModality(Qt::WindowModal);
    s->show();//affiche w
}

void gestion_des_vehicules::on_pushButton_6_clicked()
{
    QFile file ("C:\\Users\\kamel\\Desktop\\Qt\\vehicules\\historique.txt");
        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::information(0,"info",file.errorString());
        }
        QTextStream in (&file);
        ui->textBrowser->setText(in.readAll());
}

void gestion_des_vehicules::on_supprimer_clicked()
{
    QString id = ui->comboBox->currentText();
    bool test=tmpv.supprimer_vehicules(id);
    if(test)
    {    ui->table->setModel(tmpv.afficher_vehicules());//refresh
         ui->comboBox->setModel(tmpv.afficher_vehiculeslist());

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer Vehicule"),
                    QObject::tr("verifier le ref  !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void gestion_des_vehicules::on_radioButton_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from VEHICULES ORDER BY PRIX ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("MARQUE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("CARBURANT"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("PLAQUE"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("AGE"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("PRIX"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("ID_C"));

ui->table->setModel(model) ;
}

void gestion_des_vehicules::on_rech_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from VEHICULES ORDER BY PRIX DESC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("MARQUE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("CARBURANT"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("PLAQUE"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("AGE"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("PRIX"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("ID_C"));

ui->table->setModel(model) ;
}

void gestion_des_vehicules::on_coderech_textChanged(const QString &arg1)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select * from VEHICULES WHERE REF like '"+ui->coderech->text()+"' OR MARQUE like '"+ui->coderech->text()+"' OR CARBURANT like '"+ui->coderech->text()+"' OR PLAQUE like '"+ui->coderech->text()+"' OR AGE like '"+ui->coderech->text()+"' OR PRIX like '"+ui->coderech->text()+"' OR ID_C like '"+ui->coderech->text()+"'");
         tmpv.rechercher(q) ;
           q.exec();//execution
           model->setQuery(q);
           ui->table->setModel(tmpv.rechercher(q)) ;//return model et affchage

}

void gestion_des_vehicules::on_pushButton_4_clicked()
{
    QPrinter printer;
        printer.setPrinterName("vehicules");
        QPrintDialog dialog(&printer,this);
        if(dialog.exec()== QDialog::Rejected) return;//cntrl de voir si ca marche ou pas
        ui->textBrowser->print(&printer);
}

void gestion_des_vehicules::on_pushButton_modif_3_clicked()
{
    QString ID = ui->idC->text();
    QString TYPE= ui->type->text();
    QDate date= ui->dateEdit->date();

    contravention p(ID,date,TYPE);

bool test=tmpc.modifier_contravention(p);
if(test)
{

    ui->table1->setModel(tmpc.afficher_contravention());//refresh
     ui->comboBox_2->setModel(tmpc.afficher_contraventionlist());
}
else
{
    QMessageBox::critical(nullptr, QObject::tr("modifier CONTRAVENTION"),
                QObject::tr("CONTRAVENTION non valide  !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}
}

void gestion_des_vehicules::on_pushButton_13_clicked()
{
    QString ID = ui->idC->text();
    QString TYPE= ui->type->text();
    QDate date= ui->dateEdit->date();

    contravention p(ID,date,TYPE);

    if(p.verif_id(p.get_id_c())==false){
     QMessageBox::critical(nullptr, QObject::tr("Ajouter Contravention"),
                 QObject::tr(" Id doit contenir 8 chiffres !\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);


    }else if(TYPE==""){
     QMessageBox::critical(nullptr, QObject::tr("Ajouter Contravention"),
                 QObject::tr(" TYPE vide !\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else{

    bool test=p.ajouter_contravention();
    if(test)
    {
      ui->table1->setModel(tmpc.afficher_contravention());//refresh
       ui->comboBox_2->setModel(tmpc.afficher_contraventionlist());

    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("Ajouter une Contravention"),
                    QObject::tr("Contravention existe deja  !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    }
}


void gestion_des_vehicules::on_supprimer_3_clicked()
{
    QString id = ui->comboBox_2->currentText();
    bool test=tmpc.supprimer_contravention(id);
    if(test)
    {    ui->table1->setModel(tmpc.afficher_contravention());//refresh
         ui->comboBox_2->setModel(tmpc.afficher_contraventionlist());

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer Contravention"),
                    QObject::tr("verifier l'id  !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}


void gestion_des_vehicules::on_suppC_textChanged(const QString &arg1)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select * from CONTRAVENTION WHERE ID_C like '"+ui->coderech->text()+"' OR DATE_C like '"+ui->coderech->text()+"' OR TYPE like '"+ui->coderech->text()+"'");
         tmpc.rechercher(q) ;
           q.exec();
           model->setQuery(q);
           ui->table1->setModel(tmpc.rechercher(q)) ;
}

void gestion_des_vehicules::on_radioButton_3_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from CONTRAVENTION ORDER BY TYPE DESC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_C"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_C"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));
ui->table1->setModel(model) ;
}

void gestion_des_vehicules::on_radioButton_4_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from CONTRAVENTION ORDER BY TYPE");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_C"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_C"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));
ui->table1->setModel(model) ;
}





/*void gestion_des_vehicules::on_pushButton_2_clicked()
{
    QString val=ui->comboBox->currentText()  ;
    QSqlQuery query ;
    query.prepare("select * from VEHICULES where REF='"+val+"'") ;

  if (query.exec())
  {
      while (query.next()) {


          ui->ref->setText(query.value(0).toString()) ;
        ui->marque->setText(query.value(1).toString()) ;
      ui->carbu->setText(query.value(2).toString()) ;
         ui->plaque->setText(query.value(3).toString()) ;
         ui->age->setText(query.value(4).toString()) ;
        ui->prix->setText(query.value(5).toString()) ;
       ui->id_cc->setText(query.value(6).toString()) ;}}
}*/

void gestion_des_vehicules::on_comboBox_2_currentIndexChanged(const QString &arg1)
{
    QString val=ui->comboBox_2->currentText()  ;
    QSqlQuery query ;
    query.prepare("select * from CONTRAVENTION where ID_C='"+val+"'") ;

  if (query.exec())
  {
      while (query.next()) {


          ui->idC->setText(query.value(0).toString()) ;
       ui->dateEdit->setDate(query.value(1).toDate()) ;
      ui->type->setText(query.value(2).toString()) ;
         }}
}

void gestion_des_vehicules::on_comboBox_currentIndexChanged(const QString &arg1)
{
    QString val=ui->comboBox->currentText()  ;
    QSqlQuery query ;
    query.prepare("select * from VEHICULES where REF='"+val+"'") ;

  if (query.exec())
  {
      while (query.next()) {


          ui->ref->setText(query.value(0).toString()) ;
        ui->marque->setText(query.value(1).toString()) ;
      ui->carbu->setText(query.value(2).toString()) ;
         ui->plaque->setText(query.value(3).toString()) ;
         ui->age->setText(query.value(4).toString()) ;
        ui->prix->setText(query.value(5).toString()) ;
       ui->id_cc->setText(query.value(6).toString()) ;}}
}
