#include "demande.h"
#include <QDebug>

Demande::Demande()
{

iddemande="";
idCitoyen="";
datedemande="";
type="";
description="";

}

Demande::Demande(QString iddemande,QString idCitoyen,QString datedemande ,QString type,QString description )
{
  this->iddemande=iddemande;
  this->idCitoyen=idCitoyen;
  this->datedemande=datedemande;
  this->type=type;
  this->description=description;


}
//ajouter


bool Demande::ajouter(Demande d)
{
    QSqlQuery query;

    query.prepare("INSERT INTO TABDEMANDE (IDDEMANDE, IDCITOYEN, DATEDEMANDE, TYPE, DESCRIPTION) "
                        "VALUES (:iddemande, :idCitoyen, :datedemande, :type, :description)");
    query.bindValue(":iddemande",d.get_iddemande());
    query.bindValue(":idCitoyen",d.get_idCitoyen());
    query.bindValue(":datedemande",d.get_datedemande());
    query.bindValue(":type",d.get_type());
    query.bindValue(":description",d.get_description());

    return query.exec();
}
//afiicher

QSqlQueryModel * Demande::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from TABDEMANDE");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("iddemande"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("idcitoyen"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("datedemande"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("description"));

    return model;
}


//supprimer

bool Demande::supprimer(QString iddemande1)
{
QSqlQuery query;

query.prepare("Delete from TABDEMANDE where IDDEMANDE= :IDDEMANDE ");
query.bindValue(":IDDEMANDE", iddemande1);
return    query.exec();
}
//modifier

bool Demande::modifier(Demande d)
{
    QSqlQuery query;

       query.prepare("UPDATE TABDEMANDE SET  IDDEMANDE=:iddemande ,IDCITOYEN=:idCitoyen ,DATEDEMANDE =:datedemande  ,TYPE =:type  WHERE IDDEMANDE=:iddemande");
       query.bindValue(":iddemande",d.get_iddemande());
       query.bindValue(":idCitoyen",d.get_idCitoyen());
       query.bindValue(":datedemande",d.get_datedemande());
       query.bindValue(":type",d.get_type());
       query.bindValue(":description",d.get_description());

    return query.exec();
}
//tri

QSqlQueryModel *Demande::tri()
{
QSqlQuery *q = new QSqlQuery();
QSqlQueryModel *model = new QSqlQueryModel();
q->prepare("SELECT * FROM TABDEMANDE ORDER BY IDDEMANDE");
q->exec();
model->setQuery(*q);
return model;
}

//recherche


QSqlQueryModel * Demande::rechercher(QSqlQuery q)
{
    QSqlQueryModel *model= new QSqlQueryModel();

    model->setQuery(q);
    return (model);
}


bool Demande::verif_iddemande(QString ch_iddemande){
   bool test=true;
   int i;
   if(ch_iddemande.length()!=4){
      test=false;
      return  test;
   }else{
       for(i=0;i<ch_iddemande.length();i++){
           if(!((ch_iddemande[i]>='0')&&(ch_iddemande[i]<='4'))){
               test=false;
               return  test;
       }
       }
   }
return test;}
bool Demande::verif_type(QString type){
    bool test=true;
    int i;
    if(type.length()>20){
       test=false;
       return  test;
    }else{
        for(i=0;i<type.length();i++){
            if(!(((type[i]>='A')&&(type[i]<='Z'))||((type[i]>='a')&&(type[i]<='z')))){
                test=false;
                return  test;
        }
    }
  }

    return  test;
}



QSqlQueryModel* Demande::showidCitoyen()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select CIN from TABCITOYEN");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
        return model;
}
