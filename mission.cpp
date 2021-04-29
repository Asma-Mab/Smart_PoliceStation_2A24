#include "mission.h"

//CONSTRUCTEUR PAR DEFAUT

mission::mission()
{

}

//CONSTRUCTEUR POUR AFFICHER

mission::mission(int id,QString type,QDate datemision,QString nom)
{
    this->id=id;
    this->type=type;
    this->datemision=datemision;
    this->nom=nom;

}

//CONSTRUCTEUR POUR AJOUTER

mission::mission(QString type,QDate datemision,QString nom)
{
    this->type=type;
    this->datemision=datemision;
    this->nom=nom;

}


//*******AJOUTER

bool mission::ajouter()
{
QSqlQuery query;

query.prepare("INSERT INTO MISSION (type, DATEMISION, nom) "
                    "VALUES (:type, :datemision, :nom)");


query.bindValue(":type", type);
query.bindValue(":datemision", datemision);
query.bindValue(":nom", nom);


return    query.exec();
}

//******AFFICHER

QSqlQueryModel * mission::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from MISSION");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date Mission"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nom"));



    return model;
}

//*******SUPPRIMPER

bool mission::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from MISSION where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}



//*******MODIFIER

bool mission::modifier(QString type, QDate datemision, QString nom,QString id)
{
QSqlQuery query;

query.prepare("UPDATE MISSION SET type= :type, datemision= :datemision, nom= :nom "
                    " WHERE  ID = :id ");


query.bindValue(":id", id);
query.bindValue(":type", type);
query.bindValue(":datemision", datemision);
query.bindValue(":nom", nom);


return    query.exec();
}

//******REMPLIR COMBO BOX

QSqlQueryModel * mission::remplircombomission()
{
    QSqlQueryModel * mod= new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select ID from MISSION");
    query.exec();
    mod->setQuery(query);
    return mod;
}


QSqlQuery mission::request(QString id)
{
    QSqlQuery query;
    query.prepare("select * from MISSION where ID= '"+id+"'");
    query.addBindValue(id);
    query.exec();
    return query;
}

//******RECHERCHE AVANCEE

QSqlQueryModel * mission::afficherecherche(QString res)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select * from MISSION  where (id LIKE '%"+res+"%' OR type LIKE '%"+res+"%' OR nom LIKE '%"+res+"%')");
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date Mission"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nom"));


    return model;
}

//******AFFICHER TRI

QSqlQueryModel * mission::triafficher(QString col)
{QSqlQueryModel * model= new QSqlQueryModel();

    QSqlQuery query;
    query.prepare("select * from MISSION order by "+col);
    query.exec();


model->setQuery(query);

model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date Mission"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nom"));

return model;
}

