/* Copyright 2015 Marcos Vazquez. All rights reserved.    
 * 
 * Author: Marcos Vazquez <vazquezre@esat-alumni.es>  
 * Created on November 9, 2015, 12:06 PM
 */

#ifndef ALLY_H
#define ALLY_H 1

#include "Character.h"

class Ally: public Character {
public:
    Ally();
    Ally(const Ally& orig);
    virtual ~Ally();
    void SetBaseStats();
private:

};

#endif /* ALLY_H */

