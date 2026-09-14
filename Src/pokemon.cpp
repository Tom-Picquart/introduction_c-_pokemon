//
// Created by tompi on 10/09/2026.
//
#include "../Inc/pokemon.h"
#include <iostream>

int Pokemon::numberOfPokemon=0;

Pokemon::Pokemon(const int &id, const string &name, const double &maxHitPoint, const double &hitPoint, const double &attack, const double &defense):
id(id), name(name),maxHitPoint(maxHitPoint), hitPoint(hitPoint),attack(attack),defense(defense) {
    numberOfPokemon++;
}

Pokemon::Pokemon(const Pokemon &pokemon):
id(pokemon.id), name(pokemon.name),maxHitPoint(pokemon.maxHitPoint),hitPoint(pokemon.hitPoint),attack(pokemon.attack),defense(pokemon.defense) {
    numberOfPokemon++;
}

Pokemon::~Pokemon() {
    numberOfPokemon--;
}

void Pokemon::displayInfo() const {
    std::cout << "Id:"<< id << std::endl;
    std::cout << "Name:" << name << std::endl;
    std::cout << "maxHitPoint" << maxHitPoint << std::endl;
    std::cout << "HitPoint:" << hitPoint << std::endl;
    std::cout << "attack:"<< attack << std::endl;
    std::cout << "defense:"<< defense << std::endl;
}

void Pokemon::attacks(Pokemon &target) {
    std::cout << name << " attacks " << target.name <<std::endl;
    if (attack>target.defense) {
        target.hitPoint=target.hitPoint-(attack-target.defense);
        if (target.hitPoint<0) {
            target.hitPoint=0;
            std::cout << target.name << " died" << std::endl;
        }
        else {
            std::cout << target.name << " took " << attack-target.defense << " damage" <<std::endl;
            std::cout << target.name << " has " << target.hitPoint << " hitpoints left" <<std::endl;
        }

    }
    else {
        std::cout << target.name << " took no damage"  <<std::endl;
    }

}


int Pokemon::getId() const {
    return id;
}

string Pokemon::getName() const {
    return name;
}



double Pokemon::getMaxHitPoint() const {
    return maxHitPoint;
}

double Pokemon::getHitPoint() const {
    return hitPoint;
}

double Pokemon::getAttack() const {
    return attack;
}

double Pokemon::getDefense() const {
    return defense;
}

int Pokemon::getNumberOfPokemon() const {
    return numberOfPokemon;
}
