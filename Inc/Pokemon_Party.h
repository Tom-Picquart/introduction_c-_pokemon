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

    Pokemon_Party(string pokemon1, string pokemon2, string pokemon3, string pokemon4, string pokemon5 , string pokemon6);
    void addToParty(const Pokemon& pokemon);
    void sendtoBattle(int index);
    Pokemon* getFirstPokemon();
    Pokemon* getPokemon(int index);
    void healPokemon(int index);
    void healAll();
    void showPartyHP() const;
    int getSize() const;
    Pokemon GetPokemonByName(string name) override;
    Pokemon GetPokemonById(int id) override;

    ~Pokemon_Party() override;
};
#endif //TICTACTOE_POKEMON_PARTY_H
