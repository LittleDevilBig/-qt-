#include "battlefailed.h"
#include "ui_battlefailed.h"
#include <QApplication>
#include <QProcess>

BattleFailed::BattleFailed(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BattleFailed)
{
    ui->setupUi(this);
    setFixedSize(width(),height());//1193,766
}

BattleFailed::~BattleFailed()
{
    delete ui;
}



void BattleFailed::on_restartgame_clicked()
{
    qApp->closeAllWindows();
    QProcess::startDetached(qApp->applicationFilePath(),QStringList());
}

void BattleFailed::on_goodbye_clicked()
{
    close();
}
