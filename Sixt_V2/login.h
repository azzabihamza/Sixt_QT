#ifndef LOGIN_H
#define LOGIN_H
#include <QString>
#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QTime>
#include <QDateTime>

#include "mainwindow.h"

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT


public:
    explicit login(QWidget *parent = nullptr);
    ~login();

    bool Login(QString u, QString p);
    bool loggedIn;
    QDate currentDate ;




private slots:
    void on_pushButton_connexion_clicked();
    void UpadateTime();

    void on_shutDown_clicked();



private:
    Ui::login *ui;
    QString userName;
    QString password ;
    MainWindow *mainwindow;

};

#endif // LOGIN_H
