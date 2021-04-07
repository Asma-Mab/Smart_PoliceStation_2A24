#ifndef CONNEXION_H
#define CONNEXION_H
#include <QSqlDatabase>

class connexion
{
private :
QSqlDatabase db ;
public:
    connexion();
    bool createconnect() ;
    void fermerconnexion () ;

};

#endif // CONNEXION_H
