#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
#include "smtp.h"
#include "qcustomplot.h"
#include <QtTextToSpeech/QTextToSpeech>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui {class Client;}
QT_END_NAMESPACE

class Client : public QMainWindow
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = nullptr);
    ~Client();

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_7_clicked();

    void on_tridesc_clicked();

    void on_rech_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_table_activated(const QModelIndex &index);

    void on_pdf_clicked();

    void on_sendBtn_clicked();

    void sendMail();

    void mailSent(QString);

private:
    Ui::Client *ui;
};

#endif // CLIENT_H
