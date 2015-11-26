/* Copyright 2015 Marcos Vazquez. All rights reserved.    
 * 
 * Author: Marcos Vazquez <vazquezre@esat-alumni.es>  
 * Created on November 26, 2015, 2:43 PM
 */

#ifndef SPELL_H
#define SPELL_H

#include <ESAT/sprite.h>
#include "../../include/Character/Character.h"
#include <string>

class Spell {
public:
    Spell();
    Spell(const Spell& orig);
    virtual ~Spell();
    void Cast(Character* player, Character* enemy);
    
    int id_;
    std::string name_;
    int price_;
    ESAT::SpriteHandle img_;
    
private:

};

#endif /* SPELL_H */

