#ifndef BATTLEWIN_H
#define BATTLEWIN_H

#include <QWidget>


namespace Ui {
class BattleWin;
}

class BattleWin : public QWidget
{
    Q_OBJECT

public:
    explicit BattleWin(QWidget *parent = 0);
    ~BattleWin();

private slots:
    void on_ACARD_clicked();

    void on_ANEQUIPMENT_clicked();

    void on_skippart_clicked();

private:
    Ui::BattleWin *ui;
};

#endif // BATTLEWIN_H
