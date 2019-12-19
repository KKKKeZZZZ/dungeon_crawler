#include "creatures.h"

using namespace core::creatures;

/* ------------------------------------------------------------------------------
 * Creature member implementations
 * -----------------------------------------------------------------------------*/

Creature::Creature(const std::string &name, const std::string& description, int strength,int dexterity
                   ,int wisdom,int health,bool isBoss)
  : _name{name},_description(description),_strength(strength),_dexterity(dexterity),_wisdom(wisdom),_health(health),_isBoss(isBoss)
{

}
void Creature::setDamage(){
    if (_isBoss){
        _damage = (this -> _strength -1) * 2;
    }
    if (!_isBoss){
        _damage = (this->_strength - 1);
    }
}
void Creature::setDodge(){
    if (_isBoss){// boss is strongger
        _dodge = 100 / 5 * (this -> _dexterity - 1);
    }
    if (!_isBoss){
        _dodge = 100 / 10 * (this -> _dexterity - 1);
    }
}
void Creature::setHealth(int value){
    _health = value;
}
const std::string& Creature::name() const {
  return _name;
}
const int& Creature::getDamage() const{
   return _damage;
}
const int& Creature::getDexterity() const{
   return _dexterity;
}
const int& Creature::getDodge() const{
   return _dodge;
}
const int& Creature::getHealth() const{
   return _health;
}
const int& Creature::getStrength() const{
   return _strength;
}
const int& Creature::getWisdom() const{
   return _wisdom;
}
std::string Creature::description(){
    return _description;
}

/* ------------------------------------------------------------------------------
 * Goblin member implementations
 * -----------------------------------------------------------------------------*/

Goblin::Goblin(bool isBoss):Creature ("Goblin", "A small nimble creature who favours the short sword", 2,4,1,20,isBoss)
{
    setDodge();
    _weapon = std::shared_ptr<core::items::Weapon>(new core::items::ShortSword);
    setDamage();
}
///*
const int& Goblin::attack(){
    setDamage();
    _damage += _weapon->weaponDamage();
    return _damage;
}
//*/
//void Character::attack(){}
/* ------------------------------------------------------------------------------
 * Werewolf member implementations
 * -----------------------------------------------------------------------------*/

Werewolf::Werewolf(bool isBoss) :Creature("Werewolf", "Glowing red eyes peer out from behind a long nose and sharp teeth",5,2,1,30,isBoss)
{
    setDodge();
    _damage = 0;
}
const int Werewolf::attack(){
    int times;
    int type;
    int damage = 0;
    bool isBite = false;
    times = rand()%100 +1;
    type = rand() %3 + 1;
    setDamage();
    if (times >= 40){// attck once
        damage += _damage;
        if (type >= 2){// bite or hit
            damage += rand()% 6 + 5 ;
            isBite = true;
        }
        else{
            damage += rand() % 6 + 2;
        }

    }
    else if(times >= 70){//attack twice
        damage += _damage;
        if(!isBite){
            if(type >= 1){
                damage += rand() % 6 +5;
            }
            else{
                damage += rand() % 6 + 2;
            }
        }
        else{
            damage+= rand() % 6 + 2;
        }
    }
    else if(times >= 90){// boo, all the three times
        damage += _damage;
        if(!isBite){// all type attack is used!
            damage += rand() % 6 + 5;
        }
        else{
            damage += rand() % 6 + 2;
        }
    }
    return damage;
}

/* ------------------------------------------------------------------------------
 * EvilWizard member implementations
 * -----------------------------------------------------------------------------*/

EvilWizard::EvilWizard(bool isBoss) :Creature ("Evil Wizard", "Cackling over an old tome, this wizard seems insanely evil; or maybe just insane? it is hard to tell",1,2,5,20,isBoss)
{
    _weapon = std::shared_ptr<core::items::Weapon>(new core::items::WizardsStaff);
}
const int& EvilWizard::attack(){
    int type;
    _damage = 0;
    type = rand() % 2;// hit or magic
    if (type <=1){
        _damage += this->_weapon->weaponDamage();
        return _damage;
    }
    _damage += rand() % 11 + 10;
    return _damage;
}
