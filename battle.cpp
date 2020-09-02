#include "battle.h"
#include "ui_battle.h"
#include "globals.h"
#include <qstring.h>
#include <QMessageBox>
#include "battlefailed.h"
#include "battlewin.h"
#include <QDebug>
int rnd;
QPushButton* Hand[11];

void cardset()//put handcards into buttons
{
    for(int i=0;i<me->HANDCARDS.size();i++)
    {
        if(me->HANDCARDS[i]!=NULL)
        {
            QString sse=QString("QPushButton{background-image: url(:/Pictures/card%1.png);}"
                                /*"QPushButton:hover{background-color:white; color: black;}"*/
                                /*"QPushButton:pressed{border-style: inset; }"*/).arg(me->HANDCARDS[i]->ID);
            Hand[i+1]->setStyleSheet(sse);
            Hand[i+1]->setToolTip(me->HANDCARDS[i]->hint);
            Hand[i+1]->setVisible(true);
            Hand[i+1]->setEnabled(true);
            Hand[i+1]->setText(QString(""));
        }
        else Hand[i+1]->setVisible(false);
    }
    for(int i=me->HANDCARDS.size();i<10;i++)Hand[i+1]->setVisible(false);
    qDebug()<<"MYCARDS |";for(int i=0;i<me->MYCARDS.size();i++)qDebug()<<me->MYCARDS[i]->hint;
    //qDebug()<<"CARDS |";for(int i=0;i<me->CARDS.size();i++)qDebug()<<me->CARDS[i]->ID<<"|";
    qDebug()<<"handCARDS |";for(int i=0;i<me->HANDCARDS.size();i++)qDebug()<<me->HANDCARDS[i]->hint;
}

