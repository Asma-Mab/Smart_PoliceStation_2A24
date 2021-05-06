#include "gestioncitoyen.h"
#include "ui_gestioncitoyen.h"
#include "Citoyen.h"
#include "demande.h"
#include "smtp.h"
#include <QMessageBox>
#include <QComboBox>
#include <QTextStream>
#include <QPixmap>
#include <QDebug>
#include"QMessageBox"
#include<QPropertyAnimation>
#include<random>
#include"QPainter"
#include"QFont"
#include"QPen"
#include"QPdfWriter"
#include"QTextDocumentWriter"
#include"QDesktopServices"
#include"QtPrintSupport/QPrinter"
#include <QPropertyAnimation>
#include <QTableWidget>
//#include <src/SmtpMime>//
#include <QFile>
#include <QDate>
#include <QCalendarWidget>
#include <QSqlError>
#include <popup.h>

Gestioncitoyen::Gestioncitoyen(QWidget *parent):

    QMainWindow(parent),
       ui(new Ui::Gestioncitoyen)
   {
   ui->setupUi(this);
   ui->tabcitoyen->setModel(tmpcitoyen.afficher());
   ui->tabledemande->setModel(tmpdemande.afficher());
   ui->idclient->setModel(a.shownidCitoyen());
   QPixmap pic("C:/Users/infoMix/Desktop/imen/b.jpeg");
              ui->label_13->setPixmap(pic);
              ui->label_14->setPixmap(pic);
              popUp = new PopUp();
              popUp->setPopupText("Welcome to Hot Plus Plus");
              popUp->show();

}
Gestioncitoyen::~Gestioncitoyen()
{
    delete ui;
}


void Gestioncitoyen::initialiser()
{
                ui->lineEdit_idClient->clear();
             ui->lineEdit_nom->clear();
             ui->lineEdit_prenom->clear();
             ui->lineEdit_email->clear();
            ui->lineEdit_num->clear();
}
void Gestioncitoyen::init()
{
              ui->num->clear();
             ui->idclient->clear();
             ui->dateavis->clear();
             ui->etat_2->clear();

}

// ajouter client

void Gestioncitoyen::on_pushButton_ajoutcitoyen_clicked()
{

    QString idClient=ui->lineEdit_idClient->text();
    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_prenom->text();
    QString email= ui->lineEdit_email->text();
     QString numero= ui->lineEdit_num->text();
    Citoyen c(idClient,nom,prenom,email,numero);

     if(c.verif_id(idClient)==false){
            popUp = new PopUp();
            popUp->setPopupText("ID doit contenir 8 chiffres ! ");
            popUp->show();

         }else if(nom==""){
            popUp = new PopUp();
            popUp->setPopupText(" veuillez remplir le champ nom ! ");
            popUp->show();

         }else if(prenom==""){
            popUp = new PopUp();
            popUp->setPopupText("veuillez remplir le champ prenom ! ");
            popUp->show();

         }if(c.verif_email(email)==false){
            popUp = new PopUp();
            popUp->setPopupText("verifiez le champ email ");
            popUp->show();

        }else if(numero==""){
           popUp = new PopUp();
           popUp->setPopupText("veuillez remplir le champ num! ");
           popUp->show();
         }
         else{

         bool test= c.ajouter(c);
       if(test)
       {
          ui->tabclient->setModel(tmpclient.afficher());
        initialiser();
        QFile file("C:\\Users\\infoMix\\Desktop\\imen\\Historique1.txt");
                    if (!file.open(QIODevice::WriteOnly | QIODevice::Append |QIODevice::Text))
                        return;
                    QTextStream cout(&file);
                    QString message2="\n L'historique des clients à ajouter :"+idClient+" "+nom+" "+prenom+" "+email+" "+numero;
                    cout << message2;
        }

}
}
//supprimer client

