#include "gestion_dhia.h"
#include "ui_gestion_dhia.h"
#include <QDebug>
#include "smtp.h"
gestion_dhia::gestion_dhia(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gestion_dhia)
{
    ui->setupUi(this);
    //affichage contenu base
    show_tables();
    QStringList listrole;
    listrole << "type1" << "type2" << "type3" << "type4";
    ui->type->addItems(listrole);
    ui->type_modif->addItems(listrole);

    ui->zone->setModel(tmpzone.remplircombozone());
    ui->zone_m->setModel(tmpzone.remplircombozone());

    ui->id_inf_modif->setModel(inf.remplircombinf());
    ui->id_modif_zone->setModel(tmp_zone.remplircombozone());

}

gestion_dhia::~gestion_dhia()
{
    delete ui;
}

void gestion_dhia::show_tables()
{
    show_zone();
    show_infraction();
}

/*********************************** zone ****************************/

//************************ crud

//ajout


void gestion_dhia::on_btnajoutzone_clicked()
{
    zone mc(ui->id->text(),ui->ville->text(),ui->rue->text());
    if(mc.ajouter())
    {

        //NOTIFICATION
        trayIcon = new QSystemTrayIcon(this);
        trayIcon->setVisible(true);
        trayIcon->setIcon(this->style()->standardIcon(QStyle::SP_DesktopIcon));
        trayIcon->setToolTip("Ajouter" "\n"
                        "Ajouter avec sucées");
        trayIcon->showMessage("Ajouter","Ajouter avec sucées",QSystemTrayIcon::Information,1500);
        trayIcon->show();
        sendMail();
        }
          else
          {
              QMessageBox::critical(nullptr, QObject::tr("Ajouter une zone"),
                          QObject::tr("Erreur !.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
          }
    show_zone();
}


//selection
void gestion_dhia::on_table_zone_clicked(const QModelIndex &index)
{
    selected_zone=ui->table_zone->model()->data(index).toString();
}

//modification

void gestion_dhia::on_id_modif_zone_currentIndexChanged(const QString &arg1)
{
    QSqlQuery query;

    query =tmpzone.request(ui->id_modif_zone->currentText());
    if(query.exec())
    {
        while(query.next())
        {
            ui->ville_modif->setText(query.value(1).toString());
            ui->rue_modif->setText(query.value(2).toString());
            }
    }

}

void gestion_dhia::on_btnmodifzone_clicked()
{
    //mofication
    zone zo(ui->id_modif_zone->currentText(),ui->ville_modif->text(),ui->rue_modif->text());
    zo.modifier(ui->id_modif_zone->currentText());

    //refresh du tableau (affichage)
    show_zone();
    //NOTIFICATION
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setVisible(true);
    trayIcon->setIcon(this->style()->standardIcon(QStyle::SP_DesktopIcon));
    trayIcon->setToolTip("Modifier" "\n"
                    "Modifier avec sucées");
    trayIcon->showMessage("Modifier","Modifier avec sucées",QSystemTrayIcon::Warning,1500);
    trayIcon->show();

}

//suppression

void gestion_dhia::on_deletezone_clicked()
{
  zone mc;
  mc.supprimer(selected_zone);
 //refresh du tableau (affichage)
  show_zone();
  //NOTIFICATION
  trayIcon = new QSystemTrayIcon(this);
  trayIcon->setVisible(true);
  trayIcon->setIcon(this->style()->standardIcon(QStyle::SP_DesktopIcon));
  trayIcon->setToolTip("Supprimer" "\n"
                  "Supprimer avec sucées");
  trayIcon->showMessage("Supprimer","Supprimer avec sucées",QSystemTrayIcon::Warning,1500);
  trayIcon->show();

}

//affichage
void gestion_dhia::show_zone()
{
    //creation model (masque du tableau) : permet recherche et tri
        proxy_zone = new QSortFilterProxyModel();

     //definir la source (tableau original)
        proxy_zone->setSourceModel(tmp_zone.afficher());

     //pour la recherche
        proxy_zone->setFilterCaseSensitivity(Qt::CaseInsensitive); // S=s (pas de difference entre majiscule et miniscule)

        //remplissage tableau avec le masque
        ui->table_zone->setModel(proxy_zone);
}

//************************ metiers


//recherche dynamique
void gestion_dhia::on_zone_sel_col_currentIndexChanged(const QString &arg1)
{
    sel_col_zone=ui->zone_sel_col->currentIndex()-1;
    proxy_zone->setFilterKeyColumn(sel_col_zone); // chercher dans tout le tableau (-1) ou donner le numero de la colone
}
void gestion_dhia::on_rech_zone_textChanged(const QString &arg1)
{
    proxy_zone->setFilterFixedString(arg1);
}

//imprimer
void gestion_dhia::on_pushButton_2_clicked()
{
        QString strStream;
        QTextStream out(&strStream);

        const int rowCount = ui->table_zone->model()->rowCount();
        const int columnCount =ui->table_zone->model()->columnCount();

        out <<  "<html>\n"
            "<head>\n"
            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
            <<  QString("<title>%1</title>\n").arg("strTitle")
            <<  "</head>\n"
            "<body bgcolor=#ffffff link=#5000A0>\n"
            "<table border=1 cellspacing=0 cellpadding=2>\n";

        // headers
        out << "<thead><tr bgcolor=#f0f0f0>";
        for (int column = 0; column < columnCount; column++)
            if (ui->table_zone->isColumnHidden(column))
                out << QString("<th>%1</th>").arg(ui->table_zone->model()->headerData(column, Qt::Horizontal).toString());
        out << "</tr></thead>\n";

        // data table
        for (int row = 0; row < rowCount; row++) {
            out << "<tr>";
            for (int column = 0; column < columnCount; column++) {
                if (!ui->table_zone->isColumnHidden(column)) {
                    QString data = ui->table_zone->model()->data(ui->table_zone->model()->index(row, column)).toString().simplified();
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

        delete document;
}


/*********************************** infraction ****************************/

//************************ crud

//ajout

void gestion_dhia::on_btnajout_clicked()
{
    //ajout
    infraction mc(ui->id_inf->text(),ui->date->text(),ui->heure->text(),ui->type->currentText(),ui->zone->currentText());
    mc.ajouter();
    mc.count_infractions();

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


//selection
void gestion_dhia::on_table_infraction_clicked(const QModelIndex &index)
{
    selected_infraction=ui->table_infraction->model()->data(index).toString();
}

//modification

void gestion_dhia::on_id_inf_modif_currentIndexChanged(const QString &arg1)
{
        QSqlQuery query;

        query =inf.request(ui->id_inf_modif->currentText());
        if(query.exec())
        {
            while(query.next())
            {
                ui->date_modif->setDate(QDate::fromString(query.value(1).toString(),"dd/MM/yyyy"));
                ui->heure_modif->setTime(query.value(2).toTime());
                ui->type_modif->setCurrentText(query.value(3).toString());
            }
        }

}


void gestion_dhia::on_btnmodif_clicked()
{
    //mofication
    infraction mc(ui->id_inf_modif->currentText(),ui->date_modif->text(),ui->heure_modif->text(),ui->type_modif->currentText(),ui->zone_m->currentText());
    mc.modifier(ui->id_inf_modif->currentText());
    mc.count_infractions();

    //refresh du tableau (affichage)
      show_tables();
      //NOTIFICATION
      trayIcon = new QSystemTrayIcon(this);
      trayIcon->setVisible(true);
      trayIcon->setIcon(this->style()->standardIcon(QStyle::SP_DesktopIcon));
      trayIcon->setToolTip("Modifier" "\n"
                      "Modifier avec sucées");
      trayIcon->showMessage("Modifier","Modifier avec sucées",QSystemTrayIcon::Warning,1500);
      trayIcon->show();

}


//suppression
void gestion_dhia::on_deleteinfraction_clicked()
{
  infraction mc;
  mc.supprimer(selected_infraction);
  mc.count_infractions();

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

//affichage
void gestion_dhia::show_infraction()
{
    //creation model (masque du tableau) : permet recherche et tri
        proxy_infraction = new QSortFilterProxyModel();

     //definir la source (tableau original)
        proxy_infraction->setSourceModel(tmp_infraction.afficher());

     //pour la recherche
        proxy_infraction->setFilterCaseSensitivity(Qt::CaseInsensitive); // S=s (pas de difference entre majiscule et miniscule)

        //remplissage tableau avec le masque
        ui->table_infraction->setModel(proxy_infraction);
}

//************************ metiers

//recherche dynamique
void gestion_dhia::on_infraction_sel_col_currentIndexChanged(const QString &arg1)
{
    sel_col_infraction=ui->infraction_sel_col->currentIndex()-1;
    proxy_infraction->setFilterKeyColumn(sel_col_infraction); // chercher dans tout le tableau (-1) ou donner le numero de la colone

}
void gestion_dhia::on_rech_infraction_textChanged(const QString &arg1)
{
    proxy_infraction->setFilterFixedString(arg1);
}

//MAILING
void gestion_dhia::sendMail()
{
    Smtp* smtp = new Smtp("bouslimidhia60@gmail.com","dhia191JMT","smtp.gmail.com", 465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail("bouslimidhia60@gmail.com", "bouslimidhia60@gmail.com" ," ZONE","ZONE ajouter");
}

void gestion_dhia::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}


