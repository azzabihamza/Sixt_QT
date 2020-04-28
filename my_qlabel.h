#ifndef MY_QLABEL_H
#define MY_QLABEL_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QMouseEvent>
#include <QDebug>
#include <QEvent>

class my_QLabel : public QLabel
{
    Q_OBJECT
public:
    explicit my_QLabel(QWidget *parent = nullptr);

    void mousePressEvent(QMouseEvent *ev);

signals:
    void Mouse_Pressed();
};

#endif // MY_QLABEL_H
