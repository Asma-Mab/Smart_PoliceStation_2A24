#ifndef VEHICULE_H
#define VEHICULE_H

#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QtGui>
#include <QtSql>
#include <QtCore>

class vehicule
{
public:
    vehicule();
    vehicule(int,QString,QString);
    vehicule(QString,QString);

    bool ajouter();
    bool supprimer(int);

    QSqlQueryModel * afficherecherche(QString);
    QSqlQueryModel * triafficher(QString);
    QSqlQueryModel * afficher();
    QSqlQueryModel * remplircombovehicule();
    QSqlQuery request(QString);
    bool modifier(QString,QString,QString);
    QStringList listevehicules();
    int calculmarque(QString);

private:
    int id;
    QString matricule;
    QString marque;
};

#endif // VEHICULE_H
