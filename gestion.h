#ifndef GESTION_H
#define GESTION_H
#include "Citoyen.h"
#include "smtp.h"
#include"demande.h"
#include "popup.h"
#include <QMainWindow>
#include <QComboBox>
#include <QPixmap>
#include<QPainter>
#include"QFont"
#include"QPen"
#include<QPrintDialog>
#include"QPdfWriter"
#include"QDesktopServices"
#include"QtPrintSupport/QPrinter"
#include <QPropertyAnimation>
#include "smtp.h"
#include <QMessageBox>
#include <QComboBox>
#include <QTextStream>
#include <QPixmap>
#include <QDebug>
#include"QMessageBox"
#include<QPropertyAnimation>
#include<random>
#include"QPainter"
#include"QFont"
#include"QPen"
#include"QPdfWriter"
#include"QTextDocumentWriter"
#include"QDesktopServices"
#include"QtPrintSupport/QPrinter"
#include <QPropertyAnimation>
#include <QTableWidget>
//#include <src/SmtpMime>//
#include <QFile>
#include <QDate>
#include <QCalendarWidget>
#include <QSqlError>
#include <popup.h>
#include <QDialog>

namespace Ui {
class gestion;
}

class gestion : public QDialog
{
    Q_OBJECT



public:
    explicit gestion(QWidget *parent = nullptr);
    ~gestion();
private slots:

    void on_pushButton_ajoutC_clicked();

    void on_pushButton_historiqueC_clicked();

    void on_pushButton_mailingC_clicked();

    void on_pushButton_modifier_citoyen_clicked();

    void on_radioButton_tri_cin_clicked();

    void on_radioButton_trinom_clicked();

    void on_tabcitoyen_activated(const QModelIndex &index);
    void initialiser();

    void init();
    void on_pushButton_ajoutavis_clicked();

    void on_pushButton_suppavis_clicked();

    void on_pushButton_modifieravis_clicked();

    void on_pushButton_historiqueavis_clicked();

    void on_pushButton_actualiser_clicked();

    void on_pb_supprimer_clicked();

    void on_pushButton_actualiser_citoyen_clicked();

    void on_cinrecherche_cursorPositionChanged(int arg1, int arg2);



    void on_tabledemande_activated(const QModelIndex &index);

    void on_radioButton_triparnum_clicked();

    void on_radioButton_tridesc_clicked();

    void on_lineEdit_rechercheD_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::gestion *ui;


     Demande tmpdemande;
     Citoyen tmpcitoyen;
     Citoyen c ;
     Demande d ;
     PopUp *popUp;
};

#endif // GESTION_H
