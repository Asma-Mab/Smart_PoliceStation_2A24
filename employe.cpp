#include "employe.h"

employe::employe()
{

}

employe::employe(QString s1 ,QString s2,QString s3 ,QString s4 ,QString s5,QString s6,double s7 ){

    id=s1;
    nom=s2;
    tel=s3;
    mail=s4;
    naissance=s5;
    grade=s6;
    salaire=s7;
}


bool employe::ajouter(){

    QSqlQuery query;


    query.prepare("INSERT INTO EMPLOYES (ID,NOM,TEL,MAIL,NAISSANCE,SALAIRE,GRADE) VALUES (:id, :nom, :tel ,:mail,:naissance,:salaire,:grade)");

    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":tel", tel);
    query.bindValue(":mail", mail);
    query.bindValue(":naissance", naissance);
    query.bindValue(":salaire", salaire);
    query.bindValue(":grade", grade);

    return    query.exec();

}

bool employe::modifier(QString selected){

    QSqlQuery query;


    query.prepare(" UPDATE EMPLOYES SET NOM= :nom ,Tel= :tel ,MAIL= :mail,NAISSANCE= :naissance ,SALAIRE= :salaire,GRADE= :grade "
                  "where ID= :id");
    query.bindValue(":id", selected);
    query.bindValue(":nom", nom);
    query.bindValue(":tel", tel);
    query.bindValue(":mail", mail);
    query.bindValue(":naissance", naissance);
    query.bindValue(":salaire", salaire);
  query.bindValue(":grade", grade);


    return    query.exec();

}

 QSqlQueryModel * employe::afficher(){

     QSqlQueryModel * modal=new QSqlQueryModel();
     modal->setQuery("SELECT * FROM EMPLOYES");

     return modal;

 }
  bool employe::supprimer(QString selected){

      QSqlQuery query;
      query.prepare("Delete from EMPLOYES where ID = :id ");
      query.bindValue(":id", selected);
      return    query.exec();


  }

  QSqlQueryModel * employe::remplircomboemploye()
  {
      QSqlQueryModel * mod= new QSqlQueryModel();
      QSqlQuery query;
      query.prepare("select ID from EMPLOYES");
      query.exec();
      mod->setQuery(query);
      return mod;
  }


  QSqlQuery employe::request(QString id)
  {
      QSqlQuery query;
      query.prepare("select * from EMPLOYES where ID= '"+id+"'");
      query.addBindValue(id);
      query.exec();
      return query;
  }
