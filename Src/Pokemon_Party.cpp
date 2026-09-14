//
// Created by tompi on 14/09/2026.
//
#include "../Inc/Pokemon_Party.h"

#include <algorithm>
#include <iostream>


Pokemon_Party::Pokemon_Party()= default;

void Pokemon_Party::addToParty( Pokemon pokemon) {
    Party.push_back(pokemon);
}

void Pokemon_Party::removeFromParty(int index) {
    Party.erase(Party.begin()+index);
}
Pokemon Pokemon_Party::GetPokemonById(int id) {

}

Pokemon Pokemon_Party::GetPokemonByName(string name) {

}
void Pokemon_Party::showParty() {
    std::cout << "Pokemons in party:" << std::endl;
    for (Pokemon pokemon : Party) {
        std::cout << pokemon.getName() << std::endl;
    }
}

Pokemon_Party::~Pokemon_Party() {

}