#ifndef SECRETAIRE_H
#define SECRETAIRE_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>
#include <QDebug>
#include <QMessageBox>
#include <QSqlRecord>
class Secretaire
{
public:
    Secretaire();
    Secretaire(QString,QString,int,int,QString,QString,QString);
    QString get_nom();
    QString get_prenom();
    int get_cin();
    int get_gsm();
    QString get_datenai();
    QString get_adresse();
    QString get_service();
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
    QString nom,prenom,datenai,adresse,service;
    int cin,gsm;
};

#endif // SECRETAIRE_H
