#include "login.h"
#include "ui_login.h"
#include "gestion_des_vehicules.h"

login::login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}


void login::on_pushButton_clicked()
{
    gestion_des_vehicules P;
    P.exec();
}
