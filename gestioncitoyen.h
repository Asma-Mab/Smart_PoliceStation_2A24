#ifndef GESTIONCITOYEN_H
#define GESTIONCITOYEN_H
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


namespace Ui {
class Gestioncitoyen;
}

class Gestioncitoyen: public QMainWindow
{
    Q_OBJECT

public:
    explicit Gestioncitoyen(QWidget *parent = nullptr);
    ~Gestioncitoyen();
private slots:




   void on_pb_supprimer_clicked();

    void initialiser();

    void init();

    void on_tabclient_activated(const QModelIndex &index);

    void on_idClient2_2_cursorPositionChanged(int arg1, int arg2);

    void on_tabledemande_activated(const QModelIndex &index);

    void on_radioButton_tri_clicked();

    void on_radioButton_triparnom_clicked();

    void on_pushButton_ajoutcitoyen_clicked();

    void on_pushButton_modifier_citoyen_clicked();

    void on_pushButton_actualiser_citoyen_clicked();

    void on_pushButton_pdf_clicked();

    void on_pushButton_mailing_clicked();

    void on_radioButton_triparnum_clicked();

    void on_radioButton_tridesc_clicked();


    void on_lineEdit_recherche_cursorPositionChanged(int arg1, int arg2);

    void on_pushButton_ajoutdemande_clicked();

    void on_pushButton_suppdemande_clicked();

    void on_pushButton_modifierdemande_clicked();

    void on_pushButton_pdfdemande_clicked();

    void on_pushButton_actualiser_clicked();

    void on_pushButton_historiquedemande_clicked();



    void on_pushButton_historiquefcitoyen_clicked();

private:
    Ui::Gestioncitoyen *ui;

     Demande tmpdemande;
     Citoyen tmpcitoyen;
     Citoyen c ;
     Demande d ;
     PopUp *popUp;
};

#endif // GESTIONCITOYEN_H
