#ifndef INTERFACECLIENT_H
#define INTERFACECLIENT_H

#include <QDialog>
#include "popup.h"
#include "client.h"
#include "convention.h"

namespace Ui {
class interfaceClient;
}

class interfaceClient : public QDialog
{
    Q_OBJECT

public:
    explicit interfaceClient(QWidget *parent = nullptr);
    ~interfaceClient();

    /*bool isCharacter(const char Character);
    bool isNumber(const char Character);
    bool isValidEmailAddress(const char * EmailAddress);*/
    QString text;

private slots:
    void on_pushButton_ajouter_clicked();

    void on_pushButton_modifier_clicked();

    void on_table_client_activated(const QModelIndex &index);

    void on_pushButton_supprimer_clicked();

    void on_pushButton_ajouter_2_clicked();

    void on_pushButton_modifier_2_clicked();

    void on_table_client_2_activated(const QModelIndex &index);

    void on_pushButton_supprimer_2_clicked();

    void on_sendBtn_clicked();

    void sendMail();

private:
    Ui::interfaceClient *ui;
    popup *popUp;
    Client client;
    Convention convention;
    QDate dateSystem;
};

#endif // INTERFACECLIENT_H
