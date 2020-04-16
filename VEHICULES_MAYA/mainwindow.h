#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QTimer>
#include <QMainWindow>
#include <QMediaPlayer>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void myfunction();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_modifier_clicked();

    void on_supprimer_clicked();




    void on_cx_ref_cursorPositionChanged(int arg1, int arg2);

    void on_radioButton_clicked();

    void on_textEdit_copyAvailable(bool b);

    void on_coderech_cursorPositionChanged(int arg1, int arg2);

    void on_rech_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QMediaPlayer *click;
};

#endif // MAINWINDOW_H
