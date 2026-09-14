//
// Created by tompi on 11/09/2026.
//

#ifndef C___POKEDEX_H
#define C___POKEDEX_H
#include "Pokemon_vector.h"


class Pokedex: public Pokemon_vector {
    private:
    Pokedex(string fileName);
    static Pokedex* instance;
    public:
    static Pokedex  *getInstance();
    Pokemon GetPokemonByName(string name) override;
    Pokemon GetPokemonById(int id) override;

    ~Pokedex() override;
};
#endif //C___POKEDEX_H
