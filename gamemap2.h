#ifndef GAMEMAP2_H
#define GAMEMAP2_H

#include <QWidget>


namespace Ui {
class gamemap2;
}

class gamemap2 : public QWidget
{
    Q_OBJECT

public:
    explicit gamemap2(QWidget *parent = 0);
    void eqini();
    ~gamemap2();

private slots:
    void on_BattleSkeleton_clicked();

    void on_BattleMushroom_clicked();

    void on_BattleMachine_clicked();

    void on_BattleSlime_clicked();

    void on_BattleArthas_clicked();

    void on_BattleEyeofCthulu_clicked();

    void on_Battle_11451481019_clicked();

    void on_BattleSteves_clicked();

    void on_nextmap_clicked();

private:
    Ui::gamemap2 *ui;
};

#endif // GAMEMAP2_H
