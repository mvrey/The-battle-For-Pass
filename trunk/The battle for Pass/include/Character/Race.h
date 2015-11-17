/* Copyright 2015 Marcos Vazquez. All rights reserved.    
 * 
 * Author: Marcos Vazquez <vazquezre@esat-alumni.es>  
 * Created on November 16, 2015, 6:28 PM
 */

#ifndef RACE_H
#define RACE_H 1

#include <ESAT/sprite.h>
#include <string>


class Race {
public:
    Race();
    Race(std::string name);
    Race(const Race& orig);
    virtual ~Race();
    void LoadImages();
    
    float HP_;
    float MP_;
    float attack_;
    float defense_;
    
    std::string name_;
    ESAT::SpriteHandle face_imgs_[4];
    ESAT::SpriteHandle bust_imgs_[4];
private:

};

#endif /* RACE_H */

