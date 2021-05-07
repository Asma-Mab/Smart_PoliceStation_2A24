#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "entretien.h"
#include "secretaire.h"
#include "rendez_vous.h"
#include "plaintes.h"
#include "personne.h"
#include "bus.h"
#include <QHeaderView>
#include "mailing/mailing/SmtpMime"
#include "QtPrintSupport/QPrinter"
#include "QImage"
#include <QPainter>
#include "iostream"
#include <QtCharts>

QT_CHARTS_USE_NAMESPACE

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    mysystem = new QSystemTrayIcon(this);
    mysystem->setIcon(QIcon(":/icon.png"));
    mysystem->setVisible(true);
    //on_refresh_clicked() ;
    trier1=new Personne();
    ui->tableView_2->setModel(tmpp.afficher());
    ui->listebus->setModel(trier1->afficher());
  //on_supprimer_bus_clicked();
//void QHeaderView::sectionClicked ( int logicalIndex ) ;
    QPainter painter(this);
       painter.setPen(Qt::blue);
       painter.setFont(QFont("Arial", 30));
    QHeaderView *header=ui->listebus->horizontalHeader() ;
    QObject::connect(header,SIGNAL(sectionClicked ( int )),this,SLOT(modifierr(int)) ) ;
}

MainWindow::~MainWindow()
{
    delete ui;
}
/*





void MainWindow::on_pushButton_15_clicked()
{
  ui->stackedWidget->setCurrentIndex(0) ;
  on_refresh_clicked() ;
}



void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(0) ;
    on_refresh_clicked() ;
}



void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0) ;
    on_refresh_clicked() ;
}



void MainWindow::on_pushButton_3_clicked()
{
   ui->stackedWidget_2->setCurrentIndex(1);
}

void MainWindow::on_pushButton_4_clicked()
{
     ui->stackedWidget_2->setCurrentIndex(3);
}

void MainWindow::on_pushButton_5_clicked()
{
     ui->stackedWidget_2->setCurrentIndex(2);
}

void MainWindow::on_pushButton_48_clicked()
{
  ui->stackedWidget_2->setCurrentIndex(0);
  //ui->tableView_2->setModel(tmps.afficher());

  on_refresh_clicked() ;
}

void MainWindow::on_pushButton_43_clicked()
{

    int id = ui->lineEdit_idAE->text().toInt();
    QString rapport= ui->lineEdit_rapportAE->text();
    QString date= ui->dateEdit_dateAE->text();
    QString etat= ui->comboBox_etatAE->currentText();
    QString duree= ui->lineEdit_dureeAE->text();
    QString prix= ui->lineEdit_prixAE->text();
      ui->lineEdit_idAE->clear() ;
      ui->dateEdit_dateAE->clear() ;
      ui->lineEdit_dureeAE->clear() ;
      ui->lineEdit_prixAE->clear() ;
      ui->lineEdit_rapportAE->clear() ;
 entretien e(id,date,rapport,duree,prix,etat);
  bool test=e.ajouter();
  if(test)
{
QMessageBox::information(nullptr, QObject::tr("Ajouter un entretien"),
                  QObject::tr("entretien ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
 ui->stackedWidget_2->setCurrentIndex(0);
 //ui->tableView_2->setModel(tmps.afficher());
 on_refresh_clicked() ;

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un entretien"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_pushButton_61_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
    //ui->tableView_2->setModel(tmps.afficher());
    on_refresh_clicked() ;
}



void MainWindow::on_pushButton_59_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
   // ui->tableView_2->setModel(tmps.afficher());
    on_refresh_clicked() ;
}










void MainWindow:: modifierr(int index)
{
    //bus *s =new bus();
    QSqlQueryModel * model = trier->sort(index);
     ui->listebus->setModel(model);
    //delete s;
}


 void MainWindow::on_listebus_clicked()
{
     int id = getIDFromTableView(ui->listebus);
     entretien * s = new entretien();
     QSqlQueryModel * model = s->afficher(id) ;
     ui->tableView_2->setModel(model);
     ui->tableView_2->setColumnHidden(0,true) ;
     delete s;
}

void MainWindow::on_pushButton_16_clicked()
{
    stat = new statistique_etat(this) ;
    //![1]
        QBarSet *set0 = new QBarSet("Libre");
        QBarSet *set1 = new QBarSet("Occupée");

        int nb0=0;
        QSqlQuery query0("select * from PLACE where ETAT=1");
        while(query0.next())
        {
            nb0++;
        }
        int nb1=0;
        QSqlQuery query1("select * from PLACE where ETAT=0 ");
        while(query1.next())
        {
            nb1++;
        }
       // int nb2=0;


        *set0 << nb0 ;
        *set1 << nb1 ;

    //![1]

    //![2]
        QBarSeries *series = new QBarSeries();
        series->append(set0);
        series->append(set1);

    //![2]

    //![3]
        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Etat");
        chart->setAnimationOptions(QChart::SeriesAnimations);
    //![3]

    //![4]
        QStringList categories;
        categories << "Place disponible";

        QBarCategoryAxis *axisX = new QBarCategoryAxis();
        axisX->append(categories);
        chart->addAxis(axisX, Qt::AlignBottom);
        series->attachAxis(axisX);
   int nb=0;
   QSqlQuery query("select * from PLACE ");
   while(query.next())
   {
       nb++;
   }

        QValueAxis *axisY = new QValueAxis();
        axisY->setRange(0,nb);
        chart->addAxis(axisY, Qt::AlignLeft);
        series->attachAxis(axisY);
    //![4]

    //![5]
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);
    //![5]

    //![6]

        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
        stat->setCentralWidget(chartView);
        stat->show();
}
*/
void MainWindow::on_ajouter_rdv_clicked()
{
    ui->stackedWidget->setCurrentIndex(1) ;
    p = new Personne();
   QSqlQueryModel *model = p->afficher();
   ui->tableView_6->setModel(model);
   delete p ;
}

