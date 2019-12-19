#include "door.h"
//#include <string>
using namespace core::dungeon;

Room* Door::leadTo(Room* start){// the door can be walk through
    if (_start == start) return _destination;
    if(_destination == start) return _start;

}
const int& Door::id() const{
    return _id;
}
void Door::initate(Room* start,Room* destination){// add the door from the start to destination
    _start = start;
    _destination = destination;
}
std::string Door::description(){
    return _description;
}
Door::Door(const int& id,const std::string& s) :_id(id), _description(s)
{
    _start = NULL;
    _destination = NULL;

}
