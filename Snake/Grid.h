#ifndef GRID_H
#define GRID_H

#include <SFML/Graphics.hpp>
using namespace sf;

class Grid {
private:
    RectangleShape** grid;
    int rows, cols;

public:
    Grid(int width = 800, int height = 600, int cellSize = 20);
    ~Grid();

    void draw(RenderWindow& window);
};

#endif
