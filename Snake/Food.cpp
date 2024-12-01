#include "Food.h"
#include <cstdlib>

int Food::food_count = 0;

Food::Food(int cellSize) : squareSize(cellSize) {
    food.setSize(Vector2f(squareSize, squareSize));
    food.setFillColor(Color::Red);
    setFoodPosition();
}

void Food::draw(RenderWindow& window) {
    window.draw(food);
}

void Food::setFoodPosition() {
    int f_x = (rand() % (800 / squareSize)) * squareSize;
    int f_y = (rand() % (600 / squareSize)) * squareSize;
    food.setPosition(Vector2f(f_x, f_y));
}

Vector2f Food::get_food_position() const {
    return food.getPosition();
}

int Food::get_food_count() {
    return food_count;
}

void Food::increase_food_count() {
    ++food_count;
}
