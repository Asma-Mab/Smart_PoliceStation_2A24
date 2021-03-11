#include "infraction.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
Infraction::Infraction()
{
num=0; date=""; heure=0; type="";

}

Infraction::Infraction(int num,QString date,int heure,QString type)
{this->num=num; this->date=date; this->heure=heure; this->type=type;}
int Infraction::getnum(){return num;}
QString Infraction::getdate(){return date;}
int Infraction::getheure(){return heure;}
QString Infraction::gettype(){return type;}
void Infraction::setnum(int num){this->num=num;}
void Infraction::setdate(QString date){this->date=date;}
void Infraction::setheure(int heure){this->heure=heure;}
void Infraction::settype(QString type){this->type=type;}
bool Infraction::ajouter()
{

QString num_string= QString::number(num);
    QSqlQuery query;

    query.prepare("INSERT INTO infraction (num, datee, heure,type) "
                  "VALUES (:num, :date, :hour, :type)");
    query.bindValue(":num", num_string);
    query.bindValue(":date", date);
    query.bindValue(":hour", heure);
    query.bindValue(":type", type);
    return query.exec();
}

bool Infraction::supprimer(int num)
{

    QSqlQuery query;

    query.prepare("Delete from Infraction where num=:num "  ) ;

    query.bindValue(":num", num);

    return query.exec();
}

QSqlQueryModel* Infraction::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();


        model->setQuery("SELECT* FROM Infraction");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiantt"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("date"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("heure"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
    return model;

}

