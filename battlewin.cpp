#include "battlewin.h"
#include "ui_battlewin.h"
#include "roles.h"
#include "card.h"
#include "globals.h"
#include <QString>
#include <QDebug>

BattleWin::BattleWin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BattleWin)
{
    ui->setupUi(this);
    setFixedSize(width(),height());//1193,766

    ui->ANEQUIPMENT->setVisible(false);
    ui->eqlabel->setVisible(false);


    double magicdd=(double)rand()/(double)RAND_MAX;
    if(magicdd>0.5)
    {
        ui->eqlabel->setVisible(true);
        ui->ANEQUIPMENT->setVisible(true);
    }
}

BattleWin::~BattleWin()
{
    delete ui;
}

void BattleWin::on_ACARD_clicked()
{
    double magicd=(double)rand()/(double)RAND_MAX;
    card* crd;
    if(magicd>0.94)crd=new Attack;
    else if(magicd>0.82)crd=new Heal;
    else if(magicd>0.67)crd=new Getcost;
    else if(magicd>0.52)crd=new Getcard;
    else if(magicd>0.37)crd=new DoubleAttack;
    else if(magicd>0.22)crd=new PowerAttack;
    else if(magicd>0.14)crd=new MegaDefend;
    else if(magicd>0.06)crd=new AttackDefend;
    else crd=new Manaspring;
    me->MYCARDS.push_back(crd);
    ui->ACARD->setStyleSheet(QString("QPushButton{background-image: url(:/Pictures/card%1.png);}").arg(crd->ID));
    ui->ACARD->setToolTip(crd->hint);
    ui->ACARD->setEnabled(false);
    ui->cdlabel->setText(crd->hint);
    ui->cdlabel->setAlignment(Qt::AlignCenter);
    ui->cdlabel->setWordWrap(true);
    ui->cdlabel->setFont(QFont("Microsoft YaHei",22,75));

}

