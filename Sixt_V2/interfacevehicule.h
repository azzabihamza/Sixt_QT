#ifndef INTERFACEVEHICULE_H
#define INTERFACEVEHICULE_H

#include <QMainWindow>
#include <QDialog>
#include <QString>
#include <QDate>
#include <QTimer>
#include "vehicules.h"
#include "contravention.h"
#include "popup.h"


namespace Ui {
class interfaceVehicule;
}

class interfaceVehicule : public QMainWindow
{
    Q_OBJECT

public:
    explicit interfaceVehicule(QWidget *parent = nullptr);
    ~interfaceVehicule();

    QString text;

private slots:

    void UpadateTime();

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





    //void on_pushButton_2_clicked();

    void on_comboBox_2_currentIndexChanged(const QString &arg1);

    void on_comboBox_currentIndexChanged(const QString &arg1);


    void on_PBvehicule_clicked();

    void on_PBcontravention_clicked();

    void on_PBhistorique_clicked();

    void on_PBclose_clicked();

    void on_PBacceuil_clicked();

    void on_PBacceuil_2_clicked();

    void on_PBacceuil_3_clicked();

private:
    Ui::interfaceVehicule *ui;
    vehicules tmpv;
    contravention tmpc;
    popup *popUp;
};

#endif // INTERFACEVEHICULE_H
