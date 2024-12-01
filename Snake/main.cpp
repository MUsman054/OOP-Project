#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include"GameSpirit.h"
#include "Snake.h"
#include "Food.h"
#include "SuperFood.h"
#include "Grid.h"

using namespace sf;
using namespace std;


int main() 
{
    RenderWindow window(VideoMode(800, 600), "Snake Game");
    Snake snake;
    sf::Music music;
    music.openFromFile("snakeSound.ogg");
    
    music.play();
    music.setLoop(true);
     sf::Texture snaki;
    snaki.loadFromFile("images2.png");
     
    
    snake.setHeadTexture(snaki);
    

    Font font;
    font.loadFromFile("arial.ttf");

    Text game_over;
    game_over.setFont(font);
    game_over.setCharacterSize(50);
    game_over.setFillColor(Color::Red);
    game_over.setPosition(250, 250);

    Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(30);
    scoreText.setFillColor(Color::Blue);
    scoreText.setPosition(0, 0);

    window.setFramerateLimit(15);

    int dx = 20, dy = 0;
    bool pause_game = false;
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == Event::Closed)
                window.close();
        }

        if (!snake.getchk_game_over()) {
            if (Keyboard::isKeyPressed(Keyboard::Up) && dy == 0) {
                dx = 0;
                dy = -20;
            }
            if (Keyboard::isKeyPressed(Keyboard::Down) && dy == 0) {
                dx = 0;
                dy = 20;
            }
            if (Keyboard::isKeyPressed(Keyboard::Left) && dx == 0) {
                dx = -20;
                dy = 0;
            }
            if (Keyboard::isKeyPressed(Keyboard::Right) && dx == 0) {
                dx = 20;
                dy = 0;
            }
            if(Keyboard::isKeyPressed(Keyboard::Escape))
            {
                pause_game = true;
            }
            if(Keyboard::isKeyPressed(Keyboard::P) && pause_game)
            {
                pause_game = false;
            }
            if(!pause_game)
            {
                snake.move(dx, dy);
            snake.checkBoundary();
            snake.itselfCollision();
            snake.food_eaten();}
        }

        scoreText.setString("Score: " + to_string(snake.getscore()));

        window.clear();
        snake.draw(window);
        window.draw(scoreText);

        if (snake.getchk_game_over()) 
        {
            game_over.setString("Game Over\nYour Score: " + to_string(snake.getscore()));
            window.draw(game_over);
        }

        window.display();
    }

    return 0;
}
