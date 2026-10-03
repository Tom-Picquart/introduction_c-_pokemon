//
// Created by tompi on 27/09/2026.
//

#ifndef TICTACTOE_RESTSTATE_H
#define TICTACTOE_RESTSTATE_H
#include <SFML/Graphics.hpp>
#include <memory>
#include "GameState.h"
#include "PokemonSprite.h"
class RestState : public GameState
{
private:
    std::unique_ptr<Pokemon> defeatedPokemon;
    bool selectingPokemon = false;
    bool capturedPokemon = false;
    std::vector<std::unique_ptr<PokemonSprite>> partySprites;
    std::unique_ptr<PokemonSprite> defeatedSprite;
    void initializeSprites(Game& game);
    void handleMouseClick(Game& game, float x, float y);
    void capturePokemon(Game& game);
    void healParty(Game& game);
    void selectPokemon(Game& game, int index);
    int getPokemonIndexAt(float x, float y) const;

public:
    RestState();
    explicit RestState(std::unique_ptr<Pokemon> defeatedPokemon);
    void handleEvent(Game& game, const sf::Event& event) override;
    void update(Game& game) override;
    void render(Game& game) override;
};
#endif //TICTACTOE_RESTSTATE_H
