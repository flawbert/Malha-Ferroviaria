QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    trem.cpp

HEADERS += \
    mainwindow.h \
    trem.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../Downloads/Trem_-_Codigo_Fonte_1/Código QT5 Ubuntu - Trem/Trem.pro.user \
    ../Downloads/Trem_-_Codigo_Fonte_1/Código QT5 Ubuntu - Trem/Trem.pro.user.10 \
    ../Downloads/Trem_-_Codigo_Fonte_1/Código QT5 Ubuntu - Trem/Trem.pro.user.61b66b7
