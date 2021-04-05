#ifndef ADD_CRIME_H
#define ADD_CRIME_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>


namespace Ui {
class add_crime;
}

class add_crime : public QDialog
{
    Q_OBJECT

public:
    explicit add_crime(QWidget *parent = nullptr);
    ~add_crime();

    QString type() const;
    QString date() const;
    QString id() const ;

    void fill_form(QString);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::add_crime *ui;
};

#endif // ADD_CRIME_H
