QT       += core gui
QT       += sql
QT += multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    logi.cpp \
    main.cpp \
    regi.cpp \
    widget.cpp

HEADERS += \
    logi.h \
    regi.h \
    widget.h

FORMS += \
    logi.ui \
    regi.ui \
    widget.ui

TRANSLATIONS += \
    smartplayer_zh_CN.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
