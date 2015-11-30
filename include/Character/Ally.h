/* Copyright 2015 Marcos Vazquez. All rights reserved.    
 * 
 * Author: Marcos Vazquez <vazquezre@esat-alumni.es>  
 * Created on November 9, 2015, 12:06 PM
 * 
 * A class representing a playable character
 */

#ifndef ALLY_H
#define ALLY_H 1

#include "Character.h"
#include "../Screen/Screen.h"
#include "../Spell/Heal.h"
#include "../Spell/FireSword.h"
#include "../Spell/Blizzard.h"

class Ally: public Character {
public:
    Ally();
    Ally(const Ally& orig);
    virtual ~Ally();
    void SetBaseStats();
    void Init();
    
    Spell* spells_[10];
    int num_spells_ = 0;
    int num_healing_potions_ = 3;
    
private:

};

#endif /* ALLY_H */

