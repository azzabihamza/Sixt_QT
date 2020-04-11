#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "interfacecontrat.h"

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


void MainWindow::on_pushButton_clicked()
{
    interfaceContrat GestionLocation;
    GestionLocation.setModal(true);
    GestionLocation.exec();
}
