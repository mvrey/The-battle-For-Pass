/* Copyright 2015 Marcos Vazquez. All rights reserved.    
 * 
 * Author: Marcos Vazquez <vazquezre@esat-alumni.es>  
 * Created on November 16, 2015, 6:29 PM
 * 
 * Represents the race of a given character
 */

#include "../../include/Character/Race.h"
#include "../../include/Character/Job.h"

Race::Race() {
  
}

Race::Race(std::string name) {
  name_ = name;
}

Race::Race(const Race& orig) {
}

Race::~Race() {
  for (int i=0; i<4; i++) {
    ESAT::SpriteRelease(face_imgs_[i]);
    ESAT::SpriteRelease(bust_imgs_[i]);
    face_imgs_[i] = nullptr;
    bust_imgs_[i] = nullptr;
  }
}

/** @brief
 *
 *
 *
 *  @return
 *  @param
 *  @param
 */
void Race::LoadImages() {
  Job::LoadImages(this);
}