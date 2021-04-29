#include "missioninterface.h"
#include "ui_missioninterface.h"
#include <QMessageBox>
#include<QtCharts/QChartView>
#include<QtCharts/QBarSeries>
#include<QtCharts/QBarSet>
#include<QtCharts/QLegend>
#include<QtCharts/QBarCategoryAxis>
#include<QtCharts/QHorizontalStackedBarSeries>
#include<QtCharts/QLineSeries>
#include<QtCharts/QCategoryAxis>

#include<QtCharts/QPieSeries>
#include<QtCharts/QPieSlice>
#include<QGridLayout>

MissionInterface::MissionInterface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MissionInterface)
{
    ui->setupUi(this);
    setWindowTitle("Gestion de Mission");

    //INITIALISATION ADMIN
    //Column size
    ui->table_mission->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->table_vehicule->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    QStringList listmission;
    listmission << "" << "ID" << "NOM" << "TYPE";

    ui->comboBox_tri_mission->addItems(listmission);

    QStringList listvehicule;
    listvehicule << "" << "ID" << "MATRICULE" << "MARQUE";

    ui->comboBox_tri_vehicule->addItems(listvehicule);


    //refresh combobox + tableau
    refreshmission();
    refreshvehicule();

}

MissionInterface::~MissionInterface()
{
    delete ui;
}

//refresh mission
void MissionInterface::refreshmission()
{
    //remplir tableau
    ui->table_mission->setModel(tmpmission.afficher());

    ui->comboBox_mission_modif->setModel(tmpmission.remplircombomission());
    ui->comboBox_mission_supp->setModel(tmpmission.remplircombomission());

}

//refresh vehicule
void MissionInterface::refreshvehicule()
{
    //remplir tableau
    ui->table_vehicule->setModel(tmpvehicule.afficher());

    ui->comboBox_vehicule_modif->setModel(tmpvehicule.remplircombovehicule());
    ui->comboBox_vehicule_supp->setModel(tmpvehicule.remplircombovehicule());

}

