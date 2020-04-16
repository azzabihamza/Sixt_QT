#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QDateTime>
#include <QStyleFactory>
#include <QMediaPlayer>
#include <QPixmap>
#include <QPrinter>
#include <QPrintDialog>
#include <QFile>
//#include "statistiques.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
qApp->setStyle(QStyleFactory::create("Fusion"));
    QPixmap pix("A:/PROJET QT/qt/template.png");
    int w =ui->pic->width();
    int h =ui->pic->height();
      ui->pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    ui->status->setText("Connected...");
  timer = new QTimer(this);
  connect(timer,SIGNAL(timeout()),this,SLOT(myfunction()));
  timer->start(1000);

  click = new QMediaPlayer();
  click->setMedia(QUrl::fromLocalFile("A:/PROJET QT/crud/click.mp3"));

}

MainWindow::~MainWindow()
{

    delete ui;

}

void MainWindow::myfunction()
{
    QTime time = QTime::currentTime();
QString time_text = time.toString ("hh : mm : ss");
if ((time.second()%2) == 0){
    time_text[3] = ' ';
    time_text[8] = ' ';
}
ui->time_label->setText(time_text);
}

void MainWindow::on_pushButton_clicked()//ajout
{
click->play();
QString REF,NOM,PRIX,AGE;
REF=ui->cx_ref->text();
NOM=ui->cx_nom->text();
PRIX=ui->cx_prix->text();
AGE=ui->cx_age->text();

QSqlQuery qry;
qry.prepare("INSERT into VEHICULE (REF,NOM,PRIX,AGE) values ('"+REF+"','"+NOM+"','"+PRIX+"','"+AGE+"')");
if (qry.exec())
{
    QFile file("C:\\Users\\kamel\\Documents\\crud\\historique.txt");
                        if (!file.open(QIODevice::WriteOnly | QIODevice::Append |QIODevice::Text))
                            return;
                        QTextStream cout(&file);
                        QString message2="\n L'historique des vehicules à ajouter :"+REF+" "+NOM+" "+PRIX+" "+AGE+"";
                        cout << message2;
QMessageBox::information(this,tr("Done"),tr("Ajout succès"));}
else
{QMessageBox::critical(this,tr("Sorry"),tr("Error"));}

}

void MainWindow::on_pushButton_2_clicked()//affichage
{
    click->play();
    QSqlQueryModel  *modal = new QSqlQueryModel();
    QSqlQuery* qry = new QSqlQuery();
    qry->prepare("Select * from VEHICULE");
    qry->exec();
    modal->setQuery(*qry);
    ui->table->setModel(modal);

}

void MainWindow::on_modifier_clicked()//modifier
{   click->play();
   QString REF,NOM,PRIX,AGE;
    REF=ui->cx_ref_2->text();
    NOM=ui->cx_nom_2->text();
    PRIX=ui->cx_prix_2->text();
    AGE=ui->cx_age_2->text();
    QSqlQuery qry;
    qry.prepare("UPDATE VEHICULE set REF='"+REF+"',NOM='"+NOM+"',PRIX='"+PRIX+"',AGE='"+AGE+"' where REF='"+REF+"'");

    if (qry.exec())
    {
    QMessageBox::information(this,tr("Done"),tr("Modifier succès"));}
    else
    {QMessageBox::critical(this,tr("Sorry"),tr("Error"));}

}

void MainWindow::on_supprimer_clicked()//supp
{   click->play();
    QString REF,NOM,PRIX,AGE;
    REF=ui->cx_ref_3->text();
    QSqlQuery qry;
    qry.prepare("Delete from VEHICULE where REF='"+REF+"'");

    if (qry.exec())
    {
    QMessageBox::information(this,tr("Done"),tr("Supprimers succès"));}
    else
    {QMessageBox::critical(this,tr("Sorry"),tr("Error"));}
}

void MainWindow::on_radioButton_clicked()//TRI PAR RAPPORT AU PRIX
{
    click->play();
    QSqlQueryModel  *modal = new QSqlQueryModel();
    QSqlQuery* qry = new QSqlQuery();
    qry->prepare("Select * from VEHICULE ORDER BY PRIX DESC");
   qry->exec();
    modal->setQuery(*qry);
    ui->table->setModel(modal);
}


void MainWindow::on_rech_clicked()
{
    QSqlQueryModel  *modal = new QSqlQueryModel();
        QSqlQuery* qry = new QSqlQuery();
        QString coderech;
        coderech=ui->coderech->text();
        qry->prepare("Select * from VEHICULE where NOM like '"+coderech+"%'");
        qry->exec();
        modal->setQuery(*qry);
        ui->table->setModel(modal);
}

void MainWindow::on_pushButton_4_clicked()
{
    QPrinter printer ;
        printer.setPrinterName("blablabla") ;
        QPrintDialog dialog (&printer,this) ;
        if ( dialog.exec()== QDialog::Rejected) return ;
        ui->textEdit->print(&printer) ;
}

/*void MainWindow::on_pushButton_5_clicked()
{
    statistiques *s = new statistiques();
        setWindowModality(Qt::WindowModal);
        s->show();
}
*/
void MainWindow::on_pushButton_6_clicked()
{
    QFile file ("C:\\Users\\kamel\\Documents\\crud\\historique.txt");
            if (!file.open(QIODevice::ReadOnly))
            {
                QMessageBox::information(0,"info",file.errorString());
            }
            QTextStream in (&file);
            ui->textBrowser->setText(in.readAll());
}
