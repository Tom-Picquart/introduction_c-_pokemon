//
// Created by tompi on 18/09/2026.
//
#include <SFML/Graphics.hpp>

#ifndef TICTACTOE_GAMESTATE_H
#define TICTACTOE_GAMESTATE_H
class Game;
class GameState
{
public:
    virtual ~GameState() = default;

    virtual void handleEvent(
        Game& game,
        const sf::Event& event
    ) = 0;

    virtual void update(Game& game) = 0;

    virtual void render(Game& game) = 0;
};

#endif //TICTACTOE_GAMESTATE_H
