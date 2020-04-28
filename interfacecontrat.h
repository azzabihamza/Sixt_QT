#ifndef INTERFACECONTRAT_H
#define INTERFACECONTRAT_H

#include <QDialog>
#include "contratlocation.h"
#include "mainwindow.h"

namespace Ui {
class interfaceContrat;
}

class interfaceContrat : public QDialog
{
    Q_OBJECT

public:
    explicit interfaceContrat(QWidget *parent = nullptr);
    ~interfaceContrat();

private slots:
    void on_pushButton_AjouterContrat_clicked();

    void on_pushButton_ModifieContrat_clicked();

    void on_pushButton_supprimerContrat_clicked();

    void on_pushButton_clicked();

    void on_tableContratLocation_activated(const QModelIndex &index);

private:
    Ui::interfaceContrat *ui;
    ContratLocation contratLocation;
    QDate dateSystem;
    QString text;

};

#endif // INTERFACECONTRAT_H
