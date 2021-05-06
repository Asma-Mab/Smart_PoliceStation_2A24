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
    statrefresh();

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
    if(ui->type->text()!="" && ui->nom->text()!="")
    {
        mission mis(ui->type->text(),ui->datemission->date(),ui->nom->text());
    bool test = mis.ajouter();
    if(test)
{
        //NOTIFICATION
        trayIcon = new QSystemTrayIcon(this);
        trayIcon->setVisible(true);
        trayIcon->setIcon(this->style()->standardIcon(QStyle::SP_DesktopIcon));
        trayIcon->setToolTip("Ajouter" "\n"
                        "Ajouter avec sucées");
        trayIcon->showMessage("Ajouter","Ajouter avec sucées",QSystemTrayIcon::Information,1500);
        trayIcon->show();

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
    else
        QMessageBox::critical(nullptr, QObject::tr("Verifier les Champs"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

//ajouter vehicule

void MissionInterface::on_btn_ajouter_2_clicked()
{
    if(ui->matricule->text() != "" && ui->marque->text() != "" )
    {
    vehicule vehi(ui->matricule->text(),ui->marque->text());
    bool test = vehi.ajouter();
    if(test)
{
        //NOTIFICATION
        trayIcon = new QSystemTrayIcon(this);
        trayIcon->setVisible(true);
        trayIcon->setIcon(this->style()->standardIcon(QStyle::SP_DesktopIcon));
        trayIcon->setToolTip("Ajouter" "\n"
                        "Ajouter avec sucées");
        trayIcon->showMessage("Ajouter","Ajouter avec sucées",QSystemTrayIcon::Information,1500);
        trayIcon->show();
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
    else
        QMessageBox::critical(nullptr, QObject::tr("Verifier les champs"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

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
            //NOTIFICATION
            trayIcon = new QSystemTrayIcon(this);
            trayIcon->setVisible(true);
            trayIcon->setIcon(this->style()->standardIcon(QStyle::SP_DesktopIcon));
            trayIcon->setToolTip("Modifier" "\n"
                            "Modifier avec sucées");
            trayIcon->showMessage("Modifier","Modifier avec sucées",QSystemTrayIcon::Warning,1500);
            trayIcon->show();

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
            //NOTIFICATION
            trayIcon = new QSystemTrayIcon(this);
            trayIcon->setVisible(true);
            trayIcon->setIcon(this->style()->standardIcon(QStyle::SP_DesktopIcon));
            trayIcon->setToolTip("Supprimer" "\n"
                            "Supprimer avec sucées");
            trayIcon->showMessage("Supprimer","Modifier avec sucées",QSystemTrayIcon::Warning,1500);
            trayIcon->show();

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
            //NOTIFICATION
            trayIcon = new QSystemTrayIcon(this);
            trayIcon->setVisible(true);
            trayIcon->setIcon(this->style()->standardIcon(QStyle::SP_DesktopIcon));
            trayIcon->setToolTip("Modifier" "\n"
                            "Modifier avec sucées");
            trayIcon->showMessage("Modifier","Modifier avec sucées",QSystemTrayIcon::Warning,1500);
            trayIcon->show();

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

            //NOTIFICATION
            trayIcon = new QSystemTrayIcon(this);
            trayIcon->setVisible(true);
            trayIcon->setIcon(this->style()->standardIcon(QStyle::SP_DesktopIcon));
            trayIcon->setToolTip("Supprimer" "\n"
                            "Supprimer avec sucées");
            trayIcon->showMessage("Supprimer","Supprimer avec sucées",QSystemTrayIcon::Warning,1500);
            trayIcon->show();

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

// STATISTIQUE

void MissionInterface::statrefresh(){

    QtCharts::QPieSeries *series=new QtCharts::QPieSeries();
    QStringList l=tmpvehicule.listevehicules();
   for (int i = 0; i < l.size(); ++i){

       series->append("Vehicule marque :"+l[i] ,tmpvehicule.calculmarque(l[i]));
   }


    QtCharts::QPieSlice *slice1=series->slices().at(1);
    slice1->setExploded(true);

    QtCharts::QChart *chart =new QtCharts::QChart();
    chart->addSeries(series);
    chart->setTitle("statistiques");
    chart->setAnimationOptions(QtCharts::QChart::AllAnimations);

    QtCharts::QChartView *chartview=new QtCharts::QChartView(chart);

    QGridLayout *mainLayout=new QGridLayout();
    mainLayout->addWidget(chartview,0,0);
    ui->statistiques->setLayout(mainLayout);

}


void MissionInterface::on_btnpdf_clicked()
{

    QString strStream;
               QTextStream out(&strStream);
               const int rowCount = ui->table_mission->model()->rowCount();
               const int columnCount =ui->table_mission->model()->columnCount();

               out <<  "<html>\n"
                       "<head>\n"
                       "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                       <<  QString("<title>%1</title>\n").arg("eleve")
                       <<  "</head>\n"
                       "<body bgcolor=#F4B8B8 link=#5000A0>\n"
                          // "<img src='C:/Users/ksemt/Desktop/final/icon/logo.webp' width='20' height='20'>\n"
                           "<img src='C:/Users/DeLL/Desktop/logooo.png' width='100' height='100'>\n"
                           "<h1>   Liste des Session </h1>"
                            "<h1>  </h1>"

                           "<table border=1 cellspacing=0 cellpadding=2>\n";


               // headers
                   out << "<thead><tr bgcolor=#f0f0f0>";
                   for (int column = 0; column < columnCount; column++)
                       if (!ui->table_mission->isColumnHidden(column))
                           out << QString("<th>%1</th>").arg(ui->table_mission->model()->headerData(column, Qt::Horizontal).toString());
                   out << "</tr></thead>\n";
                   // data table
                      for (int row = 0; row < rowCount; row++) {
                          out << "<tr>";
                          for (int column = 0; column < columnCount; column++) {
                              if (!ui->table_mission->isColumnHidden(column)) {
                                  QString data = ui->table_mission->model()->data(ui->table_mission->model()->index(row, column)).toString().simplified();
                                  out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                              }
                          }
                          out << "</tr>\n";
                      }
                      out <<  "</table>\n"
                          "</body>\n"
                          "</html>\n";

                      QTextDocument *document = new QTextDocument();
                      document->setHtml(strStream);

                      QPrinter printer;

                      QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                      if (dialog->exec() == QDialog::Accepted) {
                          document->print(&printer);
                   }

}
