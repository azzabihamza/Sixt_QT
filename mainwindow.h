#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_5_clicked(); //AJOUT

    //void on_tabWidget_tabBarClicked(int index);

    void on_pushButton_7_clicked(); //AFFICHER

    //void on_table_activated(const QModelIndex &index);

    void on_pushButton_3_clicked(); //MODIFIER

    void on_pushButton_clicked(); //SUPPRIMER

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
