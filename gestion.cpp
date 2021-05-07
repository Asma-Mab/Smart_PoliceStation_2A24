#include "gestion.h"
#include "ui_gestion.h"

gestion::gestion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion)
{
    ui->setupUi(this);
    ui->tabcitoyen->setModel(tmpcitoyen.afficher());
    ui->tabledemande->setModel(tmpdemande.afficher());
    ui->idcitoyen->setModel(d.showidCitoyen());
    QPixmap pic("C:/Users/enisg/OneDrive/Images/polic.jpg");
               ui->label_13->setPixmap(pic);
               ui->label_14->setPixmap(pic);
               popUp = new PopUp();
               popUp->setPopupText("Welcome to Smart Police Station Plus");
               popUp->show();
}
void gestion::initialiser()
{
                ui->lineEdit_cin->clear();
             ui->lineEdit_nom->clear();
             ui->lineEdit_prenom->clear();
             ui->lineEdit_email->clear();

}
void gestion::init()
{
              ui->numD->clear();
             ui->idcitoyen->clear();
             ui->dateD->clear();
             ui->typeD->clear();
             ui->lineEdit->clear();
}
gestion::~gestion()
{
    delete ui;
}

void gestion::on_pushButton_ajoutC_clicked()
{  QString idClient=ui->lineEdit_cin->text();
    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_prenom->text();
    QString email= ui->lineEdit_email->text();

    Citoyen c(idClient,nom,prenom,email);

     if(c.verif_cin(idClient)==false){
            popUp = new PopUp();
            popUp->setPopupText("Cin doit contenir 8 chiffres ! ");
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

        }
         else{

         bool test= c.ajouter(c);
       if(test)
       {
          ui->tabcitoyen->setModel(tmpcitoyen.afficher());
        initialiser();
        QFile file("Historique1.txt");
                    if (!file.open(QIODevice::WriteOnly | QIODevice::Append |QIODevice::Text))
                        return;
                    QTextStream cout(&file);
                    QString message2="\n L'historique des citoyens à ajouter :"+idClient+" "+nom+" "+prenom+" "+email;
                    cout << message2;
        }

}

}

void gestion::on_pushButton_historiqueC_clicked()
{
    QFile file ("Historique1.txt");
                if (!file.open(QIODevice::ReadOnly))
                {
                    QMessageBox::information(0,"info",file.errorString());
                }
                QTextStream in (&file);
                ui->textBrowser->setText(in.readAll());
}

void gestion::on_pushButton_mailingC_clicked()
{

    Smtp* smtp = new Smtp("enisgharbia@gmail.com", "smartiquahot++", "smtp.gmail.com", 465);
                           connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
                               smtp->sendMail("enisgharbia@gmail.com", "hiba.sboui@esprit.tn" , "Smart Rapid police station","Alert");
}

void gestion::on_pushButton_modifier_citoyen_clicked()
{
    QSqlQuery query;
    QString idCitoyen = ui->lineEdit_cin->text();
      QString nom = ui->lineEdit_nom->text();
      QString prenom =ui->lineEdit_prenom->text();
      QString  email = ui->lineEdit_email->text();


    Citoyen c (idCitoyen,nom,prenom,email);


    bool test=false;

         if (idCitoyen>0)test=tmpcitoyen.modifier(c);
        {
             ui->tabcitoyen->setModel(tmpcitoyen.afficher());

            QMessageBox::information(this,"citoyen supprime","citoyen modifie");
        }

}

void gestion::on_radioButton_tri_cin_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();

       model->setQuery("select * from tabcitoyen ORDER BY CIN ");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin "));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("email"));

       ui->tabcitoyen->setModel(model) ;
}

void gestion::on_radioButton_trinom_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();

       model->setQuery("select * from tabcitoyen ORDER BY NOM ");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin "));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("email"));

       ui->tabcitoyen->setModel(model) ;
}

