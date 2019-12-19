#include "menuinterface.h"
#include <algorithm>
#include <stdlib.h>

using namespace core;

MenuInterface::MenuInterface(std::ostream &display, std::istream &input)
  : _display{display}, _input{input}, _currentMenu{Menu::Main} {
}

void MenuInterface::displayWelcome(const std::string &author, const std::string &title) const {
  std::string welcomeText{"Welcome to " + title};
  std::string authorText{"Developed by " + author};
  std::string comp3023{"COMP 3023 Software Development with C++"};

  unsigned int columns{std::max(welcomeText.size(), std::max(authorText.size(), comp3023.size()))};

  _display << centre(columns, welcomeText.size()) << welcomeText << std::endl
           << centre(columns, authorText.size()) << authorText << std::endl
           << centre(columns, comp3023.size()) << comp3023 << std::endl;
}

void MenuInterface::run() {
  displayMenu();
  while (processSelection(getCharacterInput()) && _input) {
    displayMenu();
  }
}

void MenuInterface::displayMenu() const {
   waitUntillNewline();

  switch (_currentMenu) {
  case Menu::Main:
    displayMainMenu();
    break;
  case Menu::CharacterDetails:
    characterDetailsMenu();
    break;
  case Menu::DungeonSelect:
    dungeonTypeMenu();
    break;
  case Menu::Action:
    actionMenu();
    break;
  case Menu::Combat:
    combatMenu();
    break;
  }
}

bool MenuInterface::processSelection(char selection) {
  if (!_input) return false; // graceful exit when input ends

  switch (_currentMenu) {
  case Menu::Main:
    return processMainMenu(tolower(selection));
  case Menu::CharacterDetails:
    processCharacterDetails(tolower(selection));
    break;
  case Menu::DungeonSelect:
    processDungeonType(tolower(selection));
    break;
  case Menu::Action:
    processAction(tolower(selection));
    break;
  case Menu::Combat:
    processCombatAction(tolower(selection));
  }

  return true;
}

char MenuInterface::getCharacterInput() const {
  char input;
  _input >> input;
  _input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  echo(input); // for when running the input script
  return input;
}

int MenuInterface::getIntInput() const {
  int input;
  _input >> input;
  _input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  while (!_input) {
    _input.clear();
    warnSelectionInvalid(char(_input.peek()));
    _input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    _input >> input;
    _input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }

  echo(input);

  return input;
}

void MenuInterface::warnSelectionInvalid(char selection) const {
  _display << "Sorry, \'" << selection << "\' is not a valid option, please try again."
           << std::endl;
}

void MenuInterface::setMenu(Menu newMenu) {
  _currentMenu = newMenu;
}

void MenuInterface::displayMainMenu() const {
  _display << "What would you like to do?" << std::endl;
  _display << " (p)lay the game" << std::endl;
  _display << " (c)haracter details" << std::endl;
  _display << " (q)uit" << std::endl;
}

bool MenuInterface::processMainMenu(char selection) {
  switch (selection) {
  case 'p':
    playGame();
    break;
  case 'c':
    createCharacter();
    break;
  case 'q':
    return quitGame();
  default:
    warnSelectionInvalid(selection);
  }
  return true;
}

void MenuInterface::playGame() {
    if (Game::getInstance()->player() == nullptr){
        createCharacter();
    }
    setMenu(Menu::DungeonSelect);
    // TODO: implement this member function.
}

void MenuInterface::createCharacter() {
    int points = 6;
    int strength;
    int dexterity;
    int wisdom;

    std::cout << "\nYou need to create a character... what is your name" << std::endl;

    std::string names;
    std::cin >> names;
    Character* player = new Character(names);
    std::cout <<"\nWelcome " << player->name() << ", you have *6* stat points to allocate. "
                                               "\nA high Strength stat will boost your damage in combat. "
                                               "\nHow many points do you want to add to your Strength (cannot exceed 5)?"<<std::endl;

    std::cin >> strength;
    player->setStrength(strength);
    points -= strength;
    std::cout << "\nYou have *"<< points <<"* stat points remaining. "
                                         "\nA high Dexterity stat will increase your "
                                         "\nability to dodge creature attacks. "
                                         "\nHow many points do you want to add to you Dexterity (cannot exceed 5)?" << std::endl;
    std::cin >> dexterity;
    player->setDexterity(dexterity);
    points -= dexterity;
    std::cout << "\nYou have *" << points << "* stat point remaining. "
                                           "\nA high Wisdom stat will boost "
                                           "\nthe effectiveness of magical items. "
                                           "\nHow many points do you want to add to your Wisdom (cannot exceed 5)?" << std::endl;
    std::cin >> wisdom;
    player->setWisdom(wisdom);
    points -= wisdom;
    if (points > 0){
        std::cout << "\nYou have *" << points<< "* status points remaining." << std::endl;
    }
    player->setHealth(50);
    player->setDodge();
    player->setDamage();
    _game.setPlayer(std::shared_ptr<Character>(player));
    std::cout << "\n*** Character Summary ***" << std::endl;
    std::cout << player->name() << std::endl;
    std::cout << "Strength:  " << player->getStrength() << std::endl;
    std::cout << "Dexterity: " << player->getDexterity() << std::endl;
    std::cout << "Wisdom:    " << player->getWisdom() << std::endl;
    std::cout << "Health:    " << player->getHealth() << " / 50 "<< std::endl;
    std::cout << "Damage:    " << player->getDamage() << std::endl;
    std::cout << "Dodge:     " << player->getDodge() <<" % "<< std::endl;
    std::cout << "Weapon:    " << player->weapon()->lDescription()<< std::endl;
    std::cout << "Item:      " << "you look into your backpack, emptiness looks back. if only you had something to put in it." << "\n" <<std::endl;

  // TODO: implement this member function.
}

