#include "gestion_adam.h"
#include "ui_gestion_adam.h"

gestion_adam::gestion_adam(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gestion_adam)
{
    ui->setupUi(this);

    ui->id_modif->setModel(tmpgrade.remplircombograde());
    ui->id_modif_emp->setModel(tmpemploye.remplircomboemploye());
    ui->grade->setModel(tmpgrade.remplircombograde());
    ui->grade_modif->setModel(tmpgrade.remplircombograde());
    //affichage contenu base
    show_tables();
}

gestion_adam::~gestion_adam()
{
    delete ui;
}

void gestion_adam::show_tables()
{
show_employe();
show_grade();
}

/************************** employeloye ********************************/

//affichage
void gestion_adam::show_employe()
{
    //creation model (masque du tableau) : permet recherche et tri
        proxy_employe = new QSortFilterProxyModel();

     //definir la source (tableau original)
        proxy_employe->setSourceModel(tmp_employe.afficher());

     //pour la recherche
        proxy_employe->setFilterCaseSensitivity(Qt::CaseInsensitive); // S=s (pas de difference entre majiscule et miniscule)

        //remployelissage tableau avec le masque
        ui->table_employe->setModel(proxy_employe);
}

//recherche dynamique
void gestion_adam::on_employe_sel_col_currentIndexChanged(int index)
{
    sel_col_employe=ui->employe_sel_col->currentIndex()-1;
    proxy_employe->setFilterKeyColumn(sel_col_employe); // chercher dans tout le tableau (-1) ou donner le numero de la colone
}

void gestion_adam::on_rech_employe_textChanged(const QString &arg1)
{
    proxy_employe->setFilterFixedString(arg1);

}

//ajout

void gestion_adam::on_btn_ajouter_emp_clicked()
{
    //recuperation des donnees
      QString s1=ui->id_emp->text();
      QString s2=ui->nom->text();
      QString s3=ui->tel->text();
      QString s4=ui->mail->text();
      QString s5=ui->naissance->text();
      QString s6=ui->grade->currentText();
      double s7=ui->salaire->text().toDouble();

      //ajout
      employe mc(s1,s2,s3,s4,s5,s6,s7);
      mc.ajouter();

      //refresh du tableau (affichage)
        show_employe();

      //envoie mail d'affectation
      Smtp* smtp = new Smtp(mail,password, "smtp.gmail.com");
      connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

   QString msg=s2+", vous avez ete reconnue comme "+s6+" avec un identifiant "+s1;
          smtp->sendMail(mail,s4, "Affectation" ,msg);

}

//get id from selected row
void gestion_adam::on_table_employe_clicked(const QModelIndex &index)
{
    selected_employe=ui->table_employe->model()->data(index).toString();
}

//suppression
void gestion_adam::on_actiondelete_employe_triggered()
{
    employe mc;
  mc.supprimer(selected_employe);

 //refresh du tableau (affichage)
   show_employe();
}


//modification


void gestion_adam::on_id_modif_emp_currentIndexChanged(const QString &arg1)
{

    QSqlQuery query;

    query =tmpemploye.request(ui->id_modif_emp->currentText());
    if(query.exec())
    {
        while(query.next())
        {
            ui->nom_modif->setText(query.value(1).toString());
            ui->tel_modif->setText(query.value(2).toString());
            ui->mail_modif->setText(query.value(3).toString());
            ui->naissance_modif->setDate(QDate::fromString(query.value(4).toString(),"dd/MM/yyyy"));
            ui->grade_modif->setCurrentText(query.value(5).toString());
            ui->salaire_modif->setValue(query.value(6).toFloat());
            }
    }

}
void gestion_adam::on_btn_modif_emp_clicked()
{
    //recuperation des donnees
      QString s2=ui->nom_modif->text();
      QString s3=ui->tel_modif->text();
      QString s4=ui->mail_modif->text();
      QString s5=ui->naissance_modif->text();
      QString s6=ui->grade_modif->currentText();
      double s7=ui->salaire_modif->text().toDouble();

      //mofication
      employe mc(ui->id_modif_emp->currentText(),s2,s3,s4,s5,s6,s7);
      mc.modifier(ui->id_modif_emp->currentText());

      //refresh du tableau (affichage)
        show_employe();

}



//export excel
void gestion_adam::on_export_2_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                    tr("Excel Files (*.xls)"));
    if (fileName.isEmpty())
        return;

    ExportExcelObject obj(fileName, "mydata", ui->table_employe);

    //colums to export
    obj.addField(0, "ID", "char(20)");
    obj.addField(1, "Nom", "char(20)");
    obj.addField(2, "Mail", "char(20)");
    obj.addField(3, "Tel", "char(20)");
    obj.addField(4, "Naissance", "char(20)");
    obj.addField(5, "Grade", "char(20)");
    obj.addField(6, "Salaire", "char(20)");



    int retVal = obj.export2Excel();
    if( retVal > 0)
    {
        QMessageBox::information(this, tr("Done"),
                                 QString(tr("%1 records exported!")).arg(retVal)
                                 );
    }
}


/************************** grade ********************************/

//affichage
void gestion_adam::show_grade()
{
    //creation model (masque du tableau) : permet recherche et tri
        proxy_grade = new QSortFilterProxyModel();

     //definir la source (tableau original)
        proxy_grade->setSourceModel(tmp_grade.afficher());

     //pour la recherche
        proxy_grade->setFilterCaseSensitivity(Qt::CaseInsensitive); // S=s (pas de difference entre majiscule et miniscule)
       //remployelissage tableau avec le masque
        ui->table_grade->setModel(proxy_grade);
}

//recherche dynamique
void gestion_adam::on_grade_sel_col_currentIndexChanged(int index)
{
    sel_col_grade=ui->grade_sel_col->currentIndex()-1;
    proxy_grade->setFilterKeyColumn(sel_col_grade); // chercher dans tout le tableau (-1) ou donner le numero de la colone

}

void gestion_adam::on_rech_grade_textChanged(const QString &arg1)
{
    proxy_grade->setFilterFixedString(arg1);

}

//ajout


void gestion_adam::on_btn_ajouter_Grade_clicked()
{
    //ajout
    grade mc(ui->id->text(),ui->description->text());
    mc.ajouter();

    //refresh du tableau (affichage)
      show_grade();

}

//get id from selected row
void gestion_adam::on_table_grade_clicked(const QModelIndex &index)
{
    selected_grade=ui->table_grade->model()->data(index).toString();
}

//suppression

void gestion_adam::on_btn_supp_grade_clicked()
{
    grade mc;
  mc.supprimer(selected_grade);

 //refresh du tableau (affichage)
   show_grade();


}


//modification

void gestion_adam::on_id_modif_currentIndexChanged(const QString &arg1)
{
    QSqlQuery query;

    query =tmpgrade.request(ui->id_modif->currentText());
    if(query.exec())
    {
        while(query.next())
        {
            ui->description_modif->setText(query.value(1).toString());
            }
    }

}

void gestion_adam::on_btn_modifier_Grade_clicked()
{  //recuperation des donnees
    QString s2=ui->description_modif->text();

    //mofication
    grade mc(ui->id_modif->currentText(),s2);
    mc.modifier(ui->id_modif->currentText());

    //refresh du tableau (affichage)
      show_grade();


}
