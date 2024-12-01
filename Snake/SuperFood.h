#ifndef SUPERFOOD_H
#define SUPERFOOD_H

#include "Food.h"
#include <SFML/Graphics.hpp>

using sf::Color;

class SuperFood : public Food {
public:
    SuperFood(int cellSize = 20);
};

#endif
