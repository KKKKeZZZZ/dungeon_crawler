#ifndef GAME_H
#define GAME_H
#include <map>
#include <memory>
#include <random>
#include <string>
#include <ctime>
#include "character.h"
#include "dungeon.h"

namespace core {

/*-----------------------------------------------------------------------------------
 * NOTE: DO NOT modify or remove ALREADY IMPLEMENTED members of this class.
 * You will need to COMPLETE the implementations of the suggested skeleton functions
 * and/or ADD methods to this class to implement the gameplay requirements.
 *
 * To complete the implementations of the suggested functions you will need to
 * fix their return types and/or parameters.
 *-----------------------------------------------------------------------------------*/

/**
 * @brief TODO The Game class
 */
class Game
{
public:
  int level();
  void destroy();
  void createGame();
  // TODO implement the Game class

  Game(); ///< You may need to change the parameters, accessibility, etc. of this.
  static Game* getInstance();
  /**
   * @brief player Retrieves the player's Character, if any.
   */
  std::shared_ptr<Character> player() const;

  /**
   * @brief setPlayer Sets the current player character for the game.
   */
  void setPlayer(std::shared_ptr<Character> player);

  /**
   * @brief dungeon Returns the current dungeon level, if any.
   */
  std::shared_ptr<dungeon::Dungeon> dungeon() const;

  /**
   * @brief createDungeon Initiates the creation of a new dungeon level.
   * Any previous dungeon level is destroyed.
   */
  void createDungeon(char input);

  /**
   * @brief start Initialises the game to the starting state, i.e.,
   * the character has just entered the first room of the dungeon.
   */
  void enterDungeon();

  /**
   * @brief currentRoom Answers the current room the player's character is in.
   * @return the Room the player is in
   */
  core::dungeon::Room* currentRoom() const;

  /**
   * @brief navigate Move the player's character to a neighbouring
   * Room of the current room.
   */
  void navigate(char c);

  /**
   * @brief navigateBack Move the character to the previous room.
   */
  void navigateBack();

  /**
   * @brief exitLevel update the game state with successful completion
   * of the current level.
   */
  void exitLevel();

  /**
   * @brief exitDungeon update the game to the state where the character
   * has completely left the dungeon, ready for a completely new dungeon
   * to be created.
   */
  void exitDungeon();

  /**
   * @brief doActionRound Performs a player action (weapon attack, item use,
   * or special ability), including a responding attack by a creature if one is present.
   */
  void doActionRound(char c);

  // Functions with provided implementations are declared below, DO NOT MODIFY

  /**
   * @brief randomIntBetween Returns a random integer between the provided min and max
   * values (inclusive). If max is smaller than low, the values are flipped to be safe.
   *
   * This function is a helper for randomly determining which types of room, item,
   * creature, etc., are present in a dungeon as well as determining damage values.
   *
   * @param min the low value
   * @param max the high value
   * @return the randomly generated integer
   */
  int randomIntBetweenInc(int min, int max);

  /**
   * @brief randomIntBetweenEx Returns a random integer between the provided min and max
   * values (exclusive). If max is smaller than low, the values are flipped to be safe.
   *
   * This function is a helper for randomly determining which types of room, item,
   * creature, etc., are present in a dungeon as well as determining damage values.
   *
   * @param min the low value
   * @param max the high value
   * @return the randomly generated integer
   */
  int randomIntBetweenEx(int min, int max);

  /**
   * @brief randomDouble Returns a random double in the range 0.0 - 1.0
   *
   * This function is a helper for determining whether an attack is dodged,
   * as the dodge chance is a percentage.
   *
   * @return the randomly generated double
   */
  double randomDouble();

private:
  static Game* _game;
  std::mt19937 _randomGenerator; //!< Mersenne Twister random number generator seeded by current time
  std::uniform_real_distribution<double> _realDistribution; //!< For random numbers between 0.0 & 1.0
  int _level;
  std::shared_ptr<dungeon::Dungeon> _dungeon;
  std::shared_ptr<Character> _player;
  core::dungeon::Room* _room;
  core::dungeon::Room* _previous;
  core::dungeon::Room* _mid;
  std::string _type;
};

} // namespace core

#endif // GAME_H
