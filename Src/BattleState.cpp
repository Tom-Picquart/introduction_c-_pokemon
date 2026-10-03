//
// Created by tompi on 18/09/2026.
//
#include "..//Inc//BattleState.h"
#include "..//Inc//Pokedex.h"
#include "..//Inc//GameOverState.h"
#include "..//Inc//Game.h"
#include "..//Inc//RestState.h"
#include <random>
#include <iostream>
#include <memory>

void BattleState::generateEnemy(){
    Pokedex* pokedex = Pokedex::getInstance();

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 721);

    enemyPokemon = std::make_unique<Pokemon>(pokedex->GetPokemonById(distrib(gen)));
    enemySprite.load(*enemyPokemon);
    enemySprite.setPosition(800.f, 100.f);
    enemySprite.setScale(3.f, 3.f);
}

void BattleState::attack(Game &game) {
    Pokemon* playerPokemon =game.getParty().getFirstPokemon();
    playerPokemon->attacks(*enemyPokemon);
    if (enemyPokemon->isKO()) {
        game.setState(std::make_unique<RestState>(std::move(enemyPokemon)));
        return;
    }
    enemyPokemon->attacks(*playerPokemon);
    if (playerPokemon->isKO()) {
        game.setState(std::make_unique<GameOverState>());
        return;
    }
}

void BattleState::flee(Game& game)
{
    game.setState(std::make_unique<RestState>(nullptr));
}

void BattleState::handleEvent(Game& game,const sf::Event& event){
    if (enemyPokemon == nullptr){
        generateEnemy();
        std::cout << "A wild "<< enemyPokemon->getName()<< " appeared!" << std::endl;
    }
    if (event.type != sf::Event::MouseButtonPressed) {
        return;
    }
    if (event.mouseButton.button != sf::Mouse::Left) {
        return;
    }
    float mouseX =static_cast<float>(event.mouseButton.x);
    float mouseY =static_cast<float>(event.mouseButton.y);

    if (600.f<mouseX && mouseX<700.f && 600.f<mouseY && mouseY<680.f) {
        attack(game);
        return;
    }
    if(950.f<mouseX && mouseX<1050.f && 600.f<mouseY && mouseY<680.f) {
        flee(game);
        return;
    }
}

void BattleState::update(Game& game){}

void BattleState::render(Game& game){
    sf::RenderWindow& window = game.getWindow();
    Pokemon* playerPokemon =game.getParty().getFirstPokemon();
    if (playerPokemon != nullptr){
        playerSprite.load(*playerPokemon);
        playerSprite.setPosition(150.f, 350.f);
        playerSprite.setScale(3.f, 3.f);
        playerSprite.draw(window);

        sf::Text Pokemon1;
        Pokemon1.setFont(game.getFont());
        Pokemon1.setString(playerPokemon->getName()+"\n"+std::to_string((int)playerPokemon->getHitPoint())+ " / "+ std::to_string((int)playerPokemon->getMaxHitPoint())+ " HP");
        Pokemon1.setCharacterSize(28);
        Pokemon1.setPosition(150.f, 650.f);

        window.draw(Pokemon1);
    }

    enemySprite.draw(window);
    if (enemyPokemon != nullptr) {
        sf::Text Pokemon2;
        Pokemon2.setFont(game.getFont());
        Pokemon2.setString(enemyPokemon->getName()+"\n"+std::to_string((int)enemyPokemon->getHitPoint())+ " / "+ std::to_string((int)enemyPokemon->getMaxHitPoint())+ " HP");
        Pokemon2.setCharacterSize(28);
        Pokemon2.setPosition(850.f, 350.f);

        window.draw(Pokemon2);
    }

    sf::Text attackText;
    attackText.setFont(game.getFont());
    attackText.setString("ATTACK");
    attackText.setCharacterSize(28);
    attackText.setPosition(600.f,620.f);
    window.draw(attackText);

    sf::Text fleeText;
    fleeText.setFont(game.getFont());
    fleeText.setString("Flee");
    fleeText.setCharacterSize(28);
    fleeText.setPosition(950.f,620.f);
    window.draw(fleeText);
}