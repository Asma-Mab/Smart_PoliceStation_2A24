#include "menu.h"
#include "ui_menu.h"
#include "missioninterface.h"
#include "gestion_dhia.h"
#include "gestion_selmen.h"
#include "gestion.h"
#include "gestion_adam.h"
#include "mainwindow.h"
#include "connection.h"

Menu::Menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_pushButton_clicked()
{
    gestion_dhia *dhia_inter = new gestion_dhia();
    dhia_inter->show();

}

void Menu::on_pushButton_infraction_clicked()
{

    MissionInterface *misinter = new MissionInterface();
    misinter->show();
}

void Menu::on_pushButton_criminel_clicked()
{
    gestion_selmen *selmen_inter = new gestion_selmen();
    selmen_inter->show();

}

void Menu::on_pushButton_infraction_2_clicked()
{

    gestion *cytoyen = new gestion();
    cytoyen->show();

}

void Menu::on_pushButton_infraction_3_clicked()
{
    gestion_adam *emp = new gestion_adam();
    emp->show();

}

void Menu::on_pushButton_infraction_4_clicked()
{
    Connection c;
    bool test=c.ouvrirConnexion();
    if(test){
        MainWindow *m = new MainWindow();
        m->show();

    }

}
