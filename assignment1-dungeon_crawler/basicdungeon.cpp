#include "basicdungeon.h"

using namespace core::dungeon;

/* ------------------------------------------------------------------------------
 * BasicDungeon member implementations
 * -----------------------------------------------------------------------------*/

BasicDungeon::BasicDungeon()
{
    Room* room1 = createRoom(1);
    this->addRoom(std::shared_ptr<Room>(room1));
    Room* room2 = createRoom(2);
    this->addRoom(std::shared_ptr<Room>(room2));
    Room* room3 = createRoom(3);
    this->addRoom(std::shared_ptr<Room>(room3));
    Room* room4 = createRoom(4);
    this->addRoom(std::shared_ptr<Room>(room4));
    Room* room5 = createRoom(5);
    this->addRoom(std::shared_ptr<Room>(room5));
    Room* room6= createRoom(6);
    this->addRoom(std::shared_ptr<Room>(room6));
    Room* room7= createRoom(7);
    this->addRoom(std::shared_ptr<Room>(room7));
    Room* room8= createRoom(8);
    this->addRoom(std::shared_ptr<Room>(room8));
    Room* room9= createRoom(9);
    this->addRoom(std::shared_ptr<Room>(room9));

    Door* door1n = new OpenDoorway(1);
    Door* door9e = new OpenDoorway(2);
    Door* door1s = new OpenDoorway(3);
    Door* door1e = new OpenDoorway(4);
    Door* door2s = new OpenDoorway(5);
    Door* door3s = new OpenDoorway(6);
    Door* door4e = new OpenDoorway(7);
    Door* door5e = new OpenDoorway(8);
    Door* door5s = new OpenDoorway(9);
    Door* door7e = new OpenDoorway(10);
    Door* door8e = new OpenDoorway(11);

    Wall* wall = new BasicWall();

    this->addDoor(std::shared_ptr<Door>(door1n));
    this->addDoor(std::shared_ptr<Door>(door9e));
    this->addDoor(std::shared_ptr<Door>(door1s));
    this->addDoor(std::shared_ptr<Door>(door1e));
    this->addDoor(std::shared_ptr<Door>(door2s));
    this->addDoor(std::shared_ptr<Door>(door3s));
    this->addDoor(std::shared_ptr<Door>(door4e));
    this->addDoor(std::shared_ptr<Door>(door5e));
    this->addDoor(std::shared_ptr<Door>(door5s));
    this->addDoor(std::shared_ptr<Door>(door5e));
    this->addDoor(std::shared_ptr<Door>(door7e));
    this->addDoor(std::shared_ptr<Door>(door8e));
    door1n->initate(NULL,room1);
    door9e->initate(room9,NULL);
    door1s->initate(room1,room4);
    door1e->initate(room1,room2);
    door2s->initate(room2,room5);
    door3s->initate(room6,room3);
    door4e->initate(room4,room5);
    door5e->initate(room5,room6);
    door5s->initate(room5,room8);
    door7e->initate(room8,room7);
    door8e->initate(room8,room9);
    room1->setNorth(door1n);
    room1->setSouth(door1s);
    room1->setEast(door1e);
    room2->setWest(door1e);
    room2->setSouth(door2s);
    room3->setSouth(door3s);
    room4->setNorth(door1s);
    room4->setEast(door4e);
    room5->setNorth(door2s);
    room5->setSouth(door5s);
    room5->setEast(door5e);
    room5->setWest(door4e);
    room6->setWest(door5e);
    room6->setNorth(door3s);
    room7->setEast(door7e);
    room8->setWest(door7e);
    room8->setNorth(door5s);
    room8->setEast(door8e);
    room9->setWest(door8e);
    room9->setEast(door9e);

    room1->setWWall(wall);
    room4->setWWall(wall);
    room3->setWWall(wall);
    room7->setWWall(wall);
    room2->setNWall(wall);
    room3->setNWall(wall);
    room7->setNWall(wall);
    room9->setNWall(wall);
    room2->setEWall(wall);
    room3->setEWall(wall);
    room6->setEWall(wall);
    room4->setSWall(wall);
    room6->setSWall(wall);
    room7->setSWall(wall);
    room8->setSWall(wall);
    room9->setSWall(wall);



    room3->setCreature(std::shared_ptr<core::creatures::Creature>(createCreature(false)));
    room5->setCreature(std::shared_ptr<core::creatures::Creature>(createCreature(false)));
    room9->setCreature(std::shared_ptr<core::creatures::Creature>(createCreature(true)));

    room3->setItem(std::shared_ptr<core::items::Item>(createItem()));
    room5->setItem(std::shared_ptr<core::items::Item>(createItem()));
    room7->setItem(std::shared_ptr<core::items::Item>(createItem()));
}
Room* BasicDungeon::createRoom(int i){
    int type = rand() % 2;
    if (type >=1){
        return new RockChamber(i);
    }
    return new QuartzChamber(i);
}
core::creatures::Creature* BasicDungeon::createCreature(bool isBoss){
    int type = rand() % 2;
    if (type >= 1){
        return new core::creatures::Goblin(isBoss);
    }
    return new core::creatures::Werewolf(isBoss);
}
core::items::Item* BasicDungeon::createItem(){
    int type = rand() % 4;
    if (type >= 3){
        return new core::items::ShortSword();
    }
    else if (type >= 2){
        return new core::items::BattleAxe();
    }
    else if (type >= 1){
        return new core::items::AcidFlask();
    }
    else{
        return new core::items::HealthPotion();
    }
}

/* ------------------------------------------------------------------------------
 * RockChamber member implementations
 * -----------------------------------------------------------------------------*/

RockChamber::RockChamber(int id) :Room(id,"A dark and empty chamber")
{

}

/* ------------------------------------------------------------------------------
 * QuartzChamber member implementations
 * -----------------------------------------------------------------------------*/

QuartzChamber::QuartzChamber(int id):Room(id,"A chamber that glitters like a thousand stars in the torchlight")
{

}

/* ------------------------------------------------------------------------------
 * BasicWall member implementations
 * -----------------------------------------------------------------------------*/

BasicWall::BasicWall():Wall("Out of the darkness looms a jagged formation of rock: you cannot go that way" )
{

}
