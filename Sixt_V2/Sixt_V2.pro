QT       += core gui
QT += sql
QT += printsupport
QT += charts
QT += network serialport
QT       += core gui network sql printsupport serialport charts  \
            multimedia multimediawidgets
QT += multimedia widgets texttospeech

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    agence.cpp \
    assurance.cpp \
    client.cpp \
    connexion.cpp \
    contratlocation.cpp \
    contravention.cpp \
    convention.cpp \
    database.cpp \
    dialogaddassurance.cpp \
    interfaceclient.cpp \
    interfacecontrat.cpp \
    interfacemarketing.cpp \
    interfacepersonel.cpp \
    interfacevehicule.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    personnel.cpp \
    popup.cpp \
    promotions.cpp \
    publicite.cpp \
    qcustomplot.cpp \
    smtp.cpp \
    statistiques.cpp \
    statistiquespromo.cpp \
    vehicules.cpp

HEADERS += \
    agence.h \
    assurance.h \
    client.h \
    connexion.h \
    contratlocation.h \
    contravention.h \
    convention.h \
    database.h \
    dialogaddassurance.h \
    interfaceclient.h \
    interfacecontrat.h \
    interfacemarketing.h \
    interfacepersonel.h \
    interfacevehicule.h \
    login.h \
    mainwindow.h \
    personnel.h \
    popup.h \
    promotions.h \
    publicite.h \
    qcustomplot.h \
    smtp.h \
    statistiques.h \
    statistiquespromo.h \
    vehicules.h

FORMS += \
    dialogaddassurance.ui \
    interfaceclient.ui \
    interfacecontrat.ui \
    interfacemarketing.ui \
    interfacepersonel.ui \
    interfacevehicule.ui \
    login.ui \
    mainwindow.ui \
    statistiques.ui \
    statistiquespromo.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resource.qrc

DISTFILES += \
    src/img/logo.png
