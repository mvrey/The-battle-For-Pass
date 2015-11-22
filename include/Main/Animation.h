/* Copyright 2015 Marcos Vazquez. All rights reserved.    
 * 
 * Author: Marcos Vazquez <vazquezre@esat-alumni.es>  
 * Created on November 9, 2015, 2:06 PM
 *
 * File:   Manager.h                                               
 * A class that manages sprites and animations
 *
 */

#ifndef ANIMATION_H
#define ANIMATION_H

#include <ESAT/sprite.h>
#include <string>
#include "../../include/Main/Map.h"

class Animation {
  public:
    Animation();
    Animation(const Animation& orig);
    virtual ~Animation();
    
    void LoadFromFile(std::string path, int rows, int columns, float width, 
                        float height, float offsetX, float offsetY);
    
    ESAT::SpriteHandle GetCurrentFrame();
    ESAT::SpriteHandle GetNextFrame();
    void NextFrame();
    void DrawCurrentFrame();
    
    //ESAT::SpriteHandle(s), not int(s)
    ESAT::SpriteHandle frames_[100];
    int num_frames_;
    int current_frame_;
    int fps_;
    
  private:

};

#endif /* ANIMATION_H */

