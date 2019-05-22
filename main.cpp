#include <SFML/Graphics.hpp>
#include <BoardView.h>
#include <Fruit.h>
#include <Snake.h>
#include <GameController.h>

using namespace std;

int main(){

    srand (time(NULL));

    BoardView bv;
    Snake s(bv);
    Fruit fr(bv,s);
    GameController gc(s,fr,bv);

    // Create the main window
    sf::RenderWindow window(sf::VideoMode( bv.getWidth()+100, bv.getHeight()+100), "SAPER");

    // Start the game loop
    while (window.isOpen())
    {

        gc.game();

        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                window.close();

            gc.handleEvent(event);
        }
        // Clear screen
        window.clear();

        gc.draw(window);

        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}
