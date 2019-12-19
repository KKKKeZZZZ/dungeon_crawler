#ifndef ITEMS_H
#define ITEMS_H
#include <iostream>
namespace core {
namespace items {

/**
 * @brief TODO The Item class
 */
class Item
{
public:
  Item(const std::string& name, const std::string& sDescription = "", const std::string& lDescription = "");
  virtual ~Item() = default;
  const std::string& name();
  const std::string& sDescription();
  const std::string& lDescription();

private:
  const std::string _name;
  const std::string _sDescription;
  const std::string _lDescription;
};

/**
 * @brief TODO The Weapon class
 */
class Enchantment;
class Weapon : public Item
{
public:
  Weapon(const std::string& name = "", const std::string& sDescription = "",
         const std::string& lDescription = "", int min = 0, int max = 0);
  //void generateDamage
  int weaponDamage();
  void enchanting(Enchantment& enchant);
  const int& getMin();
  const int& getMax();

private:
  const int& _min;
  const int& _max;
  Enchantment* _prefix;
  Enchantment* _suffix;

};

/**
 * @brief TODO The Fists class
 */
class Fists : public Weapon
{
public:
  Fists();
};

/**
 * @brief TODO The ShortSword class
 */
class ShortSword : public Weapon
{
public:
  ShortSword();
};

/**
 * @brief TODO The BattleAxe class
 */
class BattleAxe : public Weapon
{
public:
  BattleAxe();
};

/**
 * @brief TODO The WizardsStaff class
 */
class WizardsStaff : public Weapon
{
public:
  WizardsStaff();
  int ability();

};

/**
 * @brief TODO The MagicWand class
 */
class MagicWand : public Weapon
{
public:
  MagicWand();
  int ability();
};

/**
 * @brief TODO The ConsumableItem class
 */
class ConsumableItem : public Item
{
public:
  ConsumableItem(const std::string& name="",const std::string& sDescription= "",
                 const std::string& lDescription="",const std::string& effect="");
  const std::string& effect();
private:
  const std::string& _effect;
};

/**
 * @brief TODO The HealthPotion class
 */
class HealthPotion : public ConsumableItem
{
public:
  HealthPotion();
  int work();
};

/**
 * @brief TODO The AcidFlask class
 */
class AcidFlask : public ConsumableItem
{
public:
  AcidFlask();
  int work();
};

/**
 * @brief TODO The Teleporter class
 */
class Teleporter : public ConsumableItem
{
public:
  Teleporter();
  int work();
};

class Enchantment: public Item
{
public:
  Enchantment(const std::string& name = "",const std::string& description="");

};

/**
 * @brief TODO The FlameEnchantment class
 */
class FlameEnchantment : public Enchantment
{
public:
  FlameEnchantment();
};

/**
 * @brief TODO The ElectricityEnchantment class
 */
class ElectricityEnchantment : public Enchantment
{
public:
  ElectricityEnchantment();
};

/**
 * @brief TODO The HealingEnchantment class
 */
class HealingEnchantment : public Enchantment
{
public:
  HealingEnchantment();
};

/**
 * @brief TODO The VampirismEnchantment class
 */
class VampirismEnchantment : public Enchantment
{
public:
  VampirismEnchantment();
};

} // namespace items
} // namespace core


#endif // ITEMS_H
