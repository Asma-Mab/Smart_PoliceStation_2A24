#ifndef GESTION_SELMEN_H
#define GESTION_SELMEN_H

#include <QMainWindow>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>

#include "crime.h"
#include "add_crime.h"
#include "criminel.h"
#include "add_criminel.h"
#include "stat_crime.h"

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
    void on_actionadd_criminel_triggered();

    void on_table_criminel_clicked(const QModelIndex &index);

    void on_table_criminel_doubleClicked(const QModelIndex &index);

    void on_actiondelete_criminel_triggered();

    void on_criminel_sel_col_currentIndexChanged(const QString &arg1);

    void on_rech_criminel_textChanged(const QString &arg1);

    void on_actionadd_crime_triggered();

    void on_table_crime_clicked(const QModelIndex &index);

    void on_table_crime_doubleClicked(const QModelIndex &index);

    void on_actiondelete_crime_triggered();

    void on_crime_sel_col_currentIndexChanged(const QString &arg1);

    void on_rech_crime_textChanged(const QString &arg1);

    void on_stat_crime_clicked();


private:
    Ui::gestion_selmen *ui;
    QString selected_criminel="",selected_crime="";
    int sel_col_criminel=-1,sel_col_crime=-1;
        stat_crime *s;

};

#endif // GESTION_SELMEN_H
