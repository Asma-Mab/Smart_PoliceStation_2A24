#ifndef STAT_CRIME_H
#define STAT_CRIME_H

#include <QDialog>

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

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
using namespace std;

QT_CHARTS_USE_NAMESPACE
namespace Ui {
class stat_crime;
}

class stat_crime : public QDialog
{
    Q_OBJECT

public:
    explicit stat_crime(QWidget *parent = nullptr);
    ~stat_crime();

    QChartView *chartView ;
    void choix_pie();

private:
    Ui::stat_crime *ui;
};

#endif // STAT_CRIME_H
