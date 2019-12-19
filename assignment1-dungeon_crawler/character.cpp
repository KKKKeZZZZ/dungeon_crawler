#include "character.h"
#include "creatures.h"
using core::Character;

Character::Character(const std::string &name)
 : _name{name},_strength(1) , _dexterity(1), _wisdom(1),_health(50),
   _weapon(std::shared_ptr<core::items::Weapon>(new core::items::Fists()))
{

}
void Character::setStrength(int value){
   if (value < 0) {
       value = 0;
   }
   _strength += value;
   if (_strength > 6) {
       _strength = 6;
   }
}
void Character::setWisdom(int value){
   if (value < 0) {
       value = 0;
   }
   _wisdom += value;
   if(_wisdom > 6){
       _wisdom = 6;
   }

}
void Character::setDexterity(int value){
   if (value < 0) {
       value = 0;
   }
   _dexterity += value;
   if(_dexterity > 6){
       _dexterity = 6;
   }
}
void Character::setWeapon(std::shared_ptr<core::items::Weapon> weapon){
    _weapon = weapon;
}
void Character::setItem(std::shared_ptr<core::items::ConsumableItem> item){
    _consume = item;
}
void Character::setDamage(){
   _damage = (this -> _strength -1) * 2;
}
void Character::setDodge(){
   _dodge = 100 / 5 * (this -> _dexterity - 1);
}
void Character::setHealth(int health){
   _health = health;
}
const int& Character::getDamage() const{
   return _damage;
}
const int& Character::getDexterity() const{
   return _dexterity;
}
const int& Character::getDodge() const{
   return _dodge;
}
const int& Character::getHealth() const{
   return _health;
}
const int& Character::getStrength() const{
   return _strength;
}
const int& Character::getWisdom() const{
   return _wisdom;
}
const std::shared_ptr<core::items::Weapon>& Character::weapon(){
    return _weapon;
}
const std::shared_ptr<core::items::ConsumableItem>& Character::item(){
    return _consume;
}
const int& Character::attack(){
    setDamage();
    _damage += _weapon->weaponDamage();
    return _damage;
}



const std::string& Character::name() const {
  return _name;
}



std::ostream& operator<<(std::ostream &stream, const Character &character) {
  stream << character.name();
  return stream;
}
