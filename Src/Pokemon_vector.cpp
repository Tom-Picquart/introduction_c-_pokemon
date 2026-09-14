//
// Created by tompi on 14/09/2026.
//
#include "../Inc/Pokemon_vector.h"
#include <iostream>
#include <vector>



void Pokemon_vector::displayPokemonList() {
    for (Pokemon pokemon : arrayOfPokemon) {
        std::cout <<"Pokemon number " << pokemon.getId() <<" : " << pokemon.getName() << std::endl;
    }
}

Pokemon_vector::~Pokemon_vector() {

}

