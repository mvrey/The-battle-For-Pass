/* Copyright 2015 Marcos Vazquez. All rights reserved.    
 * 
 * Author: Marcos Vazquez <vazquezre@esat-alumni.es>  
 * Created on November 26, 2015, 6:33 PM
 */

#ifndef FIRESWORD_H
#define FIRESWORD_H 1

#include "Spell.h"

class FireSword: public Spell {
public:
    FireSword();
    FireSword(const FireSword& orig);
    virtual ~FireSword();
    bool Cast(Character* player, Character* enemy);
    
private:

};

#endif /* FIRESWORD_H */