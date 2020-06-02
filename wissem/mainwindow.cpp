#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "publicite.h"
#include"promotions.h"
#include "statistiques.h"
#include <QMessageBox>
#include "login.h"
#include "ui_login.h"
#include "smtp.h"
#include "qcustomplot.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tablPublicite_2->setModel(tmpPublicite.afficher());
    ui->tableView_promo->setModel(tmppromotions.afficher_p());


        QSqlQueryModel * model2= new QSqlQueryModel();
        QSqlQueryModel * model1= new QSqlQueryModel();
        model2->setQuery("select ID from Publicite")  ;
        ui->comboBox_m->setModel(model2) ;
        model1->setQuery("select Idpromo from Promo") ;
        ui->comboBox_p->setModel(model1) ;


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::refrech()
{
        QSqlQueryModel * model2= new QSqlQueryModel();
        model2->setQuery("select id  from Publicite")  ;
        ui->comboBox_m->setModel(model2) ;
        ui->lineEdit_nom_2->clear();

}

void MainWindow::on_on_pb_ajouter_clicked_clicked()
{
    int id =ui->lineEdit_id_2->text().toInt();
    QString nom=ui->lineEdit_nom_2->text();
    QDate date_pub= ui->dateEdit_evenements->date();

    Publicite p(id,nom,date_pub);
if (id==NULL || nom==""){
    QMessageBox::information(nullptr, windowTitle(),QObject::tr("remplir les champs"));

}else if (p.ajouter()){
ui->tablPublicite_2->setModel(tmpPublicite.afficher());
ui->lineEdit_id_2->clear();
ui->lineEdit_nom_2->clear();

refrech();
QMessageBox::information(nullptr, windowTitle(),QObject::tr("la pub est ajoutée"));

}
}


void MainWindow::on_on_pb_supprimer_clicked()
{
    int id =ui->comboBox_m->currentText().toInt();
    bool test=tmpPublicite.supprimer(id);

    if (id==0){
        QMessageBox::information(nullptr, windowTitle(),QObject::tr("ID INCORRECT "));
    }else if (tmpPublicite.supprimer(id)){

    ui->tablPublicite_2->setModel(tmpPublicite.afficher());
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select id from publicite");
    ui->comboBox_m->setModel(model);
    ui->lineEdit_id_2->clear();
    ui->lineEdit_nom_2->clear();
    ui->dateEdit_evenements->clear();
    QMessageBox::information(nullptr, windowTitle(),QObject::tr("PUB A ETE SUPPRIME "));
    }

}
void MainWindow::on_on_pb_modifier_clicked()
{


        int id =ui->comboBox_m->currentText().toInt();
        QDate date_pub =ui->dateEdit_evenements->date();
        QString nom =ui->lineEdit_nom_2->text();

Publicite e(id,nom,date_pub);

bool test=false;
         if (id>0)test=tmpPublicite.modifier(e);
        {
             ui->tablPublicite_2->setModel(tmpPublicite.afficher());
             ui->lineEdit_id_2->clear();
             ui->lineEdit_nom_2->clear();

            QMessageBox::information(this,"publicite supprime","modification terminée ");
        }

}


void MainWindow::on_comboBox_m_currentIndexChanged(const QString &arg1)
{

    int id =ui->comboBox_m->currentText().toInt();
    QSqlQuery query;
    query.prepare("select * from Publicite where id=id");

}
void MainWindow::on_comboBox_p_currentIndexChanged(const QString &arg1)
{

    QString idpromo =ui->comboBox_p->currentText();
    QSqlQuery query;
    query.prepare("select * from Promo where Idpromo=idpromo");

}

void MainWindow::on_on_pb_actualiser_clicked()
{
    ui->tablPublicite_2->setModel(tmpPublicite.afficher());
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select code from Publicite");
    ui->comboBox_m->setModel(model);


}

void MainWindow::on_refrech_mod_clicked()
{
        QSqlQueryModel * model2= new QSqlQueryModel();
        model2->setQuery("select id  from Publicite")  ;
        ui->comboBox_m->setModel(model2) ;
}

void MainWindow::on_radioButton_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from Publicite ORDER BY ID ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
ui->tablPublicite_2->setModel(model) ;

}


void MainWindow::on_radioButton_2_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from Publicite ORDER BY ID desc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
ui->tablPublicite_2->setModel(model) ;
}

void MainWindow::on_lineEdit_rech_textEdited(const QString &arg1)
{
    QSqlQueryModel * model= new QSqlQueryModel();
        QSqlQuery q;
        q.prepare("select * from Publicite WHERE ID like '"+ui->lineEdit_rech->text()+"' OR  NOM like '"+ui->lineEdit_rech->text()+"' OR date_pub like '"+ui->lineEdit_rech->text()+"' ");
             tmpPublicite.rechercher(q) ;
               q.exec();
               model->setQuery(q);
               ui->tablPublicite_2->setModel(tmpPublicite.rechercher(q));
}

void MainWindow::on_on_pb_ajouter_p_clicked()
{
    {
        QString idpromo =ui->lineEdit_ID_promo->text();
        QString nomp=ui->lineEdit_Nom_p->text();
        int pourcentage= ui->lineEdit_pourcentage->text().toFloat();

       promotions p(idpromo,nomp,pourcentage);
    if (idpromo=="" || nomp=="" || pourcentage==NULL){
        QMessageBox::information(nullptr, windowTitle(),QObject::tr("remplir les champs"));
    }else if (p.ajouter_p()){
    ui->tableView_promo->setModel(tmppromotions.afficher_p());
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select idpromo from promo");
    ui->comboBox_p->setModel(model);
    ui->lineEdit_ID_promo->clear();
    ui->lineEdit_Nom_p->clear();
    ui->lineEdit_pourcentage->clear();
    refrech();
    QMessageBox::information(nullptr, windowTitle(),QObject::tr("la promo est ajoutée"));

    }

    }

}

