#include <string>
#include <vector>

#ifndef POKEMON_H
#define POKEMON_H

class Pokemon{
    public:
    // ---------------- constructors ----------------
    Pokemon();
    Pokemon(string name, int hp, int att, int def, vector<string> type);

    // ---------------- mutator functions ----------------
    virtual void speak();
    virtual void printStats();

    // ---------------- accessor functions ----------------

    protected:
    string name;
    int hp;
    int attack;
    int defense;
    vector<string> type;
};
#endif