#include "connection.h"
#include "QSqlDatabase"
Connection::Connection()
{

}
bool Connection::createConnection(){
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("projet_2A");
    db.setUserName("dhia");
    db.setPassword("SYSTEM");
    if(db.open())
        test=true;
    return test;


}
