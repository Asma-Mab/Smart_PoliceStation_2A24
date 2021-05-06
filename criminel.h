#ifndef CRIMINEL_H
#define CRIMINEL_H

#include <QSqlQuery>
#include <QSqlQueryModel>
#include <iostream>
#include <vector>
using namespace std;

class criminel
{
public:
    criminel();

    criminel(QString,QString,QString,QString);

    bool ajouter();
    bool modifier(QString);
     QSqlQueryModel * afficher();
      bool supprimer(QString);
      QSqlQueryModel * remplircombocriminel();
      QSqlQuery request(QString);

      void count_criminels();

    QString id,nom,prenom,crime;

};

#endif // CRIMINEL_H
