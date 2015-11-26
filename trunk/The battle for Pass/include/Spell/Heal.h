/* Copyright 2015 Marcos Vazquez. All rights reserved.    
 * 
 * Author: Marcos Vazquez <vazquezre@esat-alumni.es>  
 * Created on November 26, 2015, 6:33 PM
 */

#ifndef HEAL_H
#define HEAL_H

#include "Spell.h"

class Heal: public Spell {
public:
    Heal();
    Heal(const Heal& orig);
    virtual ~Heal();
    bool Cast(Character* player, Character* enemy);
    
private:

};

#endif /* HEAL_H */