void MenuInterface::dungeonTypeMenu() const {
    _display << "\nWhile roaming the country side you encounter a strange fork in the road. "
                "\nTo the left lies a dark cave, the foul stench of rotting flesh emanates from it. "
                "\nTo the right is a mysterious tower, a strange magical energy lights the path. "
                "\nWhat would you like to do? "<< std::endl;
    _display << "Go left: create a (b)asic dungeon" << std::endl;
    _display << "Go right: create a (m)agical dungeon" << std::endl;
    _display << "(r)eturn the way you came : back to main menu" <<"\n"<< std::endl;
}

void MenuInterface::processDungeonType(char selection) {
    switch(selection){
    case'b':
    { _display << "\nYou enter a dark cave..." << std::endl;


        _game.createDungeon('b');
        _game.enterDungeon();
        setMenu(Menu::Action);
        break;}
    case 'm':
        _display << "\nYou enter a mysterious tower..." << std::endl;
        _game.createDungeon('m');
        _game.enterDungeon();
        setMenu(Menu::Action);
        break;
    default:
        warnSelectionInvalid(selection);
        setMenu(Menu::DungeonSelect);
    }


}

void MenuInterface::switchToCharacterMenu() {
  // TODO: implement this member function

  setMenu(Menu::CharacterDetails);
}

bool MenuInterface::quitGame() const {
  // TODO: complete implementation

  return !confirm("\nAre you sure you want to quit?");
}

void MenuInterface::characterDetailsMenu() const {
    std::cout << "\n*** Character Summary ***" << std::endl;
    std::cout << _game.player()->name() << std::endl;
    std::cout << "Strength:  " << _game.player()->getStrength() << std::endl;
    std::cout << "Dexterity: " << _game.player()->getDexterity() << std::endl;
    std::cout << "Wisdom:    " << _game.player()->getWisdom() << std::endl;
    std::cout << "Health:    " << _game.player()->getHealth() << " / 50 "<< std::endl;
    std::cout << "Damage:    " << _game.player()->getDamage() << std::endl;
    std::cout << "Dodge:     " << _game.player()->getDodge() <<" % "<< std::endl;
    std::cout << "Weapon:    " << _game.player()->weapon()->lDescription()<< std::endl;
    std::cout << "Item:      " << "you look into your backpack, emptiness looks back. if only you had something to put in it." << "\n" <<std::endl;
    _display << "\n\nWhat would you like to do?\n";
    _display <<"view (w)eapon info. \n";
    _display <<"view (i)tem info. \n";
    _display << "Return to the previous (m)enu." << std::endl;

}

void MenuInterface::processCharacterDetails(char selection) {
    switch (selection)
    {
    case 'w':
        displayWeaponDetails();
        break;

    case 'i':
        displayItemDetails();
        break;

    case 'm':
        setMenu(Menu::Action);
        break;

    default :
        warnSelectionInvalid(selection);
        setMenu(Menu::CharacterDetails);
    }

}

void MenuInterface::displayWeaponDetails() {
    _display << "\nWeapon: "<< _game.player()->weapon()->name();
    _display << "\nMin. Damage: " << _game.player()->weapon()->getMin();
    _display << "\nMax. Damage: " << _game.player()->weapon()->getMax();
    _display << "\n" << _game.player()->weapon()->lDescription();
}

void MenuInterface::displayItemDetails() {
    if(_game.player()->item() == nullptr){
        _display << "\nYou have nothing in your bag."<<std::endl;
    }
    else{
        _display << "\nItem: "<< _game.player()->item()->name();
        _display << "\nShort description: " << _game.player()->item()->sDescription();
        _display << "\nLong description: " << _game.player()->item()->lDescription();
    }

}

