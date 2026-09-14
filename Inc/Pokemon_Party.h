//
// Created by tompi on 14/09/2026.
//

#ifndef TICTACTOE_POKEMON_PARTY_H
#define TICTACTOE_POKEMON_PARTY_H
#include "Pokemon_vector.h"


class Pokemon_Party: public Pokemon_vector {
private:
    std::vector<Pokemon> Party;
    int party_size_max=6;
public:

    Pokemon_Party();
    void catchPokemon(Pokemon pokemon);
    void addToParty(Pokemon pokemon);
    void removeFromParty( int index);
    void sendtoBattle(Pokemon pokemon);
    void returnToParty(Pokemon pokemon);
    void showParty();
    Pokemon GetPokemonByName(string name) override;
    Pokemon GetPokemonById(int id) override;

    ~Pokemon_Party() override;
};
#endif //TICTACTOE_POKEMON_PARTY_H
