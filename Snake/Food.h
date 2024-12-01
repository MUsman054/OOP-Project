#ifndef FOOD_H
#define FOOD_H

#include <SFML/Graphics.hpp>
using namespace sf;

class Food {
protected:
    RectangleShape food;
    static int food_count;
    int squareSize;

public:
    Food(int cellSize = 20);
    void draw(RenderWindow& window);
    void setFoodPosition();
    Vector2f get_food_position() const;
    static int get_food_count();
    static void increase_food_count();
};

#endif // FOOD_H
