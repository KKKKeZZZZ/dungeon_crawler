#include "room.h"
#include "door.h"
#include "creatures.h"
#include "items.h"
#include "wall.h"
using namespace core::dungeon;

Room::Room(int id, const std::string& description)
    : _id{id},_description(description)
{

}
//four direction of the room if is a room, add room. if not add wall
void Room::setNorth(Door* north){
    _north = north;
}
void Room::setSouth(Door* south){
    _south = south;
}
void Room::setWest(Door* west){
    _west = west;
}
void Room::setEast(Door* east){
    _east = east;
}
void Room::setNWall(Wall* north){
    _nWall = north;
}
void Room::setSWall(Wall* south){
    _sWall = south;
}
void Room::setEWall(Wall* east){
    _eWall = east;
}
void Room::setWWall(Wall* west){
    _wWall = west;
}
void Room::setCreature(std::shared_ptr<core::creatures::Creature> creature){
    _creature = creature;
}
void Room::setItem(std::shared_ptr<core::items::Item> item){
    _item = item;
}
std::string Room::description(){
    return _description;
}
Door* Room::getNorth(){
    if (_north != NULL ) return _north;
}
Door* Room::getSouth(){
    if (_south != NULL) return _south;
}
Door* Room::getWest(){
    if (_west != NULL) return _west;
}
Door* Room::getEast(){
    if (_east != NULL) return _east;
}
std::shared_ptr<core::creatures::Creature> Room::getCreature(){
    return _creature;
}
std::shared_ptr<core::items::Item> Room::getItem(){
    return _item;
}

int Room::id() {
  return _id;
}
