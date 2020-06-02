#ifndef INTERFACECLIENT_H
#define INTERFACECLIENT_H

#include <QDialog>
#include <QString>
#include "popup.h"
#include "agence.h"
#include "personnel.h"

namespace Ui {
class interfacePersonnel;
}

class interfacePersonnel : public QDialog
{
    Q_OBJECT

public:
    explicit interfacePersonnel(QWidget *parent = nullptr);
    ~interfacePersonnel();

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
    Ui::interfacePersonnel *ui;
    popup *popUp;
    Agence agence;
    Personnel personnel;
    QDate dateSystem;
};

#endif // INTERFACECLIENT_H
