#include "my_qlabel.h"

my_QLabel::my_QLabel(QWidget *parent) : QLabel(parent)
{

}

void my_QLabel::mousePressEvent(QMouseEvent *ev)
{
    emit Mouse_Pressed();
}
