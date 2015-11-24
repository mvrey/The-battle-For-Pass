/* Copyright 2015 Marcos Vazquez. All rights reserved.    
 * 
 * Author: Marcos Vazquez <vazquezre@esat-alumni.es>  
 * Created on November 23, 2015, 1:22 AM
 *
 * File:   Misc.h                                              
 * A static class holding common functions
 *
 */

#ifndef MISC_H
#define MISC_H 1

#include <ESAT/sprite.h>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <cstdlib>
#include "../../include/config.h"


class Misc {
  
  public:

    static ESAT::SpriteHandle GetSubImage(ESAT::SpriteHandle img, int x, int y, 
                                          int width, int height);
    static int random(int limit);
    static int random_sign();
    
    
  private:
    Misc();
    Misc(const Misc& orig);
    ~Misc();
};

#endif /* MISC_H */