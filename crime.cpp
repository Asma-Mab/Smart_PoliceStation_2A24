#include "crime.h"

crime::crime()
{

}

crime::crime(QString s1,QString s2,QString s3){

    id=s1;
    type=s2;
    date=s3;

}


bool crime::ajouter(){

    QSqlQuery query;


    query.prepare("INSERT INTO CRIME(ID,DATE_CRIME,TYPE) VALUES (:id,:date,:type)");

    query.bindValue(":id", id);
    query.bindValue(":date",date);
    query.bindValue(":type",type);



    return    query.exec();

}

bool crime::modifier(QString selected){

    QSqlQuery query;


    query.prepare(" UPDATE CRIME SET  DATE_CRIME=:date,TYPE=:type"
                  " where ID= :id");
    query.bindValue(":id", selected);
    query.bindValue(":date",date);
    query.bindValue(":type",type);



    return    query.exec();

}

 QSqlQueryModel * crime::afficher(){

     QSqlQueryModel * modal=new QSqlQueryModel();
     modal->setQuery("SELECT * FROM CRIME");

     return modal;

 }
  bool crime::supprimer(QString selected){

      QSqlQuery query;
      query.prepare("Delete from CRIME where ID = :id ");
      query.bindValue(":id", selected);
      return    query.exec();


  }
  QSqlQueryModel * crime::remplircombocrime()
  {
      QSqlQueryModel * mod= new QSqlQueryModel();
      QSqlQuery query;
      query.prepare("select ID from CRIME");
      query.exec();
      mod->setQuery(query);
      return mod;
  }

  QSqlQuery crime::request(QString id)
  {
      QSqlQuery query;
      query.prepare("select * from CRIME where ID= '"+id+"'");
      query.addBindValue(id);
      query.exec();
      return query;
  }



