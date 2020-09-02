#ifndef BATTLEFAILED_H
#define BATTLEFAILED_H

#include <QWidget>


namespace Ui {
class BattleFailed;
}

class BattleFailed : public QWidget
{
    Q_OBJECT

public:
    explicit BattleFailed(QWidget *parent = 0);
    ~BattleFailed();

private slots:
    void on_goodbye_clicked();

    void on_restartgame_clicked();

private:
    Ui::BattleFailed *ui;
};

#endif // BATTLEFAILED_H
