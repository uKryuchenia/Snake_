#ifndef SNAKE_H
#define SNAKE_H

#include <BoardView.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>

using namespace std;

enum Direction  { Up, Down, Left, Right};

struct Field{

    int x;
    int y;
};

class Snake{

    BoardView & board;

    int quantity=3;
    Field snake[100];
    int score=0;
    Direction dir=Right;

    bool start = false;
    bool gameOver=false;
    float timeRestart=0, pause=0.45, time=0;

    sf::Texture Texture1,Texture2,Texture3;
    sf::Sprite head,body,finish;
    sf::Clock clock;
    sf::Font font;
    sf::Text text,text1;

    sf::SoundBuffer buffer1;
    sf::Sound gameO;

public:

    Snake(BoardView & b);
    string intToString(int x);
    void setScore();
    void timer();
    void motion();
    void setFruitS();
    void handleEvent(sf::Event &event);
    void draw(sf::RenderWindow &window);
    int snakeX(int x);
    int snakeY(int y);
    int setScoreGameCon();
    int setQuantyti();
    int getQuantyti();
};

#endif // SNAKE_H
