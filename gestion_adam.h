#ifndef GESTION_ADAM_H
#define GESTION_ADAM_H

#include <QMainWindow>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QDialog>
#include <QFileDialog>


#include "grade.h"
#include "employe.h"

#include "smtp.h"
#include "exportexcelobject.h"



namespace Ui {
class gestion_adam;
}

class gestion_adam : public QMainWindow
{
    Q_OBJECT

public:
    explicit gestion_adam(QWidget *parent = nullptr);
    ~gestion_adam();

    employe tmp_employe;
    grade tmp_grade;
    QSortFilterProxyModel *proxy_employe,*proxy_grade;
    void show_employe();
    void show_grade();
    void show_tables();
private slots:

    void on_rech_employe_textChanged(const QString &arg1);

    void on_actiondelete_employe_triggered();

    void on_employe_sel_col_currentIndexChanged(int index);

    void on_table_employe_clicked(const QModelIndex &index);



    void on_table_grade_clicked(const QModelIndex &index);

    void on_grade_sel_col_currentIndexChanged(int index);

    void on_rech_grade_textChanged(const QString &arg1);




    void on_export_2_clicked();

    void on_btn_ajouter_Grade_clicked();

    void on_btn_supp_grade_clicked();

    void on_id_modif_currentIndexChanged(const QString &arg1);

    void on_btn_ajouter_emp_clicked();

    void on_btn_modifier_Grade_clicked();

    void on_btn_modif_emp_clicked();

    void on_id_modif_emp_currentIndexChanged(const QString &arg1);

private:
    Ui::gestion_adam *ui;
    QString selected_employe="",selected_grade="";
    int sel_col_employe=-1,sel_col_grade=-1;


    QString mail="adam.goulli@esprit.tn";
    QString password="TGOD420AWIZ";
    grade tmpgrade;
    employe tmpemploye;

};

#endif // GESTION_ADAM_H
