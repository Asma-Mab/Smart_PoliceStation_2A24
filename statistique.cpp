#include "statistique.h"
#include "ui_statistique.h"

Statistique::Statistique(QWidget *personne) :
    QDialog(personne),
    ui(new Ui::Statistique)
{
    ui->setupUi(this);

}

Statistique::~Statistique()
{
    delete ui;
}
