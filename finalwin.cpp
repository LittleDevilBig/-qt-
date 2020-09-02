#include "finalwin.h"
#include "ui_finalwin.h"
#include <QApplication>
#include <QProcess>
#include <qstring.h>
#include "globals.h"
#include "battle.h"
#include <QMessageBox>
#include "battlefailed.h"
#include "battlewin.h"

FinalWin::FinalWin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FinalWin)
{
    ui->setupUi(this);
    setFixedSize(width(),height());//1193,766
    ui->prize->setPixmap(QPixmap(QString("://Pictures/prize.png")).scaled(ui->prize->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
}

FinalWin::~FinalWin()
{
    delete ui;
}

void FinalWin::on_restartgame_clicked()
{
    qApp->closeAllWindows();
    QProcess::startDetached(qApp->applicationFilePath(),QStringList());
}
