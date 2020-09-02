#ifndef CARD_H
#define CARD_H
#include<roles.h>
#include<qstring.h>
class Hero;
class Monster;
class card
{
public:
    int ID;
    QString hint;
    card(int id=0):ID(id){}
    friend class Hero;
    virtual bool use(Hero& h,Monster& m,int num){}
};
#endif // CARD_H
