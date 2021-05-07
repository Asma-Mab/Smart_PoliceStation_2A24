#ifndef GRADE_H
#define GRADE_H

#include <QSqlQuery>
#include <QSqlQueryModel>


class grade
{
public:
    grade();
    grade(QString,QString);

    bool ajouter();
    bool modifier(QString);
     QSqlQueryModel * afficher();
      bool supprimer(QString);
      QSqlQueryModel * remplircombograde();
      QSqlQuery request(QString);

    QString id,description;
};

#endif // GRADE_H
