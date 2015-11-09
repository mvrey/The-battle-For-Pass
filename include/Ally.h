/* Copyright 2015 Marcos Vazquez. All rights reserved.    
 * 
 * Author: Marcos Vazquez <vazquezre@esat-alumni.es>  
 * Created on November 9, 2015, 12:06 PM
 */

#ifndef ALLY_H
#define ALLY_H

#include "Character.h"

class Ally: public Character {
public:
    Ally();
    Ally(const Ally& orig);
    virtual ~Ally();
private:

};

#endif /* ALLY_H */

