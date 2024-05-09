#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include <vector>
using namespace std;

class Pokemon{
    public:
        // Contructors
        Pokemon();
        Pokemon(string name, int hp, int att, int def, vector<string> type);

        // Mutator functinos
        virtual void speak();
        virtual void printStats();

        // Accessor Functions

    protected:
        string name;
        int hp;
        int attack;
        int defense;
        vector<string> type;
};
#endif 