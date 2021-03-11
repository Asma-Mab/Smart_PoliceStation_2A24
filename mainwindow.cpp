#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "infraction.h"
#include <QIntValidator>
#include "QMessageBox"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_numero->setValidator(new QIntValidator(100, 9999, this));
    ui->tab_infraction->setModel(I.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{
   int num=ui->le_numero->text().toInt();
    QString date=ui->la_datee->text();
    int heure=ui->le_heuree->text().toInt();
    QString type=ui->le_typee->text();
    Infraction I(num,date,heure,type);
    bool test=I.ajouter();
    QMessageBox msgBox;
    if(test)
       {
        msgBox.setText("Ajout avec succes");
     ui->tab_infraction->setModel(I.afficher());
    }
    else
        msgBox.setText("Echec d'ajout");
    msgBox.exec();

}

void MainWindow::on_pb_supprimer_clicked()
{
    Infraction I1; I1.setnum(ui->le_id_supp->text().toInt());
    bool test=I1.supprimer(I1.getnum());
    QMessageBox msgBox;
    if(test)
    {
        msgBox.setText("Suppression avec succes");
     ui->tab_infraction->setModel(I.afficher());
    }
    else
        msgBox.setText("Echec suppression");
    msgBox.exec();
}
