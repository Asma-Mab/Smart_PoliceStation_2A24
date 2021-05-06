#include "zone.h"

zone::zone()
{

}

zone::zone(QString s1,QString s2,QString s3){

    id=s1;
    ville=s2;
    rue=s3;
}


bool zone::ajouter(){

    QSqlQuery query;


    query.prepare("INSERT INTO ZONE(ID,VILLE,RUE) VALUES (:id,:ville,:rue)");

    query.bindValue(":id", id);
    query.bindValue(":ville",ville);
    query.bindValue(":rue",rue);



    return    query.exec();

}

bool zone::modifier(QString selected){

    QSqlQuery query;


    query.prepare(" UPDATE ZONE SET  VILLE=:ville,RUE=:rue"
                  " where ID= :id");
    query.bindValue(":id", selected);
    query.bindValue(":ville",ville);
    query.bindValue(":rue",rue);



    return    query.exec();

}

 QSqlQueryModel * zone::afficher(){

     QSqlQueryModel * modal=new QSqlQueryModel();
     modal->setQuery("SELECT * FROM ZONE");

     return modal;

 }
  bool zone::supprimer(QString selected){

      QSqlQuery query;
      query.prepare("Delete from ZONE where ID = :id ");
      query.bindValue(":id", selected);
      return    query.exec();


  }

  QSqlQueryModel * zone::remplircombozone()
  {
      QSqlQueryModel * mod= new QSqlQueryModel();
      QSqlQuery query;
      query.prepare("select ID from ZONE");
      query.exec();
      mod->setQuery(query);
      return mod;
  }

  QSqlQuery zone::request(QString id)
  {
      QSqlQuery query;
      query.prepare("select * from ZONE where ID= '"+id+"'");
      query.addBindValue(id);
      query.exec();
      return query;
  }



