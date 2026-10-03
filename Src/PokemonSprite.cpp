//
// Created by tompi on 27/09/2026.
//
#include "../Inc/PokemonSprite.h"

#include <iostream>
#include <string>

PokemonSprite::PokemonSprite()
{
}

bool PokemonSprite::load(const Pokemon& pokemon)
{
    std::string path =
        "../image_pokedex-20260914/pokemon/"
        + std::to_string(pokemon.getId())
        + ".png";

    if (!texture.loadFromFile(path))
    {
        std::cerr << "Unable to load Pokemon image: "
                  << path
                  << std::endl;

        return false;
    }

    sprite.setTexture(texture);

    return true;
}

void PokemonSprite::setPosition(float x, float y)
{
    sprite.setPosition(x, y);
}

void PokemonSprite::setScale(float x, float y)
{
    sprite.setScale(x, y);
}

void PokemonSprite::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}