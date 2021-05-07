#include "Citoyen.h"
#include <QDebug>



Citoyen::Citoyen()
{
cin ="";
nom="";
prenom="";
email="";
//numero="";

}
Citoyen::Citoyen(QString cin,QString nom,QString prenom ,QString email)
{
  this->cin=cin;
  this->nom=nom;
  this->prenom=prenom;
  this->email=email;


}

//ajouter

bool Citoyen::ajouter(Citoyen c)
{
    QSqlQuery query;

    query.prepare("INSERT INTO TABCITOYEN (CIN, NOM, PRENOM, EMAIL) "
                        "VALUES (:cin, :nom, :prenom, :email)");
    query.bindValue(":cin",c.get_cin());
    query.bindValue(":nom",c.get_nom());
    query.bindValue(":prenom",c.get_prenom());
    query.bindValue(":email",c.get_email());
    //query.bindValue(":numero",c.get_num());
    return query.exec();
}



//afficher

QSqlQueryModel * Citoyen::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from TABCITOYEN");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Cin"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));

    return model;
}

//supprimer

bool Citoyen::supprimer(QString cin1)
{
QSqlQuery query;
//QString cin= QString::number(cin1);
query.prepare("Delete from tabcitoyen where cin = :cin ");
query.bindValue(":cin",cin1);
return    query.exec();
}
//modifier
bool Citoyen::modifier(Citoyen c)
{
    QSqlQuery query;

       query.prepare("UPDATE TABCITOYEN SET NOM =:nom , PRENOM =:prenom , EMAIL =:email WHERE cin =:cin ");
       query.bindValue(":cin", c.get_cin());
       query.bindValue(":nom", c.get_nom());
       query.bindValue(":prenom",c.get_prenom());
       query.bindValue(":email", c.get_email());
    return query.exec();
}

//tri

QSqlQueryModel *Citoyen::tri()
{
QSqlQuery *q = new QSqlQuery();
QSqlQueryModel *model = new QSqlQueryModel();
q->prepare("SELECT * FROM TABCITOYEN ORDER BY NOM");
q->exec();
model->setQuery(*q);
return model;
}


QSqlQueryModel * Citoyen::recherchercin(QSqlQuery q)
{
    QSqlQueryModel *model= new QSqlQueryModel();

    model->setQuery(q);
    return (model);
}


QSqlQueryModel * Citoyen::getIdModel()
{
    QSqlQuery *query = new QSqlQuery();
    QSqlQueryModel *model = new QSqlQueryModel();
    query->prepare("select idClient from TABCLIENT");
    query->exec();
    model->setQuery(*query);
    return model;
}

bool Citoyen::verif_email(QString ch){
   bool test=false;
   int i;
   for(i=0;i<ch.length();i++)
   {
       if(ch[i]=='@'){
           test=true;
       }
   }
   return  test;
}


bool Citoyen::verif_cin(QString ch_id){
   bool test=true;
   int i;
   if(ch_id.length()!=8){
      test=false;
      return  test;
   }else{
       for(i=0;i<ch_id.length();i++){
           if(!((ch_id[i]>='0')&&(ch_id[i]<='9'))){
               test=false;
               return  test;
       }
       }
   }
return test;}

bool Citoyen::verif_nom(QString nom){
    bool test=true;
    int i;
    if(nom.length()>20){
       test=false;
       return  test;
    }else{
        for(i=0;i<nom.length();i++){
            if(!(((nom[i]>='A')&&(nom[i]<='Z'))||((nom[i]>='a')&&(nom[i]<='z')))){
                test=false;
                return  test;
        }
    }
  }
    return  test;
}