void MenuInterface::actionMenu() const {
        auto room = _game.currentRoom();
        _display << "Looking around you see... ";
        /*
        if (_game.currentRoom()->getNorth()!= nullptr){
            _display <<"To the NORTH you see " << _game.currentRoom()->getNorth()->leadTo(_game.currentRoom()) ->description();
        }
        if (_game.currentRoom()->getSouth()!= nullptr){
            _display <<"To the SOUTH you see " << _game.currentRoom()->getSouth()->leadTo(_game.currentRoom()) ->description();
        }
        if (_game.currentRoom()->getEast()!= nullptr){
            _display <<"To the EAST you see " << _game.currentRoom()->getEast()->leadTo(_game.currentRoom()) ->description();
        }
        if (_game.currentRoom()->getWest()!= nullptr){
            _display <<"To the WEST you see " << _game.currentRoom()->getWest()->leadTo(_game.currentRoom()) ->description();
        }
        */
        auto creature = room->getCreature();
        if (creature == NULL)// room without creature
        {
            _game.currentRoom()->description();
            _display << "What would you like to do ? \n"
                << " Go (n)orth \n"
                << " Go (e)ast\n"
                << " Go (s)outh\n"
                << " Go (w)est\n"
                << " Go (b)ack the way you came\n";
            if (_game.currentRoom()->getItem()){//if room has item
                _display << " (p)ick - up item.\n"
                << " c(o)mpare items.\n";

            }
            _display << " Use specia(l) ability\n"
                << " Use (i)tem\n"
                << " View your (c)haracter stats\n"
                << " Return to the main (m)enu\n";
        }
        else
        {
            _display << _game.currentRoom()->description() << std::endl;
            _display << "Blocking your path stands a "<<creature->name()<<": "<<creature->description()<<std::endl;
            combatMenu();
        }
}

void MenuInterface::processAction(char selection) {
    switch (selection)
    {
    case 'n':
        // exit the start room
        if (_game.currentRoom()->id() == 1){
            _display <<"After exploring *0* levels, you run out of the cave as quickly as your legs can carry you."
                       "\nAs you emerge from the darkness you are startled by the bright light and pause while your eyes adjust.";
            _game.destroy();
            setMenu(Menu::Main);
        }
        else{
            _display << "\nHeading north...";
            _game.navigate('n');
        }


        //doNavigate()
        break;
    case 'e':
        _display << "\nHeading east...";
        _game.navigate('e');
        break;
    case 's':
        _display << "\nHeading south...";
        _game.navigate('s');
        break;
    case 'w':
        _display << "\nHeading west...";
        _game.navigate('w');
        break;
    case 'c':
        _display << "\n***Character Summary***\n";
        switchToCharacterMenu();
        break;
    case 'b':
        _game.navigateBack();
        _display << "\nYou go back the way you came...\n";
        break;
    case 'l':
        processCombatAction('l');
        break;
    case 'i':
        processCombatAction('i');
        break;
    case 'p':
        processCombatAction('p');
        break;
    case 'o':
        processCombatAction('o');
        break;
    case 'm':
        processCombatAction('m');
        break;
    case 'a':
        processCombatAction('a');
        break;
    default:
        warnSelectionInvalid(selection);
        break;
    }
}

void MenuInterface::combatMenu() const {
    _display << "\nWhat would you like to do ?\n";
    _display << " Go (b)ack the way you came\n";
    _display << " (a)ttack with your weapon\n";
    _display << " use specia(l) ability\n";
    _display << " use (i)tem\n";
    _display << " View your (c)haracter stats\n";
    _display << " Return to the main (m)enu\n";
}

void MenuInterface::processCombatAction(char selection) {
    switch (selection)
    {
    case 'a':
        _display <<"Atacking!!"<< std::endl;
        doAttack();
        break;
    case 'c':
        //_display << "\n***Character Summary***\n";
        switchToCharacterMenu();
        break;
    case 'l':
        useSpecialAbility();
        break;
    case 'm':
        setMenu(Menu::Main);
        break;
    case 'i':
        useItem();
        break;
    case 'b':
        _game.navigateBack();
        break;
    default:
        warnSelectionInvalid(selection);
    }
}


