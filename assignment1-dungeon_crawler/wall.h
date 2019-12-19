#ifndef WALL_H
#define WALL_H
#include <string>
namespace core {
namespace dungeon {

/**
 * @brief TODO The Wall class
 */
class Wall
{
public:
  Wall(const std::string& description = "");
  const std::string& getDescription();
private:
  std::string  _description;
};

} // namespace dungeon
} // namespace core

#endif // WALL_H
