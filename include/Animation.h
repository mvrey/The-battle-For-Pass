/* Copyright 2015 Marcos Vazquez. All rights reserved.    
 * 
 * Author: Marcos Vazquez <vazquezre@esat-alumni.es>  
 * Created on November 9, 2015, 2:06 PM
 *
 * File:   Manager.cc                                               
 * A class that manages sprites and animations
 *
 */

#ifndef ANIMATION_H
#define ANIMATION_H

#include <string>

class Animation {
  public:
    Animation();
    Animation(const Animation& orig);
    virtual ~Animation();
    
    void LoadFromFile(std::string path, int rows, int columns, float width, 
                        float height, float offsetX, float offsetY);
    
    //Returns a ESAT::SpriteHandle
    void GetCurrentFrame();
    void NextFrame();
    
    
    //ESAT::SpriteHandle(s), not int(s)
    int frames_[100];
    int num_frames_;
    int current_frame_;
    
    
  private:

};

#endif /* ANIMATION_H */

