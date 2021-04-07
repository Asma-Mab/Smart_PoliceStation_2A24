#include "mainwindow.h"
#include "connexion.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    //QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);
    //MainWindow w;
    connexion c ;
    c.createconnect();
    MainWindow w ;
    w.show();
   /* try {
        c.createconnect();
        w.show();

    } catch (QString s) {
       qDebug()<<s; }*/
    return a.exec();
}
