#include "rendez_vous.h"

Rendez_vous::Rendez_vous()
{
    idr=0;
    dater="";
    timer="";
    patient=0;
    desc="";
    nombre=new int(20);

}
Rendez_vous::Rendez_vous(int idr,QString dater,QString timer,int patient,QString desc)
{
    this->idr=idr;
    this->dater=dater;
    this->timer=timer;
    this->patient=patient;
    this->desc=desc;
    nombre=new int(20);
}

int Rendez_vous::get_id(){return idr;};
QString Rendez_vous::get_date(){return dater;};
QString Rendez_vous::get_temps(){return timer;};
int Rendez_vous::get_patient(){return patient;};
QString Rendez_vous::get_desc(){return desc;};


bool Rendez_vous::ajouter()
{
QSqlQuery query;
QString res= QString::number(idr);
Rendez_vous s;
if (s.rech(idr)==0)
{
query.prepare("INSERT INTO RENDEZ_VOUS (ID_R,DATE_R,TEMPS_R,PATIENT,DESCRIPTION) "
                    "VALUES (:idr, :dater, :timer, :patient, :desc)");
query.bindValue(":idr", idr);
query.bindValue(":dater", dater);
query.bindValue(":timer", timer);
query.bindValue(":patient", patient);
query.bindValue(":desc", desc);

}

return    query.exec();
}

QSqlQueryModel * Rendez_vous::afficher()
{
    QSqlQuery query;
     query.prepare("Select * from RENDEZ_VOUS");
    QSqlQueryModel *model = new QSqlQueryModel();
    query.exec();
    model->setQuery(query);
    return model;
}

bool Rendez_vous::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from RENDEZ_VOUS where ID_R = :id ");
query.bindValue(":id", res);
return    query.exec();
}



bool Rendez_vous::update()
{

    QSqlQuery query;
    int first=0 ;
        QString res1=QString::number(idr);
         QString editer="Update RENDEZ_VOUS set" ;
        query.bindValue(":dater",dater);
        if(dater!="")
        {
            editer+=" DATE_R = :dater" ;
            first=1 ;
        }

        query.bindValue(":timer",timer);
        if(timer!=""&& first!=0)
            editer+=" ,TEMPS_R= :timer" ;
        else if (timer!=""&&first==0)
          {
            editer+=" TEMPS_R= :timer" ;
            first=1 ;
          }
             query.bindValue(":patient",patient);
             if(patient!=0&& first!=0)
                 editer+=" ,PATIENT = :patient" ;
             else if (patient!=0 && first==0)
             {
                editer+=" PATIENT = :patient" ;
                first=1 ;
             }

               query.bindValue(":desc",desc);
               if(desc!=""&& first!=0)
                   editer+=" ,DESCRIPTION = :desc" ;
               else if (desc!=""&&first==0)
               {
                 editer+=" DESCRIPTION = :desc" ;
                 first=1 ;
               }



               editer+=" where ID_R = :id" ;



               QByteArray chaine = editer.toLocal8Bit();
               const char *final = chaine.data();

            query.prepare(final);


         query.bindValue(":id",QVariant(res1).toInt());
         query.bindValue(":dater", dater);
         query.bindValue(":timer", timer);
         query.bindValue(":patient", patient);
         query.bindValue(":desc", desc);

         return query.exec();
}


QSqlQueryModel * Rendez_vous::afficher_tri()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from RENDEZ_VOUS order by ID_R asc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_R"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_R "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("TEMPS_R"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("PATIENT"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DESCRIPTION "));
    return model;
}

QSqlQueryModel * Rendez_vous::chercher(int id)
 {

     QSqlQueryModel * model = new QSqlQueryModel();
     QSqlQuery query;
     query.prepare(QString("select * from RENDEZ_VOUS WHERE ID_R=:id"));

     query.bindValue(":id",id);

      query.exec();
     model->setQuery(query);
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_R"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_R "));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("TEMPS_R"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("PATIENT"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("DESCRIPTION "));

return model;
 }


