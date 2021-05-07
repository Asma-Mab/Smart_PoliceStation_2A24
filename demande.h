#ifndef DEMANDE_H
#define DEMANDE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include"QPainter"
#include"QPdfWriter"
#include"QDesktopServices"
#include"QtPrintSupport/QPrinter"
#include <QPropertyAnimation>

class Demande
{  public:
    Demande() ;
    Demande(QString ,QString ,QString ,QString,QString);
    QString get_iddemande( ){return iddemande ;}
    QString get_idCitoyen(){return  idCitoyen ;}
    QString get_datedemande(){ return  datedemande;}
    QString get_type() {return type ;}
    QString get_description() {return description ;}

    void setiddemande(QString);
    void setidCitoyen(QString);
    void setdatedemande( QDate);
    void settype(QString);
    void setdescription(QString);

    bool ajouter(Demande d);
    bool modifier (Demande d);
    bool supprimer(QString iddemande1);
    QSqlQueryModel * afficher();
    QSqlQueryModel *rechercher(QSqlQuery q);
    QSqlQueryModel *tri();
    QSqlQueryModel *showidCitoyen();
    bool verif_type(QString type);
    bool verif_iddemande(QString iddemande);

    private:

    QString iddemande, idCitoyen,type, datedemande,description;


};

#endif // DEMANDE_H

