#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <SFML/Audio.hpp>
#include <Fruit.h>
#include <Snake.h>
#include <BoardView.h>

class GameController
{

    Snake &snak;
    Fruit &fruit;
    BoardView & board;

    sf::Sound ateFruit;
    sf::SoundBuffer buffer;

public:
    GameController(Snake &s,Fruit &f,BoardView & b);

    void snakeAteFruit();
    void game();
    void handleEvent(sf::Event &event);
    void draw(sf::RenderWindow &window);

};

#endif // GAMECONTROLLER_H
