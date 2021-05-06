#ifndef STATISTIQUE_ETAT_H
#define STATISTIQUE_ETAT_H

#include <QMainWindow>

namespace Ui {
class statistique_etat;
}

class statistique_etat : public QMainWindow
{
    Q_OBJECT

public:
    explicit statistique_etat(QWidget *personne = nullptr);
    ~statistique_etat();

private:
    Ui::statistique_etat *ui;
};

#endif // STATISTIQUE_ETAT_H
