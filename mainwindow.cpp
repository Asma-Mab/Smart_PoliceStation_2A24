#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //ouverture connection base de donnees

    if( c.createconnect()){
     close();
     gestion_dhia *go;
     go = new gestion_dhia();
     go->show();
     }
}
