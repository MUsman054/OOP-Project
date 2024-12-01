#include "Snake.h"

Snake::Snake(int gridWidth, int gridHeight, int cellSize)
    : grid(gridWidth, gridHeight, cellSize), food(cellSize), superfood(cellSize), squareSize(cellSize),
      length(4), chk_game_over(false), is_superfood_active(false), score(0) {
    body = new RectangleShape[length];
    for (int i = 0; i < length; ++i) {
        body[i].setSize(Vector2f(squareSize, squareSize));
        body[i].setFillColor(Color::Green);
        body[i].setPosition(Vector2f(400 - i * squareSize, 300));
    }
}

Snake::~Snake() {
    delete[] body;
}

void Snake::setHeadTexture(Texture& texture) {
    body[0].setTexture(&texture);
}

void Snake::draw(RenderWindow& window) {
    grid.draw(window);

    for (int i = 0; i < length; ++i) {
        window.draw(body[i]);
    }

    food.draw(window);

    if (is_superfood_active) {
        superfood.draw(window);
    }
}

void Snake::move(int dx, int dy) {
    if (chk_game_over)
        return;

    for (int i = length - 1; i > 0; --i) {
        body[i].setPosition(body[i - 1].getPosition());
    }
    body[0].move(Vector2f(dx, dy));
}

void Snake::checkBoundary() {
    if (body[0].getPosition().x < 0)
        body[0].setPosition(Vector2f(800, body[0].getPosition().y));
    else if (body[0].getPosition().x >= 800)
        body[0].setPosition(Vector2f(0, body[0].getPosition().y));
    if (body[0].getPosition().y < 0)
        body[0].setPosition(Vector2f(body[0].getPosition().x, 600));
    else if (body[0].getPosition().y >= 600)
        body[0].setPosition(Vector2f(body[0].getPosition().x, 0));
}

void Snake::grow() {
    RectangleShape* newBody = new RectangleShape[length + 1];
    for (int i = 0; i < length; ++i) {
        newBody[i] = body[i];
    }

    newBody[length].setSize(Vector2f(squareSize, squareSize));
    newBody[length].setFillColor(Color::Green);
    newBody[length].setPosition(body[length - 1].getPosition());

    delete[] body;
    body = newBody;
    ++length;
}

void Snake::itselfCollision() {
    for (int i = 1; i < length; ++i) {
        if (body[0].getPosition() == body[i].getPosition()) {
            chk_game_over = true;
            break;
        }
    }
}

void Snake::food_eaten() {
    Vector2f foodPosition = food.get_food_position();
    Vector2f headPosition = body[0].getPosition();

    if (headPosition.x == foodPosition.x && headPosition.y == foodPosition.y) {
        food.increase_food_count();
        score += 2;
        grow();
        food.setFoodPosition();

        if (food.get_food_count() % 5 == 0) {
            is_superfood_active = true;
            superfood.setFoodPosition();
            superfood_timer.restart();
        }
    }

    if (is_superfood_active) {
        Vector2f superFoodPosition = superfood.get_food_position();
        if (headPosition.x == superFoodPosition.x && headPosition.y == superFoodPosition.y) {
            score += 5;
            grow();
            is_superfood_active = false;
        }

        if (superfood_timer.getElapsedTime().asSeconds() > 5) {
            is_superfood_active = false;
        }
    }
}

bool Snake::getchk_game_over() {
    return chk_game_over;
}

int Snake::getscore() {
    return score;
}
