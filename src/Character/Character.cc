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
  
  std::string path = "assets/character/"+race_->name_+"/"+Job::job_names_[job_->id_]+"/animation.png";
  printf("Loading animations from %s\n", path.c_str());
  
  animation_south_ = new Animation();
  animation_south_->LoadFromFile(path, 1, 8, 70, 70, 0, 0);
  
  animation_west_ = new Animation();
  animation_west_->LoadFromFile(path, 1, 8, 70, 70, 0, 70);
  
  animation_east_ = new Animation();
  animation_east_->LoadFromFile(path, 1, 8, 70, 70, 0, 140);
  
  animation_north_ = new Animation();
  animation_north_->LoadFromFile(path, 1, 8, 70, 70, 0, 210);
}