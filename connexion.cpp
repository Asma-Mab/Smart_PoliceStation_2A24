#include "connexion.h"
#include <QSqlError>
connexion::connexion()
{

}

bool connexion::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("validation");
db.setUserName("zizo");//inserer nom de l'utilisateur
db.setPassword("zizo");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;
else throw QString ("Erreur Paramétres"+db.lastError().text());
return  test;
}



void connexion::fermerconnexion()
{db.close();}

