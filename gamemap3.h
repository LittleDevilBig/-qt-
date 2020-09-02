#ifndef GAMEMAP3_H
#define GAMEMAP3_H

#include <QWidget>


namespace Ui {
class gamemap3;
}

class gamemap3 : public QWidget
{
    Q_OBJECT

public:
    explicit gamemap3(QWidget *parent = 0);
    void eqini();
    ~gamemap3();

private slots:
    void on_BattleGilgamesh_clicked();

    void on_BattleArthas_clicked();

    void on_BattleSteves_clicked();

    void on_BattlePony_clicked();

    void on_BattleUSS_Enterprise_clicked();

    void on_BattleNo_99_clicked();

    void on_BattleMoon_Lord_clicked();

    void on_BattleEnder_Dragon_clicked();

    void on_WinGame_clicked();

private:
    Ui::gamemap3 *ui;
};

#endif // GAMEMAP3_H
