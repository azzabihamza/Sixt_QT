#include "mainwindow.h"
#include "connexion.h"
#include "login.h"
#include <QApplication>
#include <QMessageBox>
#include <QtDebug>
#include <QString>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Connexion c;
    login w;
    c.ouvrirConnexion();

    w.show();

    return a.exec();
}
