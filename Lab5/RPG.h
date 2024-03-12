#ifndef RPH_H
#define RPG_H

using namespace std;

const int SKILL_SIZE = 2;

class RPG {
    public:
    //constructors
    RPG();
    RPG(string name, int health, int strength, int defense, string type);

    void setSkills();
    void printAction(string, RPG);
    void updateHealth(int new_health);
    void attack(RPG *); // not implemented
    void useSkill(RPG *); // not implemented
    const bool isAlive();
    const string getName();
    const int getHealth();
    const int getStrength();
    const string getType();
    const int getDefense();

private:
    string name;
    int health;
    int strength;
    int defense;
    string type; // warrior, thief, archer
    string skills[SKILL_SIZE];
};
#endif