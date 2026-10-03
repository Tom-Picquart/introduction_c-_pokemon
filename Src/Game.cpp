//
// Created by tompi on 18/09/2026.
//
#include "..//Inc//Game.h"
#include "..//Inc//StartState.h"
#include "..//Inc//Pokemon_Party.h"
#include <iostream>
#include <memory>

Game::Game(sf::RenderWindow& window): window(window),playerParty("","","","","",""){
    font.loadFromFile("../font/alk-life-webfont.ttf");
    state = std::make_unique<StartState>();
}


void Game::setState(std::unique_ptr<GameState> newState){
    state = std::move(newState);
}

void Game::run(){
    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }

            state->handleEvent(*this, event);
        }

        state->update(*this);
        window.clear();
        state->render(*this);
        window.display();
    }
}

bool Game::canHeal() const{
    return healUses < MAX_HEAL_USES;
}

int Game::getHealUses() const{
    return healUses;
}

int Game::getRemainingHeals() const{
    return MAX_HEAL_USES - healUses;
}

void Game::healParty(){
    if (!canHeal())
        return;

    playerParty.healAll();

    healUses++;
}

Pokemon_Party& Game::getParty(){
    return playerParty;
}

void Game::resetParty(){
    playerParty = Pokemon_Party("","","","","","");
    healUses = 0;
}

sf::RenderWindow& Game::getWindow(){
    return window;
}

sf::Font& Game::getFont(){
    return font;
}