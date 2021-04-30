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


#include "zone.h"
#include "add_zone.h"
#include "infraction.h"
#include "add_infraction.h"

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
    void on_actionadd_zone_triggered();

    void on_table_zone_clicked(const QModelIndex &index);

    void on_table_zone_doubleClicked(const QModelIndex &index);

    void on_actiondelete_zone_triggered();

    void on_zone_sel_col_currentIndexChanged(const QString &arg1);

    void on_rech_zone_textChanged(const QString &arg1);

    void on_actionadd_infraction_triggered();

    void on_table_infraction_clicked(const QModelIndex &index);

    void on_table_infraction_doubleClicked(const QModelIndex &index);

    void on_actiondelete_infraction_triggered();

    void on_infraction_sel_col_currentIndexChanged(const QString &arg1);

    void on_rech_infraction_textChanged(const QString &arg1);

    void on_pushButton_2_clicked();


private:
    Ui::gestion_dhia *ui;
    QString selected_zone="",selected_infraction="";
    int sel_col_zone=-1,sel_col_infraction=-1;
};

#endif // GESTION_DHIA_H
