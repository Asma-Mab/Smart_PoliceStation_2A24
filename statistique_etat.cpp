#include "statistique_etat.h"
#include "ui_statistique_etat.h"

statistique_etat::statistique_etat(QWidget *personne) :
    QMainWindow(personne),
    ui(new Ui::statistique_etat)
{
    ui->setupUi(this);
}

statistique_etat::~statistique_etat()
{
    delete ui;
}
