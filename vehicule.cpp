#include "vehicule.h"

//CONSTRUCTEUR PAR DEFAUT

vehicule::vehicule()
{

}

//CONSTRUCTEUR POUR AFFICHER

vehicule::vehicule(int id,QString matricule,QString marque)
{
    this->id=id;
    this->matricule=matricule;
    this->marque=marque;
}

//CONSTRUCTEUR POUR AJOUTER

vehicule::vehicule(QString matricule,QString marque)
{
    this->matricule=matricule;
    this->marque=marque;
}


//*******AJOUTER

bool vehicule::ajouter()
{
QSqlQuery query;

query.prepare("INSERT INTO VEHICULE (MATRICULE, MARQUE) "
                    "VALUES (:matricule, :marque)");


query.bindValue(":matricule", matricule);
query.bindValue(":marque", marque);


return    query.exec();
}

//******AFFICHER

QSqlQueryModel * vehicule::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from VEHICULE");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Matricule"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Marque"));



    return model;
}

//*******SUPPRIMPER

bool vehicule::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from VEHICULE where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}



//*******MODIFIER

bool vehicule::modifier(QString matricule, QString marque,QString id)
{
QSqlQuery query;

query.prepare("UPDATE VEHICULE SET MATRICULE= :matricule, MARQUE= :marque "
                    " WHERE  ID = :id ");


query.bindValue(":id", id);
query.bindValue(":matricule", matricule);
query.bindValue(":marque", marque);


return    query.exec();
}

//******REMPLIR COMBO BOX

QSqlQueryModel * vehicule::remplircombovehicule()
{
    QSqlQueryModel * mod= new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select ID from VEHICULE");
    query.exec();
    mod->setQuery(query);
    return mod;
}


QSqlQuery vehicule::request(QString id)
{
    QSqlQuery query;
    query.prepare("select * from VEHICULE where ID= '"+id+"'");
    query.addBindValue(id);
    query.exec();
    return query;
}

//******RECHERCHE AVANCEE

QSqlQueryModel * vehicule::afficherecherche(QString res)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select * from VEHICULE  where (id LIKE '%"+res+"%' OR matricule LIKE '%"+res+"%' OR marque LIKE '%"+res+"%')");
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Matricule"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Marque"));



    return model;
}

//******AFFICHER TRI

QSqlQueryModel * vehicule::triafficher(QString col)
{QSqlQueryModel * model= new QSqlQueryModel();

    QSqlQuery query;
    query.prepare("select * from VEHICULE order by "+col);
    query.exec();


model->setQuery(query);

model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Matricule"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Marque"));

return model;
}

//STAT
QStringList vehicule::listevehicules(){
    QSqlQuery query;
    query.prepare("select marque from VEHICULE");
    query.exec();
    QStringList list;
    while(query.next()){
        list.append(query.value(0).toString());
    }

    return list;
}

int vehicule::calculmarque(QString marque){
    QSqlQuery query;
     query.prepare("select  COUNT(marque) from VEHICULE  WHERE marque=:marque");
     query.bindValue(":marque", marque );
     query.exec();
      int total=0;

     while(query.next()){
       total++;

     }


     return total;
}


