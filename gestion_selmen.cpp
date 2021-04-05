#include "gestion_selmen.h"
#include "ui_gestion_selmen.h"

gestion_selmen::gestion_selmen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gestion_selmen)
{
    ui->setupUi(this);
    //affichage contenu base
    show_tables();
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
void gestion_selmen::on_actionadd_criminel_triggered()
{
    //creation instance
        add_criminel ac(this);

        //ouvrir dialog
        int res=ac.exec();
        if (res == QDialog::Rejected )
            return;

      //recuperation des donnees
        QString s1=ac.id();
        QString s2=ac.nom();
        QString s3=ac.prenom();
        QString s4=ac.crime();

        //ajout
        criminel mc(s1,s2,s3,s4);
       mc.ajouter();
        mc.count_criminels();
        //refresh du tableau (affichage)
          show_tables();
}

//get id from selected row
void gestion_selmen::on_table_criminel_clicked(const QModelIndex &index)
{
    selected_criminel=ui->table_criminel->model()->data(index).toString();
}

//suppression
void gestion_selmen::on_actiondelete_criminel_triggered()
{
    criminel mc;
  mc.supprimer(selected_criminel);

  mc.count_criminels();
  //refresh du tableau (affichage)
    show_tables();
}


//modification

void gestion_selmen::on_table_criminel_doubleClicked(const QModelIndex &index)
{
    add_criminel ac(this);

  ac.fill_form(selected_criminel);
  int res=ac.exec();
  if (res == QDialog::Rejected )
    return;


  //recuperation des donnees
    QString s2=ac.nom();
    QString s3=ac.prenom();
     QString s4=ac.crime();

    //mofication
    criminel mc(selected_criminel,s2,s3,s4);
    mc.modifier(selected_criminel);

    mc.count_criminels();
    //refresh du tableau (affichage)
      show_tables();



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
void gestion_selmen::on_actionadd_crime_triggered()
{
    //creation instance
        add_crime ac(this);

        //ouvrir dialog
        int res=ac.exec();
        if (res == QDialog::Rejected )
            return;

      //recuperation des donnees
        QString s1=ac.id();
        QString s2=ac.type();
        QString s3=ac.date();

        //ajout
        crime mc(s1,s2,s3);
        mc.ajouter();

        //refresh du tableau (affichage)
          show_crime();

}

//get id from selected row
void gestion_selmen::on_table_crime_clicked(const QModelIndex &index)
{
    selected_crime=ui->table_crime->model()->data(index).toString();
}

//suppression
void gestion_selmen::on_actiondelete_crime_triggered()
{
    crime mc;
  mc.supprimer(selected_crime);

 //refresh du tableau (affichage)
   show_crime();

}


//modification
void gestion_selmen::on_table_crime_doubleClicked(const QModelIndex &index)
{
    add_crime ac(this);

  ac.fill_form(selected_crime);
  int res=ac.exec();
  if (res == QDialog::Rejected )
    return;


  //recuperation des donnees
    QString s2=ac.type();
    QString s3=ac.date();

    //mofication
    crime mc(selected_crime,s2,s3);
    mc.modifier(selected_crime);

    //refresh du tableau (affichage)
      show_crime();


}

//stat
void gestion_selmen::on_stat_crime_clicked()
{
    s = new stat_crime();
  s->choix_pie();
  s->show();
}
