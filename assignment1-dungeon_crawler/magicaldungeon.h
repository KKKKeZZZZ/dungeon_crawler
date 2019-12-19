#ifndef MAGICALDUNGEON_H
#define MAGICALDUNGEON_H
#include "commondungeon.h"

namespace core {
namespace dungeon {

// TODO: define component classes spcific to the MagicalDungeon type

/**
 * @brief TODO The MagicalDungeon class
 */
class MagicalDungeon:public Dungeon
{
public:
  MagicalDungeon();
  Room* createRoom(int i);
  core::creatures::Creature* createCreature(bool isBoss);
  core::items::Item* createItem();
};

/**
 * @brief TODO The EnchantedLibrary class
 */
class EnchantedLibrary: public Room
{
public:
  EnchantedLibrary(int id);
};

/**
 * @brief TODO The AlchemistsLaboratory class
 */
class AlchemistsLaboratory:public Room
{
public:
  AlchemistsLaboratory(int id);
};

/**
 * @brief TODO The MagicWall class
 */
class MagicWall:public Wall
{
public:
  MagicWall();
};

} // namespace dungeon
} // namespace core

#endif // MAGICALDUNGEON_H
