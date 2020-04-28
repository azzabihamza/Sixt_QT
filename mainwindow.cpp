#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "interfacecontrat.h"

#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    button =new QPushButton();



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







void MainWindow::on_pushButtonContrat_clicked()
{
    interfaceContrat GestionLocation;
    GestionLocation.setModal(true);
    GestionLocation.exec();

}
