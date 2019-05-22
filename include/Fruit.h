#ifndef FRUIT_H
#define FRUIT_H

#include <BoardView.h>
#include <Snake.h>
#include <SFML/Graphics.hpp>


class Fruit
{
    BoardView &board;
    Snake &snak;
    int x=0, x1=0,y=0, y1=0;
    sf::Texture texture;
    sf::Sprite cherry;

public:
    Fruit(BoardView & board, Snake &snak);
    void draw(sf::RenderWindow &window);
    void setFruit();
    int getFruitX();
    int getFruitY();

};

#endif // FRUIT_H
