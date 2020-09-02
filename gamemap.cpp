#include "gamemap.h"
#include "ui_gamemap.h"
#include "globals.h"
#include "battle.h"
#include "gamemap2.h"
#include "qstring.h"
Gamemap::Gamemap(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Gamemap)
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
    ui->BattleArthas->setEnabled(false);
    ui->BattleEyeofCthulu->setEnabled(false);
    ui->BattleMachine->setEnabled(false);
    ui->BattleMushroom->setEnabled(false);
    ui->BattleSkeleton->setEnabled(false);
    ui->Battle_11451481019->setEnabled(false);
    ui->nextmap->setVisible(false);
    eqini();
}

void Gamemap::eqini()
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

Gamemap::~Gamemap()
{
    delete ui;
}

void Gamemap::on_Battle1_clicked()
{
    enemy=new Slime;
    close();
    ui->BattleSkeleton->setEnabled(true);
    ui->BattleMushroom->setEnabled(true);
    ui->Battle1->setEnabled(false);
    Battle* battlepage_1=new Battle;
    battlepage_1->show();
}

void Gamemap::on_BattleSkeleton_clicked()
{
    enemy=new Skeleton;
    close();
    ui->BattleEyeofCthulu->setEnabled(true);
    ui->BattleMushroom->setEnabled(false);
    ui->BattleSkeleton->setEnabled(false);
    Battle* battlepage_Skeleton=new Battle;
    battlepage_Skeleton->show();
}

void Gamemap::on_BattleMushroom_clicked()
{
    enemy=new Mushroom;
    close();
    ui->BattleMushroom->setEnabled(false);
    ui->BattleSkeleton->setEnabled(false);
    ui->BattleMachine->setEnabled(true);
    ui->BattleArthas->setEnabled(true);
    Battle* battlepage_Mushroom=new Battle;
    battlepage_Mushroom->show();
}

void Gamemap::on_BattleEyeofCthulu_clicked()
{
    enemy=new EyeofCthulu;
    close();
    ui->BattleEyeofCthulu->setEnabled(false);
    ui->Battle_11451481019->setEnabled(true);
    Battle* battlepage_EyeofCthulu=new Battle;
    battlepage_EyeofCthulu->show();
}

void Gamemap::on_BattleMachine_clicked()
{
    enemy=new Machine;
    close();
    ui->BattleMachine->setEnabled(false);
    ui->BattleArthas->setEnabled(false);
    ui->Battle_11451481019->setEnabled(true);
    Battle* battlepage_Machine=new Battle;
    battlepage_Machine->show();
}

void Gamemap::on_Battle_11451481019_clicked()
{
    enemy=new _11451481019;
    close();
    ui->Battle_11451481019->setEnabled(false);
    ui->BattleArthas->setEnabled(true);
    Battle* battlepage__11451481019=new Battle;
    battlepage__11451481019->show();
}

void Gamemap::on_BattleArthas_clicked()
{
    enemy=new Arthas;
    close();
    ui->BattleArthas->setEnabled(false);
    ui->BattleMachine->setEnabled(false);
    ui->nextmap->setVisible(true);
    Battle* battlepage_Arthas=new Battle;
    battlepage_Arthas->show();
}

void Gamemap::on_nextmap_clicked()
{
    map2=new gamemap2;
    mapnum=2;
    close();
    map2->show();
}