void MainWindow::on_on_pb_supprimer_promo_clicked()
{
      int idpromo =ui->comboBox_p->currentText().toInt();
    bool test=tmppromotions.supprimer_p(idpromo);
    if(test)
  {
  ui->tableView_promo->setModel(tmppromotions.afficher_p());
  QSqlQueryModel *model = new QSqlQueryModel();
  model->setQuery("select idpromo from promo");
  ui->comboBox_p->setModel(model);
  ui->lineEdit_ID_promo->clear();
  ui->lineEdit_Nom_p->clear();
  ui->lineEdit_pourcentage->clear();

  refrech();
  QMessageBox::information(nullptr, windowTitle(),QObject::tr("suppression terminée"));
  }
    else
    {
        QMessageBox::information(nullptr, windowTitle(),QObject::tr("Id n'existe pas"));
}


}

void MainWindow::on_on_pb_modifier_promo_clicked()
{
    QString idpromo =ui->comboBox_p->currentText();
QString nomp=ui->lineEdit_Nom_p->text();
int pourcentage= ui->lineEdit_pourcentage->text().toFloat();

promotions p(idpromo,nomp,pourcentage);

bool test=false;
     if (idpromo>0)test=tmppromotions.modifier_p(p);
    {
         ui->tableView_promo->setModel(tmppromotions.afficher_p());
         ui->lineEdit_ID_promo->clear();
         ui->lineEdit_Nom_p->clear();
         ui->lineEdit_pourcentage->clear();

        QMessageBox::information(this,"promo supprime","modification terminée");
    }
}

void MainWindow::on_on_pb_actualiser_m_p_clicked()
{
    QSqlQueryModel * model2= new QSqlQueryModel();
        model2->setQuery("select idpromo  from promo")  ;

}



void MainWindow::on_on_pb_trier_p_croissante_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from promo ORDER BY IDPROMO ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDPROMO "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("pourcentage"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("nomp"));
ui->tableView_promo->setModel(model) ;
}

void MainWindow::on_on_pb_trier_promo_decroissante_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from promo ORDER BY IDpromo desc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDpromo "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nomp"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("pourcentage"));
ui->tableView_promo->setModel(model) ;
}



void MainWindow::on_lineEdit_rech_2_cursorPositionChanged(int arg1, int arg2)
{
    QSqlQueryModel * model= new QSqlQueryModel();
        QSqlQuery q;
        q.prepare("select * from promo WHERE IDPROMO like '"+ui->lineEdit_rech_2->text()+"' OR  NOMP like '"+ui->lineEdit_rech_2->text()+"' OR pourcentage like '"+ui->lineEdit_rech_2->text()+"' ");
             tmppromotions.rechercher_m(q) ;
               q.exec();
               model->setQuery(q);
               ui->tableView_promo->setModel(tmppromotions.rechercher_m(q));
}

void MainWindow::on_pushButton_clicked()
{
    statistiques *s = new statistiques();
    setWindowModality(Qt::WindowModal);
    s->show();
}


void MainWindow::on_tableView_promo_activated(const QModelIndex &index)
{
    //QString val=ui->tableView_promo->model()->data(index).toString();

QString val =ui->tableView_promo->model()->data(index).toString();
      QSqlQuery qry;
     // qry.prepare("select * from promo where idpromo='"+val+"' or nomp='"+val+"' or pourcentage='"+val+"");

      qry.prepare("select * from promo where idpromo='"+val+"' or nomp='"+val+"' or pourcentage='"+val+"");
  if(qry.exec())
  {

  while(qry.next())
  {
      ui->lineEdit_ID_promo->setText(qry.value(0).toString());
      ui->lineEdit_Nom_p->setText(qry.value(1).toString());
      ui->lineEdit_pourcentage->setText(qry.value(2).toString());





  }

  }
}

void MainWindow::on_pushButton_2_clicked()
{

    {

            ui->tableView_promo->setModel(tmppromotions.afficher_p());
            QSqlQueryModel *model = new QSqlQueryModel();
            model->setQuery("select idpromo from promo");
            ui->comboBox_p->setModel(model);

    }
}

/*void MainWindow::on_comboBox_m_activated(const QString &arg1)
{

    ui->comboBox_m->currentText().toInt();
    QSqlQuery query;
    query.prepare("select * from Publicite where ID=id ");

    ui->lineEdit_id_2->setText(query.value(0).toString());
    ui->lineEdit_nom_2->setText(query.value(1).toString());
    ui->dateEdit_evenements->setDate(query.value(2).toDate());
}
*/
/*void MainWindow::on_comboBox_p_activated(const QString &arg1)
{
    int id =ui->comboBox_p->currentText().toInt();
    QSqlQuery query;
    query.prepare("select * from promo where idpromo=idpromo");
            ui->lineEdit_ID_promo->setText(query.value(0).toString());
            ui->lineEdit_Nom_p->setText(query.value(1).toString());
            ui->lineEdit_pourcentage->setText(query.value(2).toString());
}

*/

void MainWindow::on_on_pb_actualiser_2_clicked()
{
    if(tmppromotions.actualiser())
        {
            ui->tableView_promo->setModel(tmppromotions.actualiser());
        }
}
