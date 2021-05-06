#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include "bus.h"
#include "entretien.h"
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include "statistique_etat.h"
#include "arduino.h"
#include "rendez_vous.h"
#include "secretaire.h"
#include "plaintes.h"
#include "personne.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QSystemTrayIcon;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
  /*  void on_ajouter_bus_clicked();

    void on_supprimer_bus_clicked();

    void on_modifier_bus_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_42_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_48_clicked();

    void on_pushButton_43_clicked();

    void on_pushButton_61_clicked();

    void on_pushButton_62_clicked();

    void on_pushButton_59_clicked();

    void on_pushButton_60_clicked();

    void on_annuler_S_clicked();

    void on_annulerA_clicked();

    void on_annuler_M_clicked();

    void on_annulerAE_clicked();

    void on_annuler_SE_clicked();

    void on_annnulerME_clicked();

    void on_refresh_clicked();

    void on_search_button_clicked();

    void modifierr(int index) ;

    void on_espace_chercher_textChanged();

    void on_listebus_clicked();


    void on_pushButton_16_clicked();
*/
    void on_ajouter_rdv_clicked();

    void on_supprimer_rdv_clicked();

    void on_modifier_rdv_clicked();

    void on_search_button_clicked();

    void on_refresh_clicked();

    void on_espace_chercher_textChanged();

    void on_annulerA_clicked();

    void on_annuler_M_clicked();

    void on_annuler_S_clicked();

    void on_confirmer_A_R_clicked();

    void on_confirmerM_R_clicked();

    void on_confimerS_R_clicked();

    void on_ajouter_S_clicked();

    void on_modifier_S_clicked();

    void on_supprimer_S_clicked();

    void on_annulerAS_clicked();

    void on_annuler_SS_clicked();

    void on_annnulerMS_clicked();

    void on_confirmerSS_clicked();
    void on_pushButton_16_clicked();

   // void on_pushButton_43_clicked();

    void on_confirmerMS_clicked();

    void on_confirmerAS_clicked();
    void modifierr(int index) ;

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

private:
    int getIDFromTableView(QTableView * tv);
    Ui::MainWindow *ui;
    QSystemTrayIcon *mysystem;
    Secretaire tmps,tmpentret ;
    Rendez_vous tmpbus,tempbus;
     Rendez_vous * b,*trier ;
     statistique_etat *stat ;
     Plaintes tmpp;
     Personne *trier1,*p;
     Personne tmppers;
};
#endif // MAINWINDOW_H