Battle::Battle(QWidget *parent) :QWidget(parent),ui(new Ui::Battle)
{
    ui->setupUi(this);
//=======================BASIC THINGS=======================
    setFixedSize(width(),height());//1193,766

    setAutoFillBackground(true);
    QPalette backg=this->palette();
    QString dir=QString("://Pictures/%1-background.png").arg(enemy->ID);
    backg.setBrush(QPalette::Window,QBrush(QPixmap(dir).scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    this->setPalette(backg);

    ui->defflag->setPixmap(QPixmap(QString("://Pictures/defendbig.png")).scaled(ui->defflag->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    ui->edefflag->setPixmap(QPixmap(QString("://Pictures/defendsml.png")).scaled(ui->edefflag->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

    ui->Egainattack->setPixmap(QPixmap(QString("://Pictures/gainatk.png")).scaled(ui->Egainattack->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    ui->Egaindefense->setPixmap(QPixmap(QString("://Pictures/gaindef.png")).scaled(ui->Egaindefense->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    ui->Egaincard->setPixmap(QPixmap(QString("://Pictures/gaincard.png")).scaled(ui->Egaincard->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    ui->Egaincost->setPixmap(QPixmap(QString("://Pictures/gaincost.png")).scaled(ui->Egaincost->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    ui->Egainlife->setPixmap(QPixmap(QString("://Pictures/gainlife.png")).scaled(ui->Egainlife->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    ui->ERhoAias->setPixmap(QPixmap(QString("://Pictures/rhoaias.png")).scaled(ui->ERhoAias->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    ui->EDagger->setPixmap(QPixmap(QString("://Pictures/dagger.png")).scaled(ui->EDagger->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

    ui->enemyimage->setToolTip(enemy->information);

    if(me->EQUIPMENTS[1])
    {
        ui->meimage->setStyleSheet(tr("background-image: url(:/Pictures/Warrior1.png);"));
    }
    else
    {
        ui->meimage->setStyleSheet(tr("background-image: url(:/Pictures/Wizard1.png);"));
    }
    ui->enemyimage->setPixmap(QPixmap(QString("://Pictures/%1-Monster.png").arg(enemy->ID)).scaled(ui->enemyimage->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    ui->round->setAlignment(Qt::AlignRight);
    ui->eatk->setAlignment(Qt::AlignRight);
    ui->edef->setAlignment(Qt::AlignRight);
    ui->atk->setAlignment(Qt::AlignRight);
    ui->def->setAlignment(Qt::AlignRight);
    ui->mana->setAlignment(Qt::AlignRight);
    ui->attempt->setAlignment(Qt::AlignRight);
//=======================EASY BUTTON CALL=======================
    Hand[1]=ui->Handcard1;
    Hand[2]=ui->Handcard2;
    Hand[3]=ui->Handcard3;
    Hand[4]=ui->Handcard4;
    Hand[5]=ui->Handcard5;
    Hand[6]=ui->Handcard6;
    Hand[7]=ui->Handcard7;
    Hand[8]=ui->Handcard8;
    Hand[9]=ui->Handcard9;
    Hand[10]=ui->Handcard10;
//=======================INITIALIZING DATA=======================

    me->DEF=me->MAXDEF;
    me->HP=me->MAXHP;
    me->ATK=me->MAXATK;
    if(me->EQUIPMENTS[2])me->COST=me->MAXCOST+2;
    else me->COST=me->MAXCOST;



//=======================FIRST PLANNING CARDS=======================
    me->CARDROLL();
    if(me->EQUIPMENTS[8])me->FETCHCARDS(me->CARDNUM+1);
    else me->FETCHCARDS(me->CARDNUM);
    cardset();

//=======================INI. FLAGS=======================
    me->DEFFLAG=false;
    if(enemy->roundskill[1]==2||enemy->roundskill[1]==4||enemy->roundskill[1]==5)
    {
        enemy->DEFFLAG=true;
    }
    else enemy->DEFFLAG=false;
    me->FLAG_CARD_10=false;
    me->FLAG_SLEEP=0;
    me->FLAG_MONSTER_6=false;
    me->FLAG_MONSTER_7=false;
    enemy->ESCAPE=0;
    me->FLAG_CARD_5=0;
//=======================INITIALIZING TEXTS=======================
    rnd=1;
    ui->sleep->setVisible(false);
    ui->absorbed->setVisible(false);
    ui->horror->setVisible(false);
    this->labelini();
}

void Battle::labelini()
{
    ui->round->setText(QString("%1").arg(rnd));
    ui->atk->setText(QString("%1").arg(me->ATK));
    ui->def->setText(QString("%1").arg(me->DEF));
    ui->mana->setText(QString("%1").arg(me->COST));
    ui->eatk->setText(QString("%1×%2").arg(enemy->TIME).arg(enemy->ATK));
    ui->edef->setText(QString("%1").arg(enemy->DEF));
    ui->mehp->setMaximum(me->MAXHP);
    ui->enemyhp->setMaximum(enemy->MAXHP);
    if(me->DEFFLAG)ui->defflag->setVisible(true);
    else ui->defflag->setVisible(false);
    if(enemy->DEFFLAG)ui->edefflag->setVisible(true);
    else ui->edefflag->setVisible(false);

    if(enemy->ESCAPE)ui->escape->setVisible(true);
    else ui->escape->setVisible(false);
    if(me->HP>0)ui->mehp->setValue(me->HP);
    else ui->mehp->setValue(0);
    if(enemy->HP>0)ui->enemyhp->setValue(enemy->HP);
    else ui->enemyhp->setValue(0);

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

    if(enemy->ID==14&&enemy->FLAG_MONSTER_14!=-2)ui->passive->setVisible(true);
    else ui->passive->setVisible(false);

    if(enemy->ID!=8)
    {
        if(enemy->roundskill[rnd%6]==1)
        {
            ui->attempt->setText(tr("ATTACK"));
            ui->attempt->setToolTip(tr("对你进行攻击"));
        }
        else if(enemy->roundskill[rnd%6]==2)
        {
            ui->attempt->setText(tr("DEFEND"));
            ui->attempt->setToolTip(tr("集中精神防御"));
        }
        else if(enemy->roundskill[rnd%6]==3)
        {
            ui->attempt->setText(tr("SKILL"));
            ui->attempt->setToolTip(QString("使用特殊技能——")+enemy->skillhint);
        }
    }
    else
    {
        if((enemy->HP<=80&&enemy->FLAG_MONSTER_8==1)||(enemy->HP<=80&&enemy->FLAG_MONSTER_8==2))
        {
            ui->attempt->setText(tr("??????"));
            ui->attempt->setToolTip(tr("?????????????"));
        }
        else
        {
            if(enemy->HP>120)
            {
                if(enemy->roundskill[rnd%6]==1)
                {
                    ui->attempt->setText(tr("ATTACK"));
                    ui->attempt->setToolTip(tr("对你进行攻击"));
                }
                else if(enemy->roundskill[rnd%6]==2)
                {
                    ui->attempt->setText(tr("DEFEND"));
                    ui->attempt->setToolTip(tr("集中精神防御"));
                }
                else if(enemy->roundskill[rnd%6]==3)
                {
                    ui->attempt->setText(tr("SKILL"));
                    ui->attempt->setToolTip(QString("使用特殊技能——全能玩家：进攻同时防御"));
                }
            }
            else if(enemy->HP>80)
            {
                ui->attempt->setText(tr("INVENT"));
                ui->enemyimage->setPixmap(QPixmap(QString("://Pictures/%1-Monster.png").arg(enemy->ID+1)).scaled(ui->enemyimage->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

                setAutoFillBackground(true);
                QPalette backg=this->palette();
                QString dir=QString("://Pictures/%1-background.png").arg(enemy->ID+1);
                backg.setBrush(QPalette::Window,QBrush(QPixmap(dir).scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
                this->setPalette(backg);

                ui->attempt->setToolTip(QString("使用特殊技能——创世纪发明家：对方麻痹两回合，自身HP下降40"));
            }
            else
            {
                if(enemy->roundskill[rnd%6]==1)
                {
                    ui->attempt->setText(tr("ATTACK"));
                    ui->attempt->setToolTip(tr("对你进行攻击"));
                }
                else if(enemy->roundskill[rnd%6]==2)
                {
                    ui->attempt->setText(tr("DEFEND"));
                    ui->attempt->setToolTip(tr("集中精神防御"));
                }
                else if(enemy->roundskill[rnd%6]==3)
                {
                    ui->attempt->setText(tr("SKILL"));
                    ui->attempt->setToolTip(QString("使用特殊技能——锁头一击：史蒂夫拿出祖传的AWM并使用锁头挂打出致命一击,本回合ATK上升25，攻击造成1.5倍伤害"));
                }
            }
        }
    }

}

Battle::~Battle()
{
    delete ui;
}

void Battle::on_Handcard1_clicked()
{
    int originalhp=enemy->HP;
    if(me->HANDCARDS[0]->use(*me,*enemy,0))
    {
        ui->Handcard1->setEnabled(false);
        ui->Handcard1->setText("USED");
        if(enemy->HP<originalhp)
        {
            if(enemy->ESCAPE>0)
            {
                enemy->HP=originalhp;
                //<MISSANIMATION>
            }
            else
            {
                //<HITANIMATION>
            }
        }
        this->labelini();
        me->CARDS.push(me->HANDCARDS[0]);
        me->HANDCARDS[0]=NULL;
        if(me->DIE())
        {
            BattleFailed* btfd=new BattleFailed;
            close();
            btfd->show();
        }
        if(enemy->DIE())
        {
            for(int i=0;i<me->HANDCARDS.size();i++)if(me->HANDCARDS[i])me->CARDS.push(me->HANDCARDS[i]);
            me->HANDCARDS.clear();
            if(enemy->ID==11)
            {
                QMessageBox::about(this,tr("遗言"),tr("From吉尔伽美什：\n现在是你更强"));
            }
            BattleWin* btwn=new BattleWin;
            close();
            btwn->show();
        }
    }
    else QMessageBox::about(this,tr("OOPS"),tr("NO ENOUGH MANA!"));
}

void Battle::on_Handcard2_clicked()
{
    int originalhp=enemy->HP;
    if(me->HANDCARDS[1]->use(*me,*enemy,1))
    {
        ui->Handcard2->setEnabled(false);
        ui->Handcard2->setText("USED");
        if(enemy->HP<originalhp)
        {
            if(enemy->ESCAPE>0)
            {
                enemy->HP=originalhp;
                //<MISSANIMATION>
            }
            else
            {
                //<HITANIMATION>
            }
        }
        this->labelini();
        me->CARDS.push(me->HANDCARDS[1]);
        me->HANDCARDS[1]=NULL;
        if(me->DIE())
        {
            BattleFailed* btfd=new BattleFailed;
            close();
            btfd->show();
        }
        if(enemy->DIE())
        {
            for(int i=0;i<me->HANDCARDS.size();i++)if(me->HANDCARDS[i])me->CARDS.push(me->HANDCARDS[i]);
            me->HANDCARDS.clear();
            if(enemy->ID==11)
            {
                QMessageBox::about(this,tr("遗言"),tr("From吉尔伽美什：\n现在是你更强"));
            }
            BattleWin* btwn=new BattleWin;
            close();
            btwn->show();
        }
    }
    else QMessageBox::about(this,tr("OOPS"),tr("NO ENOUGH MANA!"));
}

void Battle::on_Handcard3_clicked()
{
    int originalhp=enemy->HP;
    if(me->HANDCARDS[2]->use(*me,*enemy,2))
    {
        ui->Handcard3->setEnabled(false);
        ui->Handcard3->setText("USED");
        if(enemy->HP<originalhp)
        {
            if(enemy->ESCAPE>0)
            {
                enemy->HP=originalhp;
                //<MISSANIMATION>
            }
            else
            {
                //<HITANIMATION>
            }
        }
        this->labelini();
        me->CARDS.push(me->HANDCARDS[2]);
        me->HANDCARDS[2]=NULL;
        if(me->DIE())
        {
            BattleFailed* btfd=new BattleFailed;
            close();
            btfd->show();
        }
        if(enemy->DIE())
        {
            for(int i=0;i<me->HANDCARDS.size();i++)if(me->HANDCARDS[i])me->CARDS.push(me->HANDCARDS[i]);
            me->HANDCARDS.clear();
            if(enemy->ID==11)
            {
                QMessageBox::about(this,tr("遗言"),tr("From吉尔伽美什：\n现在是你更强"));
            }
            BattleWin* btwn=new BattleWin;
            close();
            btwn->show();
        }
    }
    else QMessageBox::about(this,tr("OOPS"),tr("NO ENOUGH MANA!"));
}

void Battle::on_Handcard4_clicked()
{
    int originalhp=enemy->HP;
    if(me->HANDCARDS[3]->use(*me,*enemy,3))
    {
        ui->Handcard4->setEnabled(false);
        ui->Handcard4->setText("USED");
        if(enemy->HP<originalhp)
        {
            if(enemy->ESCAPE>0)
            {
                enemy->HP=originalhp;
                //<MISSANIMATION>
            }
            else
            {
                //<HITANIMATION>
            }
        }
        this->labelini();
        me->CARDS.push(me->HANDCARDS[3]);
        me->HANDCARDS[3]=NULL;
        if(me->DIE())
        {
            BattleFailed* btfd=new BattleFailed;
            close();
            btfd->show();
        }
        if(enemy->DIE())
        {
            for(int i=0;i<me->HANDCARDS.size();i++)if(me->HANDCARDS[i])me->CARDS.push(me->HANDCARDS[i]);
            me->HANDCARDS.clear();
            if(enemy->ID==11)
            {
                QMessageBox::about(this,tr("遗言"),tr("From吉尔伽美什：\n现在是你更强"));
            }
            BattleWin* btwn=new BattleWin;
            close();
            btwn->show();
        }
    }
    else QMessageBox::about(this,tr("OOPS"),tr("NO ENOUGH MANA!"));
}

void Battle::on_Handcard5_clicked()
{
    int originalhp=enemy->HP;
    if(me->HANDCARDS[4]->use(*me,*enemy,4))
    {
        ui->Handcard5->setEnabled(false);
        ui->Handcard5->setText("USED");
        if(enemy->HP<originalhp)
        {
            if(enemy->ESCAPE>0)
            {
                enemy->HP=originalhp;
                //<MISSANIMATION>
            }
            else
            {
                //<HITANIMATION>
            }
        }
        this->labelini();
        me->CARDS.push(me->HANDCARDS[4]);
        me->HANDCARDS[4]=NULL;
        if(me->DIE())
        {
            BattleFailed* btfd=new BattleFailed;
            close();
            btfd->show();
        }
        if(enemy->DIE())
        {
            for(int i=0;i<me->HANDCARDS.size();i++)if(me->HANDCARDS[i])me->CARDS.push(me->HANDCARDS[i]);
            me->HANDCARDS.clear();
            if(enemy->ID==11)
            {
                QMessageBox::about(this,tr("遗言"),tr("From吉尔伽美什：\n现在是你更强"));
            }
            BattleWin* btwn=new BattleWin;
            close();
            btwn->show();
        }
    }
    else QMessageBox::about(this,tr("OOPS"),tr("NO ENOUGH MANA!"));
}

void Battle::on_Handcard6_clicked()
{
    int originalhp=enemy->HP;
    if(me->HANDCARDS[5]->use(*me,*enemy,5))
    {
        ui->Handcard6->setEnabled(false);
        ui->Handcard6->setText("USED");
        if(enemy->HP<originalhp)
        {
            if(enemy->ESCAPE>0)
            {
                enemy->HP=originalhp;
                //<MISSANIMATION>
            }
            else
            {
                //<HITANIMATION>
            }
        }
        this->labelini();
        me->CARDS.push(me->HANDCARDS[5]);
        me->HANDCARDS[5]=NULL;
        if(me->DIE())
        {
            BattleFailed* btfd=new BattleFailed;
            close();
            btfd->show();
        }
        if(enemy->DIE())
        {
            for(int i=0;i<me->HANDCARDS.size();i++)if(me->HANDCARDS[i])me->CARDS.push(me->HANDCARDS[i]);
            me->HANDCARDS.clear();
            if(enemy->ID==11)
            {
                QMessageBox::about(this,tr("遗言"),tr("From吉尔伽美什：\n现在是你更强"));
            }
            BattleWin* btwn=new BattleWin;
            close();
            btwn->show();
        }
    }
    else QMessageBox::about(this,tr("OOPS"),tr("NO ENOUGH MANA!"));
}

void Battle::on_Handcard7_clicked()
{
    int originalhp=enemy->HP;
    if(me->HANDCARDS[6]->use(*me,*enemy,6))
    {
        ui->Handcard7->setEnabled(false);
        ui->Handcard7->setText("USED");
        if(enemy->HP<originalhp)
        {
            if(enemy->ESCAPE>0)
            {
                enemy->HP=originalhp;
                //<MISSANIMATION>
            }
            else
            {
                //<HITANIMATION>
            }
        }
        this->labelini();
        me->CARDS.push(me->HANDCARDS[6]);
        me->HANDCARDS[6]=NULL;
        if(me->DIE())
        {
            BattleFailed* btfd=new BattleFailed;
            close();
            btfd->show();
        }
        if(enemy->DIE())
        {
            for(int i=0;i<me->HANDCARDS.size();i++)if(me->HANDCARDS[i])me->CARDS.push(me->HANDCARDS[i]);
            me->HANDCARDS.clear();
            if(enemy->ID==11)
            {
                QMessageBox::about(this,tr("遗言"),tr("From吉尔伽美什：\n现在是你更强"));
            }
            BattleWin* btwn=new BattleWin;
            close();
            btwn->show();
        }
    }
    else QMessageBox::about(this,tr("OOPS"),tr("NO ENOUGH MANA!"));
}

void Battle::on_Handcard8_clicked()
{
    int originalhp=enemy->HP;
    if(me->HANDCARDS[7]->use(*me,*enemy,7))
    {
        ui->Handcard8->setEnabled(false);
        ui->Handcard8->setText("USED");
        if(enemy->HP<originalhp)
        {
            if(enemy->ESCAPE>0)
            {
                enemy->HP=originalhp;
                //<MISSANIMATION>
            }
            else
            {
                //<HITANIMATION>
            }
        }
        this->labelini();
        me->CARDS.push(me->HANDCARDS[7]);
        me->HANDCARDS[7]=NULL;
        if(me->DIE())
        {
            BattleFailed* btfd=new BattleFailed;
            close();
            btfd->show();
        }
        if(enemy->DIE())
        {
            for(int i=0;i<me->HANDCARDS.size();i++)if(me->HANDCARDS[i])me->CARDS.push(me->HANDCARDS[i]);
            me->HANDCARDS.clear();
            if(enemy->ID==11)
            {
                QMessageBox::about(this,tr("遗言"),tr("From吉尔伽美什：\n现在是你更强"));
            }
            BattleWin* btwn=new BattleWin;
            close();
            btwn->show();
        }
    }
    else QMessageBox::about(this,tr("OOPS"),tr("NO ENOUGH MANA!"));
}

void Battle::on_Handcard9_clicked()
{
    int originalhp=enemy->HP;
    if(me->HANDCARDS[8]->use(*me,*enemy,8))
    {
        ui->Handcard9->setEnabled(false);
        ui->Handcard9->setText("USED");
        if(enemy->HP<originalhp)
        {
            if(enemy->ESCAPE>0)
            {
                enemy->HP=originalhp;
                //<MISSANIMATION>
            }
            else
            {
                //<HITANIMATION>
            }
        }
        this->labelini();
        me->CARDS.push(me->HANDCARDS[8]);
        me->HANDCARDS[8]=NULL;
        if(me->DIE())
        {
            BattleFailed* btfd=new BattleFailed;
            close();
            btfd->show();
        }
        if(enemy->DIE())
        {
            for(int i=0;i<me->HANDCARDS.size();i++)if(me->HANDCARDS[i])me->CARDS.push(me->HANDCARDS[i]);
            me->HANDCARDS.clear();
            if(enemy->ID==11)
            {
                QMessageBox::about(this,tr("遗言"),tr("From吉尔伽美什：\n现在是你更强"));
            }
            BattleWin* btwn=new BattleWin;
            close();
            btwn->show();
        }
    }
    else QMessageBox::about(this,tr("OOPS"),tr("NO ENOUGH MANA!"));
}

void Battle::on_Handcard10_clicked()
{
    int originalhp=enemy->HP;
    if(me->HANDCARDS[9]->use(*me,*enemy,9))
    {
        ui->Handcard10->setEnabled(false);
        ui->Handcard10->setText("USED");
        if(enemy->HP<originalhp)
        {
            if(enemy->ESCAPE>0)
            {
                enemy->HP=originalhp;
                //<MISSANIMATION>
            }
            else
            {
                //<HITANIMATION>
            }
        }
        this->labelini();
        me->CARDS.push(me->HANDCARDS[9]);
        me->HANDCARDS[9]=NULL;
        if(me->DIE())
        {
            BattleFailed* btfd=new BattleFailed;
            close();
            btfd->show();
        }
        if(enemy->DIE())
        {
            for(int i=0;i<me->HANDCARDS.size();i++)if(me->HANDCARDS[i])me->CARDS.push(me->HANDCARDS[i]);
            me->HANDCARDS.clear();
            if(enemy->ID==11)
            {
                QMessageBox::about(this,tr("遗言"),tr("From吉尔伽美什：\n现在是你更强"));
            }
            BattleWin* btwn=new BattleWin;
            close();
            btwn->show();
        }
    }
    else QMessageBox::about(this,tr("OOPS"),tr("NO ENOUGH MANA!"));
}

void Battle::on_ENDROUND_clicked()
{
//=======================DELETING&DISABLING HANDCARDS=======================
    for(int i=0;i<10;i++)Hand[i+1]->setEnabled(false);
    for(int i=0;i<me->HANDCARDS.size();i++)if(me->HANDCARDS[i])me->CARDS.push(me->HANDCARDS[i]);
    me->HANDCARDS.clear();
//=======================MONSTER TIME=======================
    if(enemy->ESCAPE)enemy->ESCAPE--;
    if(enemy->ID==8)
    {
        if(enemy->HP<=120&&enemy->HP>80)
        {
            enemy->FLAG_MONSTER_8=2;
            enemy->ATK=0;
            enemy->DEF=0;
            enemy->TIME=0;
            ui->enemyimage->setPixmap(QPixmap(QString("://Pictures/%1-Monster.png").arg(enemy->ID+1)).scaled(ui->enemyimage->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

            setAutoFillBackground(true);
            QPalette backg=this->palette();
            QString dir=QString("://Pictures/%1-background.png").arg(enemy->ID+1);
            backg.setBrush(QPalette::Window,QBrush(QPixmap(dir).scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
            this->setPalette(backg);

            labelini();
        }
        else if(enemy->HP<=80&&!enemy->FLAG_MONSTER_10)
        {
            enemy->FLAG_MONSTER_10=true;
            enemy->FLAG_MONSTER_8=3;
            enemy->ATK=25;
            enemy->DEF=12;
            enemy->TIME=1;
            enemy->DEFFLAG=false;
            ui->enemyimage->setPixmap(QPixmap(QString("://Pictures/%1-Monster.png").arg(enemy->ID+2)).scaled(ui->enemyimage->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

            setAutoFillBackground(true);
            QPalette backg=this->palette();
            QString dir=QString("://Pictures/%1-background.png").arg(enemy->ID+2);
            backg.setBrush(QPalette::Window,QBrush(QPixmap(dir).scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
            this->setPalette(backg);

            enemy->roundskill[(rnd+6)%6]=3;
            enemy->roundskill[rnd%6]=1;
            enemy->roundskill[(rnd+1)%6]=2;
            enemy->roundskill[(rnd+2)%6]=3;
            enemy->roundskill[(rnd+3)%6]=1;
            enemy->roundskill[(rnd+4)%6]=2;
            enemy->roundskill[(rnd+5)%6]=3;
            labelini();
        }
    }
    if(enemy->FLAG_MONSTER_14==-1)
    {
        enemy->FLAG_MONSTER_14=-2;
        enemy->HP=20;
        me->getdamage(40,1);
        labelini();
    }
    switch(enemy->roundskill[rnd%6])
    {
    case 1:enemy->attack(*me);break;
    case 2:enemy->DEFFLAG=false;break;
    case 3:enemy->skill(*me);break;
    //case 4:enemy->skill(*me);enemy->DEFFLAG=false;break;
    //case 5:enemy->skill(*me);enemy->attack(*me);enemy->DEFFLAG=false;break;
    }
    switch(enemy->roundskill[(rnd+1)%6])
    {
    case 2:
    case 4:
    case 5:
        enemy->DEFFLAG=true;break;
    }
    if(enemy->ID==8&&enemy->HP>120)enemy->DEFFLAG=true;
    if(me->DIE())
    {
        BattleFailed* btfd=new BattleFailed;
        close();
        btfd->show();
    }
    if(enemy->DIE())
    {
        if(enemy->ID==11)
        {
            QMessageBox::about(this,tr("遗言"),tr("From吉尔伽美什：\n现在是你更强"));
        }
        BattleWin* btwn=new BattleWin;
        close();
        btwn->show();
    }
//=======================STARTNG THE NEXT ROUND=======================
    rnd++;
    bool flagflagsleep=false;
    bool flagflagmonster7=false;
    bool flagflagmonster6=false;
    if(me->FLAG_SLEEP>0)
    {
        me->FLAG_SLEEP--;
        flagflagsleep=true;
        me->COST=0;
    }
    else if(me->FLAG_CARD_10)
    {
        me->FLAG_CARD_10=false;
        me->COST=99;
    }
    else if(me->EQUIPMENTS[2])
    {
        me->COST=me->MAXCOST+2;
    }
    else
    {
        me->COST=me->MAXCOST;
    }
    if(me->COST>0)
    {
        if(me->FLAG_MONSTER_7)
        {
            me->FLAG_MONSTER_7=false;
            flagflagmonster7=true;
            me->COST--;
        }
    }
    me->DEFFLAG=false;
    if(me->FLAG_MONSTER_6)
    {
        me->FLAG_MONSTER_6=false;
        flagflagmonster6=true;
        me->ATK=me->ATK*0.5;
    }
    else
    {
        me->ATK=me->MAXATK;
    }
    this->labelini();
    if(flagflagsleep)ui->sleep->setVisible(true);
    else ui->sleep->setVisible(false);
    if(flagflagmonster7)ui->absorbed->setVisible(true);
    else ui->absorbed->setVisible(false);
    if(flagflagmonster6)ui->horror->setVisible(true);
    else ui->horror->setVisible(false);
    if(me->EQUIPMENTS[8])
    {
        if(me->FLAG_CARD_5)
        {
            me->FETCHCARDS(me->CARDNUM+1+me->FLAG_CARD_5);
            me->FLAG_CARD_5=0;
        }
        else me->FETCHCARDS(me->CARDNUM+1);
    }
    else
    {
        if(me->FLAG_CARD_5)
        {
            me->FETCHCARDS(me->CARDNUM+me->FLAG_CARD_5);
            me->FLAG_CARD_5=0;
        }
        else me->FETCHCARDS(me->CARDNUM);
    }
    cardset();
}