// add it to character
void MenuInterface::pickupItem() {
    if (confirm("\nThis action will drop your current item. Are you sure ? "))
     {
          auto item = _game.currentRoom()->getItem();

          _display << "\nYou picked up a " << item->name() << std::endl;

          if (item->name() == "Short Sword" || item->name() =="Battle Axe" || item->name() == "Wizzard's Staff" || item->name() == "Magic Wand") // weapon
          {
              auto weapon = std::dynamic_pointer_cast<core::items::Weapon>(item);
              _game.player()->setWeapon(weapon);

          }
          // is consumable item
          else if (item->name() == "Health Potion" || item->name() == "Acid Flask" || item->name() == "Teleporter") // consumable item
          {
              auto consumable = std::dynamic_pointer_cast<core::items::ConsumableItem>(item);
              _game.player()->setItem(consumable);
          }

          _game.currentRoom()->setItem(NULL);
     }

}
// compare behavior
void MenuInterface::compareItems() {
    auto item = _game.currentRoom()->getItem();
        if (item->name() == "Health Potion" || item->name() == "Acid Flask" || item->name() == "Teleporter") // consumable item
        {
            _display << "\n***Item Comparison***" << std::endl
                << "\n--Room\n" << item->name() << "\n" << item->sDescription() << std::endl << std::endl
                << "\n--Backpack\n";

            auto mine = _game.player()->item();
            if (mine == NULL)
            {
                _display << "Your backpack is empty.\n\n" ;
            }
            else
            {
                _display<<item->name() << "\n" << item->sDescription() << "\n\n";
            }
        }
        else if ((item->name() == "Short Sword" || item->name() =="Battle Axe" || item->name() == "Wizzard's Staff" || item->name() == "Magic Wand")) // weapon
        {
            auto weapon = (core::items::Weapon*) &(*item);
            _display << "\n***Weapon Comparison***\n"
                << "\n--Room\n";
            std::cout << "\nName: "<< weapon->name()<<"\n"
                      <<"\nShort Description: " << weapon->sDescription() << "\n"
                      <<"\nLong Description: " << weapon->lDescription()<< std::endl;

            _display << "\n--Equipped\n";
            auto mine = _game.player()->weapon();
            displayWeaponDetails();
        }


}
// attck behavior
void MenuInterface::doAttack() {
    _display << "\nYou attack the creature...";
        auto room = _game.currentRoom();
        auto player = _game.player();
        auto creature = room->getCreature();
        int damage = 0;
        int creatureHealth = creature->getHealth();
        int playerHealth = player->getHealth();
        // you attack

        if (rand() % 100 > creature->getDodge())// your attack missed by creature
            _display << "dodged by the creature!" << std::endl;
        else
            creatureHealth -= player->attack();// gotya
            _display << "*" << damage << "* damages to the creature." << std::endl;

        // creature dead?
        if (creature->getHealth() <= 0)
        {
            _display << "You win the fight!" << std::endl;
            if (room->getItem() != NULL)
            {
                _display << "Digging through the remains of the creature you find something interesting." << std::endl;
                setMenu(Menu::Action);
            }
            room->setCreature(NULL);
            setMenu(Menu::Action);
            return;
        }

        //you are attacked
        _display << "The creature attacks...";

        if (rand() % 100 > player->getDodge())
            _display << "dodged by you!" << std::endl;
        else
            playerHealth -= creature->getDamage();
            _display << "*" << damage << "* damages to you." << std::endl;

        // you dead?
        if (player->getHealth() <= 0)
        {
            _display << "You lose the fight!" << std::endl;
            leaveDungeon();
            setMenu(Menu::Main);
            return;
        }

}
//use consumable item
void MenuInterface::useItem() {
    auto item = _game.player()->item();
        if (item != NULL)
        {
            _display << "You use an item("<<item->name()<<")...";
            auto room = _game.currentRoom();
            auto player = _game.player();
            auto creature = _game.currentRoom()->getCreature();

            if (item->name() == "Health Potion"){
                player->setHealth(player->getHealth()+ 25);
                if (player->getHealth()> 50){
                    player->setHealth(50);

                }
                player->setItem(NULL);
            }
            if (item->name() == "Acid Flask"){
                creature->setHealth(creature->getHealth() - 10);
                if(creature->getHealth()<=0){
                    creature->setHealth(0);
                }
                player->setItem(NULL);
            }

    }
}
// use weapon ability
void MenuInterface::useSpecialAbility() {
    auto weapon = _game.player()->weapon();
    auto creature = _game.currentRoom()->getCreature();
        if (weapon != NULL)
        {
            if(weapon->name() == "Wizzard's Staff"){
                creature->setHealth(creature->getHealth() - (rand() % 11 + 10));
                if(creature->getHealth()<=0){
                    creature->setHealth(0);
                }
            }
            if(weapon->name() == "Magic Wand"){
                _game.player()->setHealth(50);
            }
        }
}

void MenuInterface::leaveDungeon() {
    _display << "\nAfter exploring * " << _game.level() << " * levels, you run out of the cave as quickly as your legs can carry you.\n";
        _display << "\nAs you emerge from the darkness you are startled by the bright light and pause while your eyes adjust.\n";
        _game.destroy();
        setMenu(Menu::Main);
}

bool MenuInterface::confirm(const std::string &confirmationPrompt) const {
    _display << confirmationPrompt.c_str() << " (y/n)" << std::endl;
     char ch = getCharacterInput();

     if (ch == 'y' || ch == 'Y'){
         return true;
     }
     else{
         return false;
     }

}
