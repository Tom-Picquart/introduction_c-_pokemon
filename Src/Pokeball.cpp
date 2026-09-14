//
// Created by tompi on 14/09/2026.
//
#include "../Inc/Pokeball.h"
#include <iostream>


Pokeball::Pokeball()= default;

void Pokeball::catchPokemon(Pokemon pokemon) {
    float catchrate = 1-(pokemon.getHitPoint()/300);

}

Pokemon Pokeball::GetPokemonById(int id) {

}

Pokemon Pokeball::GetPokemonByName(string name) {

}

Pokeball::~Pokeball() {

}