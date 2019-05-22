#include "Snake.h"

Snake::Snake(BoardView &b) : board(b)
{
    snake[0].x = board.getboardWidth()/2;
    snake[0].y = board.getboardHeight()/2;

    for(int i=1; i<quantity; i++)
    {
        snake[i].x = snake[i-1].x-1;
        snake[i].y = snake[i-1].y;
    }
    setScore();


    buffer1.loadFromFile("sound/GameOver.ogg");
    gameO.setBuffer(buffer1);


    if (!font.loadFromFile("arial.ttf"))
    {
        std::cout<<"error"<<std::endl;
    }

    text.setFont(font);
    text.setString("Score  =  " );
    text1.setFont(font);

    text.setPosition(board.getWidth()/2-board.getSizX(),0);
    text.setCharacterSize(board.getSizX()*0.8);
    text.setColor(sf::Color::Black);

    text1.setPosition(board.getWidth()/2+2.5*board.getSizX(),0);
    text1.setCharacterSize(board.getSizX()*0.8);
    text1.setColor(sf::Color::Black);

    Texture1.loadFromFile("images/blue.png");
    head.setTexture(Texture1);
    Texture2.loadFromFile("images/white.png");
    body.setTexture(Texture2);
    Texture3.loadFromFile("images/finish.png");
    finish.setTexture(Texture3);
}

string Snake::intToString(int x)
{
    stringstream ss;
    ss << x << endl;
    string newString = ss.str();
    return newString;
}

void Snake::setScore()
{
    text1.setString(intToString(score));
}

void Snake::timer()
{
    time = clock.getElapsedTime().asSeconds();
    clock.restart();
    timeRestart+=time;

    if (timeRestart>pause and gameOver!=true)
    {
        timeRestart=0;

        //funkcja ruchu snake
        motion();
        setScore();
    }

    if(score==3){ pause=0.4; }
    if(score==6){ pause=0.35; }
    if(score==10){ pause=0.33; }
    if(score==15){ pause=0.3; }
    if(score==20){ pause=0.25; }
    if(score==25){ pause=0.2; }
}

void Snake::motion()
{
    if(start) {

        for(int i=quantity; i>0; i--)
        {
            snake[i].x = snake[i-1].x;
            snake[i].y = snake[i-1].y;
        }

        if(dir == Up)
            snake[0].y=snake[0].y-1;

        if(dir == Down)
            snake[0].y=snake[0].y+1;

        if(dir == Left)
            snake[0].x=snake[0].x-1;

        if(dir == Right)
            snake[0].x=snake[0].x+1;
    }

    //wyszedłeś za granicy pola
    if(snake[0].x<0 or snake[0].x > board.getboardWidth()-1 or snake[0].y<0 or snake[0].y > board.getboardHeight()-1){
        gameOver=true;
        gameO.play();
    }

    //czy zjadł sam siebie
    for(int i=quantity; i>1; i--)
    {
        if(snake[i].x == snake[0].x and snake[i].y==snake[0].y )
            gameOver=true;
            gameO.play();
    }
}

void Snake::handleEvent(sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        start=true;

        if (event.key.code == sf::Keyboard::Up)
        {
            if(dir == Down) {}
            else
                dir = Up;
        }

        if (event.key.code == sf::Keyboard::Down)
        {
            if(dir == Up) {}
            else
                dir = Down;
        }

        if (event.key.code == sf::Keyboard::Left)
        {
            if(dir == Right) {}
            else
                dir = Left;
        }

        if (event.key.code == sf::Keyboard::Right)
        {
            if(dir == Left) {}
            else
                dir = Right;
        }
    }
}

void Snake::draw(sf::RenderWindow &window)
{
    if(gameOver==false)
    {
        head.setPosition(snake[0].x*50+50,snake[0].y*50+50);

        for (int i=0; i<quantity; i++)
        {
            body.setPosition(snake[i].x*50+50,snake[i].y*50+50);
            window.draw(body);
        }
        window.draw(text);
        window.draw(text1);
        window.draw(head);
    }
    else
    {
        window.clear();
        finish.setPosition(150,150);
        window.draw(finish);
    }
}

int Snake::snakeX(int x)
{
    return snake[x].x;
}

int Snake::snakeY(int y)
{
    return snake[y].y;
}

int Snake::setQuantyti()
{
    quantity++;
}

int Snake::getQuantyti()
{
    return quantity;
}

int Snake::setScoreGameCon()
{
    score++;
}
/*
bool Snake::fruitInSnake()
{
    for(int i=quantity; i>1; i--)
    {
        if(snake[i].x==fruit.getFruitX() and snake[i].y==fruit.getFruitY() )
            return true;
    }
}
*/
