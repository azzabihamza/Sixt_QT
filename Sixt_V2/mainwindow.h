#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPushButton>
#include <QDate>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QDate dateSystem;
    QPushButton *button;

private slots:
    
    
    void on_pushButtonContrat_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
