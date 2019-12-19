#ifndef CREATURE_H
#define CREATURE_H
#include <string>
#include "items.h"
#include <memory>
namespace core {
namespace creatures {

// TODO: define Creature class and the its concrete subclasses.
// There is some example code in here, but it can be modified if desired.

/**
 * @brief TODO The Creature class
 */
class Creature
{
public:
  Creature(const std::string &name,const std::string& description, int strength,int dexterity
           ,int wisdom, int health, bool isBoss = false);

  const std::string& name() const;
  void setDamage();
  void setDodge();
  void setHealth(int i);
  const int& getStrength() const;
  const int& getDexterity() const;
  const int& getWisdom() const;
  const int& getHealth() const;
  const int& getDamage() const;
  const int& getDodge() const;
  std::string description();
  //const int& attack() {return _damage;}
protected:
  std::shared_ptr<items::Weapon> _weapon;
private:
  std::string _name;
  std::string _description;
  int _strength;
  int _dexterity;
  int _wisdom;
  int _health;
  int _damage;
  int _dodge;
  bool _isBoss;

};

/**
 * @brief TODO The Goblin class
 */
class Goblin: public Creature
{
public:
  Goblin(bool isBoss);
  const int& attack();
private:
  int _strength;
  int _wisdom;
  int _dexterity;
  int _damage;
  int _health;
  int _dodge;
  //shortSword _goblins;
};

/**
 * @brief TODO The Werewolf class
 */
class Werewolf: public Creature
{
public:
  Werewolf(bool isBoss);
  const int attack();
private:
  int _strength;
  int _wisdom;
  int _dexterity;
  int _damage;
  int _health;
  int _dodge;
};

/**
 * @brief TODO The EvilWizard class
 */
class EvilWizard:public Creature
{
public:
  EvilWizard(bool isBoss);
  const int& attack();
private:
  int _strength;
  int _wisdom;
  int _dexterity;
  int _damage;
  int _health;
  int _dodge;
};

} // namespace creatures
} // namespace core

#endif // CREATURE_H
