#include "game.h"
#include "items.h"
#include <sstream>
#include <iomanip>

using namespace core::items;

/* ------------------------------------------------------------------------------
 * Item member implementations
 * -----------------------------------------------------------------------------*/

Item::Item(const std::string& name, const std::string& sDescription, const std::string& lDescription)
    :_name(name),_sDescription(sDescription),_lDescription(lDescription)
{

}
const std::string& Item::name(){
    return _name;
}
const std::string& Item::lDescription(){
    return _lDescription;
}
const std::string& Item::sDescription(){
    return _sDescription;
}

/* ------------------------------------------------------------------------------
 * ConsumeableItem member implementations
 * -----------------------------------------------------------------------------*/

ConsumableItem::ConsumableItem(const std::string& name, const std::string& sDescription,
                               const std::string& lDescription, const std::string& effect)
                               :Item(name,sDescription,lDescription),_effect(effect)
{

}
const std::string& ConsumableItem::effect(){
    return _effect;
}
HealthPotion::HealthPotion():ConsumableItem ("Health Potion", "a cloudy green fluid in a glass vial"
                                             ,"While it does not look appetising, drinking this potion is the ultimate boost to your immune system: kale really is that good for you",
                                              "Healing: Restore 25 health points")
{

}
int HealthPotion::work(){// can be add to the character's health points
    return 25;
}
AcidFlask::AcidFlask():ConsumableItem ("Acid Flask", "the label reads \"danger: corrosive substance!\"",
                                       "Spilling this potion could really hurt. It is probably best if you keep the stopper in at all times",
                                       "Deals damage to an the opponent: 10 damage")
{

}
int AcidFlask::work(){
    return 10;
}
Teleporter::Teleporter():ConsumableItem ("Teleporter", "a small device with a big red button, I wonder what it does",
                                         "Inspecting the device closely reveals nothing about its origin nor function. But the big red button is very tempting...",
                                         "Moves the character to a random room in the dungeon level")
{

}
int Teleporter::work(){// use to get the room throught room's id
    return rand() % 9 +1;
}

/* ------------------------------------------------------------------------------
 * Weapon member implementations
 * -----------------------------------------------------------------------------*/

Weapon::Weapon(const std::string& name, const std::string& sDescription,
               const std::string& lDescription, int min, int max )
        :Item(name,sDescription,lDescription), _min(min),_max(max)
{
    _prefix = NULL;
    _suffix = NULL;

}
const int& Weapon::getMin(){
    return _min;
}
const int& Weapon::getMax(){
    return _max;
}
int Weapon::weaponDamage(){//calculate the random number between min and max

    int weaponDamage = 0;
    weaponDamage = rand()%(this->getMax() - this->getMin() + 1) + this->getMin();
    return weaponDamage;
}
void Weapon::enchanting(Enchantment& enchant){
    if(_prefix == NULL){_prefix = &enchant;}
    else if(_suffix == NULL){_suffix = &enchant;}
}
Fists::Fists()
    :Weapon("Fists", "you look down at your fists and shrug, \"these will do\"",
            "Fists are the weapon of choice for someone who has nothing else.",4,4)
{

}

ShortSword::ShortSword()
    :Weapon ("Short Sword", "a sharp and pointy instrument, good for stabbing",
             "Not very large, but with a sharp point. Short swords are designed more for stabbing than for slicing. The hilt is surprisingly ornate for such an inconspicuous weapon. ",
             5, 10)
{

}

BattleAxe::BattleAxe()
    :Weapon("Battle Axe", "heavy, but effective",
            "A large and heavy weapon. The battle axe must be wielded with two hands but even then you are almost as likely to cut off your own limbs as those of an enemy.",10,15)
{

}

WizardsStaff::WizardsStaff()
    :Weapon("Wizard's Staff", "it would break if you leant on it, but it shoots fireballs so that’s something "
            ,"Not a very sturdy staff, but the swirl of magical fire around its top belies a magical secret: it shoots fireballs! "
            ,1,2)//,_ability()
{

}
int WizardsStaff::ability(){
    std::cout << "Fireball, deals 10 - 20 damage to the opponent" << std::endl;
    int damage = 0;
    damage += rand() % 11 + 10;
 return damage;
}
MagicWand::MagicWand()
    :Weapon("Magic Wand", "birch with angel’s feather core and rubberised leather grip ",
            "Apparently, there is no other wand like this one in existence. The angel’s feather at its core allows the bearer to perform unbelievable feats of healing. "
            ,5,10)
{

}
int MagicWand::ability(){
    std::cout<< "I AM STRONG AGAIN"<< std::endl;
    return 50;
}

/* ------------------------------------------------------------------------------
 * Enchantment member implementations
 * -----------------------------------------------------------------------------*/

Enchantment::Enchantment(const std::string& name, const std::string& description):Item(name,description)
{

}

FlameEnchantment::FlameEnchantment():Enchantment ("Flaming","Holding it fells warm to the touch and sparks leap out when it makes contact with something. \nDeals an extra 5 damage when the weapon is uesd to attack")
{

}

ElectricityEnchantment::ElectricityEnchantment():Enchantment ("Electrified", "The air crackles around it making the hairs on your arm stand on end. \nDeals an extra 5 damage when the weapon is used to attack")
{

}

HealingEnchantment::HealingEnchantment():Enchantment ("For healing", "Just being near it makes you feel warm and fuzzy inside. \nHeals the owner for 5 health points")
{

}

VampirismEnchantment::VampirismEnchantment():Enchantment ("Power of Vampirism", "Occasionally drops of blood appear on the surface but you are ensurefrom whence they came. \nHalf the damage you attacked will add to your health points")
{

}
