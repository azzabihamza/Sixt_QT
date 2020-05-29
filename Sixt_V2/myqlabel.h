#ifndef MYQLABEL_H
#define MYQLABEL_H
#include <QLabel>
#include <QObject>
#include <QWidget>

class myQlabel : public QLabel
{
public:
    myQlabel();

    void mousePressEvent(QMouseEvent *ev);

signals:
    void Mouse_Pressed();
};

#endif // MYQLABEL_H
