#ifndef PLAINTES_H
#define PLAINTES_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>
#include <QDebug>
#include <QMessageBox>
#include <QSqlRecord>

class Plaintes
{
public:
    Plaintes();
    Plaintes(int,QString,QString,QString);
    int get_id();
    QString get_raison();
    QString get_date();
    QString get_type();
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
    int id;
    QString raison,date,type;
};

#endif // PLAINTES_H
