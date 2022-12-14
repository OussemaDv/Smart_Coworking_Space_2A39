QT += core
QT += core gui
QT += core gui charts
QT +=sql
QT += printsupport
QT += serialport network axcontainer


CONFIG += enable_encoder_qr_code

include(QZXing/QZXing.pri)

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
    Detecteur.cpp \
    Fournisseur.cpp \
    adherents.cpp \
    arduino.cpp \
    calculatrice.cpp \
    catalogue.cpp \
    chatclient.cpp \
    chatserver.cpp \
    chatwindow.cpp \
    connexion.cpp \
    dialog.cpp \
    employe.cpp \
    espace.cpp \
    exportexcelobject.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    map.cpp \
    materiels.cpp \
    reservation.cpp \
    serverwindow.cpp \
    serverworker.cpp \
    smtp.cpp

HEADERS += \
    Detecteur.h \
    Fournisseur.h \
    adherents.h \
    arduino.h \
    calculatrice.h \
    catalogue.h \
    chatclient.h \
    chatserver.h \
    chatwindow.h \
    connexion.h \
    dialog.h \
    employe.h \
    espace.h \
    exportexcelobject.h \
    login.h \
    mainwindow.h \
    map.h \
    materiels.h \
    reservation.h \
    serverwindow.h \
    serverworker.h \
    smtp.h \
    webaxwidget.h

FORMS += \
    Detecteur.ui \
    calculatrice.ui \
    catalogue.ui \
    chatwindow.ui \
    dialog.ui \
    login.ui \
    mainwindow.ui  \
    map.ui \
    serverwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc

SUBDIRS += \
    Atelier_Connexion.pro \
    Atelier_Connexion.pro

DISTFILES += \
    pictures/customer-service.png \
    pictures/fire-prevention.png \
    pictures/gmail.png \
    pictures/logoesprit.png \
    pictures/logoprojet.png \
    pictures/map.png \
    pictures/pdf.png \
    pictures/whatsapp.png
