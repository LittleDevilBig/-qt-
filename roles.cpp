#include "roles.h"
#include<time.h>
#include<QDebug>
//=======================Hero=======================
void cardswap(card**x,card**y)
{
    card* temp=*x;
    *x=*y;
    *y=temp;
}
Hero::Hero(int maxhp, int atk, int def, int cost):HP(maxhp),MAXHP(maxhp),ATK(atk),MAXATK(atk),DEF(def),MAXDEF(def),COIN(100),CARDNUM(4),COST(cost),MAXCOST(cost),DEFFLAG(false),FLAG_CARD_10(false),FLAG_CARD_5(0)
{
    for(int i=0;i<sizeof(EQUIPMENTS)/sizeof(*EQUIPMENTS);i++)EQUIPMENTS[i]=false;

    for(int i=1;i<=3;i++)MYCARDS.push_back(new Attack);
    MYCARDS.push_back(new Defend);
    for(int i=1;i<=3;i++)MYCARDS.push_back(new Heal);
    for(int i=1;i<=2;i++)MYCARDS.push_back(new Getcard);
    MYCARDS.push_back(new Getcost);//Add Beginning Cards
}
void Hero::getdamage(int atk, int time)
{
    if(DEFFLAG)
    {
        for(int i=1;i<=time;i++)
        {
            if(atk<=DEF)return;
            else
            {
                if(EQUIPMENTS[6]&&(atk-DEF)>=20)HP-=(atk-DEF-5);
                else HP-=(atk-DEF);
            }
        }
    }
    else
    {
        for(int i=1;i<=time;i++)
        {
            if(EQUIPMENTS[6]&&atk>=20)HP-=(atk-5);
            else HP-=atk;
        }
    }
}
void Hero::CARDROLL()//random all cards[only before the battle]
{
    int k=MYCARDS.size();
    srand((unsigned)time(NULL));
    for(int i=k-1;i>=0;i--)cardswap(&MYCARDS[i],&MYCARDS[rand()%(i+1)]);
    for(int i=0;i<k;i++)CARDS.push(MYCARDS[i]);
}
void Hero::FETCHCARDS(int num)//get num cards from CARDS to HANDCARDS
{
    bool flag=true;
    for(int i=1;i<=num;i++)
    {
        if(flag)
        {
            flag=false;
            for(int j=0;j<HANDCARDS.size();j++)
            {
                if(HANDCARDS[j]==NULL)
                {
                    flag=true;
                    HANDCARDS[j]=CARDS.front();
                    CARDS.pop();
                }
            }
        }
        if(!flag)
        {
            if(HANDCARDS.size()<10)
            {
                HANDCARDS.push_back(CARDS.front());
                CARDS.pop();
            }
            else return;
        }
    }
}
//=======================Monster=======================
Monster::Monster(int maxhp, int atk, int def, int time, int id):ID(id),HP(maxhp),MAXHP(maxhp),ATK(atk),TIME(time),DEF(def),DEFFLAG(false),dmgweight(1.0),FLAG_MONSTER_14(0),FLAG_MONSTER_8(0),FLAG_MONSTER_9(false),FLAG_MONSTER_10(false){}

void Monster::getdamage(int atk,int time,bool SAFLAG)
{
    atk*=dmgweight;
    if(DEFFLAG)
    {
        for(int i=1;i<=time;i++)
        {
            if(atk<=DEF)continue;
            else
            {
                if(SAFLAG&&(atk-DEF)>=24)HP-=(atk-DEF+8);
                else HP-=(atk-DEF);
            }
        }
    }
    else
    {
        for(int i=1;i<=time;i++)
        {
            if(SAFLAG&&atk>=24)HP-=(atk+8);
            else HP-=atk;
        }
    }
}
void Monster::attack(Hero& h){h.getdamage(ATK,TIME);}

bool Monster::DIE()
{
    if(ID==14&&HP<=0&&FLAG_MONSTER_14!=-2)
    {
        FLAG_MONSTER_14=-1;
        HP=0;
        return false;
    }
    if(HP<=0)return true;
    return false;
}

Slime::Slime():Monster(60,12,0,1,1)
{
    roundskill[0]=3;
    roundskill[1]=1;
    roundskill[2]=3;
    roundskill[3]=3;
    roundskill[4]=1;
    roundskill[5]=3;
    roundskill[6]=3;
    skillhint=QString("柔软身躯：受到的攻击攻击弱化10%");
    information=QString("史莱姆（Slime）\n<主动技能>【柔软身躯】：受到的攻击弱化10%");
}
void Slime::skill(Hero &h)
{
    dmgweight*=0.9;
}

