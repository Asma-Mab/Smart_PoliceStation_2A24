#include "cnx.h"
#include <QSqlError>
#include <QDebug>
Cnx::Cnx(){
                      }
bool Cnx::ouvrirConnexion()
{bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
                           db.setDatabaseName("Source_Projet2A");
                           db.setUserName("enis");//inserer nom de l'utilisateur
                           db.setPassword("enis");//inserer mot de passe de  l'utilisateur




if (db.open())
    test=true;

qDebug()<<db.lastError().text();
return  test;
}
void Cnx::fermerConnexion()
{db.close();}
