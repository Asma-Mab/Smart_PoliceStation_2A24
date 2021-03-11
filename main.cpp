#include "mainwindow.h"
#include <QApplication>
#include "QMessageBox"
#include "QDebug"
#include "connection.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Connection C;
    bool test=C.createConnection();
    MainWindow w;
    if(test)

  {
        qDebug() <<"Connection réussite";
        w.show();
    }
    else
        qDebug() <<"erreur de connection ";

    return a.exec();
}
