#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPushButton>
#include <QDate>
#include "interfacecontrat.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QDate dateSystem;
    QPushButton *button;
    QString getNomAgent();
    void setNomAgent(QString);

private slots:
    
    
    void on_pushButtonContrat_clicked();

    void on_pushButtonVehicule_clicked();

    void on_deconnexion_clicked();

private:
    Ui::MainWindow *ui;
    QString nomAgent;

};
#endif // MAINWINDOW_H
