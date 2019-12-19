#include "testing.h"

#include "basicdungeon.h"
#include "character.h"
#include "commondungeon.h"
#include "creatures.h"
#include "door.h"
#include "dungeon.h"
#include "game.h"
#include "items.h"
#include "magicaldungeon.h"
#include "room.h"
#include "wall.h"

#include <iostream>
#include <iomanip>
#include <limits>
#include <memory>
#include <string>

/*
 * IMPLEMENT your tests in this file as required.
 */

using namespace core;
using namespace dungeon;
using namespace creatures;
using std::cout;
using std::endl;
using std::setw;

Testing::Testing(): _failure{false}, _failMessages{}
{

}

Testing::~Testing() {

}

void Testing::runTests() {
  cout << std::left;
  cout << setw(30) << "Character class tests ... " << testCharacter()  << endl;
  cout << setw(30) << "Creature class tests ... "  << testCreature()   << endl;
  cout << setw(30) << "Door class tests ... "      << testDoor()       << endl;
  cout << setw(30) << "Dungeon class tests ... "   << testDungeon()    << endl;
  cout << setw(30) << "Game class tests ... "      << testGame()       << endl;
  cout << setw(30) << "Item class tests ... "      << testItem()       << endl;
  cout << setw(30) << "Room class tests ... "      << testRoom()       << endl;
  cout << setw(30) << "Wall class tests ... "      << testWall()       << endl;
}

// This is an example of a simple way of performing your tests.
// It is incomplete, so you will need to extend it if you intend to continue with it.
std::string Testing::testCharacter() {
  _failure = false; // ensure this is at the beggining of each test

  std::string name{"Character Name"};

  Character c{name};

  equal<std::string>(name, c.name(),   "Character .name() does not match constructor value");

  // TODO: complete the testing of the Character class

  return passFailText();
}

std::string Testing::testCreature() {
  _failure = false; // ensure this is at the beggining of each test

  std::string name{"Creature Name"};

  //Creature c{name,"d",0,0,0,0};

  //equal<std::string>(name, c.name(),   "Creature .name() does not match constructor value");

  // TODO: complete the testing of the Creature class(es): can be removed

  return passFailText();
}
std::string Testing::testDoor() {
  _failure = false; // ensure this is at the beggining of each test

  // TODO: complete the testing of the Door class(es): can be removed

//  return passFailText();
  return "Skipped";
}
std::string Testing::testDungeon() {
  _failure = false; // ensure this is at the beggining of each test

  int roomId{1};
  std::shared_ptr<Room> room{std::make_shared<Room>(roomId)};

  Dungeon dungeon{};

  dungeon.addRoom(room);
  equal(room, dungeon.retrieveRoom(roomId), "Dungeon .add/.retrieveRoom() failure, does not return room that was added");

  // TODO: complete the testing of the Dungeon class(es): can be removed

//  return passFailText();
  return "Skipped";
}

std::string Testing::testGame() {
  _failure = false;

  Game game{};

  // TODO: implement the testing of the Game class


  // The following tests the random number generation.
  int value{game.randomIntBetweenInc(5, 0)};
  greaterThan(-1, value, "Swapping the min and max (incl.) did not work. Got negative value.");
  lessThan(6, value, "Swapping the min and max (incl.) did not work. value out of range.");

  value = game.randomIntBetweenEx(5, 0);
  greaterThan(-1, value, "Swapping the min and max (excl.) did not work. Got negative value.");
  lessThan(5, value, "Swapping the min and max (excl.) did not work. value out of range.");

  for (int i{0}; i < 1000; ++i) {
    // Not really a good test for this, but just in case.
    int value = game.randomIntBetweenInc(2, 5);
    greaterThan(1, value, "Game .randomIntBetweenInc somehow generated a value out of range");
    lessThan(6, value, "Game .randomIntBetweenInc somehow generated a value out of range");
  }

  for (int i{0}; i < 1000; ++i) {
    // Not really a good test for this, but just in case.
    int value = game.randomIntBetweenEx(2, 5);
    greaterThan(1, value, "Game .randomIntBetweenEx somehow generated a value out of range");
    lessThan(5, value, "Game .randomIntBetweenEx somehow generated a value out of range");
  }

  for (int i{0}; i < 1000; ++i) {
    // Not really a good test for this, but just in case.
    double value = game.randomDouble();
    double tinyValueBelow1{std::nextafter(0.0, std::numeric_limits<double>::min())};
    greaterThan(tinyValueBelow1, value, "Game .randomDouble somehow generated a value out of range");
    lessThan(1.0, value, "Game .randomDouble somehow generated a value out of range");
  }

  return passFailText();
}

std::string Testing::testItem() {
  _failure = false; // ensure this is at the beggining of each test

  // TODO: complete the testing of the Item class(es): can be removed

//  return passFailText();
  return "Skipped";
}

std::string Testing::testRoom() {
    _failure = false;

    int roomId{1};

    Room room{roomId};

    equal(roomId, room.id(), "Room .id() does not match constructor value");

    // TODO: complete the testing of the Character class

    return passFailText();
}

std::string Testing::testWall() {
  _failure = false; // ensure this is at the beggining of each test

  // TODO: complete the testing of the Wall class(es): can be removed

//  return passFailText();
  return "Skipped";
}

// TODO: implement the rest of your tests here


// Do not modify
void Testing::printFailures(std::ostream &ostream) {
  ostream << endl;
  if (_failMessages.rdbuf()->in_avail()) {
    ostream << "Failures:" << endl;
    ostream << _failMessages.str() << endl;
  }
  else {
    ostream << "All tests passed!" << endl;
  }
}
