#include "add_criminel.h"
#include "ui_add_criminel.h"

add_criminel::add_criminel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_criminel)
{
    ui->setupUi(this);

    get_crime();

}

add_criminel::~add_criminel()
{
    delete ui;
}

//configurer ok et cancel
void add_criminel::on_buttonBox_accepted()
{
    accept();
}

void add_criminel::on_buttonBox_rejected()
{
    reject();
}

//get form content
QString add_criminel::crime() const { //combo box

    return ui->crime->currentText();
}

QString add_criminel::prenom() const { //line edit

    return ui->prenom->text();
}

QString add_criminel::nom() const { //line edit

    return ui->nom->text();
}

QString add_criminel::id() const { //line edit

    return ui->id->text();
}

//remplissage des champs du formulaire a partir de la base

void add_criminel::fill_form(QString selected ) {
    QSqlQuery query;
    query.prepare("select * from CRIMINEL where ID= :id");
    query.bindValue(":id", selected);
    query.exec();
    while(query.next()){
  ui->id->setText(query.value(0).toString()); //line edit
   ui->crime->setCurrentText(query.value(3).toString()); //combo box
   ui->nom->setText(query.value(1).toString()); //line edit
   ui->prenom->setText(query.value(2).toString()); //line edit


    }

}

//remplissage du combobox des menu a partir de la base
void add_criminel::get_crime(){
    QSqlQuery query;
    QSqlQueryModel * modal=new QSqlQueryModel();
    query.prepare("select ID from CRIME");
    query.exec();
    modal->setQuery(query);
    ui->crime->setModel(modal);


}
