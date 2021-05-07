#ifndef ADD_INFRACTION_H
#define ADD_INFRACTION_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>

namespace Ui {
class add_infraction;
}

class add_infraction : public QDialog
{
    Q_OBJECT

public:
    explicit add_infraction(QWidget *parent = nullptr);
    ~add_infraction();

    QString type() const;
    QString heure() const;
    QString id() const ;
    QString date() const ;
    QString zone() const;


    void get_zone();
    void fill_form(QString);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();


private:
    Ui::add_infraction *ui;
};

#endif // ADD_INFRACTION_H
