#ifndef BASICDUNGEON_H
#define BASICDUNGEON_H
#include "commondungeon.h"
//#include "creatures.h"

#include <memory>
namespace core {
namespace dungeon {

// TODO: define component classes spcific to the BasicDungeon type
class Creature;
class Item;
/**
 * @brief TODO The BasicDungeon class
 */
class BasicDungeon : public Dungeon
{
public:
  BasicDungeon();
  Room* createRoom(int i);
  core::creatures::Creature* createCreature(bool isBoss);
  core::items::Item* createItem();
};

/**
 * @brief TODO The RockChamber class
 */
class RockChamber : public Room
{
public:
  RockChamber(int id);
};

/**
 * @brief TODO The QuartzChamber class
 */
class QuartzChamber : public Room
{
public:
  QuartzChamber(int id);
};

/**
 * @brief TODO The BasicWall class
 */
class BasicWall : public Wall
{
public:
  BasicWall();
};

} // namespace dungeon
} // namespace core

#endif // BASICDUNGEON_H
