//
// Created by tompi on 18/09/2026.
//
#include "..//Inc//SelectPokemonState.h"
#include "..//Inc//BattleState.h"
#include "..//Inc//Game.h"
#include "..//Inc//Pokedex.h"

#include <iostream>
#include <memory>
#include <random>


void SelectPokemonState::generateStarters(){
    Pokedex* pokedex = Pokedex::getInstance();

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 721);

    int id1 = distrib(gen);
    int id2 = distrib(gen);
    int id3 = distrib(gen);

    starter1 = std::make_unique<Pokemon>(pokedex->GetPokemonById(id1));
    starter2 = std::make_unique<Pokemon>(pokedex->GetPokemonById(id2));
    starter3 = std::make_unique<Pokemon>(pokedex->GetPokemonById(id3));

    sprite1.load(*starter1);
    sprite2.load(*starter2);
    sprite3.load(*starter3);

    sprite1.setPosition(100.f, 180.f);
    sprite2.setPosition(500.f, 180.f);
    sprite3.setPosition(900.f, 180.f);

    sprite1.setScale(3.f, 3.f);
    sprite2.setScale(3.f, 3.f);
    sprite3.setScale(3.f, 3.f);

    startersGenerated = true;
}

void SelectPokemonState::handleEvent(Game& game,const sf::Event& event){
    if (!startersGenerated){
        generateStarters();
    }

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left){
        float mouseX = static_cast<float>(event.mouseButton.x);
        float mouseY = static_cast<float>(event.mouseButton.y);

        if (mouseX >= 50.f && mouseX <= 400.f && mouseY >= 150.f && mouseY <= 500.f){
            game.getParty().addToParty(*starter1);
            game.setState(std::make_unique<BattleState>());
            return;
        }

        if (mouseX >= 450.f && mouseX <= 800.f && mouseY >= 150.f && mouseY <= 500.f){
            game.getParty().addToParty(*starter2);
            game.setState(std::make_unique<BattleState>());
            return;
        }

        if (mouseX >= 850.f && mouseX <= 1200.f && mouseY >= 150.f && mouseY <= 500.f){
            game.getParty().addToParty(*starter3);
            game.setState(std::make_unique<BattleState>());
        }
    }
}

void SelectPokemonState::update(Game& game){}

void SelectPokemonState::render(Game& game){
    sf::RenderWindow& window = game.getWindow();

    if (!startersGenerated)
        return;

    sprite1.draw(window);
    sprite2.draw(window);
    sprite3.draw(window);

    sf::Text name;

    name.setFont(game.getFont());
    name.setString("Choose your starter");
    name.setCharacterSize(28);
    name.setPosition(470.f, 20.f);

    window.draw(name);
}