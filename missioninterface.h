#ifndef MISSIONINTERFACE_H
#define MISSIONINTERFACE_H

#include <QDialog>
#include "mission.h"
#include "vehicule.h"
#include <QSystemTrayIcon>
#include <QtPrintSupport/QPrintDialog>
#include <QPrinter>
#include <QPrintPreviewDialog>

namespace Ui {
class MissionInterface;
}

class MissionInterface : public QDialog
{
    Q_OBJECT

public:
    explicit MissionInterface(QWidget *parent = nullptr);
    ~MissionInterface();

private slots:
    void on_btn_ajouter_clicked();

    void refreshmission();
    void refreshvehicule();

    void on_btn_ajouter_2_clicked();

    void on_comboBox_mission_modif_currentIndexChanged(const QString &arg1);

    void on_btn_modif_clicked();

    void on_btn_supp_clicked();

    void on_recherche_cursorPositionChanged(int arg1, int arg2);

    void on_comboBox_tri_mission_currentIndexChanged(const QString &arg1);

    void on_comboBox_mission_supp_currentIndexChanged(const QString &arg1);

    void on_comboBox_vehicule_modif_currentIndexChanged(const QString &arg1);

    void on_btn_modif_2_clicked();

    void on_comboBox_vehicule_supp_currentIndexChanged(const QString &arg1);

    void on_btn_supp_2_clicked();

    void on_recherche_vehicule_cursorPositionChanged(int arg1, int arg2);

    void on_comboBox_tri_vehicule_currentIndexChanged(const QString &arg1);

    void statrefresh();
    void on_btnpdf_clicked();

private:
    mission tmpmission;
    vehicule tmpvehicule;
    QSystemTrayIcon * trayIcon;

    Ui::MissionInterface *ui;
};

#endif // MISSIONINTERFACE_H
