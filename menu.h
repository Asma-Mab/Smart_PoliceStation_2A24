#ifndef MENU_H
#define MENU_H

#include <QDialog>

namespace Ui {
class Menu;
}

class Menu : public QDialog
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_infraction_clicked();

    void on_pushButton_criminel_clicked();

    void on_pushButton_infraction_2_clicked();

    void on_pushButton_infraction_3_clicked();

    void on_pushButton_infraction_4_clicked();

private:
    Ui::Menu *ui;
};

#endif // MENU_H
