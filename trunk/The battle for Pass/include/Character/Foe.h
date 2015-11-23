/* Copyright 2015 Marcos Vazquez. All rights reserved.    
 * 
 * Author: Marcos Vazquez <vazquezre@esat-alumni.es>  
 * Created on November 9, 2015, 12:06 PM
 */

#ifndef FOE_H
#define FOE_H

#include "Character.h"

class Foe: public Character {
public:
    Foe();
    Foe(const Foe& orig);
    virtual ~Foe();
    
    void LoadImages();
    
private:

};

#endif /* FOE_H */

