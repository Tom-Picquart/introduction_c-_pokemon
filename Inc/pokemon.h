//
// Created by tompi on 10/09/2026.
//

#ifndef C___POKEMON_H
#define C___POKEMON_H
#include <string>
using std::string;


class Pokemon {
    private:
        int id;
        string name;
        double maxHitPoint;
        double hitPoint;
        double attack;
        double defense;
        static int numberOfPokemon;
    public:
        Pokemon()= delete;
        //constructeur
        Pokemon(const int &id, const string &name, const double &maxHitPoint, const double &hitPoint, const double &attack, const double &defense);
        //copieur
        Pokemon( const Pokemon &pokemon);

        //méthodes
        void attacks( Pokemon &target);
        void displayInfo() const;

        //getters
        int getId() const;
        string getName() const;
        double getMaxHitPoint() const;
        double getHitPoint() const;
        double getAttack() const;
        double getDefense() const;
        int getNumberOfPokemon() const;


    //destructeur
    ~Pokemon();
};


#endif //C___POKEMON_H
