#include "myqlabel.h"

myQlabel::myQlabel()
{

}

void myQlabel::mousePressEvent(QMouseEvent *ev)
{
    emit Mouse_Pressed();
}
