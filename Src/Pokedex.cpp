//
// Created by tompi on 11/09/2026.
//

#include "../Inc/Pokedex.h"
#include "../Inc/pokemon.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
Pokedex* Pokedex::instance{nullptr};


Pokedex::Pokedex(string fileName):Pokemon_vector() {

    std::cout << "*** Constructeur du Pokedex ***" << std::endl;

    std::ifstream file(fileName);
    if(!file.is_open()){
        std::cerr<<"File "<<fileName<<" not found "<<std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        //    std::cout << line << std::endl;
        std::stringstream inputstringstream(line);
        std::string cell;
        std::vector<std::string> lineData;

        while(std::getline(inputstringstream,cell,',')){
            lineData.push_back(cell);
        }
        int id = std::stoi(lineData.at(0));
        double attackValue = std::stod(lineData.at(6));
        double hitPoint = std::stod(lineData.at(5));
        double defenseValue = std::stod(lineData.at(7));
        arrayOfPokemon.push_back( Pokemon(id,lineData.at(1),hitPoint,hitPoint,attackValue,defenseValue));
    }
}

Pokedex *Pokedex::getInstance(){
    if (instance== NULL) {
        instance = new Pokedex("C://Users//tompi//Desktop//cours//c++//TP//pokedex.csv");
    }
    return instance;
}

Pokemon Pokedex::GetPokemonById(int id) {
    for (Pokemon pokemon : arrayOfPokemon) {
        if (pokemon.getId() == id) {
            return pokemon;
        }
    }
}
Pokemon Pokedex::GetPokemonByName(string name) {
    for (Pokemon pokemon : arrayOfPokemon) {
        if (pokemon.getName() == name) {
            return pokemon;
        }
    }
    throw std::runtime_error( name+" is not a valid Pokemon");

}

Pokedex::~Pokedex() {

}