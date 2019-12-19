#include "game.h"
#include "testingsettings.h"
#include <sstream>
#include "basicdungeon.h"
#include "magicaldungeon.h"
using namespace core;

// TODO: Add additional implementation here
Game* Game:: _game = nullptr;
Game* Game::getInstance(){
    if (_game == nullptr){
        _game = new Game();
    }
    return _game;
}
std::shared_ptr<Character> Game::player() const{
    if (_player != NULL){
        return _player;
    }
    return NULL;
}
void Game::destroy(){// end of the game
    _level = 0;
    _player = NULL;
    _dungeon = NULL;
    _room = NULL;

}
int Game::level(){
    return _level;
}
void Game::setPlayer(std::shared_ptr<Character> c){
    _player = c;
}
// DO NOT modify implementation below this comment
std::shared_ptr<dungeon::Dungeon> Game::dungeon() const {
    if (_dungeon != NULL){
        return _dungeon;
    }
    return NULL;
}
void Game::createDungeon(char input){
    if (input == 'b'){
        _type = "b";
        _dungeon = std::shared_ptr<core::dungeon::Dungeon>(new core::dungeon::BasicDungeon());
        _level += 1;
    }
    else if (input == 'm'){
        _dungeon = std::shared_ptr<core::dungeon::Dungeon>(new core::dungeon::MagicalDungeon());
        _type = "m";
        _level += 1;
    }
}
void Game::enterDungeon(){// to the room whose id is 1
    _room = &(*_dungeon->retrieveRoom(1));
}
core::dungeon::Room* Game::currentRoom() const{
    return _room;
}
void Game::navigate(char c){// control character moving
    _previous = _room;
    if (c == 'n'){
        std::cout<< "\nYou pass through the doorway..."<<std::endl;
        _room = _room->getNorth()->leadTo(_room);
    }
    else if(c == 's'){
        //std::cout<< _room->getSouth()->description();
        std::cout<< "\nYou pass through the doorway..."<<std::endl;
        _room = _room->getSouth()->leadTo(_room);
    }
    else if(c == 'e'){
        //std::cout<< _room->getEast()->description();
        std::cout<< "\nYou pass through the doorway..."<<std::endl;
        _room = _room->getEast()->leadTo(_room);
    }
    else if(c == 'w'){
        //std::cout<< _room->getWest()->description();
        std::cout<< "\nYou pass through the doorway..."<<std::endl;
        _room = _room->getWest()->leadTo(_room);
    }
}
void Game::navigateBack(){// go back to the room where you came from
    _mid = _room;
    _room = _previous;
    _previous = _mid;
}
void Game::exitLevel(){//exit current level
    if (_type == "b"){
        createDungeon('b');
        enterDungeon();
    }
    else if (_type == "m"){
        createDungeon('m');
        enterDungeon();
    }
}
void Game::exitDungeon(){
    if (_type == "b"){
        createDungeon('b');
        enterDungeon();
    }
    else if (_type == "m"){
        createDungeon('m');
        enterDungeon();
    }
}
void Game::doActionRound(char input){
    if (input = 'b'){
        this->navigateBack();
    }

}
Game::Game()
  : _randomGenerator{uint32_t(time(nullptr))}, _realDistribution{0.0, 1.0}
{

}

int Game::randomIntBetweenInc(int min, int max) {
#if INPUT_SCRIPT
  return min; // for consistency when using the input script
#else
  if (min == max) return max;
  if (max < min) std::swap(min, max);

  int diff{max + 1 - min};
  return int(_randomGenerator() % unsigned(diff)) + min;
#endif
}

int Game::randomIntBetweenEx(int min, int max) {
#if INPUT_SCRIPT
  return max - 1; // for consistency when using the input script
#else
  if (min == max) return max; // technically invalid for an exclusive range
  if (max < min) std::swap(min, max);

  int diff{max - min};
  return int(_randomGenerator() % unsigned(diff)) + min;
#endif
}

double Game::randomDouble() {
#if INPUT_SCRIPT
  return 1.0; // for consistency when using the input script.
#else
  return _realDistribution(_randomGenerator);
#endif
}