void gestion::on_tabcitoyen_activated(const QModelIndex &index)
{
    QString val=ui->tabcitoyen->model()->data(index).toString();


    QSqlQuery qry;
    qry.prepare("select * from tabcitoyen where cin='"+val+"' or nom='"+val+"' or prenom='"+val+"'or email='"+val+"'");

if(qry.exec())
{

while(qry.next())
{

    ui->lineEdit_cin->setText(qry.value(0).toString());
    ui->lineEdit_nom->setText(qry.value(1).toString());
    ui->lineEdit_prenom->setText(qry.value(2).toString());
     ui->lineEdit_email->setText(qry.value(3).toString());

}

}
else
{
    QMessageBox::critical(this,tr("error::"),qry.lastError().text());
}
}

void gestion::on_pushButton_ajoutavis_clicked()
{
    QString num=ui->numD->text();
    QString idCitoyen=ui->idcitoyen->currentText();
    QString dated=ui->dateD->text();
    QString type=ui->typeD->text();
     QString description=ui->lineEdit->text();
   Demande d (num,idCitoyen ,dated,type,description);


           if(d.verif_iddemande(num)==false){
              popUp = new PopUp();
              popUp->setPopupText(" num doit contenir 8 chiffres");
              popUp->show();

           }else if(d.verif_iddemande(num)==false){
              popUp = new PopUp();
              popUp->setPopupText("ID doit contenir 4 chiffres ! ");
              popUp->show();

           }else if(dated==""){
              popUp = new PopUp();
              popUp->setPopupText(" veuillez remplir le champ date ! ");
              popUp->show();

           }else if(type==""){
              popUp = new PopUp();
              popUp->setPopupText("veuillez remplir le champ etat ! ");
              popUp->show();

          }
           else{

           bool test= d.ajouter(d);
         if(test)
         {
            ui->tabledemande->setModel(tmpdemande.afficher());
         init();
          QFile file("Historique2.txt");
                      if (!file.open(QIODevice::WriteOnly | QIODevice::Append |QIODevice::Text))
                          return;
                      QTextStream cout(&file);
                      QString message2="\n L'historique des demandes à ajouter :"+num+" "+idCitoyen+" "+dated+" "+type+" ";
                      cout << message2;
          }

  }
}

void gestion::on_pushButton_suppavis_clicked()
{
    QString num= ui->numD->text();
    bool test=tmpdemande.supprimer(num);
           initialiser();
           if(test)
         {
         ui->tabledemande->setModel(tmpdemande.afficher());



         QMessageBox::information(nullptr, windowTitle(),QObject::tr("Suppression avec succés"));
         }
           else
           {
               QMessageBox::information(nullptr, windowTitle(),QObject::tr("demande n'existe pas"));
       }
}

void gestion::on_pushButton_modifieravis_clicked()
{

    QSqlQuery query;
        QString num = ui->numD->text();
          QString idCitoyen = ui->idcitoyen->currentText();
          QString dateD =ui->dateD->text();
          QString  type = ui->typeD->text();
QString  description = ui->lineEdit->text();

       Demande d (num,idCitoyen,dateD,type,description);


        bool test=false;

             if (num>0)test=tmpdemande.modifier(d);
            {
                 ui->tabledemande->setModel(tmpdemande.afficher());

                QMessageBox::information(this,"demande supprime","demande modifie");
            }
}

void gestion::on_pushButton_historiqueavis_clicked()
{
    QFile file ("Historique2.txt");
                if (!file.open(QIODevice::ReadOnly))
                {
                    QMessageBox::information(0,"info",file.errorString());
                }
                QTextStream in (&file);
                ui->textBrowser_2->setText(in.readAll());

}

