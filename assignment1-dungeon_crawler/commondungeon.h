#ifndef COMMONDUNGEON_H
#define COMMONDUNGEON_H
#include "dungeon.h"
#include "room.h"
#include "wall.h"
#include "door.h"
#include <iostream>
namespace core {
namespace dungeon {

// TODO: define concrete components classes common to all dungeon types

/**
 * @brief TODO The OpenDoorway class
 */
class OpenDoorway : public Door
{
public:
    OpenDoorway(int i);
    void setDescrition();
};

} // namespace dungeon
} // namespace core

#endif // COMMONDUNGEON_H
