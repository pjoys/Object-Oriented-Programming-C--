#include "RPG.h"
#include <iostream>
using namespace std;

RPG::RPG()
{ 
    // assign private variables
    name = "NPC";
    health = 100;
    strength = 10;
    defense = 10;
    type = "warrior";
    skills[0] = "slash";
    skills[1] = "parry";
};

RPG::RPG(string name, int health, int strength, int defense, string type){
    // assign private variables with parameter values
    this->name = name;
    this->health = health;
    this->strength = strength;
    this->defense = defense;
    this->type = type;
    // call setSkills to initialize skills based on type
    setSkills();
};

/**
 * @brief sets the skills based on the RPG's role
 * 
*/

void RPG::setSkills(){
    if (type == "image"){
        skills[0] = "fire"; 
        skills[1] = "thunder";
    } else if (type == "thief"){
        skills[0] = "pilfer";
        skills[1] = "jab";
    } else if (type == "archer"){
        skills[0] = "parry";
        skills[1] = "crossbow_attack";
    } else {
        skills[0] = "slash";
        skills[1] = "parry";
    }
}

void RPG::printAction(string skill, RPG opponent){
    printf("%s used %s on %s\n", name.c_str(), skill.c_str(), opponent.getName().c_str());
}

// implement updateHealth()

/**
 * @brief updates health into new_health
 * 
 * @param new_health
 * 
*/

void RPG::updateHealth(int new_health){
    health = new_health;
}

// implement isAlive()

/**
 * @brief returns whether health is greater than 0
 * 
 * @return true
 * @return flase
*/

const bool RPG::isAlive(){
    return health > 0;
}

const string RPG::getName()
{
    return name;
};

const int RPG::getHealth()
{
    return health;
};

const int RPG::getStrength()
{
    return strength;
};

const string RPG::getType()
{
    return type;
};

const int RPG::getDefense()
{
    return defense;
};

/**
 * @brief attack decreases the opponent's health by (strength - opponent's defense)
 * In other workds, the opponent's defense should soften the blow from the attack
 * 
 * For example, if opponent's health is 100, opponent's defense is 5, and player's
 * strength is 20, then after the attacl, opponent's health should be
 * 85 (i.e. 100 - (20-5)).
 * 
 * First calculate the opponent's health, then use (*opponent).getUpdate(hew_health)
 * to update their health.
 * 
 * @param opponent
 * 
*/

void RPG::attack(RPG * opponent){
    // implement brief
    int oppHealth = (*opponent).getHealth();
    int oppDefense = (*opponent).getDefense();

    int new_health = 0;

    if(strength - oppDefense > 0){
        int new_health = oppHealth - (strength - oppDefense);
        (*opponent).updateHealth(new_health);
    } else {
        int new_health = oppHealth - 0;
        (*opponent).updateHealth(new_health);
    }
};


/**
 * @brief Prompts the user to choose a skill and calls printAction() and attack()
 * 
 * @param opponent
*/

void RPG::useSkill(RPG * opponent){
    for(int i = 0; i < SKILL_SIZE; i++){
        printf("Skill %i: %s\n", i, skills[i].c_str());
        i++;
    };

    int chosen_skill_index;
    printf("Choose a skill to use: Enter 0 or 1\n");

    cin >> chosen_skill_index;

    string chosen_skill = skills[chosen_skill_index];

    printAction(string chosen_skill, RPG(*opponent));

    
};