void MainWindow::on_supprimer_rdv_clicked()
{
    ui->stackedWidget->setCurrentIndex(3) ;
    p= new Personne();
   QSqlQueryModel *model = p->afficher();
   ui->tableView_8->setModel(model);
   delete p ;
}

void MainWindow::on_modifier_rdv_clicked()
{
    ui->stackedWidget->setCurrentIndex(2) ;
    p = new Personne();
   QSqlQueryModel *model = p->afficher();
   ui->tableView_7->setModel(model);
   delete p ;
}

void MainWindow::on_search_button_clicked()
{
    QString key = ui->espace_chercher->toPlainText();
    int index = ui->comboBox->currentIndex();


    Personne * s = new Personne();
    QSqlQueryModel * q = s->search(index, key);
    if(q != nullptr){
        ui->listebus->setModel(q);
    }else{
        QMessageBox::critical(nullptr, QObject::tr("Warning"),
          QObject::tr("Rendez_vous non trouvé."), QMessageBox::Cancel);
    }
}

void MainWindow::on_refresh_clicked()
{
    p = new Personne();
   QSqlQueryModel *model = p->afficher();
   ui->listebus->setModel(model);
   delete p ;
}

void MainWindow::on_espace_chercher_textChanged()
{
    Personne b;
  QString index=ui->espace_chercher->toPlainText() ;
   b.recherche_id_place(ui->listebus,index) ;
}


void MainWindow::on_annulerA_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    on_refresh_clicked() ;
}

void MainWindow::on_annuler_M_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    on_refresh_clicked() ;
}

void MainWindow::on_annuler_S_clicked()
{
 ui->stackedWidget->setCurrentIndex(0);
 on_refresh_clicked() ;
}

void MainWindow::on_confirmer_A_R_clicked()
{

    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);

