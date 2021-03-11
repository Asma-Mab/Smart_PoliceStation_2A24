#ifndef INFRACTION_H
#define INFRACTION_H
#include <QString>
#include <QSqlQueryModel>
class Infraction
{
public:
    Infraction();
    Infraction(int,QString,int,QString);
    int getnum();
    QString getdate();
    int getheure();
    QString gettype();
    void setnum(int);
    void setdate(QString);
    void setheure(int);
    void settype(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
private:
    int num;
    QString date;
    int heure;
    QString type;

};

#endif // INFRACTION_H
