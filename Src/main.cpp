#include <SFML/Graphics.hpp>
#include "../Inc/main.h"
#include <iostream>
#include <vector>
int main() {
    sf::RenderWindow window(
        sf::VideoMode(1280, 720),
        "Pokemon Battle"
    );

    window.setFramerateLimit(60);

    Game game(window);

    game.run();

    return 0;
}