void gestion::on_pushButton_actualiser_clicked()
{int i;
    ui->tabledemande->setModel(d.afficher());
    qDebug()<<ui->tabledemande->model()->rowCount();
    for (i=0;i<ui->tabledemande->model()->rowCount();i++)
    {

    ui->idcitoyen->addItem(ui->tabledemande->model()->index(i,0).data().toString());
    }
    QSqlQueryModel *model= new QSqlQueryModel();
    model->setQuery(("select cin from tabcitoyen"));
    ui->idcitoyen->setModel(model);

}

void gestion::on_pb_supprimer_clicked()
{

    QString idClient= ui->lineEdit_cin->text();
    bool test=tmpcitoyen.supprimer(idClient);
           initialiser();
           if(test)
         {
         ui->tabcitoyen->setModel(tmpcitoyen.afficher());



         QMessageBox::information(nullptr, windowTitle(),QObject::tr("Suppression avec succés"));
         }
           else
           {
               QMessageBox::information(nullptr, windowTitle(),QObject::tr("Cin n'existe pas"));
       }
}

void gestion::on_pushButton_actualiser_citoyen_clicked()
{
    int i;
      ui->tabcitoyen->setModel(c.afficher());
      qDebug()<<ui->tabcitoyen->model()->rowCount();
      for (i=0;i<ui->tabcitoyen->model()->rowCount();i++)
      {
      ui->tabcitoyen->model()->index(i,0).data().toString();


      }
}

void gestion::on_cinrecherche_cursorPositionChanged(int arg1, int arg2)
{
    QSqlQueryModel * model= new QSqlQueryModel();
               QSqlQuery q;
               q.prepare("select * from tabclient WHERE nom like '"+ui->cinrecherche->text()+"' OR  cin like '"+ui->cinrecherche->text()+"' OR prenom like '"+ui->cinrecherche->text()+"' ");
                    tmpcitoyen.recherchercin(q) ;
                      q.exec();
                      model->setQuery(q);
                      ui->tabcitoyen->setModel(tmpcitoyen.recherchercin(q));
}


void gestion::on_tabledemande_activated(const QModelIndex &index)
{
    QString val=ui->tabledemande->model()->data(index).toString();


    QSqlQuery qry;
    qry.prepare("select * from tabdemande where IDDEMANDE='"+val+"' or DESCRIPTION='"+val+"' or TYPE='"+val+"'or DATEDEMANDE='"+val+"'");

if(qry.exec())
{

while(qry.next())
{


    ui->numD->setText(qry.value(0).toString());
    ui->idcitoyen->setEditText(qry.value(1).toString());
    ui->dateD->setDate(qry.value(2).toDate());
    ui->typeD->setText(qry.value(3).toString());
 ui->lineEdit->setText(qry.value(4).toString());

  }}
else
{
    QMessageBox::critical(this,tr("error::"),qry.lastError().text());
}

}

void gestion::on_radioButton_triparnum_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * from tabdemande ORDER BY iddemande ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("iddemande "));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("idcitoyen"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("datedemande"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
      model->setHeaderData(4, Qt::Horizontal, QObject::tr("description"));
        ui->tabledemande->setModel(model) ;

}

void gestion::on_radioButton_tridesc_clicked()
{ QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from tabdemande ORDER BY idcitoyen ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("iddemande "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("idcitoyen"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("datedemande"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
  model->setHeaderData(4, Qt::Horizontal, QObject::tr("description"));
    ui->tabledemande->setModel(model) ;

}

void gestion::on_lineEdit_rechercheD_cursorPositionChanged(int arg1, int arg2)
{
    QSqlQueryModel * model= new QSqlQueryModel();
               QSqlQuery q;
               q.prepare("select * from tabdemande WHERE iddemande like '"+ui->lineEdit_rechercheD->text()+"' OR  datedemande like '"+ui->lineEdit_rechercheD->text()+"' OR type like '"+ui->lineEdit_rechercheD->text()+"' ");
                    tmpdemande.rechercher(q) ;
                      q.exec();
                      model->setQuery(q);
                      ui->tabledemande->setModel(tmpdemande.rechercher(q));
}
