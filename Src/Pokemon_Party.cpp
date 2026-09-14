//
// Created by tompi on 14/09/2026.
//
#include "../Inc/Pokemon_Party.h"

#include <algorithm>
#include <iostream>


Pokemon_Party::Pokemon_Party()= default;

void Pokemon_Party::addToParty( Pokemon pokemon) {
    if (Party.size() < party_size_max){
        Party.push_back(pokemon);
    }
    else {
        std::cout << "Pokemons party is already full" << std::endl;
    }
}

void Pokemon_Party::catchPokemon(Pokemon pokemon) {
    float catchrate = 1- pokemon.getHitPoint()/300;
    float r = ((double) rand() / (RAND_MAX));
    if (r <= catchrate) {
        std::cout << pokemon.getName()<< " caught!" << std::endl;
        addToParty(pokemon);
    }
    else {
        std::cout << "Failed to capture " << pokemon.getName() <<std::endl;
    }
}

void Pokemon_Party::removeFromParty(int index) {
    Party.erase(Party.begin()+index);
}

void Pokemon_Party::sendtoBattle(Pokemon pokemon) {

}

void Pokemon_Party::returnToParty(Pokemon pokemon) {

}

void Pokemon_Party::showParty() {
    std::cout << "Pokemons in party:" << std::endl;
    for (Pokemon pokemon : Party) {
        std::cout << pokemon.getName() << std::endl;
    }
}

Pokemon_Party::~Pokemon_Party() {

}

Pokemon Pokemon_Party::GetPokemonById(int id) {

}

Pokemon Pokemon_Party::GetPokemonByName(string name) {

}