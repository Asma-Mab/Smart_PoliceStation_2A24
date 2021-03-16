#include "connection.h"
#include "QSqlDatabase"

connection::connection()
{

}

bool connection::createConnection(){
    bool test =false ;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("projet_2A") ;
    db.setUserName("salman") ;
    db.setPassword("salman");

    if(db.open())
        test=true;
    return test ;

}
