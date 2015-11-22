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
}

void Character::LoadAnimations() {
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
}


void Character::Move(int direction) {
  switch(direction) {
    case 0:
      moving_up_ = true;
      break;
    case 1:
      moving_right_ = true;
      break;
    case 2:
      moving_down_ = true;
      break;
    case 3:
      moving_left_ = true;
      break;
    default:
      moving_right_ = false;
      moving_left_ = false;
      moving_up_ = false;
      moving_down_ = false;
      //Fix floating point accumulated inaccuracies
      x = round(x);
      y = round(y);
      break;
  }
}

//Updates character animation
void Character::Update(int tile_width, int tile_height) {
  int anim_frame;
  
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
  if (anim_frame == 0)
    Move(-1);
}