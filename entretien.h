#ifndef ENTRETIEN_H
#define ENTRETIEN_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class entretien
{
public:
    entretien();
   entretien(int,QString,QString,QString,QString,QString);

     QString get_date();
     QString get_prix();
     QString get_rapport();
     QString get_duree();
     QString get_etat();
     int get_id();
     bool ajouter();
     QSqlQueryModel * afficher(int );
     bool supprimer(int);
     bool update();
      QSqlQueryModel * afficher_tri();
      QSqlQueryModel * chercher(int);
      int rech(int);
private :
      int id;
      QString date,rapport,prix,duree,etat;
};

#endif // ENTRETIEN_H
