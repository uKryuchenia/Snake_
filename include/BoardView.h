#ifndef BOARDVIEW_H
#define BOARDVIEW_H

#include <SFML/Graphics.hpp>


class BoardView
{

    int boardWidth=20;
    int boardHeight=15;

    int x0=50;
    int y0=50;
    int sizX=50;

    int width, height;


public:

    BoardView();
    void draw(sf::RenderWindow &window);
    int getboardWidth();
    int getboardHeight();
    int getWidth();
    int getHeight();
    int getSizX();


};

#endif // BOARDVIEW_H
