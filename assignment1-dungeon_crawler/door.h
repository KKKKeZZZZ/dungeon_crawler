#ifndef DOOR_H
#define DOOR_H
#include <string>

#include "room.h"
namespace core {
namespace dungeon {
class Room;
/**
 * @brief TODO The Door class
 */
class Door
{
public:
  Door(const int& id, const std::string& descrition);
  const int& id() const;
  std::string description();
  void initate(Room* start, Room* destination);
  Room* leadTo(Room* room);
  void setDescription(std::string s);

private:
  int _id;
  std::string _description;
  Room* _start;
  Room* _destination;
};

} // namespace dungeon
} // namespace core

#endif // DOOR_H
