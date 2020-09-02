#ifndef BATTLE_H
#define BATTLE_H

#include <QWidget>
#include "roles.h"
#include "card.h"
#include "gamemap.h"
#include "selecthero.h"
#include <QPalette>


namespace Ui {
class Battle;
}

class Battle : public QWidget
{
    Q_OBJECT

public:
    explicit Battle(QWidget *parent = 0);
    void labelini();
    ~Battle();

private slots:
    void on_Handcard1_clicked();

    void on_ENDROUND_clicked();

    void on_Handcard2_clicked();

    void on_Handcard3_clicked();

    void on_Handcard4_clicked();

    void on_Handcard5_clicked();

    void on_Handcard6_clicked();

    void on_Handcard7_clicked();

    void on_Handcard8_clicked();

    void on_Handcard9_clicked();

    void on_Handcard10_clicked();

private:
    Ui::Battle *ui;
};

#endif // BATTLE_H
