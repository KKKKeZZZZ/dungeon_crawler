#ifndef ROOM_H
#define ROOM_H
#include <string>
#include <iostream>
#include "items.h"
#include "creatures.h"
#include <memory>
namespace core {
namespace dungeon {
class Door;
class Wall;
/**
 * @brief TODO The Room class
 */
class Room
{
public:
  Room(int id,const std::string& description = "");

  /**
   * @brief id Returns the unique integer id of the Room.
   * @return the unique id
   */
  int id();
  void setNorth(Door* north);
  void setSouth(Door* south);
  void setWest(Door* west);
  void setEast(Door* east);
  void setWWall(Wall* west);
  void setEWall(Wall* east);
  void setNWall(Wall* north);
  void setSWall(Wall* south);
  void setCreature(std::shared_ptr<core::creatures::Creature> creature);
  void setItem(std::shared_ptr<core::items::Item> item);
  Door* getNorth();
  Door* getSouth();
  Door* getWest();
  Door* getEast();
  std::shared_ptr<core::creatures::Creature> getCreature();
  std::shared_ptr<core::items::Item> getItem();
  std::string description();
private:
  int _id;
  std::string _description;

  Door* _north;
  Door* _south;
  Door* _west;
  Door* _east;
  Wall* _nWall;
  Wall* _sWall;
  Wall* _wWall;
  Wall* _eWall;

  std::shared_ptr<core::creatures::Creature> _creature;
  std::shared_ptr<core::items::Item> _item;
};

} // namespace dungeon
} // namespace core


#endif // ROOM_H
