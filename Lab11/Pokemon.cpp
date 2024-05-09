#include <iostream>
#include
#include "Pokemon.h"

/**
 * @brief construct a new pokemon:: pokemon object
*/

Pokemon::Pokemon(){
    name = "unidentified";
    hp = 0;
    attack = 0;
    defense = 0;
    cout << "Default Constructor (Pokemon)\n";
}