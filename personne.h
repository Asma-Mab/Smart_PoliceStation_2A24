#ifndef PERSONNE_H
#define PERSONNE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>
#include <QDebug>
#include <QMessageBox>
#include <QSqlRecord>

class Personne
{
public:
    Personne();
    Personne(int,QString,QString,QString,QString,QString);
    int get_id();
    QString get_nom();
    QString get_prenom();
    QString get_adresse();
    QString get_date();
    QString get_sexe();

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
    int id,*nombre;
    QString nom,prenom,adresse,date,sexe;
};

#endif // PERSONNE_H
