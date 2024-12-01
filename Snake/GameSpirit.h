#ifndef GameSpirit_H
#define GameSpirit_H    
#include <SFML/Graphics.hpp>
using namespace sf;
class GameSpirit {
public:
    virtual void draw(RenderWindow& window) = 0;
  //  virtual void update(Event& event) = 0;
    virtual bool getchk_game_over() = 0;
    virtual int getscore() = 0;
    virtual ~GameSpirit() = default;
};
#endif