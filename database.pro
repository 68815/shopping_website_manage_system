#-------------------------------------------------
#
# Project created by QtCreator 2024-09-24T20:21:29
#
#-------------------------------------------------

QT += core gui
QT += core sql
QT += sql
QT += core gui testlib qml quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = database
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++17

QMAKE_CXXFLAGS += -std=c++17

QMAKE_LFLAGS += -Wl,--export-dynamic

INCLUDEPATH += $$PWD/app/include
DEPENDPATH += $$PWD/app/include

LIBS += -L$$PWD/lib -lQXlsx

INCLUDEPATH += . \
               app \
               app/view \
               app/model \
               app/ui \
               app/controller

SOURCES += \
        app/model/websitedao.cpp \
        app/view/pagingtoolpage.cpp \
        app/view/BaseOperatorInformation.cpp \
        app/model/DBHelper.cpp \
        app/view/filterdockwidget.cpp \
        app/view/filterdockwidget1.cpp \
        app/view/logindialog.cpp \
        main.cpp \
        app/view/mainwindow.cpp \
        app/model/merchandise.cpp \
        app/model/user.cpp \
        app/view/updatedatadialog.cpp \
        app/model/supplier.cpp \
        app/controller/websitecontroller.cpp \
        app/model/purchaseorder.cpp \
        app/model/review.cpp \
        app/model/usercomment.cpp

HEADERS += \
        app/view/pagingtoolpage.h \
        app/view/BaseOperatorInformation.h \
        app/model/DBHelper.h \
        app/view/filterdockwidget.h \
        app/view/filterdockwidget1.h \
        app/view/mainwindow.h \ \
        app/model/merchandise.h \
        app/model/user.h \
        app/model/websitedao.h \
        app/view/updatedatadialog.h \
        app/model/supplier.h \
        app/controller/websitecontroller.h \
        app/model/purchaseorder.h \
        app/model/review.h \
        app/model/usercomment.h \
        app/view/logindialog.h

FORMS += \
        app/ui/baseoperatorinformation.ui \
        app/ui/mainwindow.ui \
        app/ui/pagingtoolpage.ui \
        app/ui/updatedatadialog.ui \
        app/ui/filterdockwidget.ui \
        app/ui/filterdockwidget1.ui \
        app/ui/logindialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    test.qrc
