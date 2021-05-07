#ifndef INFRACTION_H
#define INFRACTION_H

#include <QSqlQuery>
#include <QSqlQueryModel>
#include <iostream>
#include <vector>
using namespace std;

class infraction
{
public:
    infraction();
    infraction(QString,QString,QString,QString,QString);

    bool ajouter();
    bool modifier(QString);
     QSqlQueryModel * afficher();
      bool supprimer(QString);

      void count_infractions();
      QSqlQueryModel * remplircombinf();
      QSqlQuery request(QString);

    QString id,date,heure,type,zone;
};

#endif // INFRACTION_H
