/********************************************************************************
** Form generated from reading UI file 'add_infraction.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_INFRACTION_H
#define UI_ADD_INFRACTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTimeEdit>

QT_BEGIN_NAMESPACE

class Ui_add_infraction
{
public:
    QLabel *label_5;
    QLabel *label_2;
    QLabel *label;
    QDialogButtonBox *buttonBox;
    QLabel *label_4;
    QLabel *label_3;
    QLineEdit *id;
    QLabel *label_6;
    QComboBox *type;
    QComboBox *zone;
    QTimeEdit *heure;
    QDateEdit *date;

    void setupUi(QDialog *add_infraction)
    {
        if (add_infraction->objectName().isEmpty())
            add_infraction->setObjectName(QStringLiteral("add_infraction"));
        add_infraction->resize(264, 256);
        label_5 = new QLabel(add_infraction);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(40, 137, 71, 16));
        label_2 = new QLabel(add_infraction);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 51, 47, 14));
        label = new QLabel(add_infraction);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 0, 211, 41));
        buttonBox = new QDialogButtonBox(add_infraction);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(50, 210, 161, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label_4 = new QLabel(add_infraction);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 108, 47, 14));
        label_3 = new QLabel(add_infraction);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 78, 47, 14));
        id = new QLineEdit(add_infraction);
        id->setObjectName(QStringLiteral("id"));
        id->setGeometry(QRect(120, 47, 113, 20));
        label_6 = new QLabel(add_infraction);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(40, 170, 71, 16));
        type = new QComboBox(add_infraction);
        type->setObjectName(QStringLiteral("type"));
        type->setGeometry(QRect(120, 134, 111, 22));
        zone = new QComboBox(add_infraction);
        zone->setObjectName(QStringLiteral("zone"));
        zone->setGeometry(QRect(120, 166, 111, 22));
        heure = new QTimeEdit(add_infraction);
        heure->setObjectName(QStringLiteral("heure"));
        heure->setGeometry(QRect(120, 102, 111, 22));
        date = new QDateEdit(add_infraction);
        date->setObjectName(QStringLiteral("date"));
        date->setGeometry(QRect(120, 72, 110, 22));

        retranslateUi(add_infraction);

        QMetaObject::connectSlotsByName(add_infraction);
    } // setupUi

    void retranslateUi(QDialog *add_infraction)
    {
        add_infraction->setWindowTitle(QApplication::translate("add_infraction", "Dialog", Q_NULLPTR));
        label_5->setText(QApplication::translate("add_infraction", "Type", Q_NULLPTR));
        label_2->setText(QApplication::translate("add_infraction", "ID", Q_NULLPTR));
        label->setText(QApplication::translate("add_infraction", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:600; color:#0000ff;\">Details Infraction</span></p></body></html>", Q_NULLPTR));
        label_4->setText(QApplication::translate("add_infraction", "Heure", Q_NULLPTR));
        label_3->setText(QApplication::translate("add_infraction", "Date", Q_NULLPTR));
        label_6->setText(QApplication::translate("add_infraction", "Zone", Q_NULLPTR));
        type->clear();
        type->insertItems(0, QStringList()
         << QApplication::translate("add_infraction", "type 1", Q_NULLPTR)
         << QApplication::translate("add_infraction", "type 2", Q_NULLPTR)
         << QApplication::translate("add_infraction", "type 3", Q_NULLPTR)
         << QApplication::translate("add_infraction", "type 4", Q_NULLPTR)
        );
    } // retranslateUi

};

namespace Ui {
    class add_infraction: public Ui_add_infraction {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_INFRACTION_H
