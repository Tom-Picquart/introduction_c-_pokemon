//
// Created by tompi on 18/09/2026.
//

#ifndef TICTACTOE_SELECTSTARTERSTATE_H
#define TICTACTOE_SELECTSTARTERSTATE_H
#include "GameState.h"
#include "Pokemon.h"
#include "PokemonSprite.h"

#include <memory>

class SelectPokemonState : public GameState
{
private:
    std::unique_ptr<Pokemon> starter1;
    std::unique_ptr<Pokemon> starter2;
    std::unique_ptr<Pokemon> starter3;

    PokemonSprite sprite1;
    PokemonSprite sprite2;
    PokemonSprite sprite3;

    bool startersGenerated = false;

    void generateStarters();

public:
    void handleEvent(
        Game& game,
        const sf::Event& event
    ) override;

    void update(Game& game) override;

    void render(Game& game) override;
};

#endif //TICTACTOE_SELECTSTARTERSTATE_H