void Gestioncitoyen::on_pb_supprimer_clicked()
{

    QString idClient= ui->lineEdit_idClient->text();
    bool test=tmpclient.supprimer(idClient);
           initialiser();
           if(test)
         {
         ui->tabclient->setModel(tmpclient.afficher());



         QMessageBox::information(nullptr, windowTitle(),QObject::tr("Suppression avec succés"));
         }
           else
           {
               QMessageBox::information(nullptr, windowTitle(),QObject::tr("Id n'existe pas"));
       }
    }


//modifier client


void Gestioncitoyen::on_pushButton_modifier_client_clicked()
{

      QSqlQuery query;
      QString idClient = ui->lineEdit_idClient->text();
        QString nom = ui->lineEdit_nom->text();
        QString prenom =ui->lineEdit_prenom->text();
        QString  email = ui->lineEdit_email->text();
         QString  num = ui->lineEdit_num->text();

      Client c (idClient,nom,prenom,email,num);


      bool test=false;

           if (idClient>0)test=tmpclient.modifier(c);
          {
               ui->tabclient->setModel(tmpclient.afficher());

              QMessageBox::information(this,"client supprime","client modifie");
          }


}



//actualiser


void Gestionclients::on_pushButton_actualiser_client_clicked()
{
    int i;
      ui->tabclient->setModel(c.afficher());
      qDebug()<<ui->tabclient->model()->rowCount();
      for (i=0;i<ui->tabclient->model()->rowCount();i++)
      {
      ui->tabclient->model()->index(i,0).data().toString();


      }
}

//doubleclick
void Gestionclients::on_tabclient_activated(const QModelIndex &index)
{

    QString val=ui->tabclient->model()->data(index).toString();


    QSqlQuery qry;
    qry.prepare("select * from tabclient where idClient='"+val+"' or nom='"+val+"' or prenom='"+val+"'or email='"+val+"'or numero='"+val+"'");

if(qry.exec())
{

while(qry.next())
{

    ui->lineEdit_idClient->setText(qry.value(0).toString());
    ui->lineEdit_nom->setText(qry.value(1).toString());
    ui->lineEdit_prenom->setText(qry.value(2).toString());
     ui->lineEdit_email->setText(qry.value(3).toString());
      ui->lineEdit_num->setText(qry.value(4).toString());

}

}
else
{
    QMessageBox::critical(this,tr("error::"),qry.lastError().text());
}
}
void Gestionclients::on_radioButton_tri_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();

       model->setQuery("select * from tabclient ORDER BY IdClient ");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("idClient "));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("email"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("numero"));
       ui->tabclient->setModel(model) ;
}

void Gestionclients::on_radioButton_triparnom_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();

       model->setQuery("select * from tabclient ORDER BY nom ");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("idClient "));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("email"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("numero"));
       ui->tabclient->setModel(model) ;
}
//pdf


void Gestionclients::on_pushButton_pdf_clicked()
{
    QPrinter printer;

        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName("C:/Users/infoMix/Desktop/imen/hot++.pdf");

       QPainter painter;
       painter.begin(&printer);
       QFont font;
        QString idClient = ui->lineEdit_idClient->text();
        QString nom = ui->lineEdit_nom->text();
        QString prenom = ui->lineEdit_prenom->text();
         QString email = ui->lineEdit_email->text();
         QString numero = ui->lineEdit_num->text();


       font.setPixelSize(35);
       painter.setFont(font);
       painter.setPen(Qt::blue);

       painter.drawText(100,300,"idClient :");

       painter.drawText(100,400,"nom :");

       painter.drawText(100,500,"prenom :");

       painter.drawText(100,600,"email:");

       painter.drawText(100,700,"numero :");

       font.setPixelSize(22);
       painter.setFont(font);
       painter.setPen(Qt::green);
       // QString numm= QString::number(numero);
       painter.drawText(500,300,idClient);
       painter.drawText(500,400,nom);
       painter.drawText(500,500,prenom);
       painter.drawText(500,600,email);
       painter.drawText(500,700,numero);
       painter.end();

}
// recherche
void Gestionclients::on_idClient2_2_cursorPositionChanged(int arg1, int arg2)
{
    QSqlQueryModel * model= new QSqlQueryModel();
               QSqlQuery q;
               q.prepare("select * from tabclient WHERE nom like '"+ui->idClient2_2->text()+"' OR  idClient like '"+ui->idClient2_2->text()+"' OR prenom like '"+ui->idClient2_2->text()+"' ");
                    tmpclient.recherchernomclient(q) ;
                      q.exec();
                      model->setQuery(q);
                      ui->tabclient->setModel(tmpclient.recherchernomclient(q));
}