Mushroom::Mushroom():Monster(90,20,8,1,2)
{
    roundskill[0]=3;
    roundskill[1]=1;
    roundskill[2]=2;
    roundskill[3]=3;
    roundskill[4]=1;
    roundskill[5]=2;
    roundskill[6]=3;
    skillhint=QString("有毒：造成一次ATK*2的攻击");
    information=QString("蘑菇怪（Mushroom）\n<主动技能>【有毒】：造成一次ATK*2的攻击");
}
void Mushroom::skill(Hero &h)
{
    h.getdamage(ATK*2,TIME);
}

_11451481019::_11451481019():Monster(110,20,8,1,3)
{
    roundskill[0]=3;
    roundskill[1]=1;
    roundskill[2]=2;
    roundskill[3]=3;
    roundskill[4]=1;
    roundskill[5]=2;
    roundskill[6]=3;
    skillhint=QString("昏 睡 红 茶：使对方下一回合麻痹，同时ATK永久加5");
    information=QString("野兽先辈（_11451481019）\n<主动技能>【昏 睡 红 茶】：使对方下一回合麻痹，同时ATK永久加5");
}
void _11451481019::skill(Hero &h)
{
    ATK+=5;
    h.FLAG_SLEEP++;
}

EyeofCthulu::EyeofCthulu():Monster(100,20,12,1,4)
{
    roundskill[0]=3;
    roundskill[1]=1;
    roundskill[2]=2;
    roundskill[3]=3;
    roundskill[4]=1;
    roundskill[5]=2;
    roundskill[6]=3;
    skillhint=QString("狂化：HP小于50%时，本回合TIME+3，并攻击一次；否则进行一次攻击");
    information=QString("克苏鲁之眼（Eye of Cthulu）\n<主动技能>【狂化】：HP小于50%时，本回合TIME+3，并攻击一次；否则进行一次攻击");
}
void EyeofCthulu::skill(Hero &h)
{
    if(HP>MAXHP*0.5)attack(h);
    else
    {
        TIME+=3;
        attack(h);
        TIME-=3;
    }
}

Arthas::Arthas():Monster(150,40,10,1,5)
{
    roundskill[0]=3;
    roundskill[1]=2;
    roundskill[2]=3;
    roundskill[3]=3;
    roundskill[4]=2;
    roundskill[5]=3;
    roundskill[6]=3;
    skillhint=QString("回光返照：HP小于30时发动，HP回到75，并进行一次攻击");
    information=QString("阿尔萨斯（Arthas）\n<主动技能>【回光返照】：HP小于30时发动，HP回到75，并进行一次攻击");
}
void Arthas::skill(Hero &h)
{
    if(HP<30)HP=75;
    h.getdamage(ATK,TIME);
}

Skeleton::Skeleton():Monster(60,18,0,1,6)
{
    roundskill[0]=1;
    roundskill[1]=3;
    roundskill[2]=1;
    roundskill[3]=3;
    roundskill[4]=1;
    roundskill[5]=3;
    roundskill[6]=1;
    skillhint=QString("吓人：下回合对方ATK减少一半");
    information=QString("骷髅（Skeleton）\n<主动技能>【吓人】：下回合对方ATK减少一半");
}
void Skeleton::skill(Hero &h)
{
    h.FLAG_MONSTER_6=true;
}

Machine::Machine():Monster(110,19,6,1,7)
{
    roundskill[0]=2;
    roundskill[1]=3;
    roundskill[2]=1;
    roundskill[3]=2;
    roundskill[4]=3;
    roundskill[5]=1;
    roundskill[6]=2;
    skillhint=QString("吸收：下回合对方COST减1，同时ATK加6");
    information=QString("机皇帝（Machine）\n<主动技能>【吸收】：对方COST减1，同时ATK加6");
}
void Machine::skill(Hero &h)
{
    ATK+=6;
    h.FLAG_MONSTER_7=true;
}

