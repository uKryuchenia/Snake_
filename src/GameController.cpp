#include "GameController.h"

GameController::GameController(Snake &s,Fruit &f,BoardView & b) : snak(s),fruit(f),board(b)
{
    buffer.loadFromFile("sound/sound.ogg");
    ateFruit.setBuffer(buffer);
}
void GameController::snakeAteFruit()
{
    //zjadł frukt
    if(snak.snakeX(0)==fruit.getFruitX() and snak.snakeY(0)==fruit.getFruitY())
    {
        fruit.setFruit();

        ateFruit.play();
        snak.setQuantyti();
        snak.setScoreGameCon();
    }
}

void GameController::game()
{
    snak.timer();
    snakeAteFruit();

}

void GameController::handleEvent(sf::Event &event)
{
    snak.handleEvent(event);
}


void GameController::draw(sf::RenderWindow &window)
{
    board.draw(window);
    fruit.draw(window);
    snak.draw(window);
}



