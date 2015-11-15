/* Copyright 2015 Marcos Vazquez. All rights reserved.    
 * 
 * Author: Marcos Vazquez <vazquezre@esat-alumni.es>  
 * Created on November 8, 2015, 11:53 PM
 *
 * File:   character.cc                                               
 * A class representing an abstract character, may it be friend or foe
 *
 */

#ifndef CHARACTER_H
#define CHARACTER_H

#include "../../include/Item/Inventory.h"

class Character {
  public:
    Character() = default;
    Character(const Character& orig);
    virtual ~Character();
    
    float HP_;
    float MP_;
    float attack_;
    float defense_;
    
    int level_;
    
    //position on the current map
    int x,y;
    
    Inventory inventory_;
        
  private:

};

#endif /* CHARACTER_H */