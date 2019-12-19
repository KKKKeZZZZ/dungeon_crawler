#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include <memory>
#include "items.h"
#include "creatures.h"
namespace core {

// TODO: define Character class.
// There is some example code in here, but it can be modified if desired.
class Creature;
/**
 * @brief TODO The Complete the Character class, following is just a small example
 */
class Character
{
public:
  Character(const std::string &name);

  const std::string& name() const;
  void setStrength(int strength);
  void setDexterity(int dexterity);
  void setWisdom(int wisdom);
  void setDamage();
  void setDodge();
  void setHealth(int health);
  void setWeapon(std::shared_ptr<core::items::Weapon> weapon);
  void setItem(std::shared_ptr<core::items::ConsumableItem> item);
  const int& getStrength() const;
  const int& getDexterity() const;
  const int& getWisdom() const;
  const int& getHealth() const;
  const int& getDamage() const;
  const int& getDodge() const;
  const int& attack();
 // void attack(std::shared_ptr<core::Creature> c);
  const std::shared_ptr<core::items::Weapon>& weapon();
  const std::shared_ptr<core::items::ConsumableItem>& item();

private:
  const std::string _name;
  int _strength;
  int _dexterity;
  int _wisdom;
  int _damage;
  int _health;
  int _dodge;
  std::shared_ptr<core::items::Weapon> _weapon;
  std::shared_ptr<core::items::ConsumableItem> _consume;
};

} // namespace core

std::ostream& operator<<(std::ostream &stream, const core::Character &character);

#endif // CHARACTER_H
