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
#define CHARACTER_H 1

#include <math.h>
#include "../../include/Item/Inventory.h"
#include "../../include/Character/Race.h"
#include "../../include/Character/Job.h"
#include "../../include/Main/Animation.h"
#include "../../include/Main/Grid.h"

class Character {
  public:
    Character();
    Character(const Character& orig);
    virtual ~Character();
    void virtual LoadImages();
    bool Move(int direction, Grid* collisions);
    void Stop();
    void Update(int tile_width, int tile_height);
    void ResetStatsToRace();
    void SetNextLevelXP();
    void LevelUp();
    
    std::string name_;
    
    float HP_;
    float max_HP_;
    float MP_;
    float max_MP_;
    float attack_;
    float defense_;
    
    int level_;
    int xp_;
    int next_level_xp_;
    int gold_;
    
    //position on the current map
    float x_,y_;
    int tile_x, tile_y;
    
    Inventory* inventory_;
    Race* race_;
    Job* job_;
    
    Animation* animation_north_;
    Animation* animation_south_;
    Animation* animation_east_;
    Animation* animation_west_;
    
    ESAT::SpriteHandle current_sprite_;
    ESAT::SpriteHandle battler_img_;
    ESAT::SpriteHandle dead_sprite_;
    
  private:
    bool moving_ = false;
    bool moving_right_ = false;
    bool moving_left_ = false;
    bool moving_up_ = false;
    bool moving_down_ = false;
};

#endif /* CHARACTER_H */