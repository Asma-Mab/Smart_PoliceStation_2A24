#ifndef ZONE_H
#define ZONE_H

#include <QSqlQuery>
#include <QSqlQueryModel>

class zone
{
public:
    zone();
    zone(QString,QString,QString);

    bool ajouter();
    bool modifier(QString);
     QSqlQueryModel * afficher();
      bool supprimer(QString);
      QSqlQueryModel * remplircombozone();
      QSqlQuery request(QString);

    QString id,ville,rue;
};

#endif // ZONE_H
