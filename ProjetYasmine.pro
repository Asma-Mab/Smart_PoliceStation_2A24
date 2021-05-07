QT       += core gui charts sql printsupport network multimedia

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
    Citoyen.cpp \
    bus.cpp \
    connection.cpp \
    crime.cpp \
    criminel.cpp \
    demande.cpp \
    employe.cpp \
    exportexcelobject.cpp \
    gestion.cpp \
    gestion_adam.cpp \
    gestion_dhia.cpp \
    gestion_selmen.cpp \
    grade.cpp \
    infraction.cpp \
    mailing/mailing/emailaddress.cpp \
    mailing/mailing/mimeattachment.cpp \
    mailing/mailing/mimecontentformatter.cpp \
    mailing/mailing/mimefile.cpp \
    mailing/mailing/mimehtml.cpp \
    mailing/mailing/mimeinlinefile.cpp \
    mailing/mailing/mimemessage.cpp \
    mailing/mailing/mimemultipart.cpp \
    mailing/mailing/mimepart.cpp \
    mailing/mailing/mimetext.cpp \
    mailing/mailing/quotedprintable.cpp \
    mailing/mailing/smtpclient.cpp \
    main.cpp \
    mainwindow.cpp \
    menu.cpp \
    mission.cpp \
    missioninterface.cpp \
    personne.cpp \
    plaintes.cpp \
    popup.cpp \
    rendez_vous.cpp \
    secretaire.cpp \
    smtp.cpp \
    statistique.cpp \
    statistique_etat.cpp \
    vehicule.cpp \
    zone.cpp

HEADERS += \
    Citoyen.h \
    administrateurs.h \
    bus.h \
    connection.h \
    crime.h \
    criminel.h \
    demande.h \
    employe.h \
    exportexcelobject.h \
    gestion.h \
    gestion_adam.h \
    gestion_dhia.h \
    gestion_selmen.h \
    grade.h \
    infraction.h \
    mailing/mailing/SmtpMime \
    mailing/mailing/emailaddress.h \
    mailing/mailing/mimeattachment.h \
    mailing/mailing/mimecontentformatter.h \
    mailing/mailing/mimefile.h \
    mailing/mailing/mimehtml.h \
    mailing/mailing/mimeinlinefile.h \
    mailing/mailing/mimemessage.h \
    mailing/mailing/mimemultipart.h \
    mailing/mailing/mimepart.h \
    mailing/mailing/mimetext.h \
    mailing/mailing/quotedprintable.h \
    mailing/mailing/smtpclient.h \
    mailing/mailing/smtpexports.h \
    mainwindow.h \
    menu.h \
    mission.h \
    missioninterface.h \
    personne.h \
    plaintes.h \
    popup.h \
    rendez_vous.h \
    secretaire.h \
    smtp.h \
    statistique.h \
    statistique_etat.h \
    vehicule.h \
    zone.h

FORMS += \
    gestion.ui \
    gestion_adam.ui \
    gestion_dhia.ui \
    gestion_selmen.ui \
    mainwindow.ui \
    menu.ui \
    missioninterface.ui \
    statistique.ui \
    statistique_etat.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Projet2A.pro.user

RESOURCES += \
    ressource.qrc



RC_FILE = myapp.rc
