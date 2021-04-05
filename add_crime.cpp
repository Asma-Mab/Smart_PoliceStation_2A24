#include "add_crime.h"
#include "ui_add_crime.h"

add_crime::add_crime(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_crime)
{
    ui->setupUi(this);
}

add_crime::~add_crime()
{
    delete ui;
}

//configurer ok et cancel
void add_crime::on_buttonBox_accepted()
{
    accept();
}

void add_crime::on_buttonBox_rejected()
{
    reject();
}

//get form content
QString add_crime::type() const { //text edit

    return ui->type->currentText();
}

QString add_crime::date() const { //line edit

    return ui->date->date().toString("dd.MM.yyyy");
}

QString add_crime::id() const { //line edit

    return ui->id->text();
}

//remplissage des champs du formulaire a partir de la base

void add_crime::fill_form(QString selected ) {
    QSqlQuery query;
    query.prepare("select * from CRIME where ID= :id");
    query.bindValue(":id", selected);
    query.exec();
    while(query.next()){
  ui->id->setText(query.value(0).toString()); //line edit
   ui->type->setCurrentText(query.value(2).toString()); //combo box
   ui->date->setDate(QDate::fromString(query.value(1).toString(),"dd.MM.yyyy"));//date
   ui->nb_criminel->setText(query.value(3).toString()); //line edit


    }

}