void BattleWin::on_ANEQUIPMENT_clicked()
{
    double magicddd=(double)rand()/(double)RAND_MAX;
    ui->ANEQUIPMENT->setEnabled(false);
    if(magicddd>0.78947)
    {
        if(!me->EQUIPMENTS[2])
        {
            me->EQUIPMENTS[2]=true;
            ui->ANEQUIPMENT->setText(tr("GAINCOST"));
            ui->ANEQUIPMENT->setStyleSheet(tr("color: rgb(112, 48, 160);"));
            ui->eqlabel->setText(tr("魔力宝石：每回合获得MANA永久加2"));
            ui->eqlabel->setStyleSheet(tr("color: rgb(112, 48, 160);"));
            ui->eqlabel->setAlignment(Qt::AlignCenter);
            ui->eqlabel->setWordWrap(true);
            ui->eqlabel->setFont(QFont("Microsoft YaHei",22,75));
        }
        else
        {
            ui->eqlabel->setAlignment(Qt::AlignCenter);
            ui->eqlabel->setWordWrap(true);
            ui->eqlabel->setFont(QFont("Microsoft YaHei",22,75));
            ui->eqlabel->setText(tr("又是一个魔力宝石！但两个魔力宝石会让你被魔法反噬！我可不能让你这样~"));
            ui->eqlabel->setStyleSheet(tr("color: rgb(0,0,0);"));
            ui->ANEQUIPMENT->setText(tr("GAINCOST"));
            ui->ANEQUIPMENT->setStyleSheet(tr("color: rgb(0, 0, 0);"));
        }
    }
    else if(magicddd>0.52631)
    {
        if(!me->EQUIPMENTS[3])
        {
            me->EQUIPMENTS[3]=true;
            me->MAXATK+=5;
            ui->ANEQUIPMENT->setText(tr("GAINATTACK"));
            ui->ANEQUIPMENT->setStyleSheet(tr("color: rgb(0, 176, 240);"));
            ui->eqlabel->setText(tr("增幅宝珠	：ATK永久加5"));
            ui->eqlabel->setStyleSheet(tr("color: rgb(0, 176, 240);"));
            ui->eqlabel->setAlignment(Qt::AlignCenter);
            ui->eqlabel->setWordWrap(true);
            ui->eqlabel->setFont(QFont("Microsoft YaHei",22,75));
        }
        else
        {
            ui->eqlabel->setAlignment(Qt::AlignCenter);
            ui->eqlabel->setWordWrap(true);
            ui->eqlabel->setFont(QFont("Microsoft YaHei",22,75));
            ui->eqlabel->setText(tr("又是一个增幅宝珠！但是开发者不太想让你攻击过高~"));
            ui->eqlabel->setStyleSheet(tr("color: rgb(0,0,0);"));
            ui->ANEQUIPMENT->setText(tr("GAINATTACK"));
            ui->ANEQUIPMENT->setStyleSheet(tr("color: rgb(0, 0, 0);"));
        }
    }
    else if(magicddd>0.26315)
    {
        if(!me->EQUIPMENTS[4])
        {
            me->EQUIPMENTS[4]=true;
            me->MAXDEF+=2;
            ui->ANEQUIPMENT->setText(tr("GAINDEFENSE"));
            ui->ANEQUIPMENT->setStyleSheet(tr("color: rgb(0, 176, 240);"));
            ui->eqlabel->setText(tr("圣物之盾	：DEF永久加2"));
            ui->eqlabel->setStyleSheet(tr("color: rgb(0, 176, 240);"));
            ui->eqlabel->setAlignment(Qt::AlignCenter);
            ui->eqlabel->setWordWrap(true);
            ui->eqlabel->setFont(QFont("Microsoft YaHei",22,75));
        }
        else
        {
            ui->eqlabel->setAlignment(Qt::AlignCenter);
            ui->eqlabel->setWordWrap(true);
            ui->eqlabel->setFont(QFont("Microsoft YaHei",22,75));
            ui->eqlabel->setText(tr("哇！圣物之盾！等等你是不是拿过一次了？不行不行这次不给你了~"));
            ui->eqlabel->setStyleSheet(tr("color: rgb(0,0,0);"));
            ui->ANEQUIPMENT->setText(tr("GAINDEFENSE"));
            ui->ANEQUIPMENT->setStyleSheet(tr("color: rgb(0, 0, 0);"));
        }
    }
    /*else if(magicddd>0.2)
    {
        if(!me->EQUIPMENTS[5])
        {
            me->EQUIPMENTS[5]=true;
            me->COIN+=100;
            ui->ANEQUIPMENT->setText(tr("GAINCOIN"));
            ui->ANEQUIPMENT->setStyleSheet(tr("color: rgb(146, 208, 80);"));
            ui->eqlabel->setText(tr("天降的馅饼：COIN永久加100"));
            ui->eqlabel->setStyleSheet(tr("color: rgb(146, 208, 80);"));
            ui->eqlabel->setAlignment(Qt::AlignCenter);
            ui->eqlabel->setWordWrap(true);
            ui->eqlabel->setFont(QFont("Microsoft YaHei",22,75));
        }
        else
        {
            ui->eqlabel->setAlignment(Qt::AlignCenter);
            ui->eqlabel->setWordWrap(true);
            ui->eqlabel->setFont(QFont("Microsoft YaHei",22,75));
            ui->eqlabel->setText(tr("装备重复。你可不能拿两件一样的装备！"));
            ui->eqlabel->setStyleSheet(tr("color: rgb(0,0,0);"));
            ui->ANEQUIPMENT->setText(tr("emmm...抱歉！"));
            ui->ANEQUIPMENT->setStyleSheet(tr("color: rgb(0, 0, 0);"));
        }
    }*/
    else if(magicddd>0.13158)
    {
        if(!me->EQUIPMENTS[6])
        {
            me->EQUIPMENTS[6]=true;
            ui->ANEQUIPMENT->setText(tr("Rho Aias"));
            ui->ANEQUIPMENT->setStyleSheet(tr("color: rgb(226, 107, 10);"));
            ui->eqlabel->setText(tr("Rho Aias：所有受到的伤害大于等于20的单次攻击威力减少5"));
            ui->eqlabel->setStyleSheet(tr("color: rgb(226, 107, 10);"));
            ui->eqlabel->setAlignment(Qt::AlignCenter);
            ui->eqlabel->setWordWrap(true);
            ui->eqlabel->setFont(QFont("Microsoft YaHei",22,75));
        }
        else
        {
            ui->eqlabel->setAlignment(Qt::AlignCenter);
            ui->eqlabel->setWordWrap(true);
            ui->eqlabel->setFont(QFont("Microsoft YaHei",22,75));
            ui->eqlabel->setText(tr("再次，Rho Aias！但就连卫宫都做不到双重释放，你也就别想了！"));
            ui->eqlabel->setStyleSheet(tr("color: rgb(0,0,0);"));
            ui->ANEQUIPMENT->setText(tr("Rho Aias"));
            ui->ANEQUIPMENT->setStyleSheet(tr("color: rgb(0, 0, 0);"));
        }
    }
    else
    {
        if(!me->EQUIPMENTS[7])
        {
            me->EQUIPMENTS[7]=true;
            ui->ANEQUIPMENT->setText(tr("DAGGER"));
            ui->ANEQUIPMENT->setStyleSheet(tr("color: rgb(226, 107, 10);"));
            ui->eqlabel->setText(tr("影之匕首：所有打出的威力大于等于24的单次攻击威力增加8"));
            ui->eqlabel->setStyleSheet(tr("color: rgb(226, 107, 10);"));
            ui->eqlabel->setAlignment(Qt::AlignCenter);
            ui->eqlabel->setWordWrap(true);
            ui->eqlabel->setFont(QFont("Microsoft YaHei",22,75));
        }
        else
        {
            ui->eqlabel->setAlignment(Qt::AlignCenter);
            ui->eqlabel->setWordWrap(true);
            ui->eqlabel->setFont(QFont("Microsoft YaHei",22,75));
            ui->eqlabel->setText(tr("再来一把影之匕首！影之双刀！开个玩笑~"));
            ui->eqlabel->setStyleSheet(tr("color: rgb(0,0,0);"));
            ui->ANEQUIPMENT->setText(tr("DAGGER"));
            ui->ANEQUIPMENT->setStyleSheet(tr("color: rgb(0, 0, 0);"));
        }
    }
}

void BattleWin::on_skippart_clicked()
{
    if(me->EQUIPMENTS[1])
    {
        me->MAXHP+=5;
    }
    delete enemy;
    close();
    if(mapnum==1){map->eqini();map->show();}
    else if(mapnum==2){map2->eqini();map2->show();}
    else if(mapnum==3){map3->eqini();map3->show();}
}
