//
// Created by tompi on 18/09/2026.
//

#ifndef TICTACTOE_BATTLESTATE_H
#define TICTACTOE_BATTLESTATE_H
#include "GameState.h"
#include "Pokemon.h"
#include "PokemonSprite.h"
#include <SFML/Graphics.hpp>
#include <memory>
class BattleState : public GameState
{
private:
    std::unique_ptr<Pokemon> enemyPokemon;
    PokemonSprite enemySprite;
    PokemonSprite playerSprite;
    void generateEnemy();

    void attack(Game& game);
    void flee(Game& game);

public:
    void handleEvent(Game& game, const sf::Event& event) override;
    void update(Game& game) override;
    void render(Game& game) override;
};
#endif //TICTACTOE_BATTLESTATE_H
