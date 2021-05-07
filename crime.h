#ifndef CRIME_H
#define CRIME_H

#include <QSqlQuery>
#include <QSqlQueryModel>

class crime
{
public:
    crime();
    crime(QString,QString,QString);

    bool ajouter();
    bool modifier(QString);
     QSqlQueryModel * afficher();
      bool supprimer(QString);
      QSqlQueryModel * remplircombocrime();
      QSqlQuery request(QString);

    QString id,date,type;
};

#endif // CRIME_H
