#ifndef MISSION_H
#define MISSION_H

#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QtGui>
#include <QtSql>
#include <QtCore>

class mission
{
public:
    mission();
    mission(int,QString,QDate,QString);
    mission(QString,QDate,QString);
    bool ajouter();
    bool supprimer(int);

    QSqlQueryModel * afficherecherche(QString);
    QSqlQueryModel * triafficher(QString);
    QSqlQueryModel * afficher();
    QSqlQueryModel * remplircombomission();
    QSqlQuery request(QString);
    bool modifier(QString,QDate,QString,QString);

private:
    int id;
    QString type;
    QDate datemision;
    QString nom;
};

#endif // MISSION_H
