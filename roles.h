#ifndef ROLES_H
#define ROLES_H
#include <queue>
#include <vector>
#include "card.h"
#include <cstdlib>

#define ALLCARDS 10
#define ALLEQUIPMENTS 8
class Hero;
class card;
//=======================Monster=======================
class Monster
{
public:
    int ID;
    int HP;
    int ATK;
    int TIME;
    int DEF;
    int MAXHP;

    bool DEFFLAG;
    int ESCAPE;
    int FLAG_MONSTER_14;
    int FLAG_MONSTER_8;
    bool FLAG_MONSTER_9;
    bool FLAG_MONSTER_10;

    int roundskill[8];
    QString skillhint;
    QString information;
    double dmgweight;
    friend class Hero;
    Monster(int maxhp,int atk,int def,int time,int id=0);
    virtual void getdamage(int atk,int time,bool SAFLAG=0);
    virtual void attack(Hero& h);
    virtual void skill(Hero& h)=0;
    bool DIE();//whether died
};
class Slime:public Monster
{
public:
    Slime();
    void skill(Hero &h);
};
class Mushroom:public Monster
{
public:
    Mushroom();
    void skill(Hero &h);
};
class _11451481019:public Monster
{
public:
    _11451481019();
    void skill(Hero &h);
};
class EyeofCthulu:public Monster
{
public:
    EyeofCthulu();
    void skill(Hero &h);
};
class Arthas:public Monster
{
public:
    Arthas();
    void skill(Hero &h);
};
class Skeleton:public Monster
{
public:
    Skeleton();
    void skill(Hero &h);
};
class Machine:public Monster
{
public:
    Machine();
    void skill(Hero &h);
};
class Steves:public Monster
{
public:
    Steves();
    void skill(Hero &h);
};
class Gilgamesh:public Monster
{
public:
    Gilgamesh();
    void skill(Hero &h);
};
class USS_Enterprise:public Monster
{
public:
    USS_Enterprise();
    void skill(Hero &h);
};
class Pony:public Monster
{
public:
    Pony();
    void skill(Hero &h);
};
class No_99:public Monster
{
public:
    No_99();
    void skill(Hero &h);
};
class Ender_Dragon:public Monster
{
public:
    Ender_Dragon();
    void skill(Hero &h);
};
class Moon_Lord:public Monster
{
public:
    Moon_Lord();
    void skill(Hero &h);
};
//=======================Hero=======================
class Hero
{
public:
    int HP;
    int ATK;
    int MAXATK;
    int DEF;
    int MAXDEF;
    int MAXCOST;//how many mana per round
    int COST;//how many mana this round
    int COIN;
    int CARDNUM;// how many cards per round
    int MAXHP;//max hp

    bool DEFFLAG;//if this round defend or not
    int FLAG_CARD_5;
    bool FLAG_CARD_10;
    int FLAG_SLEEP;
    bool FLAG_MONSTER_6;
    bool FLAG_MONSTER_7;

    bool EQUIPMENTS[ALLEQUIPMENTS+1]={0};
    friend class card;
    std::queue<card*>CARDS;//the cards to be fetched
    std::vector<card*>MYCARDS;//the cards that you have
    std::vector<card*>HANDCARDS;//cards in your hand, max 10
    Hero(int maxhp,int atk,int def,int cost);
    void getdamage(int atk,int time);
    bool DIE(){if(HP<=0)return true;return false;}//whether you are died
    void CARDROLL();//random all cards[only before the battle]
    void FETCHCARDS(int num);//get num cards from CARDS to HANDCARDS
};
class Warrior:public Hero
{
public:
    Warrior():Hero(100,14,8,3){EQUIPMENTS[1]=true;}
};
class Wizard:public Hero
{
public:
    Wizard():Hero(80,18,5,5){EQUIPMENTS[8]=true;}
};
//=======================Card=======================
class Attack:public card//card#1
{
public:
    Attack();
    bool use(Hero& h,Monster& m,int num);
};
class Defend:public card//card#2
{
public:
    Defend();
    bool use(Hero& h,Monster& m,int num);
};
class Heal:public card//card#3
{
public:
    Heal();
    bool use(Hero& h,Monster& m,int num);
};
class Getcost:public card//card#4
{
public:
    Getcost();
    bool use(Hero& h,Monster& m,int num);
};
class Getcard:public card//card#5
{
public:
    Getcard();
    bool use(Hero& h,Monster& m,int num);
};
class DoubleAttack:public card//card#6
{
public:
    DoubleAttack();
    bool use(Hero& h,Monster& m,int num);
};
class PowerAttack:public card//card#7
{
public:
    PowerAttack();
    bool use(Hero& h,Monster& m,int num);
};
class MegaDefend:public card//card#8
{
public:
    MegaDefend();
    bool use(Hero& h,Monster& m,int num);
};
class AttackDefend:public card//card#9
{
public:
    AttackDefend();
    bool use(Hero& h,Monster& m,int num);
};
class Manaspring:public card//card#10
{
public:
    Manaspring();
    bool use(Hero& h,Monster& m,int num);
};
#endif // ROLES_H