//Avis


 //ajouter avis

void Gestionclients::on_pushButton_ajoutavis_clicked()
{
    QString num=ui->num->text();
    QString idClient=ui->idclient->currentText();
    QString dateavis=ui->dateavis->text();
    QString etat=ui->etat_2->text();
   Avis a (num,idClient ,dateavis,etat);


           if(a.verif_num(num)==false){
              popUp = new PopUp();
              popUp->setPopupText(" num doit contenir 8 chiffres");
              popUp->show();

           }else if(a.verif_id(idClient)==false){
              popUp = new PopUp();
              popUp->setPopupText("ID doit contenir 8 chiffres ! ");
              popUp->show();

           }else if(dateavis==""){
              popUp = new PopUp();
              popUp->setPopupText(" veuillez remplir le champ date ! ");
              popUp->show();

           }else if(etat==""){
              popUp = new PopUp();
              popUp->setPopupText("veuillez remplir le champ etat ! ");
              popUp->show();

          }
           else{

           bool test= a.ajouter(a);
         if(test)
         {
            ui->tableavis->setModel(tmpavis.afficher());
         init();
          QFile file("C:\\Users\\infoMix\\Desktop\\imen\\Historique2.txt");
                      if (!file.open(QIODevice::WriteOnly | QIODevice::Append |QIODevice::Text))
                          return;
                      QTextStream cout(&file);
                      QString message2="\n L'historique des clients à ajouter :"+num+" "+idClient+" "+dateavis+" "+etat+" ";
                      cout << message2;
          }

  }

}

//modifier avis

void Gestionclients::on_pushButton_modifieravis_clicked()

{


    QSqlQuery query;
        QString num = ui->num->text();
          QString idClient = ui->idclient->currentText();
          QString dateavis =ui->dateavis->text();
          QString  etat = ui->etat_2->text();


       Avis a (num,idClient,dateavis,etat);


        bool test=false;

             if (num>0)test=tmpavis.modifier(a);
            {
                 ui->tableavis->setModel(tmpavis.afficher());

                QMessageBox::information(this,"avis supprime","avis modifie");
            }


}
//supprimer avis

void Gestionclients::on_pushButton_suppavis_clicked()
{
    QString num= ui->num->text();
    bool test=tmpavis.supprimer(num);
           initialiser();
           if(test)
         {
         ui->tableavis->setModel(tmpavis.afficher());



         QMessageBox::information(nullptr, windowTitle(),QObject::tr("Suppression avec succés"));
         }
           else
           {
               QMessageBox::information(nullptr, windowTitle(),QObject::tr("num n'existe pas"));
       }
}

//actualiser

void Gestionclients::on_pushButton_actualiser_clicked()
{
    int i;
      ui->tableavis->setModel(a.afficher());
      qDebug()<<ui->tableavis->model()->rowCount();
      for (i=0;i<ui->tableavis->model()->rowCount();i++)
      {
    // ui->tableavis->model()->index(i,0).data().toString();

      ui->idclient->addItem(ui->tableavis->model()->index(i,0).data().toString());
      }
      QSqlQueryModel *model= new QSqlQueryModel();
      model->setQuery(("select idClient from tabclient"));
      ui->idclient->setModel(model);

}



//pdf



