#ifndef ADD_CRIMINEL_H
#define ADD_CRIMINEL_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>


namespace Ui {
class add_criminel;
}

class add_criminel : public QDialog
{
    Q_OBJECT

public:
    explicit add_criminel(QWidget *parent = nullptr);
    ~add_criminel();
    QString prenom() const;
    QString nom() const;
    QString id() const ;
    QString crime() const ;

    void get_crime();
    void fill_form(QString);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();


private:
    Ui::add_criminel *ui;
};

#endif // ADD_CRIMINEL_H
