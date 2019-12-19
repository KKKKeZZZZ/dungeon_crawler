#include "wall.h"

using namespace core::dungeon;

const std::string& Wall::getDescription(){
    return _description;
}
Wall::Wall(const std::string& description):_description(description)
{

}
