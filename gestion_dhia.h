#ifndef GESTION_DHIA_H
#define GESTION_DHIA_H

#include <QMainWindow>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QDialog>
#include <QFileDialog>
#include <QMessageBox>

#include <QPainter>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>
#include <QPrintDialog>
#include <QTextStream>
#include <QSystemTrayIcon>


#include "zone.h"
#include "infraction.h"

namespace Ui {
class gestion_dhia;
}

class gestion_dhia : public QMainWindow
{
    Q_OBJECT

public:
    explicit gestion_dhia(QWidget *parent = nullptr);
    ~gestion_dhia();
    zone tmp_zone;
    infraction tmp_infraction;
    QSortFilterProxyModel *proxy_zone,*proxy_infraction;
    void show_infraction();
    void show_zone();
    void show_tables();

private slots:

    void on_table_zone_clicked(const QModelIndex &index);

    void on_zone_sel_col_currentIndexChanged(const QString &arg1);

    void on_rech_zone_textChanged(const QString &arg1);

    void on_table_infraction_clicked(const QModelIndex &index);

    void on_infraction_sel_col_currentIndexChanged(const QString &arg1);

    void on_rech_infraction_textChanged(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_deleteinfraction_clicked();

    void on_deletezone_clicked();

    void on_btnajoutzone_clicked();

    void on_btnajout_clicked();

    void on_id_inf_modif_currentIndexChanged(const QString &arg1);

    void on_id_modif_zone_currentIndexChanged(const QString &arg1);

    void on_btnmodifzone_clicked();

    void on_btnmodif_clicked();

    void sendMail();

    void mailSent(QString);


private:
    Ui::gestion_dhia *ui;
    QString selected_zone="",selected_infraction="";
    int sel_col_zone=-1,sel_col_infraction=-1;
    infraction inf;
    zone tmpzone;

    QSystemTrayIcon * trayIcon;

};

#endif // GESTION_DHIA_H
