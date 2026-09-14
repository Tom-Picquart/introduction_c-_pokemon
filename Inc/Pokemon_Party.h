//
// Created by tompi on 14/09/2026.
//

#ifndef TICTACTOE_POKEMON_PARTY_H
#define TICTACTOE_POKEMON_PARTY_H
#include "Pokemon_vector.h"

class Pokemon_Party: public Pokemon_vector {
private:
    std::vector<Pokemon> Party;
public:

    Pokemon_Party();
    void addToParty( Pokemon pokemon);
    void removeFromParty( int index);
    void showParty();
    Pokemon GetPokemonByName(string name) override;
    Pokemon GetPokemonById(int id) override;

    ~Pokemon_Party() override;
};
#endif //TICTACTOE_POKEMON_PARTY_H
