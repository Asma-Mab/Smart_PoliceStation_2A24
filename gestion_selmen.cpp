#include "gestion_selmen.h"
#include "ui_gestion_selmen.h"
#include "smtp.h"

gestion_selmen::gestion_selmen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gestion_selmen)
{
    ui->setupUi(this);
    //affichage contenu base
    show_tables();
    choix_pie();
    ui->id_crime_modif->setModel(tmpcrim.remplircombocrime());
    ui->id_criminel_modif->setModel(tmpcriminel.remplircombocriminel());
    ui->crime->setModel(tmpcrim.remplircombocrime());
    ui->crime_modif->setModel(tmpcrim.remplircombocrime());
}

gestion_selmen::~gestion_selmen()
{
    delete ui;
}

void gestion_selmen::show_tables()
{
show_criminel();
show_crime();
}

/************************** criminel********************************/

//affichage
void gestion_selmen::show_criminel()
{
    //creation model (masque du tableau) : permet recherche et tri
        proxy_criminel = new QSortFilterProxyModel();

     //definir la source (tableau original)
        proxy_criminel->setSourceModel(tmp_criminel.afficher());

     //pour la recherche
        proxy_criminel->setFilterCaseSensitivity(Qt::CaseInsensitive); // S=s (pas de difference entre majiscule et miniscule)

        //remplissage tableau avec le masque
        ui->table_criminel->setModel(proxy_criminel);
}

//recherche dynamique
void gestion_selmen::on_criminel_sel_col_currentIndexChanged(const QString &arg1)
{
    sel_col_criminel=ui->criminel_sel_col->currentIndex()-1;
    proxy_criminel->setFilterKeyColumn(sel_col_criminel); // chercher dans tout le tableau (-1) ou donner le numero de la colone

}

void gestion_selmen::on_rech_criminel_textChanged(const QString &arg1)
{
    proxy_criminel->setFilterFixedString(arg1);

}

//ajout

void gestion_selmen::on_btnajoutcriminel_clicked()
{
    //ajout
    criminel mc(ui->id_criminel->text(),ui->nom->text(),ui->prenom->text(),ui->crime->currentText());
   mc.ajouter();
    mc.count_criminels();
    //refresh du tableau (affichage)
      show_tables();
      //NOTIFICATION
      trayIcon = new QSystemTrayIcon(this);
      trayIcon->setVisible(true);
      trayIcon->setIcon(this->style()->standardIcon(QStyle::SP_DesktopIcon));
      trayIcon->setToolTip("Ajouter" "\n"
                      "Ajouter avec sucées");
      trayIcon->showMessage("Ajouter","Ajouter avec sucées",QSystemTrayIcon::Information,1500);
      trayIcon->show();


}

//get id from selected row
void gestion_selmen::on_table_criminel_clicked(const QModelIndex &index)
{
    selected_criminel=ui->table_criminel->model()->data(index).toString();
}

//suppression
void gestion_selmen::on_btnsuppcriminel_clicked()
{
    criminel mc;
  mc.supprimer(selected_criminel);

  mc.count_criminels();
  //refresh du tableau (affichage)
    show_tables();
    //NOTIFICATION
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setVisible(true);
    trayIcon->setIcon(this->style()->standardIcon(QStyle::SP_DesktopIcon));
    trayIcon->setToolTip("Supprimer" "\n"
                    "Supprimer avec sucées");
    trayIcon->showMessage("Supprimer","Supprimer avec sucées",QSystemTrayIcon::Warning,1500);
    trayIcon->show();

}


//modification

void gestion_selmen::on_id_criminel_modif_currentIndexChanged(const QString &arg1)
{
    QSqlQuery query;

    query =tmpcriminel.request(ui->id_criminel_modif->currentText());
    if(query.exec())
    {
        while(query.next())
        {
            ui->nom_modif->setText(query.value(1).toString());
            ui->prenom_modif->setText(query.value(2).toString());
            ui->crime_modif->setCurrentText(query.value(3).toString());
        }
    }

}

void gestion_selmen::on_btnamodifcriminel_clicked()
{
    //mofication
    criminel mc(ui->id_criminel_modif->currentText(),ui->nom_modif->text(),ui->prenom_modif->text(),ui->crime_modif->currentText());
    mc.modifier(ui->id_criminel_modif->currentText());

    mc.count_criminels();
    //refresh du tableau (affichage)
      show_tables();

      //NOTIFICATION
      trayIcon = new QSystemTrayIcon(this);
      trayIcon->setVisible(true);
      trayIcon->setIcon(this->style()->standardIcon(QStyle::SP_DesktopIcon));
      trayIcon->setToolTip("Modifier" "\n"
                      "Modifier avec sucées");
      trayIcon->showMessage("Modifier","Modifier avec sucées",QSystemTrayIcon::Information,1500);
      trayIcon->show();


}


/************************** crime ********************************/

//affichage
void gestion_selmen::show_crime()
{
    //creation model (masque du tableau) : permet recherche et tri
        proxy_crime = new QSortFilterProxyModel();

     //definir la source (tableau original)
        proxy_crime->setSourceModel(tmp_crime.afficher());

     //pour la recherche
        proxy_crime->setFilterCaseSensitivity(Qt::CaseInsensitive); // S=s (pas de difference entre majiscule et miniscule)
       //remplissage tableau avec le masque
        ui->table_crime->setModel(proxy_crime);
}

