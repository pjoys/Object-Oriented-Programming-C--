#define RPG_H

using namespace std;

const int SKILL_SIZE = 2;

class RPG {
    public:
    //constructors
    RPG();
    RPG(string name, int health, int strength, int defense, string type);

    // from uml chart
    RPG();
    RPG(string, int, int, int, string);

    void setSkills();
    void printAction(string, RPG);
    void updateHealth(int);
    void attack(RPG *);
    void useSkill(RPG *);

    private:
    // from uml chart
    string name;
    int health;
    int strength;
    int defense;
    string typ;
    string skills[2];

    string type;
    string skills[SKILL_SIZE];
};

#endif