void Gestionclients::on_pushButton_pdfavis_clicked()
{
    QPrinter printer;

        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName("C:/Users/infoMix/Desktop/imen/hot++.pdf");

       QPainter painter;
       painter.begin(&printer);
       QFont font;
       QString num = ui->num->text();
        QString idClient = ui->lineEdit_idClient->text();

        QString dateavis= ui->dateavis->text();
         QString etat = ui->etat_2->text();

       font.setPixelSize(35);
       painter.setFont(font);
       painter.setPen(Qt::blue);

       painter.drawText(100,300,"num :");

       painter.drawText(100,400,"idClient :");

       painter.drawText(100,500,"dateavis:");

       painter.drawText(100,600,"etat:");



       font.setPixelSize(22);
       painter.setFont(font);
       painter.setPen(Qt::green);
      //  QString numm= QString::number(numero);
       painter.drawText(500,300,num);
       painter.drawText(500,400,idClient);
       painter.drawText(500,500,dateavis);
       painter.drawText(500,600,etat);

       painter.end();

}


//historique


void Gestionclients::on_pushButton_historiquefclient_clicked()

{
    QFile file ("C:\\Users\\infoMix\\Desktop\\imen\\Historique1.txt");
            if (!file.open(QIODevice::ReadOnly))
            {
                QMessageBox::information(0,"info",file.errorString());
            }
            QTextStream in (&file);
            ui->textBrowser->setText(in.readAll());
}


void Gestionclients::on_pushButton_historiqueavis_clicked()
{
    QFile file ("C:\\Users\\infoMix\\Desktop\\imen\\Historique2.txt");
            if (!file.open(QIODevice::ReadOnly))
            {
                QMessageBox::information(0,"info",file.errorString());
            }
            QTextStream in (&file);
            ui->textBrowser_2->setText(in.readAll());
}

//mailing

void Gestionclients::on_pushButton_mailing_clicked()
{
    Smtp* smtp = new Smtp("hotsmartiqua@gmail.com", "smartiquahot++", "smtp.gmail.com", 465);
                           connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
                               smtp->sendMail("hotsmartiqua@gmail.com", "imen.chakroun@esprit.tn" , "Smart Rapid Hotel, Nouveau Evenement!","Congrats!");
}

 //doubleclick


void Gestionclients::on_tableavis_activated(const QModelIndex &index)
{

    QString val=ui->tableavis->model()->data(index).toString();


    QSqlQuery qry;
    qry.prepare("select * from tabavis where num='"+val+"' or idClient='"+val+"' or dateavis='"+val+"'or etat='"+val+"'");

if(qry.exec())
{

while(qry.next())
{


    ui->num->setText(qry.value(0).toString());
    ui->idclient->setEditText(qry.value(1).toString());
    ui->dateavis->setDate(qry.value(2).toDate());
    ui->etat_2->setText(qry.value(3).toString());


  }}
else
{
    QMessageBox::critical(this,tr("error::"),qry.lastError().text());
}

}

//tri
void Gestionclients::on_radioButton_triparnum_clicked()
{  QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from tabavis ORDER BY num ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("num "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("idClient"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("dateavis"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("etat"));

    ui->tableavis->setModel(model) ;

}

void Gestionclients::on_radioButton_tridesc_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from tabavis ORDER BY num desc");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("num "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("idClient"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("dateavis"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("etat"));

    ui->tableavis->setModel(model) ;
}



void Gestionclients::on_lineEdit_recherche_cursorPositionChanged(int arg1, int arg2)
{
    QSqlQueryModel * model= new QSqlQueryModel();
               QSqlQuery q;
               q.prepare("select * from tabavis WHERE num like '"+ui->lineEdit_recherche->text()+"' OR  dateavis like '"+ui->lineEdit_recherche->text()+"' OR etat like '"+ui->lineEdit_recherche->text()+"' ");
                    tmpavis.rechercher(q) ;
                      q.exec();
                      model->setQuery(q);
                      ui->tableavis->setModel(tmpavis.rechercher(q));
}