/*



           smtp.setUser("ForminiTN@gmail.com");

           smtp.setPassword("538886282A1");







           MimeMessage message;



           message.setSender(new EmailAddress("ForminiTN@gmail.com", "formini"));

           message.addRecipient(new EmailAddress("wassim.benfraj@esprit.tn", "morssi"));

           message.setSubject("SmtpClient for Qt - Demo");







           MimeText text;



           text.setText("Hi,\n une voiture a ete supprimer\n");







           message.addPart(&text);





           smtp.connectToHost();

           smtp.login();

           if(smtp.sendMail(message))
           {
               QMessageBox::information(nullptr, QObject::tr("mailing"),
                               QObject::tr("mailing.\n"
                                           "Click Ok to exit."), QMessageBox::Accepted);
           }

           smtp.quit();

*/
    int id = ui->id_line->text().toInt();
    QString nom= ui->name_line->text();
    QString prenom= ui->prenom_line->text();
    QString adresse= ui->adress_line->text();
     QString date= ui->dateEdit_dateA->text();
     QString sexe= ui->comboBox_2->currentText();


     QPrinter printer;
     printer.setOutputFormat(QPrinter::PdfFormat);
     printer.setOutputFileName("D:/Downloads/wess_projet1 (1)/wess_projet1/file.pdf");
     QPainter painter;
     painter.begin(&printer);
     QImage image("D:/Downloads/wess_projet1 (1)/wess_projet1/abcd.jpg");
     painter.drawImage(0,0,image);
     QFont font;

     font.setPixelSize(50);
     painter.setFont(font);
     painter.setPen(Qt::red);
     painter.drawText(50,150,"Fiche Des Personne Recherchee: ");
     font.setPixelSize(35);
     painter.setFont(font);
     painter.setPen(Qt::red);
     painter.drawText(400,300,"Nom: ");
     painter.drawText(400,500,"Prenom:");
     painter.drawText(400,650,"Adresse:");
     painter.drawText(400,800,"Date:");
     painter.drawText(400,1000,"Sexe:");

    // int cin=ui->cin->text().toInt();
    /* int id_p =ui->lineEdit_id->text().toInt();
     QString id_pdf=QString::number(id_p);
     int age_p=ui->lineEdit_age->text().toInt();
     QString age_pdf=QString::number(age_p);
     int tel_p=ui->lineEdit_tel->text().toInt();
     QString tel_pdf=QString::number(tel_p);

     QString nom_pdf=ui->lineEdit_nom->text();
     QString prenom_pdf=ui->lineEdit_prenom->text();
     QString adresse_pdf=ui->lineEdit_adresse->text();
     QString mail_pdf=ui->lineEdit_mail->text();
     QString date_pdf=ui->dateEdit->text();*/


     font.setPixelSize(20);
     painter.setFont(font);
     painter.setPen(Qt::black);
     painter.drawText(400,350,nom);
     painter.drawText(400,550,prenom);
     painter.drawText(400,700,adresse);
     painter.drawText(400,850,date);
     painter.drawText(400,1050,sexe);


     painter.end();





    //int patient= ui->lineEdit_idA_2->text().toInt();
    //QString description= ui->plainTextEdit->toPlainText();
   mysystem->show();
   mysystem->showMessage(tr("notification"),tr("ajout avec succes"));
  Personne b(id,nom,prenom,adresse,date,sexe);
  bool test=b.ajouter();
  if(test)
  {

  QMessageBox::information(nullptr, QObject::tr("Ajouter une Personne"),
                  QObject::tr("Personne ajouté.\n"
                              "Click Ok to exit."), QMessageBox::Accepted);
  ui->stackedWidget->setCurrentIndex(0) ;
  on_refresh_clicked() ;

  }
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un Personne"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);







}

void MainWindow::on_confirmerM_R_clicked()
{
    int id = ui->id_line_2->text().toInt();

    QString nom= ui->name_line_2->text();
    QString prenom= ui->prenom_line_2->text();
    QString adresse= ui->lineEdit_idA_7->text();

     QString date= ui->dateEdit_dateA_2->text();
     QString sexe= ui->comboBox_3->currentText();

   mysystem->show();
   mysystem->showMessage(tr("notification"),tr("modifcation avec succes"));
  Personne b(id,nom,prenom,adresse,date,sexe);
  bool test=b.update();
  if(test)
  {

  QMessageBox::information(nullptr, QObject::tr("Modifer une Personne"),
                  QObject::tr("Personne modifié.\n"
                              "Click Ok to exit."), QMessageBox::Accepted);
   ui->stackedWidget->setCurrentIndex(0) ;
   on_refresh_clicked() ;
  }
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier une Personne"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_confimerS_R_clicked()
{
    int id = ui->lineEdit_S->text().toInt();
    bool test=tmppers.supprimer(id);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("Supprimer Rendez-vous"),
                    QObject::tr("Entité supprimée.\n"
                                "Click Ok to exit."), QMessageBox::Accepted);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un Rendez-vous"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    ui->stackedWidget->setCurrentIndex(0) ;
    on_refresh_clicked() ;
}

void MainWindow::on_ajouter_S_clicked()
{
  ui->stackedWidget_2->setCurrentIndex(1);
}

void MainWindow::on_modifier_S_clicked()
{
  ui->stackedWidget_2->setCurrentIndex(3);
}

void MainWindow::on_supprimer_S_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(2);
}

void MainWindow::on_annulerAS_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
   ui->tableView_2->setModel(tmpp.afficher());
    on_refresh_clicked() ;
}

void MainWindow::on_annuler_SS_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
    ui->tableView_2->setModel(tmpp.afficher());
    on_refresh_clicked() ;
}

void MainWindow::on_annnulerMS_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
    ui->tableView_2->setModel(tmpp.afficher());
    on_refresh_clicked() ;
}

void MainWindow::on_confirmerSS_clicked()
{
    int id=ui->lineEdit_idSE->text().toInt();

    bool test=tmpp.supprimer(id);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("Supprimer une Plainte"),
                    QObject::tr("Plainte supprimé.\n"
                                "Click Ok to exit."), QMessageBox::Accepted);
        ui->stackedWidget_2->setCurrentIndex(0);
       ui->tableView_2->setModel(tmpp.afficher());
        on_refresh_clicked() ;

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une Plainte"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    ui->stackedWidget_2->setCurrentIndex(0);
   ui->tableView_2->setModel(tmpp.afficher());
    on_refresh_clicked() ;
}





