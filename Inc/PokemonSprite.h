//
// Created by tompi on 27/09/2026.
//

#ifndef TICTACTOE_POKEMONSPRITE_H
#define TICTACTOE_POKEMONSPRITE_H
#include <SFML/Graphics.hpp>
#include "Pokemon.h"

class PokemonSprite
{
private:
    sf::Texture texture;
    sf::Sprite sprite;

public:
    PokemonSprite();

    bool load(const Pokemon& pokemon);

    void setPosition(float x, float y);

    void setScale(float x, float y);

    void draw(sf::RenderWindow& window);
};

#endif //TICTACTOE_POKEMONSPRITE_H
