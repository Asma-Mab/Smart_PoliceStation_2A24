#ifndef STATISTIQUE_H
#define STATISTIQUE_H

#include <QDialog>

namespace Ui {
class Statistique;
}

class Statistique : public QDialog
{
    Q_OBJECT

public:
    explicit Statistique(QWidget *personne = nullptr);
    ~Statistique();

private:
    Ui::Statistique *ui;
};

#endif // STATISTIQUE_H
