#include "infraction.h"

infraction::infraction()
{

}

infraction::infraction(QString s1,QString s2,QString s3,QString s4,QString s5){

    id=s1;
    date=s2;
    heure=s3;
    type=s4;
    zone=s5;
}


bool infraction::ajouter(){

    QSqlQuery query;


    query.prepare("INSERT INTO INFRACTION VALUES (:id,:date,:heure,:type,:zone)");

    query.bindValue(":id", id);
    query.bindValue(":date",date);
    query.bindValue(":heure",heure);
    query.bindValue(":type",type);
    query.bindValue(":zone",zone);



    return    query.exec();

}

bool infraction::modifier(QString selected){

    QSqlQuery query;


    query.prepare(" UPDATE INFRACTION SET  DATE_INF=:date,HEURE_INF=:heure,TYPE=:type,ZONE=:zone"
                  " where ID= :id");
    query.bindValue(":id", selected);
    query.bindValue(":date",date);
    query.bindValue(":heure",heure);
    query.bindValue(":type",type);
    query.bindValue(":zone",zone);



    return    query.exec();

}

 QSqlQueryModel * infraction::afficher(){

     QSqlQueryModel * modal=new QSqlQueryModel();
     modal->setQuery("SELECT * FROM INFRACTION");

     return modal;

 }

 bool infraction::supprimer(QString selected){

      QSqlQuery query;
      query.prepare("Delete from INFRACTION where ID = :id ");
      query.bindValue(":id", selected);
      return    query.exec();


  }

  void infraction::count_infractions(){


      vector<QString> liste_infractions;
      QSqlQuery q1,q2,q3;
      int c;
      q1.prepare("SELECT * FROM ZONE");
      q1.exec();
      while (q1.next()){
          liste_infractions.push_back(q1.value(0).toString());
      }


      for (auto i = liste_infractions.begin(); i != liste_infractions.end(); ++i) {
           q2.prepare("SELECT * FROM INFRACTION where ZONE=:m ");
           q2.bindValue(":m", *i);
           q2.exec();
           c=0;
           while (q2.next()){c++;}


           q3.prepare(" UPDATE ZONE SET NB_INFRACTION= :nb_infraction where id= :zone");
           q3.bindValue(":nb_infraction", c);
           q3.bindValue(":zone",*i);
           q3.exec();

      }


  }

  QSqlQueryModel * infraction::remplircombinf()
  {
      QSqlQueryModel * mod= new QSqlQueryModel();
      QSqlQuery query;
      query.prepare("select ID from INFRACTION");
      query.exec();
      mod->setQuery(query);
      return mod;
  }

  QSqlQuery infraction::request(QString id)
  {
      QSqlQuery query;
      query.prepare("select * from INFRACTION where ID= '"+id+"'");
      query.addBindValue(id);
      query.exec();
      return query;
  }


