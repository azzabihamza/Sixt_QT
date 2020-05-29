#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "interfacecontrat.h"
#include "interfacevehicule.h"
#include "interfaceclient.h"
#include "interfacepersonel.h"
#include "interfacemarketing.h"
#include "login.h"

#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    button =new QPushButton();

    QPixmap logo(":/src/img/src/img/logo.png");
    QPixmap shutdown(":/src/img/src/img/off.png");

    QPixmap bg(":/src/img/src/img/bg.png");

    ui->deconnexion->setFlat(true);
    ui->deconnexion->setFocusPolicy(Qt::NoFocus);
    ui->deconnexion->setIcon(shutdown);
    ui->deconnexion->setIconSize(QSize(40,40));
    ui->deconnexion->setStyleSheet("QPushButton:flat:pressed { border: none; };");

    ui->nomAgent->setText(nomAgent);

    ui->Background->setPixmap(bg);
    ui->logo->setPixmap(logo.scaled(150,150,Qt::KeepAspectRatio));



    this->dateSystem = QDate::currentDate ();
    QPixmap ButtonContrat(":/src/img/src/img/contrat.png");
    QPixmap ButtonClient(":/src/img/src/img/client.png");
    QPixmap ButtonVehicule(":/src/img/src/img/vehicule.png");
    QPixmap ButtonAgent(":/src/img/src/img/agent.png");
    QPixmap ButtonPaiment(":/src/img/src/img/payment.png");
    QPixmap ButtonMarketing(":/src/img/src/img/marketing.png");
    int h = 150;
    int w = 360;
    // mise en forme buttons
    // Button contrat
    ui->pushButtonContrat->setFlat(true);
    ui->pushButtonContrat->setFocusPolicy(Qt::NoFocus);
    ui->pushButtonContrat->setIcon(ButtonContrat);
    ui->pushButtonContrat->setIconSize(QSize(w,h));
    ui->pushButtonContrat->setStyleSheet("QPushButton:flat:pressed { border: none; };");

    // Button Client
    ui->pushButtonClient->setFlat(true);
    ui->pushButtonClient->setFocusPolicy(Qt::NoFocus);
    ui->pushButtonClient->setIcon(ButtonClient);
    ui->pushButtonClient->setIconSize(QSize(w,h));
    ui->pushButtonClient->setStyleSheet("QPushButton:flat:pressed { border: none; };");

    // Button vehicule
    ui->pushButtonVehicule->setFlat(true);
    ui->pushButtonVehicule->setFocusPolicy(Qt::NoFocus);
    ui->pushButtonVehicule->setIcon(ButtonVehicule);
    ui->pushButtonVehicule->setIconSize(QSize(w,h));
    ui->pushButtonVehicule->setStyleSheet("QPushButton:flat:pressed { border: none; };");

    // Button Paiment
    ui->pushButtonPayment->setFlat(true);
    ui->pushButtonPayment->setFocusPolicy(Qt::NoFocus);
    ui->pushButtonPayment->setIcon(ButtonPaiment);
    ui->pushButtonPayment->setIconSize(QSize(w,h));
    ui->pushButtonPayment->setStyleSheet("QPushButton:flat:pressed { border: none; };");

    // Button Marketing
    ui->pushButtonMarketing->setFlat(true);
    ui->pushButtonMarketing->setFocusPolicy(Qt::NoFocus);
    ui->pushButtonMarketing->setIcon(ButtonMarketing);
    ui->pushButtonMarketing->setIconSize(QSize(w,h));
    ui->pushButtonMarketing->setStyleSheet("QPushButton:flat:pressed { border: none; };");

    // Button personel
    ui->pushButtonPersonel->setFlat(true);
    ui->pushButtonPersonel->setFocusPolicy(Qt::NoFocus);
    ui->pushButtonPersonel->setIcon(ButtonAgent);
    ui->pushButtonPersonel->setIconSize(QSize(w,h));
    ui->pushButtonPersonel->setStyleSheet("QPushButton:flat:pressed { border: none; };");



}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::getNomAgent()
{
    return nomAgent;
}

void MainWindow::setNomAgent(QString nom)
{
    this->nomAgent = nom;
}







void MainWindow::on_pushButtonContrat_clicked()
{
    interfaceContrat *GestionLocation;
    GestionLocation = new interfaceContrat(this);
   /* GestionLocation->setWindowFlags(GestionLocation->windowFlags() | Qt::CustomizeWindowHint | Qt::WindowStaysOnTopHint | Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint);
    GestionLocation->setWindowState(GestionLocation->windowState() | Qt::WindowFullScreen);*/
    GestionLocation->setWindowState(Qt::WindowMaximized);
    GestionLocation->show();

}

void MainWindow::on_pushButtonVehicule_clicked()
{
    interfaceVehicule *GestionVehicule;
    GestionVehicule = new interfaceVehicule(this);
    /*GestionVehicule->setWindowFlags(GestionVehicule->windowFlags() | Qt::CustomizeWindowHint | Qt::WindowStaysOnTopHint | Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint);
    GestionVehicule->setWindowState(GestionVehicule->windowState() | Qt::WindowFullScreen);*/
    GestionVehicule->setWindowState(Qt::WindowMaximized);
    GestionVehicule->show();
}

void MainWindow::on_deconnexion_clicked()
{
    login* w = new login();
    w->show();
    close();
}

void MainWindow::on_pushButtonClient_clicked()
{
    interfaceClient *GestionClient;
    GestionClient = new interfaceClient(this);
    /*GestionClient->setWindowFlags(GestionClient->windowFlags() | Qt::CustomizeWindowHint | Qt::WindowStaysOnTopHint | Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint);
    GestionClient->setWindowState(GestionClient->windowState() | Qt::WindowFullScreen);*/
    GestionClient->setWindowState(Qt::WindowMaximized);
    GestionClient->show();
}

void MainWindow::on_pushButtonPersonel_clicked()
{
    InterfacePersonel *GestionPersonnel;
    GestionPersonnel = new InterfacePersonel(this);
    GestionPersonnel->setWindowState(Qt::WindowMaximized);
    GestionPersonnel->show();
}

void MainWindow::on_pushButtonMarketing_clicked()
{
    interfaceMarketing *GestionMarketing;
    GestionMarketing = new interfaceMarketing(this);
    GestionMarketing->setWindowState(Qt::WindowMaximized);
    GestionMarketing->show();
}
