#include "plaintes.h"

Plaintes::Plaintes()
{
  id=0;
  raison="";
  date="";
  type="";
}

Plaintes::Plaintes(int idp,QString raisonp,QString datep,QString typep)
{
    id=idp;
    raison=raisonp;
    date=datep;
    type=typep;
}
//GETTERS
int Plaintes::get_id(){return id;}

QString Plaintes::get_raison(){return raison;}

QString Plaintes::get_date(){return date;}

QString Plaintes::get_type(){return type;}

bool Plaintes::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
Plaintes s;
if (s.rech(id)==0)
{
query.prepare("INSERT INTO PLAINTE (IDP,RAISON,DATEP,TYPE) "
                    "VALUES (:id, :raison, :date, :type)");
query.bindValue(":id", id);
query.bindValue(":raison", raison);
query.bindValue(":date", date);
query.bindValue(":type", type);
}
return    query.exec();
}

QSqlQueryModel * Plaintes::afficher()
{
    QSqlQuery query;
     query.prepare("Select * from PLAINTE");
    QSqlQueryModel *model = new QSqlQueryModel();
    query.exec();
    model->setQuery(query);
    return model;
}

bool Plaintes::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from PLAINTE where IDP = :id ");
query.bindValue(":id", res);
return    query.exec();
}

bool Plaintes::update()
{

    QSqlQuery query;
    int first=0 ;
        QString res1=QString::number(id);
         QString editer="Update PLAINTE set" ;
        query.bindValue(":dater",raison);
        if(raison!="")
        {
            editer+=" RAISON = :dater" ;
            first=1 ;
        }

        query.bindValue(":timer",date);
        if(date!=""&& first!=0)
            editer+=" ,DATEP= :timer" ;
        else if (date!=""&&first==0)
          {
            editer+=" DATEP= :timer" ;
            first=1 ;
          }
             query.bindValue(":patient",type);
             if(type!=""&& first!=0)
                 editer+=" ,TYPE = :patient" ;
             else if (type!="" && first==0)
             {
                editer+=" TYPE = :patient" ;
                first=1 ;
             }

              editer+=" where IDP = :id" ;
               QByteArray chaine = editer.toLocal8Bit();
               const char *final = chaine.data();

            query.prepare(final);
         query.bindValue(":id",QVariant(res1).toInt());
         query.bindValue(":dater", raison);
         query.bindValue(":timer", date);
         query.bindValue(":patient",type);

         return query.exec();
}

QSqlQueryModel * Plaintes::afficher_tri()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from PLAINTE order by IDP asc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDP"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("RAISON "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATEP"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE"));
    return model;
}

QSqlQueryModel * Plaintes::chercher(int id)
 {

     QSqlQueryModel * model = new QSqlQueryModel();
     QSqlQuery query;
     query.prepare(QString("select * from PLAINTE WHERE IDP=:id"));

     query.bindValue(":id",id);

      query.exec();
     model->setQuery(query);
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDP"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("RAISON "));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATEP"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE"));

return model;
 }
int Plaintes::rech(int id)
{

    QSqlQuery query;
        int count=0;
        bool test=0;
        QString num_string=QString::number(id);
        if(query.exec("select ID_R from PLAINTE where  IDP='" +num_string +"'"))
        {
        while(query.next())
            count++;
        if(count>=1)
            test=1;

        }
        return test;
}


