#include "Fruit.h"
#include <iostream>


Fruit::Fruit(BoardView &b,Snake &s) : board(b),snak(s)
{
    setFruit();
    texture.loadFromFile("images/1.png");
    cherry.setTexture(texture);
}

void Fruit::setFruit(){

    //wspólrzędne wiśni
    x=rand() % board.getboardWidth();
    y=rand() % board.getboardHeight();

    for(int i=snak.getQuantyti(); i>1; i--)
    {
        if(x==snak.snakeX(i) and y==snak.snakeY(i) )
            setFruit();
    }

    //wspólrzędne ekranowe
    x1=x*50+50;
    y1=y*50+50;

}

void Fruit::draw(sf::RenderWindow &window){

    cherry.setPosition(x1, y1);
    window.draw(cherry);
}

//getery wspólrzędnych wiśni dla klasy Snake
int Fruit::getFruitX(){
    return x;
}

int Fruit::getFruitY(){
    return y;
}
