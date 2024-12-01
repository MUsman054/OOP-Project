#include "SuperFood.h"

SuperFood::SuperFood(int cellSize)
    : Food(cellSize) { 
    food.setFillColor(Color::Yellow); 
    setFoodPosition();
}
