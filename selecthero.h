#ifndef SELECTHERO_H
#define SELECTHERO_H

#include <QWidget>
#include "gamemap.h"
#include "roles.h"


namespace Ui {
class SelectHero;
}

class SelectHero : public QWidget
{
    Q_OBJECT

public:
    explicit SelectHero(QWidget *parent = 0);
    ~SelectHero();

private slots:
    void on_SelectWarrior_clicked();

    void on_SelectWizard_clicked();

private:
    Ui::SelectHero *ui;
};

#endif // SELECTHERO_H
