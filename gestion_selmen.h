#ifndef GESTION_SELMEN_H
#define GESTION_SELMEN_H

#include <QMainWindow>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>

#include "crime.h"
#include "criminel.h"
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <iostream>
#include <vector>

#include <QSystemTrayIcon>

namespace Ui {
class gestion_selmen;
}

class gestion_selmen : public QMainWindow
{
    Q_OBJECT

public:
    explicit gestion_selmen(QWidget *parent = nullptr);
    ~gestion_selmen();
    criminel tmp_criminel;
    crime tmp_crime;
    QSortFilterProxyModel *proxy_criminel,*proxy_crime;
    void show_crime();
    void show_criminel();
    void show_tables();

private slots:

    void on_table_criminel_clicked(const QModelIndex &index);

    void on_criminel_sel_col_currentIndexChanged(const QString &arg1);

    void on_rech_criminel_textChanged(const QString &arg1);

    void on_table_crime_clicked(const QModelIndex &index);

    void on_crime_sel_col_currentIndexChanged(const QString &arg1);

    void on_rech_crime_textChanged(const QString &arg1);

    void on_btn_ajout_crim_clicked();

    void on_id_crime_modif_currentIndexChanged(const QString &arg1);

    void on_btn_modif_crim_clicked();

    void on_btnsuppcrime_clicked();

    void choix_pie();

    void on_btnajoutcriminel_clicked();

    void on_id_criminel_modif_currentIndexChanged(const QString &arg1);

    void on_btnamodifcriminel_clicked();

    void on_btnsuppcriminel_clicked();

    void sendMail();

    void mailSent(QString);


private:
    QtCharts::QChartView *chartView ;

    Ui::gestion_selmen *ui;
    QString selected_criminel="",selected_crime="";
    int sel_col_criminel=-1,sel_col_crime=-1;
    crime tmpcrim;
    criminel tmpcriminel;
    QSystemTrayIcon * trayIcon;

};

#endif // GESTION_SELMEN_H
