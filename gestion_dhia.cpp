#include "gestion_dhia.h"
#include "ui_gestion_dhia.h"

gestion_dhia::gestion_dhia(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gestion_dhia)
{
    ui->setupUi(this);
    //affichage contenu base
    show_tables();
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
void gestion_dhia::on_actionadd_zone_triggered()
{
    //creation instance
        add_zone ac(this);

        //ouvrir dialog
        int res=ac.exec();
        if (res == QDialog::Rejected )
            return;

      //recuperation des donnees
        QString s1=ac.id();
        QString s2=ac.ville();
        QString s3=ac.rue();


        //ajout
        zone mc(s1,s2,s3);
        mc.ajouter();

        //refresh du tableau (affichage)
          show_zone();
}

//selection
void gestion_dhia::on_table_zone_clicked(const QModelIndex &index)
{
    selected_zone=ui->table_zone->model()->data(index).toString();
}

//modification
void gestion_dhia::on_table_zone_doubleClicked(const QModelIndex &index)
{
    add_zone ac(this);

  ac.fill_form(selected_zone);
  int res=ac.exec();
  if (res == QDialog::Rejected )
    return;


  //recuperation des donnees
  QString s2=ac.ville();
  QString s3=ac.rue();

    //mofication
    zone mc(selected_zone,s2,s3);
    mc.modifier(selected_zone);

    //refresh du tableau (affichage)
      show_zone();
}

//suppression
void gestion_dhia::on_actiondelete_zone_triggered()
{
    zone mc;
  mc.supprimer(selected_zone);

 //refresh du tableau (affichage)
   show_zone();
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


/*********************************** infraction ****************************/

//************************ crud

//ajout

void gestion_dhia::on_actionadd_infraction_triggered()
{
    //creation instance
        add_infraction ac(this);

        //ouvrir dialog
        int res=ac.exec();
        if (res == QDialog::Rejected )
            return;

      //recuperation des donnees
        QString s1=ac.id();
        QString s2=ac.date();
        QString s3=ac.heure();
        QString s4=ac.type();
        QString s5=ac.zone();


        //ajout
        infraction mc(s1,s2,s3,s4,s5);
        mc.ajouter();
        mc.count_infractions();

        //refresh du tableau (affichage)
          show_tables();
}

//selection
void gestion_dhia::on_table_infraction_clicked(const QModelIndex &index)
{
    selected_infraction=ui->table_infraction->model()->data(index).toString();
}

//modification
void gestion_dhia::on_table_infraction_doubleClicked(const QModelIndex &index)
{
    add_infraction ac(this);

  ac.fill_form(selected_infraction);
  int res=ac.exec();
  if (res == QDialog::Rejected )
    return;


  //recuperation des donnees
  QString s2=ac.date();
  QString s3=ac.heure();
  QString s4=ac.type();
  QString s5=ac.zone();


    //mofication
    infraction mc(selected_infraction,s2,s3,s4,s5);
    mc.modifier(selected_infraction);
    mc.count_infractions();

    //refresh du tableau (affichage)
      show_tables();

}

//suppression
void gestion_dhia::on_actiondelete_infraction_triggered()
{
    infraction mc;
  mc.supprimer(selected_infraction);
  mc.count_infractions();

 //refresh du tableau (affichage)
   show_tables();
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

//imprimer
void gestion_dhia::on_pushButton_2_clicked()
{
        QString strStream;
        QTextStream out(&strStream);

        const int rowCount = ui->table_infraction->model()->rowCount();
        const int columnCount =ui->table_infraction->model()->columnCount();

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
            if (ui->table_infraction->isColumnHidden(column))
                out << QString("<th>%1</th>").arg(ui->table_infraction->model()->headerData(column, Qt::Horizontal).toString());
        out << "</tr></thead>\n";

        // data table
        for (int row = 0; row < rowCount; row++) {
            out << "<tr>";
            for (int column = 0; column < columnCount; column++) {
                if (!ui->table_infraction->isColumnHidden(column)) {
                    QString data = ui->table_infraction->model()->data(ui->table_infraction->model()->index(row, column)).toString().simplified();
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
