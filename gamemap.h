#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <QWidget>
#include "roles.h"
#include "card.h"
#include "selecthero.h"


namespace Ui {
class Gamemap;
}

class Gamemap : public QWidget
{
    Q_OBJECT

public:
    explicit Gamemap(QWidget *parent = 0);
    void eqini();
    ~Gamemap();

private slots:
    void on_Battle1_clicked();

    void on_BattleSkeleton_clicked();

    void on_BattleMushroom_clicked();

    void on_BattleEyeofCthulu_clicked();

    void on_BattleMachine_clicked();

    void on_Battle_11451481019_clicked();

    void on_BattleArthas_clicked();

    void on_nextmap_clicked();

private:
    Ui::Gamemap *ui;
};

#endif // GAMEMAP_H