//recherche dynamique
void gestion_selmen::on_crime_sel_col_currentIndexChanged(const QString &arg1)
{
    sel_col_crime=ui->crime_sel_col->currentIndex()-1;
    proxy_crime->setFilterKeyColumn(sel_col_crime); // chercher dans tout le tableau (-1) ou donner le numero de la colone

}

void gestion_selmen::on_rech_crime_textChanged(const QString &arg1)
{
    proxy_crime->setFilterFixedString(arg1);

}

//ajout


void gestion_selmen::on_btn_ajout_crim_clicked()
{
    crime mc(ui->id->text(),ui->type->currentText(),ui->date->text());
   mc.ajouter();
    //refresh du tableau (affichage)
    show_crime();
    sendMail();

    //NOTIFICATION
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setVisible(true);
    trayIcon->setIcon(this->style()->standardIcon(QStyle::SP_DesktopIcon));
    trayIcon->setToolTip("Ajouter" "\n"
                    "Ajouter avec sucées");
    trayIcon->showMessage("Ajouter","Ajouter avec sucées",QSystemTrayIcon::Information,1500);
    trayIcon->show();


}

//get id from selected row
void gestion_selmen::on_table_crime_clicked(const QModelIndex &index)
{
    selected_crime=ui->table_crime->model()->data(index).toString();
}

//suppression

void gestion_selmen::on_btnsuppcrime_clicked()
{
    crime mc;
  mc.supprimer(selected_crime);

 //refresh du tableau (affichage)
   show_crime();

   //NOTIFICATION
   trayIcon = new QSystemTrayIcon(this);
   trayIcon->setVisible(true);
   trayIcon->setIcon(this->style()->standardIcon(QStyle::SP_DesktopIcon));
   trayIcon->setToolTip("Supprimer" "\n"
                   "Supprimer avec sucées");
   trayIcon->showMessage("Supprimer","Supprimer avec sucées",QSystemTrayIcon::Warning,1500);
   trayIcon->show();


}

//modification
void gestion_selmen::on_id_crime_modif_currentIndexChanged(const QString &arg1)
{
    QSqlQuery query;

    query =tmpcrim.request(ui->id_crime_modif->currentText());
    if(query.exec())
    {
        while(query.next())
        {
            ui->date_modif->setDate(QDate::fromString(query.value(1).toString(),"dd/MM/yyyy"));
            ui->type_modif->setCurrentText(query.value(2).toString());
        }
    }


}

void gestion_selmen::on_btn_modif_crim_clicked()
{
    //mofication
    crime mc(ui->id_crime_modif->currentText(),ui->type_modif->currentText(),ui->date_modif->text());
    mc.modifier(ui->id_crime_modif->currentText());

    //refresh du tableau (affichage)
      show_crime();
      //NOTIFICATION
      trayIcon = new QSystemTrayIcon(this);
      trayIcon->setVisible(true);
      trayIcon->setIcon(this->style()->standardIcon(QStyle::SP_DesktopIcon));
      trayIcon->setToolTip("Modifier" "\n"
                      "Modifier avec sucées");
      trayIcon->showMessage("Modifier","Modifier avec sucées",QSystemTrayIcon::Warning,1500);
      trayIcon->show();


}

//stat
void gestion_selmen::choix_pie()
{

    vector<QString> liste_type;
    vector<qreal> count;
    QSqlQuery q1,q2;
    qreal tot=0,c;
    q1.prepare("SELECT DISTINCT TYPE FROM CRIME");
    q1.exec();
    while (q1.next()){
        liste_type.push_back(q1.value(0).toString());
    }

    q1.prepare("SELECT * FROM CRIME");
    q1.exec();
    while (q1.next()){
        tot++;
    }

    for (auto i = liste_type.begin(); i != liste_type.end(); ++i) {
         q2.prepare("SELECT * FROM CRIME where TYPE = :m");
         q2.bindValue(":m", *i);
         q2.exec();
         c=0;
         while (q2.next()){c++;}
         count.push_back(c/tot);

    }


// Define slices and percentage of whole they take up
QtCharts::QPieSeries *series = new QtCharts::QPieSeries();
for(unsigned int i = 0; i < liste_type.size(); i++)
series->append(liste_type[i] ,count[i]);




// Create the chart widget
QtCharts::QChart *chart = new QtCharts::QChart();

// Add data to chart with title and show legend
chart->addSeries(series);
chart->legend()->show();


// Used to display the chart
chartView = new QtCharts::QChartView(chart,ui->label_stat);
chartView->setRenderHint(QPainter::Antialiasing);
chartView->setMinimumSize(400,400);

chartView->show();
}


//MAILING
void gestion_selmen::sendMail()
{
    Smtp* smtp = new Smtp("selmen.mabrouk@esprit.tn","191JMT1081","smtp.gmail.com", 465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail("selmen.mabrouk@esprit.tn", "selmen.mabrouk@esprit.tn" ," CRIME","CRIME ajouter");
}

void gestion_selmen::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}