Steves::Steves():Monster(160,15,5,1,8)
{
    FLAG_MONSTER_8=1;
    roundskill[0]=3;
    roundskill[1]=3;
    roundskill[2]=3;
    roundskill[3]=3;
    roundskill[4]=3;
    roundskill[5]=3;
    roundskill[6]=2;
    skillhint=QString("三重形态：\n1.[160,120)：我的世界史蒂夫 ATK 15 DEF 5 全能玩家：进攻同时防御\n2.[120,80)：史蒂夫乔布斯 ATK 0 DEF 0 创世纪发明家:对方麻痹两回合，自身HP下降40\n3.[80,0)：PUBG史蒂夫 ATK 25 DEF 12 锁头一击：史蒂夫拿出祖传的AWM并使用锁头挂打出致命一击 本回合ATK上升25，攻击造成1.5倍伤害");
    information=QString("<被动技能>【三重形态】：随着HP的改变会改变形态\n（120<HP<=160）Minecraft史蒂夫——ATK=15，DEF=5\n<主动技能>【全能玩家】：进攻同时防御\n（80<HP<=120）史蒂夫·乔布斯——ATK=0，DEF=0\n<主动技能>【创世纪发明家】：对方麻痹两回合，自身HP减到80\n（HP<=80）PUBG史蒂夫——ATK=25，DEF=12\n<主动技能>【锁头一击】：史蒂夫拿出祖传的AWM并使用锁头挂打出致命一击，本回合ATK上升25，攻击造成1.5倍伤害");
}
void Steves::skill(Hero &h)
{
    if(HP>120)
    {
        attack(h);
        DEFFLAG=false;
    }
    else if(HP>80)
    {
        DEFFLAG=false;
        if(!FLAG_MONSTER_9){h.FLAG_SLEEP+=2;FLAG_MONSTER_9=true;}
        HP=80;
    }
    else
    {
        ATK+=25;
        h.getdamage(ATK*1.5,1);
        ATK-=25;
    }
}

Gilgamesh::Gilgamesh():Monster(10,100,0,5,11)
{
    roundskill[0]=1;
    roundskill[1]=3;
    roundskill[2]=1;
    roundskill[3]=3;
    roundskill[4]=1;
    roundskill[5]=3;
    roundskill[6]=1;
    skillhint=QString("天地乖离之星：对方HP-100");
    information=QString("吉尔伽美什（Gilgamesh）\n<主动技能>【天地乖离之星】：对方HP减100");
}
void Gilgamesh::skill(Hero &h)
{
    h.HP-=100;
}

USS_Enterprise::USS_Enterprise():Monster(100,10,6,10,12)
{
    roundskill[0]=1;
    roundskill[1]=1;
    roundskill[2]=3;
    roundskill[3]=1;
    roundskill[4]=1;
    roundskill[5]=3;
    roundskill[6]=1;
    skillhint=QString("LuckE：本回合ATK+2并攻击一次，下回合自身获得闪避");
    information=QString("企业（USS_Enterprise）\n<主动技能>【LuckE】：本回合ATK+2并攻击一次，下回合自身获得闪避");
}
void USS_Enterprise::skill(Hero &h)
{
    ATK+=2;
    attack(h);
    ATK-=2;
    ESCAPE++;
}

Pony::Pony():Monster(80,30,0,1,13)
{
    roundskill[0]=1;
    roundskill[1]=1;
    roundskill[2]=3;
    roundskill[3]=1;
    roundskill[4]=1;
    roundskill[5]=3;
    roundskill[6]=1;
    skillhint=QString("虚无：下两回合获得闪避");
    information=QString("谱尼（Pony）\n<主动技能>【虚无】：下两回合获得闪避");
}
void Pony::skill(Hero &h)
{
    ESCAPE+=2;
}

No_99::No_99():Monster(100,40,15,1,14)
{
    FLAG_MONSTER_14=1;
    roundskill[0]=1;
    roundskill[1]=2;
    roundskill[2]=1;
    roundskill[3]=1;
    roundskill[4]=2;
    roundskill[5]=1;
    roundskill[6]=1;
    skillhint=QString("（被动）No的终点：若HP为0，对对方造成40点伤害，且HP变为20");
    information=QString("No.99 希望皇龙 霍普德拉古恩（Number 99: Utopic Dragon）\n<被动技能>【No的终点】：仅发动一次，若HP为0，对对方造成40点伤害，且HP变为20");
}
void No_99::skill(Hero &h)
{
    attack(h);
}

