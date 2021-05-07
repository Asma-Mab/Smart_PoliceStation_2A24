#ifndef CITOYEN_H
#define CITOYEN_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include"QPainter"
#include"QPdfWriter"
#include"QDesktopServices"
#include"QtPrintSupport/QPrinter"
#include <QPropertyAnimation>



class Citoyen
{  public:
    Citoyen() ;
    Citoyen(QString ,QString ,QString,QString);
    QString get_cin( ){return cin ;}
    QString get_nom(){ return  nom;}
    QString get_prenom() {return prenom ;}
    QString get_email(){return  email ;}

    void initialiser();
    void setNom(QString);
    void setPrenom(QString);
    void setcin(QString);
    void setNum(QString);
    void setEmail(QString);

    bool ajouter(Citoyen c);
    bool modifier (Citoyen c);
    bool supprimer(QString cin);

    QSqlQueryModel * afficher();
    QSqlQueryModel *recherchercin(QSqlQuery q);
    QSqlQueryModel *tri();
    QSqlQueryModel * getIdModel();

    bool verif_email(QString ch);
    bool verif_cin(QString ch);
    bool verif_nom(QString ch);
    bool verif_prenom(QString ch);

    private:

    QString  cin ;
    QString nom , prenom , email ;
};

#endif // CITOYEN_H

