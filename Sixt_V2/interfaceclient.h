#ifndef INTERFACECLIENT_H
#define INTERFACECLIENT_H

#include <QDialog>
#include "client.h"
#include "convention.h"
#include "mainwindow.h"
#include "popup.h"

namespace Ui {
class interfaceClient;
}

class interfaceClient : public QDialog
{
    Q_OBJECT

public:
    explicit interfaceClient(QWidget *parent = nullptr);
    ~interfaceClient();


private slots:
    void on_ajouter_clicked();

    void on_modifier_clicked();

    void on_table_client_activated(const QModelIndex &index);

    void on_supprimer_clicked();

    void on_ajouter2_clicked();

    void on_modifier2_clicked();

    void on_table_client_2_activated(const QModelIndex &index);

    void on_supprimer2_clicked();

    void on_rechercher_clicked();

    void on_envoyer_clicked();

    void sendMail();


    void on_imprimer_clicked();

    void on_imprimer2_clicked();

    void on_PBclient_clicked();

    void on_PBconvention_clicked();

    void on_PBcontact_clicked();

    void on_PBclose_clicked();

    void on_PBacceuil_clicked();

    void on_PBacceuil_2_clicked();

    void on_PBacceuil_3_clicked();

    void on_ajouterClient_clicked();

    void UpadateTime();

private:

    Ui::interfaceClient *ui;
    Client client;
    Convention convention;
    QDate dateSystem;
    QString text;
    popup *popUp;
};


#endif // INTERFACECLIENT_H
