#include "selecthero.h"
#include "ui_selecthero.h"
#include "globals.h"
SelectHero::SelectHero(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SelectHero)
{
    ui->setupUi(this);
    setFixedSize(width(),height());//1193,766

    setAutoFillBackground(true);
    QPalette backg=this->palette();
    backg.setBrush(QPalette::Window,QBrush(QPixmap("://Pictures/select.png").scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    this->setPalette(backg);
}

SelectHero::~SelectHero()
{
    delete ui;
}
void SelectHero::on_SelectWarrior_clicked()
{
    close();
    me=new Warrior;
    enemy=NULL;
    map=new Gamemap;
    mapnum=1;
    map->show();
}

void SelectHero::on_SelectWizard_clicked()
{
    close();
    me=new Wizard;
    enemy=NULL;
    map=new Gamemap;
    mapnum=1;
    map->show();
}