void MainWindow::on_confirmerMS_clicked()
{


    int id = ui->lineEdit_idMS->text().toInt();
    QString raison= ui->lineEdit_nomMS->text();
   // QString prenom= ui->lineEdit_prenomMS->text();
    QString date= ui->dateEdit_dateMS->text();
   // int gsm= ui->lineEdit_gsmMS_2->text().toInt();
    //QString adresse= ui->lineEdit_adresseMS->text();
    QString type= ui->comboBox_serviceMS->currentText();

 Plaintes e(id,raison,date,type);
  bool test=e.update();
  if(test)
{
QMessageBox::information(nullptr, QObject::tr("Modifier une Plainte"),
                  QObject::tr("Plainte modifié.\n"
                              "Click Ok to exit."), QMessageBox::Accepted);
ui->stackedWidget_2->setCurrentIndex(0);
ui->tableView_2->setModel(tmpp.afficher());
on_refresh_clicked() ;

}
  else
      QMessageBox::critical(nullptr, QObject::tr("echec "),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_confirmerAS_clicked()
{
   /* int id = ui->lineEdit_idAS->text().toInt();
    QString nom= ui->lineEdit_nomAS->text();
    QString prenom= ui->lineEdit_prenomAS->text();
    QString date= ui->dateEdit_dateAS->text();
    int gsm= ui->lineEdit_gsmAS->text().toInt();
    QString adresse= ui->lineEdit_adresseAS->text();
    QString service= ui->comboBox_serviceAS->currentText();

      ui->lineEdit_prenomAS->clear() ;

      ui->lineEdit_gsmAS->clear() ;
      ui->lineEdit_adresseAS->clear() ;*/
      //ui->comboBox_serviceAS->clear() ;

    int id = ui->lineEdit_idAS->text().toInt();
    QString raison= ui->lineEdit_nomAS->text();
    QString type= ui->comboBox_serviceAS->currentText();
    QString date= ui->dateEdit_dateAS->text();
 Plaintes e(id,raison,date,type);
  bool test=e.ajouter();
  ui->dateEdit_dateAS->clear() ;
 ui->lineEdit_idAS->clear() ;
 ui->lineEdit_nomAS->clear() ;
  if(test)
{
QMessageBox::information(nullptr, QObject::tr("Ajouter une Plainte"),
                  QObject::tr("Plainte ajouté.\n"
                              "Click Ok to exit."), QMessageBox::Accepted);
 ui->stackedWidget_2->setCurrentIndex(0);
 ui->tableView_2->setModel(tmpp.afficher());
 on_refresh_clicked() ;

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une Plainte"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow:: modifierr(int index)
{
    ui->department->setText(QString::number(index));

//ui->department->setText((QString)index);
    //bus *s =new bus();
    QSqlQueryModel * model = trier1->sort(index);
    ui->listebus->setModel(model);
    //delete s;
}

void MainWindow::on_pushButton_16_clicked()
{
    stat = new statistique_etat(this) ;
    //![1]
        QBarSet *set0 = new QBarSet("Homme");
        QBarSet *set1 = new QBarSet("Femme");

        int nb0=0;
        QSqlQuery query0("select * from PERSONNE  where SEXE='Homme'");
        while(query0.next())
        {
            nb0++;
        }
        int nb1=0;
        QSqlQuery query1("select * from  PERSONNE  where SEXE='Femme'");
        while(query1.next())
        {
            nb1++;
        }
       // int nb2=0;


        *set0 << nb0 ;
        *set1 << nb1 ;

    //![1]

    //![2]
        QBarSeries *series = new QBarSeries();
        series->append(set0);
        series->append(set1);

    //![2]

    //![3]
        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Etat");
        chart->setAnimationOptions(QChart::SeriesAnimations);
    //![3]

    //![4]
        QStringList categories;
        categories << "Statistique des PERSONNE";

        QBarCategoryAxis *axisX = new QBarCategoryAxis();
        axisX->append(categories);
        chart->addAxis(axisX, Qt::AlignBottom);
        series->attachAxis(axisX);
   int nb=0;
   QSqlQuery query("select * from PERSONNE ");
   while(query.next())
   {
       nb++;
   }

        QValueAxis *axisY = new QValueAxis();
        axisY->setRange(0,nb);
        chart->addAxis(axisY, Qt::AlignLeft);
        series->attachAxis(axisY);
    //![4]

    //![5]
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);
    //![5]

    //![6]

        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
        stat->setCentralWidget(chartView);
        stat->show();
}

void MainWindow::on_radioButton_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * from PERSONNE ORDER BY NOM ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID "));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("SEXE"));

        ui->listebus->setModel(model) ;

}

void MainWindow::on_radioButton_2_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * from PERSONNE ORDER BY ID ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID "));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("SEXE"));

        ui->listebus->setModel(model) ;
}
