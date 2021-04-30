#include "add_zone.h"
#include "ui_add_zone.h"

add_zone::add_zone(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_zone)
{
    ui->setupUi(this);
}

add_zone::~add_zone()
{
    delete ui;
}

//configurer ok et cancel
void add_zone::on_buttonBox_accepted()
{
    accept();
}

void add_zone::on_buttonBox_rejected()
{
    reject();
}

//get form content


QString add_zone::id() const { //line edit

    return ui->id->text();
}

QString add_zone::ville() const { //line edit

    return ui->ville->text();
}

QString add_zone::rue() const { //line edit

    return ui->rue->text();
}

//remplissage des champs du formulaire a partir de la base

void add_zone::fill_form(QString selected ) {
    QSqlQuery query;
    query.prepare("select * from ZONE where ID= :id");
    query.bindValue(":id", selected);
    query.exec();
    while(query.next()){
  ui->id->setText(query.value(0).toString()); //line edit
  ui->ville->setText(query.value(1).toString()); //line edit
  ui->rue->setText(query.value(2).toString()); //line edit
   ui->nb_infraction->setText(query.value(3).toString()); //line edit


    }

}
