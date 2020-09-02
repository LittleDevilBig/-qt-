#include "gamemap2.h"
#include "ui_gamemap2.h"
#include "globals.h"
#include "battle.h"
#include <qstring.h>

gamemap2::gamemap2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gamemap2)
{
    ui->setupUi(this);
    setFixedSize(width(),height());//1193,766
    ui->Egainattack->setPixmap(QPixmap(QString("://Pictures/gainatk.png")).scaled(ui->Egainattack->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    ui->Egaindefense->setPixmap(QPixmap(QString("://Pictures/gaindef.png")).scaled(ui->Egaindefense->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    ui->Egaincard->setPixmap(QPixmap(QString("://Pictures/gaincard.png")).scaled(ui->Egaincard->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    ui->Egaincost->setPixmap(QPixmap(QString("://Pictures/gaincost.png")).scaled(ui->Egaincost->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    ui->Egainlife->setPixmap(QPixmap(QString("://Pictures/gainlife.png")).scaled(ui->Egainlife->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    ui->ERhoAias->setPixmap(QPixmap(QString("://Pictures/rhoaias.png")).scaled(ui->ERhoAias->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    ui->EDagger->setPixmap(QPixmap(QString("://Pictures/dagger.png")).scaled(ui->EDagger->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    ui->BattleSlime->setEnabled(false);
    ui->BattleSteves->setEnabled(false);
    ui->BattleArthas->setEnabled(false);
    ui->BattleEyeofCthulu->setEnabled(false);
    ui->BattleMachine->setEnabled(false);
    ui->BattleMushroom->setEnabled(false);
    ui->Battle_11451481019->setEnabled(false);
    ui->nextmap->setVisible(false);
    eqini();
}

void gamemap2::eqini()
{
    if(me->EQUIPMENTS[1])ui->Egainlife->setVisible(true);
    else ui->Egainlife->setVisible(false);
    if(me->EQUIPMENTS[2])ui->Egaincost->setVisible(true);
    else ui->Egaincost->setVisible(false);
    if(me->EQUIPMENTS[3])ui->Egainattack->setVisible(true);
    else ui->Egainattack->setVisible(false);
    if(me->EQUIPMENTS[4])ui->Egaindefense->setVisible(true);
    else ui->Egaindefense->setVisible(false);
    if(me->EQUIPMENTS[6])ui->ERhoAias->setVisible(true);
    else ui->ERhoAias->setVisible(false);
    if(me->EQUIPMENTS[7])ui->EDagger->setVisible(true);
    else ui->EDagger->setVisible(false);
    if(me->EQUIPMENTS[8])ui->Egaincard->setVisible(true);
    else ui->Egaincard->setVisible(false);
}

gamemap2::~gamemap2()
{
    delete ui;
}

void gamemap2::on_BattleSkeleton_clicked()
{
    enemy=new Skeleton;
    close();
    ui->BattleSkeleton->setEnabled(false);
    ui->BattleMushroom->setEnabled(true);
    ui->BattleMachine->setEnabled(true);
    Battle* gamepage=new Battle;
    gamepage->show();
}

void gamemap2::on_BattleMushroom_clicked()
{
    enemy=new Mushroom;
    close();
    ui->BattleMushroom->setEnabled(false);
    ui->BattleMachine->setEnabled(false);
    ui->BattleEyeofCthulu->setEnabled(true);
    ui->BattleSlime->setEnabled(true);
    Battle* gamepage=new Battle;
    gamepage->show();
}

void gamemap2::on_BattleMachine_clicked()
{
    enemy=new Machine;
    close();
    ui->BattleMachine->setEnabled(false);
    ui->BattleMushroom->setEnabled(false);
    ui->BattleArthas->setEnabled(true);
    Battle* gamepage=new Battle;
    gamepage->show();
}

void gamemap2::on_BattleSlime_clicked()
{
    enemy=new Slime;
    close();
    ui->BattleSlime->setEnabled(false);
    ui->BattleEyeofCthulu->setEnabled(false);
    ui->BattleArthas->setEnabled(true);
    Battle* gamepage=new Battle;
    gamepage->show();
}

void gamemap2::on_BattleArthas_clicked()
{
    enemy=new Arthas;
    close();
    ui->BattleArthas->setEnabled(false);
    ui->BattleEyeofCthulu->setEnabled(true);
    Battle* gamepage=new Battle;
    gamepage->show();
}

void gamemap2::on_BattleEyeofCthulu_clicked()
{
    enemy=new EyeofCthulu;
    close();
    ui->BattleEyeofCthulu->setEnabled(false);
    ui->BattleSteves->setEnabled(true);
    ui->Battle_11451481019->setEnabled(true);
    ui->BattleSlime->setEnabled(false);
    Battle* gamepage=new Battle;
    gamepage->show();
}

void gamemap2::on_Battle_11451481019_clicked()
{
    enemy=new _11451481019;
    close();
    ui->Battle_11451481019->setEnabled(false);
    Battle* gamepage=new Battle;
    gamepage->show();
}

void gamemap2::on_BattleSteves_clicked()
{
    enemy=new Steves;
    close();
    ui->Battle_11451481019->setEnabled(false);
    ui->BattleSteves->setEnabled(false);
    ui->nextmap->setVisible(true);
    Battle* gamepage=new Battle;
    gamepage->show();
}

void gamemap2::on_nextmap_clicked()
{
    map3=new gamemap3;
    mapnum=3;
    close();
    map3->show();
}
