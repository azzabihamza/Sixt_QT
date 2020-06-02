#include "popup.h"
#include <QPainter>
#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>

popup::popup(QWidget *parent) : QWidget(parent)
{
    setWindowFlags(Qt::FramelessWindowHint |        // Disable window decoration
                   Qt::Tool |                       // Discard display in a separate window
                   Qt::WindowStaysOnTopHint);       // Set on top of all windows
    setAttribute(Qt::WA_TranslucentBackground);     // Indicates that the background will be transparent
    setAttribute(Qt::WA_ShowWithoutActivating);     // At the show, the widget does not get the focus automatically

    animation.setTargetObject(this);                // Set the target animation
    animation.setPropertyName("popupOpacity");      //
    connect(&animation, &QAbstractAnimation::finished, this, &popup::hide);

    label.setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    label.setStyleSheet("QLabel { color : white; "
                        "margin-top: 6px;"
                        "margin-bottom: 6px;"
                        "margin-left: 10px;"
                        "margin-right: 10px; }");

    layout.addWidget(&icone, 0, 0);
    layout.addWidget(&label, 0, 1);
    setLayout(&layout);

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &popup::hideAnimation);
}

void popup::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QRect roundedRect;
    roundedRect.setX(rect().x() + 5);
    roundedRect.setY(rect().y() + 5);
    roundedRect.setWidth(rect().width() - 10);
    roundedRect.setHeight(rect().height() - 10);

   // painter.setBrush(QBrush(QColor(0,0,0,180)));
    painter.setPen(Qt::NoPen);

    painter.drawRoundedRect(roundedRect, 10, 10);
}

void popup::setStyle(QString type)
{

    if (type.compare("error")==0)
    {
    label.setStyleSheet("QLabel { border: 1px solid;"
                        "margin: 10px 0px;"
                        "padding: 15px 10px 15px 50px;"
                        "background-repeat: no-repeat;"
                        "background-position: 10px center;"
                        "color: #D8000C;"
                        "background-color: #FFBABA;}");
    icone.setText("<img src=:/src/img/src/img/error.png align=middle > " );
    }else if (type.compare("warning")==0)
    {
    label.setStyleSheet("QLabel {  border: 1px solid;"
                        "margin: 10px 0px;"
                        "padding: 15px 10px 15px 50px;"
                        "background-repeat: no-repeat;"
                        "background-position: 10px center;"
                        "color: #9F6000;"
                        "background-color: #FEEFB3; }");
    icone.setText("<img src=:/src/img/src/img/warning.png align=middle > " );
    }else if (type.compare("succes")==0)
    {
        label.setStyleSheet("QLabel {  border: 1px solid;"
                            "margin: 10px 0px;"
                            "padding: 15px 10px 15px 50px;"
                            "background-repeat: no-repeat;"
                            "background-position: 10px center;"
                            "color: #4F8A10;"
                            "background-color: #DFF2BF; }");
        icone.setText("<img src=:/src/img/src/img/succes.png align=middle > " );
    }
}

void popup::setPopupText(const QString &text)
{
    label.setText(text);    // Set the text in the Label
    adjustSize();           // With the recalculation notice sizes
}

void popup::show(QString type)
{
    setWindowOpacity(0.0);  // Set the transparency to zero

    animation.setDuration(150);     // Configuring the duration of the animation
    animation.setStartValue(0.0);   // The start value is 0 (fully transparent widget)
    animation.setEndValue(1.0);     // End - completely opaque widget

    setGeometry(QApplication::desktop()->availableGeometry().width() - 36 - width() + QApplication::desktop() -> availableGeometry().x(),
                QApplication::desktop()->availableGeometry().height() - 36 - height() + QApplication::desktop() -> availableGeometry().y(),
                width(),
                height());
    setStyle(type);
    QWidget::show();

    animation.start();
    timer->start(3000);
}

void popup::hideAnimation()
{
    timer->stop();
    animation.setDuration(1000);
    animation.setStartValue(1.0);
    animation.setEndValue(0.0);
    animation.start();
}

void popup::hide()
{
    // If the widget is transparent, then hide it
    if(getPopupOpacity() == 0.0){
        QWidget::hide();
    }
}

void popup::setPopupOpacity(float opacity)
{
    popupOpacity = opacity;

    setWindowOpacity(opacity);
}

float popup::getPopupOpacity() const
{
    return popupOpacity;
}
