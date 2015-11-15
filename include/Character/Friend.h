/* Copyright 2015 Marcos Vazquez. All rights reserved.    
 * 
 * Author: Marcos Vazquez <vazquezre@esat-alumni.es>  
 * Created on November 9, 2015, 12:06 PM
 */

#ifndef FRIEND_H
#define FRIEND_H

#include "Character.h"

class Friend: public Character {
public:
    Friend();
    Friend(const Friend& orig);
    virtual ~Friend();
private:

};

#endif /* FRIEND_H */

