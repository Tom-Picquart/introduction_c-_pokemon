//
// Created by tompi on 18/09/2026.
//

#ifndef TICTACTOE_GAME_H
#define TICTACTOE_GAME_H
#include <iostream>
#include <memory>
#include "Pokemon_Party.h"
#include "GameState.h"
#include <SFML/Graphics.hpp>
class Game {
private:
    sf::RenderWindow& window;
    sf::Font font;
    std::unique_ptr<GameState> state;
    Pokemon_Party playerParty;
    int healUses = 0;
    static constexpr int MAX_HEAL_USES = 5;

public:
    Game(sf::RenderWindow& window);
    void setState(std::unique_ptr<GameState> newState);
    void run();
    Pokemon_Party& getParty();
    void resetParty();
    sf::RenderWindow& getWindow();
    sf::Font& getFont();
    bool canHeal() const;
    void healParty();
    int getHealUses() const;
    int getRemainingHeals() const;
};
#endif //TICTACTOE_GAME_H
