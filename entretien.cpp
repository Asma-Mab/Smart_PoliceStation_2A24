#include "entretien.h"
#include <QDebug>
#include <QMessageBox>
entretien::entretien()
{
id=0;
prix="";
date="";
rapport="";
etat="";

}
entretien::entretien(int id,QString date,QString rapport,QString duree ,QString prix,QString etat)
{
  this->id=id;
   this->prix=prix;
 this->date=date;
    this->rapport=rapport;
    this->etat=etat;
    this->duree=duree;


}
QString entretien::get_date(){return  date;}
QString entretien::get_prix(){return prix;}
QString entretien::get_etat(){return etat;}
QString entretien::get_duree(){return duree;}

QString entretien::get_rapport(){return rapport;}
int entretien::get_id(){return  id;}

bool entretien::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
entretien b;

query.prepare("INSERT INTO entretien (ID_BUS,DATE_ENT,RAPPORT,DUREE,PRIX,ETAT) "
                    "VALUES (:id, :date, :rapport, :duree, :prix,:etat)");
query.bindValue(":id", res);
query.bindValue(":date", date);
query.bindValue(":rapport", rapport);
query.bindValue(":duree", duree);
query.bindValue(":prix", prix);
query.bindValue(":etat", etat);





return    query.exec();
}

QSqlQueryModel * entretien::afficher(int id)
{


QSqlQueryModel * model = new QSqlQueryModel();
QSqlQuery query;
query.prepare(QString("select * from entretien WHERE ID_BUS=:id"));

query.bindValue(":id",id);
query.exec();
model->setQuery(query);
/*
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Rapport"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Duree"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Prix "));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("ETAT "));*/


    return model;
}
QSqlQueryModel * entretien::afficher_tri()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from entretien order by ID_BUS asc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Rapport"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Duree"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Prix "));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("ETAT "));

    return model;
}

bool entretien::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from entretien where ID_BUS = :id ");
query.bindValue(":id", res);
return    query.exec();
}
bool entretien::update()
{

    QSqlQuery query;
    int first=0 ;
        QString res1=QString::number(id);
         QString editer="Update ENTRETIEN set" ;
        query.bindValue(":date",date);
        if(date!="")
        {
            editer+=" DATE_ENT = :date" ;
            first=1 ;
        }

        query.bindValue(":rapport",rapport);
        if(rapport!=""&& first!=0)
            editer+=" ,RAPPORT= :rapport" ;
        else if (rapport!=""&&first==0)
          {
            editer+=" RAPPORT= :rapport" ;
            first=1 ;
          }
             query.bindValue(":duree",duree);
             if(duree!=""&& first!=0)
                 editer+=" ,DUREE = :duree" ;
             else if (duree!="" && first==0)
             {
                editer+=" DUREE= :duree" ;
                first=1 ;
             }

               query.bindValue(":prix",prix);
               if(prix!=""&& first!=0)
                   editer+=" ,PRIX = :prix" ;
               else if (prix!=""&&first==0)
               {
                 editer+=" PRIX = :prix" ;
                 first=1 ;
               }
               query.bindValue(":etat",etat);
               if(etat!=""&& first!=0)
                   editer+=" ,ETAT= :etat" ;
               else if (etat!=""&&first==0)
               {
                 editer+=" ETAT= :etat" ;
                 first=1 ;
               }
               editer+=" where ID_BUS = :id" ;



               QByteArray chaine = editer.toLocal8Bit();
               const char *final = chaine.data();

              /*QMessageBox::information(nullptr, QObject::tr("Supprimer un étudiant"),
                           QObject::tr(final
                                       ), QMessageBox::Cancel);*/

            query.prepare(final);

               //query.prepare("Update entretien set MODELE= :modele,ETAT = :etat,DATE_ACHAT = :date_achat  where ID = :id");

         query.bindValue(":id",QVariant(res1).toInt());

         query.bindValue(":date", date);
         query.bindValue(":rapport", rapport);
         query.bindValue(":duree", duree);
         query.bindValue(":prix", prix);
         query.bindValue(":etat", etat);

         return query.exec();
}
QSqlQueryModel * entretien::chercher(int id)
 {

     QSqlQueryModel * model = new QSqlQueryModel();
     QSqlQuery query;
     query.prepare(QString("select * from entretien WHERE ID_BUS=:id"));

     query.bindValue(":id",id);

      query.exec();
     model->setQuery(query);
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("Date "));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Rapport"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Duree"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prix "));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("ETAT "));

return model;
 }
int entretien ::rech(int id)
{

    QSqlQuery query;
        int count=0;
        bool test=0;
        QString num_string=QString::number(id);
        if(query.exec("select ID_BUS from entretien where  ID_BUS='" +num_string +"'"))
        {
        while(query.next())
            count++;
        if(count>=1)
            test=1;

        }
        return test;
}
