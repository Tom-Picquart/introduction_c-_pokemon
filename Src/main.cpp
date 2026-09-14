#include <SFML/Graphics.hpp>
#include "../Inc/pokemon.h"
#include"../Inc/Pokedex.h"
#include "../Inc/Pokemon_party.h"
#include <iostream>
#include <vector>
int main() {
    string starter;
    Pokemon_Party party;
    Pokedex *pokedex= Pokedex::getInstance();
    std::cout<<"choose a starter";
    std::cin>>starter;
    Pokemon Starter= pokedex->GetPokemonByName(starter);
    party.addToParty(Starter);
    Pokemon Pikachu= pokedex->GetPokemonByName("Pikachu");
    Pokemon mystery= pokedex->GetPokemonById(130);
    party.addToParty(mystery);
    party.addToParty(Pikachu);
    party.removeFromParty(2);
    party.showParty();

}