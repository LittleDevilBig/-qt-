#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QWidget>
#include "selecthero.h"
#include <QPalette>
#include "roles.h"


namespace Ui {
class MainPage;
}

class MainPage : public QWidget
{
    Q_OBJECT

public:
    explicit MainPage(QWidget *parent = 0);
    ~MainPage();

private slots:
    void on_Startgame_clicked();

    void on_Guide_clicked();

private:
    Ui::MainPage *ui;
};

#endif // MAINPAGE_H
