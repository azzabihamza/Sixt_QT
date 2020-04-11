#ifndef INTERFACECONTRAT_H
#define INTERFACECONTRAT_H

#include <QDialog>
#include "contratlocation.h"

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

private:
    Ui::interfaceContrat *ui;
    ContratLocation contratLocation;
};

#endif // INTERFACECONTRAT_H
