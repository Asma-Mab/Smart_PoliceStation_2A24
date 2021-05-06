#ifndef BUS_H
#define BUS_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>
#include <QDebug>
#include <QMessageBox>
#include <QSqlRecord>

class bus
{public:
   bus();
  bus(int,QString,QString,QString,QString);
    QString get_type();
    QString get_modele();
    QString get_date_achat();
    QString get_etat();
    int get_id();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool update();
     QSqlQueryModel * afficher_tri();
     QSqlQueryModel * chercher(int);
     int rech(int);
     void recherche_id_place(QTableView *, QString);
     QSqlQueryModel * search (int type, QString key) ;
     QSqlQueryModel * sort (int type) ;

private:
    QString type,modele,date_achat,etat;
    int id,*nombre;
};

#endif // BUS_H
