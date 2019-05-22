#include "BoardView.h"


BoardView::BoardView()
{
    width=boardWidth*sizX;
    height=boardHeight*sizX;
}

void BoardView::draw(sf::RenderWindow &window)
{

    sf::RectangleShape rectangle(sf::Vector2f(width+100, height+100));
    sf::RectangleShape rectangle1(sf::Vector2f(width, height));

    rectangle.setFillColor(sf::Color(160, 95, 0));
    rectangle1.setPosition(x0,y0);
    rectangle1.setFillColor(sf::Color::Green);


    window.draw(rectangle);
    window.draw(rectangle1);

}
//dla frukta
int BoardView::getboardWidth()
{
    return boardWidth;
}


int BoardView::getboardHeight()
{
    return boardHeight;
}

//dla rysowania
int BoardView::getWidth()
{
    return width;
}


int BoardView::getHeight()
{
    return height;
}

int BoardView::getSizX()
{
    return sizX;
}
