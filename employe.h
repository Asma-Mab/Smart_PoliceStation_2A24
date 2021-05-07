#ifndef EMPLOYE_H
#define EMPLOYE_H


#include <QSqlQuery>
#include <QSqlQueryModel>

class employe
{
public:
    employe();
    employe(QString,QString,QString,QString,QString,QString,double);
    bool ajouter();
    bool modifier(QString);
     QSqlQueryModel * afficher();
      bool supprimer(QString);
      QSqlQueryModel * remplircomboemploye();
      QSqlQuery request(QString);

      QString id, nom, tel, mail, naissance,grade;
      double salaire;
};

#endif // EMPLOYE_H
