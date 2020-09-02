#include "gamemap3.h"
#include "ui_gamemap3.h"
#include "globals.h"
#include "battle.h"
#include "finalwin.h"
#include <qstring.h>

gamemap3::gamemap3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gamemap3)
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
    ui->BattleEnder_Dragon->setEnabled(false);
    ui->BattleMoon_Lord->setEnabled(false);
    ui->BattleNo_99->setEnabled(false);
    ui->BattlePony->setEnabled(false);
    ui->BattleSteves->setEnabled(false);
    ui->BattleUSS_Enterprise->setEnabled(false);
    ui->WinGame->setVisible(false);
    eqini();
}

void gamemap3::eqini()
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

gamemap3::~gamemap3()
{
    delete ui;
}

void gamemap3::on_BattleGilgamesh_clicked()
{
    enemy=new Gilgamesh;
    close();
    ui->BattleGilgamesh->setEnabled(false);
    ui->BattleArthas->setEnabled(true);
    ui->BattleSteves->setEnabled(true);
    Battle* gamepage=new Battle;
    gamepage->show();
}

void gamemap3::on_BattleArthas_clicked()
{
    enemy=new Arthas;
    close();
    ui->BattleArthas->setEnabled(false);
    ui->BattleSteves->setEnabled(false);
    ui->BattlePony->setEnabled(true);
    Battle* gamepage=new Battle;
    gamepage->show();
}

void gamemap3::on_BattleSteves_clicked()
{
    enemy=new Steves;
    close();
    ui->BattleArthas->setEnabled(false);
    ui->BattleSteves->setEnabled(false);
    ui->BattleNo_99->setEnabled(true);
    Battle* gamepage=new Battle;
    gamepage->show();
}

void gamemap3::on_BattlePony_clicked()
{
    enemy=new Pony;
    close();
    ui->BattlePony->setEnabled(false);
    ui->BattleUSS_Enterprise->setEnabled(true);
    Battle* gamepage=new Battle;
    gamepage->show();
}

void gamemap3::on_BattleUSS_Enterprise_clicked()
{
    enemy=new USS_Enterprise;
    close();
    ui->BattleUSS_Enterprise->setEnabled(false);
    ui->BattleMoon_Lord->setEnabled(true);
    ui->BattleNo_99->setEnabled(true);
    Battle* gamepage=new Battle;
    gamepage->show();
}

void gamemap3::on_BattleNo_99_clicked()
{
    enemy=new No_99;
    close();
    ui->BattleEnder_Dragon->setEnabled(true);
    ui->BattleMoon_Lord->setEnabled(false);
    ui->BattleNo_99->setEnabled(false);
    Battle* gamepage=new Battle;
    gamepage->show();
}

void gamemap3::on_BattleMoon_Lord_clicked()
{
    enemy=new Moon_Lord;
    close();
    ui->BattleEnder_Dragon->setEnabled(true);
    ui->BattleMoon_Lord->setEnabled(false);
    ui->BattleNo_99->setEnabled(false);
    Battle* gamepage=new Battle;
    gamepage->show();
}

void gamemap3::on_BattleEnder_Dragon_clicked()
{
    enemy=new Ender_Dragon;
    close();
    ui->BattleEnder_Dragon->setEnabled(false);
    ui->WinGame->setVisible(true);
    Battle* gamepage=new Battle;
    gamepage->show();
}

void gamemap3::on_WinGame_clicked()
{
    FinalWin* fnl=new FinalWin;
    close();
    fnl->show();
}