//ajouter mission
void MissionInterface::on_btn_ajouter_clicked()
{
    mission mis(ui->type->text(),ui->datemission->date(),ui->nom->text());
    bool test = mis.ajouter();
    if(test)
{
        QMessageBox::information(nullptr, QObject::tr("Ajouter une mission"),
        QObject::tr("mission ajouté.\n" "Click Cancel to exit."), QMessageBox::Cancel);

        }
          else
          {
              QMessageBox::critical(nullptr, QObject::tr("Ajouter une mission"),
                          QObject::tr("Erreur !.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
          }
    //refresh combobox + tableau
    refreshmission();
}

//ajouter vehicule

void MissionInterface::on_btn_ajouter_2_clicked()
{
    vehicule vehi(ui->matricule->text(),ui->marque->text());
    bool test = vehi.ajouter();
    if(test)
{
        QMessageBox::information(nullptr, QObject::tr("Ajouter un vehicule"),
        QObject::tr("vehicule ajouté.\n" "Click Cancel to exit."), QMessageBox::Cancel);

        }
          else
          {
              QMessageBox::critical(nullptr, QObject::tr("Ajouter un vehicule"),
                          QObject::tr("Erreur !.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
          }
    //refresh combobox + tableau
    refreshvehicule();
}

//MODIFIER

void MissionInterface::on_comboBox_mission_modif_currentIndexChanged(const QString &arg1)
{
    QSqlQuery query;

    QString id = ui->comboBox_mission_modif->currentText();

    query =tmpmission.request(id);
    if(query.exec())
    {
        while(query.next())
        {
            ui->type_modif->setText(query.value(1).toString());
            ui->datemission_modif->setDate(query.value(2).toDate());
            ui->nom_modif->setText(query.value(3).toString());
        }
    }


}

void MissionInterface::on_btn_modif_clicked()
{
    if((ui->type_modif->text() != "") &&(ui->nom_modif->text() != ""))
    {
        if(tmpmission.modifier(ui->type_modif->text(),ui->datemission_modif->date(),ui->nom_modif->text(),ui->comboBox_mission_modif->currentText()))
        {
            //refresh combobox + tableau
            refreshmission();
            //message
            QMessageBox::information(this, QObject::tr("Modifier mission"),
                        QObject::tr("Mission Modifier.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
        {
            QMessageBox::critical(this, QObject::tr("Modifier un Mission"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }


    }

}

//SUPPRIMER

void MissionInterface::on_btn_supp_clicked()
{
    QMessageBox::StandardButton reply =QMessageBox::question(this,
                          "Supprimer","Voulez-vous vraiment supprimer ?",
                          QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes)
    {
        bool test=tmpmission.supprimer(ui->comboBox_mission_supp->currentText().toInt());
        if(test)
        {
            //refresh combobox + tableau
            refreshmission();

            //message
            QMessageBox::information(this, QObject::tr("Supprimer une mission"),
                        QObject::tr("mission supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
        {
            QMessageBox::critical(this, QObject::tr("Supprimer une mission"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }

    }


}

void MissionInterface::on_comboBox_mission_supp_currentIndexChanged(const QString &arg1)
{
    QSqlQuery query;

    QString id = ui->comboBox_mission_supp->currentText();

    query =tmpmission.request(id);
    if(query.exec())
    {
        while(query.next())
        {
            ui->type_val->setText(query.value(1).toString());
            ui->date_val->setText(query.value(2).toString());
            ui->nom_val->setText(query.value(3).toString());
        }
    }

}

// RECHERCHE AVANCEE
void MissionInterface::on_recherche_cursorPositionChanged(int arg1, int arg2)
{
    ui->table_mission->setModel(tmpmission.afficherecherche(ui->recherche->text()));

    QString test =ui->recherche->text();

    if(test=="")
    {
        ui->table_mission->setModel(tmpmission.afficher());//refresh
    }

}

//TRI

void MissionInterface::on_comboBox_tri_mission_currentIndexChanged(const QString &arg1)
{
    if(!(ui->comboBox_tri_mission->currentText()==""))
    {
        ui->table_mission->setModel(tmpmission.triafficher(ui->comboBox_tri_mission->currentText()));
    }

}





void MissionInterface::on_comboBox_vehicule_modif_currentIndexChanged(const QString &arg1)
{
    QSqlQuery query;

    QString id = ui->comboBox_vehicule_modif->currentText();

    query =tmpvehicule.request(id);
    if(query.exec())
    {
        while(query.next())
        {
            ui->matricule_modif->setText(query.value(1).toString());
            ui->marque_modif->setText(query.value(2).toString());
        }
    }

}

void MissionInterface::on_btn_modif_2_clicked()
{
    if((ui->matricule_modif->text() != "") &&(ui->marque_modif->text() != ""))
    {
        if(tmpvehicule.modifier(ui->matricule_modif->text(),ui->marque_modif->text(),ui->comboBox_vehicule_modif->currentText()))
        {
            //refresh combobox + tableau
            refreshvehicule();
            //message
            QMessageBox::information(this, QObject::tr("Modifier vehicule"),
                        QObject::tr("Vehicule Modifier.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
        {
            QMessageBox::critical(this, QObject::tr("Modifier Vehicule"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }


    }

}

void MissionInterface::on_comboBox_vehicule_supp_currentIndexChanged(const QString &arg1)
{
    QSqlQuery query;

    QString id = ui->comboBox_vehicule_supp->currentText();

    query =tmpvehicule.request(id);
    if(query.exec())
    {
        while(query.next())
        {
            ui->matricule_val->setText(query.value(1).toString());
            ui->marque_val->setText(query.value(2).toString());
        }
    }

}

void MissionInterface::on_btn_supp_2_clicked()
{
    QMessageBox::StandardButton reply =QMessageBox::question(this,
                          "Supprimer","Voulez-vous vraiment supprimer ?",
                          QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes)
    {
        bool test=tmpvehicule.supprimer(ui->comboBox_vehicule_supp->currentText().toInt());
        if(test)
        {
            //refresh combobox + tableau
            refreshvehicule();

            //message
            QMessageBox::information(this, QObject::tr("Supprimer Vehicule"),
                        QObject::tr("Vehicule supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
        {
            QMessageBox::critical(this, QObject::tr("Supprimer Vehicule"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }

    }


}

void MissionInterface::on_recherche_vehicule_cursorPositionChanged(int arg1, int arg2)
{
    ui->table_vehicule->setModel(tmpvehicule.afficherecherche(ui->recherche_vehicule->text()));

    QString test =ui->recherche_vehicule->text();

    if(test=="")
    {
        ui->table_vehicule->setModel(tmpvehicule.afficher());//refresh
    }

}

void MissionInterface::on_comboBox_tri_vehicule_currentIndexChanged(const QString &arg1)
{
    if(!(ui->comboBox_tri_vehicule->currentText()==""))
    {
        ui->table_vehicule->setModel(tmpvehicule.triafficher(ui->comboBox_tri_vehicule->currentText()));
    }

}



