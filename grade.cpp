#include "grade.h"

grade::grade()
{

}

grade::grade(QString s1,QString s2){

    id=s1;
    description=s2;

}


bool grade::ajouter(){

    QSqlQuery query;


    query.prepare("INSERT INTO GRADE(ID,DESCRIPTION) VALUES (:id,:description)");

    query.bindValue(":id", id);
    query.bindValue(":description",description);



    return    query.exec();

}

bool grade::modifier(QString selected){

    QSqlQuery query;


    query.prepare(" UPDATE GRADE SET  DESCRIPTION=:description"
                  " where ID= :id");
    query.bindValue(":id", selected);
    query.bindValue(":description",description);



    return    query.exec();

}

 QSqlQueryModel * grade::afficher(){

     QSqlQueryModel * modal=new QSqlQueryModel();
     modal->setQuery("SELECT * FROM GRADE");

     return modal;

 }
  bool grade::supprimer(QString selected){

      QSqlQuery query;
      query.prepare("Delete from GRADE where ID = :id ");
      query.bindValue(":id", selected);
      return    query.exec();


  }


  QSqlQueryModel * grade::remplircombograde()
  {
      QSqlQueryModel * mod= new QSqlQueryModel();
      QSqlQuery query;
      query.prepare("select ID from GRADE");
      query.exec();
      mod->setQuery(query);
      return mod;
  }


  QSqlQuery grade::request(QString id)
  {
      QSqlQuery query;
      query.prepare("select * from GRADE where ID= '"+id+"'");
      query.addBindValue(id);
      query.exec();
      return query;
  }
