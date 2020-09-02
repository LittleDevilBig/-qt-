#include "guide.h"
#include "ui_guide.h"
#include "globals.h"
Guide::Guide(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Guide)
{
    ui->setupUi(this);
    setFixedSize(width(),height());//1193,766
    ui->end->setVisible(false);
    setAutoFillBackground(true);
    QPalette backg=this->palette();
    backg.setBrush(QPalette::Window,QBrush(QPixmap("://Pictures/instruction1.png").scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    this->setPalette(backg);
}

Guide::~Guide()
{
    delete ui;
}

void Guide::on_next_clicked()
{
    ui->next->setVisible(false);
    ui->end->setVisible(true);
    QPalette backg=this->palette();
    backg.setBrush(QPalette::Window,QBrush(QPixmap("://Pictures/instruction2.png").scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    this->setPalette(backg);
}

void Guide::on_end_clicked()
{
    close();
    w->show();
}
