/* Copyright 2015 Marcos Vazquez. All rights reserved.    
 * 
 * Author: Marcos Vazquez <vazquezre@esat-alumni.es>  
 * Created on November 26, 2015, 6:33 PM
 */

#ifndef FIRESWORD_H
#define FIRESWORD_H

#include "Spell.h"

class FireSword: public Spell {
public:
    FireSword();
    FireSword(const FireSword& orig);
    virtual ~FireSword();
    void Cast(Character* player, Character* enemy);
    
private:

};

#endif /* FIRESWORD_H */