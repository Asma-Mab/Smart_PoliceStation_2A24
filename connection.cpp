#include "connection.h"

Connection::Connection()
{}

bool Connection::ouvrirConnexion()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("projet_2a");//inserer le nom de la source de données ODBC
db.setUserName("salman");//inserer nom de l'utilisateur
db.setPassword("salman");//inserer mot de passe de cet utilisateur
if (db.open())
    test=true;
return  test;
}
QSqlDatabase Connection::getdb()
{
    return db;
}

void Connection::fermerConnexion()
{db.close();}
