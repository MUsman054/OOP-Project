#ifndef SNAKE_H
#define SNAKE_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Grid.h"
#include "Food.h"
#include "SuperFood.h"
#include "GameSpirit.h"

using namespace sf;

class Snake : public GameSpirit {
private:
    RectangleShape* body;
    int length;
    int squareSize;
    Grid grid;
    Food food;
    SuperFood superfood;
    int score;
    bool chk_game_over;
    bool is_superfood_active;
    Clock superfood_timer;

public:
    Snake(int gridWidth = 800, int gridHeight = 600, int cellSize = 20);
    ~Snake();

    void setHeadTexture(Texture& texture);
    void draw(RenderWindow& window);
    void move(int dx, int dy);
    void checkBoundary();
    void grow();
    void itselfCollision();
    void food_eaten();

    bool getchk_game_over();
    int getscore();
};

#endif