Ender_Dragon::Ender_Dragon():Monster(400,10,0,1,15)
{
    roundskill[0]=3;
    roundskill[1]=3;
    roundskill[2]=3;
    roundskill[3]=3;
    roundskill[4]=3;
    roundskill[5]=3;
    roundskill[6]=3;
    skillhint=QString("结束了？：50%概率发动，如果对方没有使用格挡类，那么本回合ATK*5，且必然攻击一次");
    information=QString("末影龙（Ender Dragon）\n<主动技能>【结束了？】：50%概率发动，如果对方没有使用格挡类，那么本回合ATK*5，且必然攻击一次");
}
void Ender_Dragon::skill(Hero &h)
{
    double magicd=(double)rand()/(double)RAND_MAX;
    if(!h.DEFFLAG&&magicd>0.5)
    {
        ATK*=5;
        attack(h);
        ATK/=5;
    }
    else attack(h);
}

Moon_Lord::Moon_Lord():Monster(200,25,10,1,16)
{
    roundskill[0]=2;
    roundskill[1]=1;
    roundskill[2]=3;
    roundskill[3]=2;
    roundskill[4]=2;
    roundskill[5]=1;
    roundskill[6]=2;
    skillhint=QString("幻想死光：40%概率发动，造成70点伤害");
    information=QString("月球领主（Moon Lord）\n<主动技能>【幻想死光】：25%概率发动，造成70点伤害");
}
void Moon_Lord::skill(Hero &h)
{
    double magicd=(double)rand()/(double)RAND_MAX;
    if(magicd>0.6)
    {
        h.getdamage(70,1);
    }
}
//=======================Card=======================
Attack::Attack():card(1){hint=QString("攻击：怪物受到我方ATK值的攻击");}
bool Attack::use(Hero& h,Monster& m,int num){if(h.COST>=1){h.COST-=1;if(h.COST<=0)h.COST=0;m.getdamage(h.ATK,1,h.EQUIPMENTS[7]);return true;}else return false;}
Defend::Defend():card(2){hint=QString("格挡：本回合我方做出防御（本卡牌每回合只能使用一次）");}
bool Defend::use(Hero& h,Monster& m,int num){if(h.COST>=1){h.COST-=1;if(h.COST<=0)h.COST=0;h.DEFFLAG=true;return true;}else return false;}
Heal::Heal():card(3){hint=QString("治愈：我方HP增加7");}
bool Heal::use(Hero& h,Monster& m,int num){if(h.COST>=1){h.COST-=1;if(h.COST<=0)h.COST=0;h.HP+=7;if(h.HP>=h.MAXHP)h.HP=h.MAXHP;return true;}else return false;}
Getcost::Getcost():card(4){hint=QString("补♂魔：我方MANA增加2");}
bool Getcost::use(Hero& h,Monster& m,int num){if(h.COST>=1){h.COST+=1;return true;}else return false;}
Getcard::Getcard():card(5){hint=QString("天使的施舍：下回合多抽取两张牌");}
bool Getcard::use(Hero& h,Monster& m,int num){if(h.COST>=1){h.COST-=1;h.FLAG_CARD_5+=2;return true;}else return false;}
DoubleAttack::DoubleAttack():card(6){hint=QString("双重攻击：攻击两次，每次造成ATK伤害");}
bool DoubleAttack::use(Hero& h,Monster& m,int num){if(h.COST>=2){h.COST-=2;m.getdamage(h.ATK,2,h.EQUIPMENTS[7]);return true;}else return false;}
PowerAttack::PowerAttack():card(7){hint=QString("弱点打击：怪物受到我方ATK*2值的攻击");}
bool PowerAttack::use(Hero& h,Monster& m,int num){if(h.COST>=2){h.COST-=2;m.getdamage(h.ATK*2,1,h.EQUIPMENTS[7]);return true;}else return false;}
MegaDefend::MegaDefend():card(8){hint=QString("重力场盾：本场战斗我方DEF增加8，本回合我方做出防御");}
bool MegaDefend::use(Hero& h,Monster& m,int num){if(h.COST>=2){h.COST-=2;h.DEF+=8;h.DEFFLAG=true;return true;}else return false;}
AttackDefend::AttackDefend():card(9){hint=QString("盾牌猛击：造成ATK攻击并格挡");}
bool AttackDefend::use(Hero& h,Monster& m,int num){if(h.COST>=1){h.COST-=1;m.getdamage(h.ATK,1,h.EQUIPMENTS[7]);h.DEFFLAG=true;return true;}else return false;}
Manaspring::Manaspring():card(10){hint=QString("法力之源：下回合我方MANA变为99");}
bool Manaspring::use(Hero& h, Monster& m,int num){if(h.COST>=3){h.COST-=3;h.FLAG_CARD_10=true;return true;}else return false;}







