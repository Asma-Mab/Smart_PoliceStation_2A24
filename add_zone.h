#ifndef ADD_ZONE_H
#define ADD_ZONE_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>

namespace Ui {
class add_zone;
}

class add_zone : public QDialog
{
    Q_OBJECT

public:
    explicit add_zone(QWidget *parent = nullptr);
    ~add_zone();

    QString rue() const;
    QString ville() const;
    QString id() const ;

    void fill_form(QString);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();
private:
    Ui::add_zone *ui;
};

#endif // ADD_ZONE_H
