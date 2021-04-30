QT       += core gui sql printsupport

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
    add_infraction.cpp \
    add_zone.cpp \
    connexion.cpp \
    gestion_dhia.cpp \
    infraction.cpp \
    main.cpp \
    mainwindow.cpp \
    zone.cpp

HEADERS += \
    add_infraction.h \
    add_zone.h \
    connexion.h \
    gestion_dhia.h \
    infraction.h \
    mainwindow.h \
    zone.h

FORMS += \
    add_infraction.ui \
    add_zone.ui \
    gestion_dhia.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
