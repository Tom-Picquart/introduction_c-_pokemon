//
// Created by tompi on 18/09/2026.
//


#include <iostream>
#include <memory>
#include <ostream>
#include "..//Inc//Game.h"
#include "..//Inc//StartState.h"
#include "..//Inc//SelectPokemonState.h"

void StartState::handleEvent(Game& game, const sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Enter)
        {
            game.setState(std::make_unique<SelectPokemonState>());
        }
    }
}

void StartState::update(Game& game){}

void StartState::render(Game& game){
    sf::RenderWindow& window = game.getWindow();
    sf::Text start;
    sf::Text pokemon;

    start.setFont(game.getFont());
    start.setString("Press Enter");
    start.setCharacterSize(28);
    start.setPosition(480.f, 500.f);

    pokemon.setFont(game.getFont());
    pokemon.setString("Pokemon");
    pokemon.setCharacterSize(35);
    pokemon.setPosition(500.f, 150.f);

    window.draw(start);
    window.draw(pokemon);
}