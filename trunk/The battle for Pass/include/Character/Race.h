/* Copyright 2015 Marcos Vazquez. All rights reserved.    
 * 
 * Author: Marcos Vazquez <vazquezre@esat-alumni.es>  
 * Created on November 16, 2015, 6:28 PM
 */

#ifndef RACE_H
#define RACE_H 1

#include <ESAT/sprite.h>
#include <string>
#include "Job.h"

class Race {
public:
    Race();
    Race(std::string name);
    Race(const Race& orig);
    virtual ~Race();
    void LoadFaces();
    
    std::string name_;
    ESAT::SpriteHandle face_imgs_[4];
private:

};

#endif /* RACE_H */

