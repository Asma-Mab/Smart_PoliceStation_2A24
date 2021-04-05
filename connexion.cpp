
#include "connexion.h"

Connexion::Connexion()
{

}

bool Connexion::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("projet_2a");
db.setUserName("salman");//inserer nom de l'utilisateur
db.setPassword("salman");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;

    return  test;
}
