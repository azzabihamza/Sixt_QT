#ifndef GESTION_DES_VEHICULES_H
#define GESTION_DES_VEHICULES_H

#include <QDialog>
#include <QString>
#include <QDate>
#include "vehicules.h"
#include "contravention.h"

namespace Ui {
class gestion_des_vehicules;
}

class gestion_des_vehicules : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_des_vehicules(QWidget *parent = nullptr);
    ~gestion_des_vehicules();

private slots:
    void on_pushButton_modif_clicked();

    void on_pushButton_clicked();



    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_supprimer_clicked();

    void on_radioButton_clicked();

    void on_rech_clicked();

    void on_coderech_textChanged(const QString &arg1);

    void on_pushButton_4_clicked();

    void on_pushButton_modif_3_clicked();

    void on_pushButton_13_clicked();

    void on_supprimer_3_clicked();

    void on_suppC_textChanged(const QString &arg1);

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();





    void on_pushButton_2_clicked();

    void on_comboBox_2_currentIndexChanged(const QString &arg1);

    void on_comboBox_currentIndexChanged(const QString &arg1);

private:
    Ui::gestion_des_vehicules *ui;
    vehicules tmpv;
    contravention tmpc;
};

#endif // GESTION_DES_VEHICULES_H
