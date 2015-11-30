/* Copyright 2015 Marcos Vazquez. All rights reserved.    
 * 
 * Author: Marcos Vazquez <vazquezre@esat-alumni.es>  
 * Created on November 26, 2015, 6:33 PM
 */

#ifndef BLIZZARD_H
#define BLIZZARD_H 1

#include "Spell.h"

class Blizzard: public Spell {
public:
    Blizzard();
    Blizzard(const Blizzard& orig);
    virtual ~Blizzard();
    bool Cast(Character* player, Character* enemy);
    
private:

};

#endif /* BLIZZARD_H */