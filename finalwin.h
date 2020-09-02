#ifndef FINALWIN_H
#define FINALWIN_H

#include <QWidget>


namespace Ui {
class FinalWin;
}

class FinalWin : public QWidget
{
    Q_OBJECT

public:
    explicit FinalWin(QWidget *parent = 0);
    ~FinalWin();

private slots:
    void on_restartgame_clicked();

private:
    Ui::FinalWin *ui;
};

#endif // FINALWIN_H