int Rendez_vous::rech(int id)
{

    QSqlQuery query;
        int count=0;
        bool test=0;
        QString num_string=QString::number(id);
        if(query.exec("select ID_R from RENDEZ_VOUS where  ID_R='" +num_string +"'"))
        {
        while(query.next())
            count++;
        if(count>=1)
            test=1;

        }
        return test;
}

QSqlQueryModel * Rendez_vous :: search (int type, QString key){
    QSqlQuery query;
    QSqlQueryModel *model = new QSqlQueryModel();
    int k ;
    switch(type){
        case 0:

            k = key.toInt();
            query.prepare("Select * from RENDEZ_VOUS where ID_R = :id");
            query.bindValue(":id", k);
           query.exec();
           model->setQuery(query);
           if(model->record(0).isEmpty() == true){ return model = nullptr;}
        break;
    case 1:

        query.prepare("Select * from RENDEZ_VOUS where DATE_R = :modele");
        query.bindValue(":modele", key);
       query.exec();
       model->setQuery(query);
       if(model->record(0).isEmpty() == true){ return model = nullptr;}
        break;
    case 2:

        query.prepare("Select * from RENDEZ_VOUS where TEMPS_R = :achat");
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


QSqlQueryModel * Rendez_vous :: sort (int type){
    QSqlQuery query;
    QSqlQueryModel *model = new QSqlQueryModel();
    switch(type){
        case 0:
        if(*nombre!=0)
        {
        query.prepare("Select * from RENDEZ_VOUS order by ID_R ASC");
       query.exec();
       model->setQuery(query);
       *nombre=0 ;
        }
        else if(*nombre==0)
        {
            query.prepare("Select * from RENDEZ_VOUS ");
           query.exec();
           model->setQuery(query);
           *nombre=20 ;
        }

        break;
    case 1: //sort by id
        if(*nombre!=1)
        {
        query.prepare("Select * from RENDEZ_VOUS order by DATE_R ASC");
       query.exec();
       model->setQuery(query);
       *nombre=1 ;
        }
        else if(*nombre==1)
        {
            query.prepare("Select * from RENDEZ_VOUS ");
           query.exec();
           model->setQuery(query);
           *nombre=20 ;
        }
        break;
    case 2: //sort by nb of use
        if(*nombre!=2)
        {
        query.prepare("Select * from RENDEZ_VOUS order by TEMPS_R ASC");
       query.exec();
       model->setQuery(query);
       *nombre=2 ;
        }
        else if(*nombre==2)
        {
            query.prepare("Select * from RENDEZ_VOUS ");
           query.exec();
           model->setQuery(query);
           *nombre=20 ;
        }
        break ;
    case 3: //sort by nb of use
        if(*nombre!=3)
        {
        query.prepare("Select * from RENDEZ_VOUS order by PATIENT ASC");
       query.exec();
       model->setQuery(query);
       *nombre=3 ;
        }
        else if(*nombre==3)
        {
            query.prepare("Select * from RENDEZ_VOUS ");
           query.exec();
           model->setQuery(query);
           *nombre=20 ;
        }

        break;
    case 4: //sort by nb of use
        if(*nombre!=4)
        {
        query.prepare("Select * from RENDEZ_VOUS order by DESCRIPTION ASC");
       query.exec();
       model->setQuery(query);
       *nombre=4 ;
        }
        else if(*nombre==4)
        {
            query.prepare("Select * from RENDEZ_VOUS ");
           query.exec();
           model->setQuery(query);
           *nombre=20 ;
        }

        break;

    }
    return model;
}
void Rendez_vous::recherche_id_place(QTableView *table, QString res)
{

QSqlQueryModel *model=new QSqlQueryModel() ;
QSqlQuery qry ;
if(res !="")
{
qry.prepare("Select * from RENDEZ_VOUS where (regexp_like(ID_R,:id))");
qry.bindValue(":id",res);
}
else {
    qry.prepare("Select * from RENDEZ_VOUS ");
}
qry.exec() ;
model->setQuery(qry) ;
table->setModel(model) ;
table->show() ;
}
