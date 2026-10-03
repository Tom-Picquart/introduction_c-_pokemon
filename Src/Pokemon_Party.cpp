//
// Created by tompi on 14/09/2026.
//
#include "../Inc/Pokemon_Party.h"
#include "../Inc/Pokedex.h"

#include <algorithm>
#include <iostream>
#include <utility>

Pokemon_Party::Pokemon_Party(string pokemon1, string pokemon2, string pokemon3, string pokemon4, string pokemon5, string pokemon6) {
    Pokedex *pokedex= Pokedex::getInstance();
    if (!pokemon1.empty()) {
        std::cout<<"adding " << pokemon1<< " to the party"<<std::endl;
        Pokemon firstpokemon= pokedex->GetPokemonByName(std::move(pokemon1));
        addToParty(firstpokemon);
    }
    if (!pokemon2.empty()) {
        std::cout<<"adding "<< pokemon2<< " to the party"<<std::endl;
        Pokemon secondpokemon= pokedex->GetPokemonByName(std::move(pokemon2));
        addToParty(secondpokemon);
    }
    if (!pokemon3.empty()) {
        std::cout<<"adding "<< pokemon3<< " to the party"<<std::endl;
        Pokemon thirdpokemon= pokedex->GetPokemonByName(std::move(pokemon3));
        addToParty(thirdpokemon);
    }
    if (!pokemon4.empty()) {
        std::cout<<"adding "<< pokemon4<< " to the party"<<std::endl;
        Pokemon fourthpokemon= pokedex->GetPokemonByName(std::move(pokemon4));
        addToParty(fourthpokemon);
    }
    if (!pokemon5.empty()) {
        std::cout<<"adding "<< pokemon5<< " to the party"<<std::endl;
        Pokemon fifthpokemon= pokedex->GetPokemonByName(std::move(pokemon5));
        addToParty(fifthpokemon);
    }
    if (!pokemon6.empty()) {
        std::cout<<"adding "<< pokemon6<< " to the party"<<std::endl;
        Pokemon sixthpokemon= pokedex->GetPokemonByName(std::move(pokemon6));
        addToParty(sixthpokemon);
    }

};

void Pokemon_Party::addToParty (const Pokemon& pokemon) {
    if (Party.size() < party_size_max){
        Party.push_back(pokemon);
    }
    else {
        int index;
        std::cout << " Party is already full, select a pokemon to remove (index 0 to 5, give an index out of range to not add the pokemon to the party)";
        std::cin >> index;
        if (index >= 0 && index < Party.size()) {
            std::cout << Party[index].getName() <<" was removed from the Party" <<std::endl;
            Party.erase(Party.begin()+index);
            Party.push_back(pokemon);
        }
        else {
            std::cout << pokemon.getName()<<" was not added to the Party" << std::endl;
        }
    }
}



//we consider that the first Pokemon in the Party is the one in battle
void Pokemon_Party::sendtoBattle(int index) {
    if (index < 0 || index >= Party.size()) {
        std::cout << "Invalid Pokemon index, first pokemon will be sent" << std::endl;
        return;
    }
    std::swap(Party[0], Party[index]);
}

Pokemon* Pokemon_Party::getFirstPokemon() {
    return &Party[0];
}
Pokemon* Pokemon_Party::getPokemon(int index){
    if (index < 0 || index >= static_cast<int>(Party.size())){
        return nullptr;
    }
    return &Party[index];
}

void Pokemon_Party::healPokemon(int index)
{
    if (index < 0 || index >= Party.size())
    {
        std::cout << "Invalid Pokemon index." << std::endl;
        return;
    }

    Party[index].heal();

    std::cout << Party[index].getName()
              << " has been fully healed!" << std::endl;
}

void Pokemon_Party::healAll(){
    for (Pokemon& pokemon : Party){
        pokemon.heal();
    }
}

void Pokemon_Party::showPartyHP() const
{
    std::cout << "\n=== YOUR POKEMON ===" << std::endl;
    for (int i = 0; i < Party.size(); i++){
        std::cout << i << " - "<< Party[i].getName()<< " : "<< Party[i].getHitPoint()<< " / "<< Party[i].getMaxHitPoint()<< " HP" <<std::endl;
    }
}

int Pokemon_Party::getSize() const{
    return static_cast<int>(Party.size());
}

Pokemon_Party::~Pokemon_Party() {

}

Pokemon Pokemon_Party::GetPokemonById(int id) {

}

Pokemon Pokemon_Party::GetPokemonByName(string name) {

}