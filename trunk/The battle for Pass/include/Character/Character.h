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
#include "../../include/Character/Race.h"
#include "../../include/Character/Job.h"
#include "../../include/Main/Animation.h"

class Character {
  public:
    Character() = default;
    Character(const Character& orig);
    virtual ~Character();
    void LoadAnimations();
    void Move(int direction);
    void Update(int tile_width, int tile_height);
    
    float HP_;
    float MP_;
    float attack_;
    float defense_;
    
    int level_;
    
    //position on the current map
    float x,y;
    
    Inventory* inventory_;
    Race* race_;
    Job* job_;
    
    Animation* animation_north_;
    Animation* animation_south_;
    Animation* animation_east_;
    Animation* animation_west_;
    
    ESAT::SpriteHandle current_sprite_;
    
  private:
    bool moving_right_ = false;
    bool moving_left_ = false;
    bool moving_up_ = false;
    bool moving_down_ = false;
};

#endif /* CHARACTER_H */