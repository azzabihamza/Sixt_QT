#ifndef GESTIONCONTRAT_H
#define GESTIONCONTRAT_H

#include <QMainWindow>
#include "contratlocation.h"
#include "mainwindow.h"


namespace Ui {
class gestionContrat;
}

class gestionContrat : public QMainWindow
{
    Q_OBJECT

public:
    explicit gestionContrat(QWidget *parent = nullptr);
    ~gestionContrat();

    void loadHistorique();

private slots:
    void on_pushButton_AjouterContrat_clicked();

    void on_pushButton_ModifieContrat_clicked();

    void on_pushButton_supprimerContrat_clicked();

    void on_pushButton_clicked();

    void on_tableContratLocation_activated(const QModelIndex &index);

    void on_pushButton_2_clicked();

    void on_imprimer_clicked();


private:
    Ui::gestionContrat *ui;
    ContratLocation contratLocation;
    QDate dateSystem;
    QString text;
};

#endif // GESTIONCONTRAT_H
