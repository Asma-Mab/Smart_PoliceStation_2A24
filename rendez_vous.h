#ifndef RENDEZ_VOUS_H
#define RENDEZ_VOUS_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>
#include <QDebug>
#include <QMessageBox>
#include <QSqlRecord>
class Rendez_vous
{
public:
    Rendez_vous();
    Rendez_vous(int,QString,QString,int,QString);
    int get_id();
    QString get_date();
    QString get_temps();
    int get_patient();
    QString get_desc();
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
    int idr,patient,*nombre;
    QString dater,timer,desc;

};

#endif // RENDEZ_VOUS_H
