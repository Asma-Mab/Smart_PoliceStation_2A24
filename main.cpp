
#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include "connection.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    connection C ;
    bool test=C.createConnection();

    if(test)

      //qDebug ()<<"Connexion reussite";
    //w.show();
        QMessageBox::information(nullptr,QObject::tr("data base is open"),
                     QObject::tr("connection successful! \n"
                               "click ok to exit"),QMessageBox::Ok);
    else
       // qDebug ()<<"erreur de connexion";
        QMessageBox::critical(nullptr,QObject::tr("data base is not open"),
                      QObject::tr("connection failed! \n"
                                  "click cancel to exit"),QMessageBox::Cancel);
    return a.exec();
}
