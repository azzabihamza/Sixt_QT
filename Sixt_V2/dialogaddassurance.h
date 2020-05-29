#ifndef DIALOGADDASSURANCE_H
#define DIALOGADDASSURANCE_H

#include <QDialog>
#include <QSqlTableModel>
#include <QDataWidgetMapper>
#include <QMessageBox>

#include <database.h>

namespace Ui {
class DialogAddAssurance;
}

class DialogAddAssurance : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAddAssurance(int row = -1, QWidget *parent = 0);
    ~DialogAddAssurance();

signals:
    void signalReady();

private slots:
    void on_buttonBox_accepted();
    void updateButtons(int row);

private:
    Ui::DialogAddAssurance *ui;
    QSqlTableModel         *model;
    QDataWidgetMapper      *mapper;

private:
    void setupModel();
    void createUI();
    void accept();
};

#endif // DIALOGADDASSURANCE_H
