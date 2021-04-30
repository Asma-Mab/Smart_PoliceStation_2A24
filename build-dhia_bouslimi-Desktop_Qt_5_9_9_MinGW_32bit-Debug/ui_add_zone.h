/********************************************************************************
** Form generated from reading UI file 'add_zone.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_ZONE_H
#define UI_ADD_ZONE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_add_zone
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *nb_infraction;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *id;
    QLabel *label_5;
    QLabel *label_3;
    QLineEdit *ville;
    QLabel *label_4;
    QLineEdit *rue;

    void setupUi(QDialog *add_zone)
    {
        if (add_zone->objectName().isEmpty())
            add_zone->setObjectName(QStringLiteral("add_zone"));
        add_zone->resize(251, 238);
        buttonBox = new QDialogButtonBox(add_zone);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(40, 180, 161, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        nb_infraction = new QLineEdit(add_zone);
        nb_infraction->setObjectName(QStringLiteral("nb_infraction"));
        nb_infraction->setGeometry(QRect(160, 140, 61, 20));
        nb_infraction->setReadOnly(true);
        label_2 = new QLabel(add_zone);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 57, 47, 14));
        label = new QLabel(add_zone);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 6, 161, 41));
        id = new QLineEdit(add_zone);
        id->setObjectName(QStringLiteral("id"));
        id->setGeometry(QRect(110, 53, 113, 20));
        label_5 = new QLabel(add_zone);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(30, 143, 111, 16));
        label_3 = new QLabel(add_zone);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 84, 47, 14));
        ville = new QLineEdit(add_zone);
        ville->setObjectName(QStringLiteral("ville"));
        ville->setGeometry(QRect(110, 80, 113, 20));
        label_4 = new QLabel(add_zone);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 114, 47, 14));
        rue = new QLineEdit(add_zone);
        rue->setObjectName(QStringLiteral("rue"));
        rue->setGeometry(QRect(110, 110, 113, 20));

        retranslateUi(add_zone);
        QObject::connect(buttonBox, SIGNAL(accepted()), add_zone, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), add_zone, SLOT(reject()));

        QMetaObject::connectSlotsByName(add_zone);
    } // setupUi

    void retranslateUi(QDialog *add_zone)
    {
        add_zone->setWindowTitle(QApplication::translate("add_zone", "Dialog", Q_NULLPTR));
        nb_infraction->setText(QString());
        nb_infraction->setPlaceholderText(QApplication::translate("add_zone", "0", Q_NULLPTR));
        label_2->setText(QApplication::translate("add_zone", "ID", Q_NULLPTR));
        label->setText(QApplication::translate("add_zone", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:600; color:#0000ff;\">Details Zone</span></p></body></html>", Q_NULLPTR));
        label_5->setText(QApplication::translate("add_zone", "Nombre Infractions", Q_NULLPTR));
        label_3->setText(QApplication::translate("add_zone", "Ville", Q_NULLPTR));
        label_4->setText(QApplication::translate("add_zone", "Rue", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class add_zone: public Ui_add_zone {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_ZONE_H
