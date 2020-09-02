#include "mainpage.h"
#include "ui_mainpage.h"
#include "finalwin.h"
#include "guide.h"

MainPage::MainPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainPage)
{
    ui->setupUi(this);
    setFixedSize(width(),height());//1193,766

    setAutoFillBackground(true);
    QPalette backg=this->palette();
    backg.setBrush(QPalette::Window,QBrush(QPixmap("://Pictures/MainPageBG.png").scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    this->setPalette(backg);

}

MainPage::~MainPage()
{
    delete ui;
}

void MainPage::on_Startgame_clicked()
{
    close();
    SelectHero* sh=new SelectHero;
    sh->show();
}

void MainPage::on_Guide_clicked()
{
    close();
    Guide* gd=new Guide;
    gd->show();
}
