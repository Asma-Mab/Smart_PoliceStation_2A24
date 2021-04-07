#include "secretaire.h"

Secretaire::Secretaire()
{
  nom="";
  prenom="";
  cin=0;
  gsm=0;
  datenai="";
  adresse="";
  service="";
}
Secretaire::Secretaire(QString nom,QString prenom,int cin,int gsm,QString datenai,QString adresse,QString service)
{
    this->nom=nom;
    this->prenom=prenom;
    this->cin=cin;
    this->gsm=gsm;
    this->datenai=datenai;
    this->adresse=adresse;
    this->service=service;
}

QString Secretaire::get_nom(){return nom;};
QString Secretaire::get_prenom(){return prenom;};
int Secretaire::get_cin(){return cin;};
int Secretaire::get_gsm(){return gsm;};
QString Secretaire::get_datenai(){return datenai;};
QString Secretaire::get_adresse(){return adresse;};
QString Secretaire::get_service(){return service;};

bool Secretaire::ajouter()
{
QSqlQuery query;
QString res= QString::number(cin);
Secretaire s;
if (s.rech(cin)==0)
{
query.prepare("INSERT INTO SECRETAIRE (NOM,PRENOM,CIN,GSM,DATE_NAI,ADRESSE,SERVICE) "
                    "VALUES (:nom, :prenom, :cin, :gsm, :datenai, :adresse, :service)");
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":cin", cin);
query.bindValue(":gsm", gsm);
query.bindValue(":datenai", datenai);
query.bindValue(":adresse", adresse);
query.bindValue(":service", service);
}

return    query.exec();
}

QSqlQueryModel * Secretaire::afficher()
{
    QSqlQuery query;
     query.prepare("Select * from SECRETAIRE");
    QSqlQueryModel *model = new QSqlQueryModel();
    query.exec();
    model->setQuery(query);
    return model;
}

bool Secretaire::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from SECRETAIRE where CIN = :id ");
query.bindValue(":id", res);
return    query.exec();
}

bool Secretaire::update()
{

    QSqlQuery query;
    int first=0 ;
        QString res1=QString::number(cin);
         QString editer="Update SECRETAIRE set" ;
        query.bindValue(":nom",nom);
        if(nom!="")
        {
            editer+=" NOM = :nom" ;
            first=1 ;
        }

        query.bindValue(":prenom",prenom);
        if(prenom!=""&& first!=0)
            editer+=" ,PRENOM= :prenom" ;
        else if (prenom!=""&&first==0)
          {
            editer+=" PRENOM= :prenom" ;
            first=1 ;
          }
             query.bindValue(":gsm",gsm);
             if(gsm!=0&& first!=0)
                 editer+=" ,GSM = :gsm" ;
             else if (gsm!=0 && first==0)
             {
                editer+=" GSM = :gsm" ;
                first=1 ;
             }

               query.bindValue(":datenai",datenai);
               if(datenai!=""&& first!=0)
                   editer+=" ,DATE_NAI = :datenai" ;
               else if (datenai!=""&&first==0)
               {
                 editer+=" DATE_NAI = :datenai" ;
                 first=1 ;
               }

               query.bindValue(":adresse",adresse);
               if(adresse!=""&& first!=0)
                   editer+=" ,ADRESSE = :adresse" ;
               else if (adresse!=""&&first==0)
               {
                 editer+=" ADRESSE = :adresse" ;
                 first=1 ;
               }

               query.bindValue(":service",service);
               if(service!=""&& first!=0)
                   editer+=" ,SERVICE = :service" ;
               else if (service!="" && first==0)
               {
                  editer+=" SERVICE = :service" ;
                  first=1 ;
               }

               editer+=" where CIN = :id" ;



               QByteArray chaine = editer.toLocal8Bit();
               const char *final = chaine.data();

            query.prepare(final);


         query.bindValue(":id",QVariant(res1).toInt());
         query.bindValue(":prenom",prenom);
        query.bindValue(":gsm",gsm);
             query.bindValue(":datenai",datenai);
               query.bindValue(":adresse",adresse);
               query.bindValue(":service",service);
               query.bindValue(":nom",nom);


         return query.exec();
}

QSqlQueryModel * Secretaire::afficher_tri()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from SECRETAIRE order by CIN asc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("GSM"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_NAI "));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("ADRESSE "));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("SERVICE "));
    return model;
}

QSqlQueryModel * Secretaire::chercher(int id)
 {

     QSqlQueryModel * model = new QSqlQueryModel();
     QSqlQuery query;
     query.prepare(QString("select * from SECRETAIRE WHERE CIN=:id"));

     query.bindValue(":id",id);

      query.exec();
     model->setQuery(query);
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM "));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("CIN"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("GSM"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_NAI "));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("ADRESSE "));
     model->setHeaderData(6, Qt::Horizontal, QObject::tr("SERVICE "));

return model;
 }

int Secretaire::rech(int id)
{

    QSqlQuery query;
        int count=0;
        bool test=0;
        QString num_string=QString::number(id);
        if(query.exec("select CIN from SECRETAIRE where  CIN='" +num_string +"'"))
        {
        while(query.next())
            count++;
        if(count>=1)
            test=1;

        }
        return test;
}

QSqlQueryModel * Secretaire :: search (int type, QString key){
    QSqlQuery query;
    QSqlQueryModel *model = new QSqlQueryModel();
    int k ;
    switch(type){
        case 0:

            k = key.toInt();
            query.prepare("Select * from SECRETAIRE where CIN = :id");
            query.bindValue(":id", k);
           query.exec();
           model->setQuery(query);
           if(model->record(0).isEmpty() == true){ return model = nullptr;}
        break;
    case 1:

        query.prepare("Select * from SECRETAIRE where NOM = :modele");
        query.bindValue(":modele", key);
       query.exec();
       model->setQuery(query);
       if(model->record(0).isEmpty() == true){ return model = nullptr;}
        break;
    case 2:

        query.prepare("Select * from SECRETAIRE where DATE_NAI = :achat");
        query.bindValue(":achat", key);
       query.exec();
       model->setQuery(query);
       if((model->record(0)).isEmpty() == true){return model = nullptr;}
        break;
    default:
        model = nullptr;
        break;
    }
    return model;
}
