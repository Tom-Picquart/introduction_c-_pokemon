//
// Created by tompi on 14/09/2026.
//

#ifndef TICTACTOE_POKEMON_VECTOR_H
#define TICTACTOE_POKEMON_VECTOR_H
#include <string>
#include <vector>
#include "pokemon.h"

class Pokemon_vector {
public:
    std::vector<Pokemon> arrayOfPokemon;
    virtual Pokemon GetPokemonByName(string name) = 0;
    virtual Pokemon GetPokemonById(int id) = 0;
    void displayPokemonList();


    virtual ~Pokemon_vector();
};

#endif //TICTACTOE_POKEMON_VECTOR_H
