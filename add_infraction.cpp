#include "add_infraction.h"
#include "ui_add_infraction.h"

add_infraction::add_infraction(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_infraction)
{
    ui->setupUi(this);

    get_zone();

}

add_infraction::~add_infraction()
{
    delete ui;
}


//configurer ok et cancel
void add_infraction::on_buttonBox_accepted()
{
    accept();
}

void add_infraction::on_buttonBox_rejected()
{
    reject();
}

//get form content

QString add_infraction::date() const { //date
    return ui->date->date().toString("dd.MM.yyyy");
}

QString add_infraction::heure() const { //time

    return ui->heure->time().toString("hh:mm");
}


QString add_infraction::type() const { //combo box

    return ui->type->currentText();
}

QString add_infraction::zone() const { //combo box

    return ui->zone->currentText();
}


QString add_infraction::id() const { //line edit

    return ui->id->text();
}

//remplissage des champs du formulaire a partir de la base

void add_infraction::fill_form(QString selected ) {
    QSqlQuery query;
    query.prepare("select * from INFRACTION where ID= :id");
    query.bindValue(":id", selected);
    query.exec();
    while(query.next()){
  ui->id->setText(query.value(0).toString()); //line edit
   ui->zone->setCurrentText(query.value(4).toString()); //combo box
   ui->type->setCurrentText(query.value(3).toString()); //combo box
   ui->date->setDate(QDate::fromString(query.value(1).toString(),"dd.MM.yyyy"));//date
   ui->heure->setTime(QTime::fromString(query.value(2).toString(),"hh:mm"));//time


    }

}

//remplissage du combobox des menu a partir de la base
void add_infraction::get_zone(){
    QSqlQuery query;
    QSqlQueryModel * modal=new QSqlQueryModel();
    query.prepare("select ID from ZONE");
    query.exec();
    modal->setQuery(query);
    ui->zone->setModel(modal);


}
