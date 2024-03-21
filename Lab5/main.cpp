#include <iostream>
#include "RPG.h"
using namespace std;

int main()
{
    RPG p1 = RPG("Wiz", 70, 45, 15, "mage");
    RPG p2 = RPG("NPC", 100, 10, 10, "warrior");

    printf("%s Current Stats\n", p1.getName().c_str());
    printf("Health: %i\t Strength: %i\t Defense: %i\n", p1.getHealth(), p1.getStrength(), p1.getDefense());

    // p2
    printf("%s Current Stats\n", p2.getName().c_str());
    printf("Health: %i\t Strength: %i\t Defense: %i\n", p2.getHealth(), p2.getStrength(), p2.getDefense());

    // call updateHealth(0) on either p1 and p2
    p1.updateHealth(0);

    // print new health
    printf("%s's new Health: %i\n", p1.getName().c_str(), p1.getHealth());
    printf("%s's new Health: %i\n", p2.getName().c_str(), p2.getHealth());

    // call isAlive()
    printf("%s is alive: %s\n", p1.getName().c_str(), p1.isAlive() ? "true" : "false");
    printf("%s is alive: %s\n", p2.getName().c_str(), p2.isAlive() ? "true" : "false");


    return 0;
};