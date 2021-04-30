/********************************************************************************
** Form generated from reading UI file 'gestion_dhia.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GESTION_DHIA_H
#define UI_GESTION_DHIA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gestion_dhia
{
public:
    QAction *actionadd_zone;
    QAction *actiondelete_zone;
    QAction *actionadd_infraction;
    QAction *actiondelete_infraction;
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLineEdit *rech_infraction;
    QTableView *table_infraction;
    QLabel *label;
    QComboBox *infraction_sel_col;
    QWidget *tab_2;
    QTableView *table_zone;
    QLabel *label_4;
    QLineEdit *rech_zone;
    QComboBox *zone_sel_col;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *gestion_dhia)
    {
        if (gestion_dhia->objectName().isEmpty())
            gestion_dhia->setObjectName(QStringLiteral("gestion_dhia"));
        gestion_dhia->resize(739, 539);
        actionadd_zone = new QAction(gestion_dhia);
        actionadd_zone->setObjectName(QStringLiteral("actionadd_zone"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/res/img/Add-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionadd_zone->setIcon(icon);
        actiondelete_zone = new QAction(gestion_dhia);
        actiondelete_zone->setObjectName(QStringLiteral("actiondelete_zone"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/res/img/delete-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actiondelete_zone->setIcon(icon1);
        actionadd_infraction = new QAction(gestion_dhia);
        actionadd_infraction->setObjectName(QStringLiteral("actionadd_infraction"));
        actiondelete_infraction = new QAction(gestion_dhia);
        actiondelete_infraction->setObjectName(QStringLiteral("actiondelete_infraction"));
        centralwidget = new QWidget(gestion_dhia);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 711, 461));
        tabWidget->setTabPosition(QTabWidget::West);
        tabWidget->setTabShape(QTabWidget::Triangular);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        rech_infraction = new QLineEdit(tab);
        rech_infraction->setObjectName(QStringLiteral("rech_infraction"));
        rech_infraction->setGeometry(QRect(430, 30, 151, 24));
        rech_infraction->setClearButtonEnabled(true);
        table_infraction = new QTableView(tab);
        table_infraction->setObjectName(QStringLiteral("table_infraction"));
        table_infraction->setGeometry(QRect(20, 71, 651, 331));
        table_infraction->setStyleSheet(QStringLiteral(""));
        table_infraction->setSortingEnabled(true);
        table_infraction->horizontalHeader()->setCascadingSectionResizes(true);
        table_infraction->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        table_infraction->horizontalHeader()->setStretchLastSection(false);
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 251, 31));
        infraction_sel_col = new QComboBox(tab);
        infraction_sel_col->setObjectName(QStringLiteral("infraction_sel_col"));
        infraction_sel_col->setGeometry(QRect(591, 30, 81, 22));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        table_zone = new QTableView(tab_2);
        table_zone->setObjectName(QStringLiteral("table_zone"));
        table_zone->setGeometry(QRect(10, 70, 651, 341));
        table_zone->setSelectionMode(QAbstractItemView::ExtendedSelection);
        table_zone->setSortingEnabled(true);
        table_zone->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 20, 211, 31));
        rech_zone = new QLineEdit(tab_2);
        rech_zone->setObjectName(QStringLiteral("rech_zone"));
        rech_zone->setGeometry(QRect(430, 30, 141, 24));
        rech_zone->setClearButtonEnabled(true);
        zone_sel_col = new QComboBox(tab_2);
        zone_sel_col->setObjectName(QStringLiteral("zone_sel_col"));
        zone_sel_col->setGeometry(QRect(580, 30, 81, 22));
        pushButton_2 = new QPushButton(tab_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(180, 420, 281, 23));
        tabWidget->addTab(tab_2, QString());
        gestion_dhia->setCentralWidget(centralwidget);
        menubar = new QMenuBar(gestion_dhia);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 739, 22));
        gestion_dhia->setMenuBar(menubar);
        statusbar = new QStatusBar(gestion_dhia);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        gestion_dhia->setStatusBar(statusbar);
        toolBar = new QToolBar(gestion_dhia);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        gestion_dhia->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actionadd_zone);
        toolBar->addAction(actiondelete_zone);
        toolBar->addSeparator();
        toolBar->addSeparator();
        toolBar->addAction(actionadd_infraction);
        toolBar->addAction(actiondelete_infraction);

        retranslateUi(gestion_dhia);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(gestion_dhia);
    } // setupUi

    void retranslateUi(QMainWindow *gestion_dhia)
    {
        gestion_dhia->setWindowTitle(QApplication::translate("gestion_dhia", "MainWindow", Q_NULLPTR));
        actionadd_zone->setText(QApplication::translate("gestion_dhia", "add_zone", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionadd_zone->setShortcut(QApplication::translate("gestion_dhia", "Ctrl+A", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actiondelete_zone->setText(QApplication::translate("gestion_dhia", "delete_zone", Q_NULLPTR));
        actionadd_infraction->setText(QApplication::translate("gestion_dhia", "add_infraction", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionadd_infraction->setShortcut(QApplication::translate("gestion_dhia", "Ctrl+Shift+A", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actiondelete_infraction->setText(QApplication::translate("gestion_dhia", "delete_infraction", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actiondelete_infraction->setShortcut(QApplication::translate("gestion_dhia", "Ctrl+Shift+D", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        rech_infraction->setPlaceholderText(QApplication::translate("gestion_dhia", "Recherche", Q_NULLPTR));
        label->setText(QApplication::translate("gestion_dhia", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:600; color:#5500ff;\">Gestion Infractions</span></p></body></html>", Q_NULLPTR));
        infraction_sel_col->clear();
        infraction_sel_col->insertItems(0, QStringList()
         << QApplication::translate("gestion_dhia", "All", Q_NULLPTR)
         << QApplication::translate("gestion_dhia", "ID", Q_NULLPTR)
         << QApplication::translate("gestion_dhia", "Date", Q_NULLPTR)
         << QApplication::translate("gestion_dhia", "Heure", Q_NULLPTR)
         << QApplication::translate("gestion_dhia", "Type", Q_NULLPTR)
         << QApplication::translate("gestion_dhia", "Zone", Q_NULLPTR)
        );
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("gestion_dhia", "Infractions", Q_NULLPTR));
        label_4->setText(QApplication::translate("gestion_dhia", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:600; color:#5500ff;\">Gestion Zones</span></p></body></html>", Q_NULLPTR));
        rech_zone->setPlaceholderText(QApplication::translate("gestion_dhia", "Recherche", Q_NULLPTR));
        zone_sel_col->clear();
        zone_sel_col->insertItems(0, QStringList()
         << QApplication::translate("gestion_dhia", "All", Q_NULLPTR)
         << QApplication::translate("gestion_dhia", "ID", Q_NULLPTR)
         << QApplication::translate("gestion_dhia", "Ville", Q_NULLPTR)
         << QApplication::translate("gestion_dhia", "Rue", Q_NULLPTR)
         << QApplication::translate("gestion_dhia", "Nb Infractions", Q_NULLPTR)
        );
        pushButton_2->setText(QApplication::translate("gestion_dhia", "Imprimer", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("gestion_dhia", "Zones", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("gestion_dhia", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class gestion_dhia: public Ui_gestion_dhia {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GESTION_DHIA_H
