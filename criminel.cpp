#include "criminel.h"

criminel::criminel()
{

}
criminel::criminel(QString s1,QString s2,QString s3,QString s4){

    id=s1;
    nom=s2;
    prenom=s3;
    crime=s4;
}


bool criminel::ajouter(){

    QSqlQuery query;


    query.prepare("INSERT INTO CRIMINEL VALUES (:id,:nom,:prenom,:crime)");

    query.bindValue(":id", id);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":crime",crime);



    return    query.exec();

}

bool criminel::modifier(QString selected){

    QSqlQuery query;


    query.prepare(" UPDATE CRIMINEL SET  NOM=:nom,prenom=:prenom,crime=:crime"
                  " where ID= :id");
    query.bindValue(":id", selected);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":crime",crime);



    return    query.exec();

}

 QSqlQueryModel * criminel::afficher(){

     QSqlQueryModel * modal=new QSqlQueryModel();
     modal->setQuery("SELECT * FROM CRIMINEL");

     return modal;

 }
  bool criminel::supprimer(QString selected){

      QSqlQuery query;
      query.prepare("Delete from CRIMINEL where ID = :id ");
      query.bindValue(":id", selected);
      return    query.exec();


  }

  void criminel::count_criminels(){


      vector<QString> liste_crime;
      QSqlQuery q1,q2,q3;
      int c;
      q1.prepare("SELECT * FROM CRIME");
      q1.exec();
      while (q1.next()){
          liste_crime.push_back(q1.value(0).toString());
      }


      for (auto i = liste_crime.begin(); i != liste_crime.end(); ++i) {
           q2.prepare("SELECT * FROM CRIMINEL where CRIME=:m ");
           q2.bindValue(":m", *i);
           q2.exec();
           c=0;
           while (q2.next()){c++;}


           q3.prepare(" UPDATE CRIME SET NB_CRIMINEL= :nb_criminel where id= :crime");
           q3.bindValue(":nb_criminel", c);
           q3.bindValue(":crime",*i);
           q3.exec();

      }


  }
  QSqlQueryModel * criminel::remplircombocriminel()
  {
      QSqlQueryModel * mod= new QSqlQueryModel();
      QSqlQuery query;
      query.prepare("select ID from CRIMINEL");
      query.exec();
      mod->setQuery(query);
      return mod;
  }

  QSqlQuery criminel::request(QString id)
  {
      QSqlQuery query;
      query.prepare("select * from CRIMINEL where ID= '"+id+"'");
      query.addBindValue(id);
      query.exec();
      return query;
  }




