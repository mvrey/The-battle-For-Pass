/* Copyright 2015 Marcos Vazquez. All rights reserved.    
 * 
 * Author: Marcos Vazquez <vazquezre@esat-alumni.es>  
 * Created on November 8, 2015, 11:53 PM
 *
 * File:   character.cc                                               
 * A class representing an abstract character, may it be friend or foe
 *
 */

#include "../../include/Character/Character.h"

Character::Character(const Character& orig) {
}

Character::~Character() {
  race_ = nullptr;
  job_ = nullptr;
  level_ = 1;
  SetNextLevelXP();
}

void Character::LoadImages() {
  int side =70;
  
  //Orc sprites have a different ratio
  if (race_->name_ == "Orc")
    side = 60;
  
  std::string path = "assets/character/"+race_->name_+"/"+Job::job_names_[job_->id_]+"/animation.png";
  printf("Loading animations from %s\n", path.c_str());
  printf("Sprite size is %dpx\n", side);
  
  animation_south_ = new Animation();
  animation_south_->LoadFromFile(path, 1, 8, side, side, 0, side*0);
  
  animation_west_ = new Animation();
  animation_west_->LoadFromFile(path, 1, 8, side, side, 0, side*1);
  
  animation_east_ = new Animation();
  animation_east_->LoadFromFile(path, 1, 8, side, side, 0, side*2);
  
  animation_north_ = new Animation();
  animation_north_->LoadFromFile(path, 1, 8, side, side, 0, side*3);
  
  //Assign default animation
  current_sprite_ = animation_east_->frames_[0];
  
  
  //Load battler image
  path = "assets/character/"+race_->name_+"/"+Job::job_names_[job_->id_]+"/bust.png";
  printf("Loading Battler from %s\n", path.c_str());
  battler_img_ = ESAT::SpriteFromFile(path.c_str());
  
  //Load dead sprite
  path = "assets/character/"+race_->name_+"/"+Job::job_names_[job_->id_]+"/dead.png";
  printf("Loading Dead Sprite from %s\n", path.c_str());
  dead_sprite_ = ESAT::SpriteFromFile(path.c_str());
  dead_sprite_ = Misc::GetSubImage(dead_sprite_, 80, side*2, side, side);
}


bool Character::Move(int direction, Grid* collisions) {
  moving_ = true;
  
  switch(direction) {
    case 0:
//      collisions->print();
      if (collisions->getElement(tile_x, tile_y-1) == nullptr) {
        moving_up_ = true;
        return true;
      }
      break;
    case 1:
      if (collisions->getElement(tile_x+1, tile_y) == nullptr) {
        moving_right_ = true;
        return true;
      }
      break;
    case 2:
      if (collisions->getElement(tile_x, tile_y+1) == nullptr) {
        moving_down_ = true;
        return true;
      }
      break;
    case 3:
      if (collisions->getElement(tile_x-1, tile_y) == nullptr) {
        moving_left_ = true;
        return true;
      }
      break;
    default:
      break;
  }
  
  return false;
}


void Character::Stop() {
  moving_ = false;
  moving_right_ = false;
  moving_left_ = false;
  moving_up_ = false;
  moving_down_ = false;
  //Fix floating point accumulated inaccuracies
  x = round(x);
  y = round(y);
}


//Updates character animation
void Character::Update(int tile_width, int tile_height) {
  int anim_frame;
  
  if (HP_ > 0) {
    if (moving_up_) {
      current_sprite_ = animation_north_->frames_[animation_north_->current_frame_];
       anim_frame = animation_north_->NextFrame();
       y -= (float)tile_height / 8;
    } else if (moving_right_) {
      current_sprite_ = animation_east_->frames_[animation_east_->current_frame_];
      anim_frame = animation_east_->NextFrame();
      x += (float)tile_width / 8;
    } else if (moving_down_) {
      current_sprite_ = animation_south_->frames_[animation_south_->current_frame_];
      anim_frame = animation_south_->NextFrame();
      y += (float)tile_height / 8;
    } else if (moving_left_) {
      current_sprite_ = animation_west_->frames_[animation_west_->current_frame_];
      anim_frame = animation_west_->NextFrame();
      x -= (float)tile_width / 8;
    }

    //Stop animation if it does a full loop
    if (anim_frame == 0 && moving_) {
      Stop();
      tile_x = x/tile_width + 1;
      tile_y = y/tile_height - 1;
      printf("Character is now at %d, %d\n", tile_x, tile_y);
    }
  }
}


void Character::ResetStatsToRace() {
  HP_ = race_->HP_;
  MP_ = race_->MP_;
  attack_ = race_->attack_;
  defense_ = race_->defense_;
}


void Character::SetNextLevelXP() {
  next_level_xp_ = 20 * (level_ * 0.6); 
}

void Character::LevelUp() {
  level_++;
  max_HP_ *= 1.1;
  HP_ = max_HP_;
  max_MP_ *= 1.1;
  MP_ = max_MP_;
  attack_ *= 1.1;
  defense_ *= 1.1;
  SetNextLevelXP();
}