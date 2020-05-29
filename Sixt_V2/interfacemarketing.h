#ifndef INTERFACEMARKETING_H
#define INTERFACEMARKETING_H

#include <QDialog>
#include "publicite.h"
#include"promotions.h"
#include "smtp.h"
#include "qcustomplot.h"

namespace Ui {
class interfaceMarketing;
}

class interfaceMarketing : public QDialog
{
    Q_OBJECT

public:
    explicit interfaceMarketing(QWidget *parent = nullptr);
    ~interfaceMarketing();
    QString text;

private slots:
    void on_on_pb_ajouter_clicked_clicked();
    void on_on_pb_supprimer_clicked();
    void on_on_pb_modifier_clicked();
    void on_comboBox_m_currentIndexChanged(const QString &arg1);
    void on_comboBox_p_currentIndexChanged(const QString &arg1);
    void on_on_pb_actualiser_clicked();
    void refrech();
    void on_refrech_mod_clicked();
    void on_radioButton_clicked();
    void on_radioButton_2_clicked();
    void on_lineEdit_rech_textEdited(const QString &arg1);

    void on_on_pb_ajouter_p_clicked();

    void on_on_pb_actualiser_2_clicked();

    void on_on_pb_supprimer_promo_clicked();

    void on_on_pb_modifier_promo_clicked();

    void on_on_pb_actualiser_m_p_clicked();

    //void on_radioButton_3_clicked();

    void on_on_pb_trier_p_croissante_clicked();

    void on_on_pb_trier_promo_decroissante_clicked();

    //void on_on_pb_recherche_promo_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_rech_2_cursorPositionChanged(int arg1, int arg2);

    void on_pushButton_clicked();
    //void sendMail();
    //void mailSent(QString);


    //void on_sendBtn_clicked();

    void on_tableView_promo_activated(const QModelIndex &index);

    void on_pushButton_2_clicked();

    //void on_comboBox_m_activated(const QString &arg1);

    //void on_comboBox_p_activated(const QString &arg1);

    //void on_lineEdit_rech_cursorPositionChanged(int arg1, int arg2);

    void on_PBpublicite_clicked();

    void on_PBpromotion_clicked();

    void UpadateTime();

    void on_PBacceuil_clicked();

    void on_PBacceuil_2_clicked();

private:
    Ui::interfaceMarketing *ui;
    Publicite tmpPublicite;
    Promotions tmppromotions;
    QDate dateSystem;
};

#endif // INTERFACEMARKETING_H
