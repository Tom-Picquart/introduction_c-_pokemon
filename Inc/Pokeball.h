//
// Created by tompi on 14/09/2026.
//
#include "Pokemon_vector.h"
#ifndef TICTACTOE_POKEBALL_H
#define TICTACTOE_POKEBALL_H
class Pokeball: public Pokemon_vector {
private:

public:
    Pokeball();
    void catchPokemon(Pokemon pokemon);
    Pokemon GetPokemonByName(string name) override;
    Pokemon GetPokemonById(int id) override;

    ~Pokeball() override;
};
#endif //TICTACTOE_POKEBALL_H
