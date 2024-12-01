#include "Grid.h"

Grid::Grid(int width, int height, int cellSize) {
    rows = height / cellSize;
    cols = width / cellSize;

    grid = new RectangleShape*[rows];
    for (int i = 0; i < rows; ++i) {
        grid[i] = new RectangleShape[cols];
        for (int j = 0; j < cols; ++j) {
            grid[i][j].setSize(Vector2f(cellSize - 1, cellSize - 1));
            grid[i][j].setFillColor(Color::White);
            grid[i][j].setPosition(Vector2f(j * cellSize, i * cellSize));
        }
    }
}

Grid::~Grid() {
    for (int i = 0; i < rows; ++i) {
        delete[] grid[i];
    }
    delete[] grid;
}

void Grid::draw(RenderWindow& window) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            window.draw(grid[i][j]);
        }
    }
}
