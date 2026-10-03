//
// Created by tompi on 18/09/2026.
//
#include <iostream>
#include "..//Inc//Game.h"
#include "..//Inc//GameOverState.h"
#include "..//Inc//StartState.h"
void GameOverState::handleEvent(
    Game& game,
    const sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Enter)
        {
            game.resetParty();

            game.setState(
                std::make_unique<StartState>()
            );
        }
    }
}

void GameOverState::update(Game& game)
{
}

void GameOverState::render(Game& game)
{
    sf::RenderWindow& window = game.getWindow();
    sf::Text start;
    sf::Text gameOver;

    start.setFont(game.getFont());
    start.setString("Press Enter to restart");
    start.setCharacterSize(28);
    start.setPosition(480.f, 500.f);

    gameOver.setFont(game.getFont());
    gameOver.setString("Game Over!");
    gameOver.setCharacterSize(35);
    gameOver.setPosition(500.f, 150.f);

    window.draw(start);
    window.draw(gameOver);
}