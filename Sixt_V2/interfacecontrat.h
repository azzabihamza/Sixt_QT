#ifndef INTERFACECONTRAT_H
#define INTERFACECONTRAT_H

#include <QDialog>
#include "contratlocation.h"
#include "assurance.h"
#include "mainwindow.h"
#include "popup.h"
#include <QSqlTableModel>

#include <database.h>
#include <dialogaddassurance.h>

namespace Ui {
class interfaceContrat;
}

class interfaceContrat : public QDialog
{
    Q_OBJECT

public:
    explicit interfaceContrat(QWidget *parent = nullptr);
    ~interfaceContrat();

    void loadHistorique();


private slots:



    void on_pushButton_AjouterContrat_clicked();

    void on_pushButton_ModifieContrat_clicked();

    void on_pushButton_supprimerContrat_clicked();

    void on_pushButton_clicked();

    void on_tableContratLocation_activated(const QModelIndex &index);

    void on_pushButton_2_clicked();

    void on_imprimer_clicked();

    void on_PBlocation_clicked();

    void on_PBassurance_clicked();

    void on_PBhistorique_clicked();

    void on_PBacceuil_clicked();

    void on_PBacceuil_4_clicked();

    void on_PBacceuil_5_clicked();


    void on_comboBox_Idagence_activated(const QString &arg1);

    void on_comboBox_Idagent_activated(const QString &arg1);

    void on_comboBox_Reference_activated(const QString &arg1);

    void on_comboBox_Idclient_activated(const QString &arg1);

    void on_pushButton_ModifierAssurance_clicked();

    void on_pushButton_AjouterAssurance_clicked();

    void on_pushButton_SupprimerAssurance_clicked();

    void on_pushButton_RechercherAssurance_clicked();

    void on_PBclose_clicked();

    void UpadateTime();

    void on_radioButton_new_clicked();

    void on_radioButton_old_clicked();

    void on_pushButton_afficherContrat_clicked();

    void on_addAssuranceButton_clicked();
    void slotUpdateModels();
    void slotEditRecord(QModelIndex index);

private:

    Ui::interfaceContrat *ui;
    ContratLocation contratLocation;
    Assurance contratAssurance;
    QDate dateSystem;
    QString text;
    popup *popUp;

    QSqlTableModel              *modelAssurance;

private:
    void setupModel(const QString &tableName, const QStringList &headers);
    void createUI();

};

#endif // INTERFACECONTRAT_H
