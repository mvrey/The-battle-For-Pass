/* Copyright 2015 Marcos Vazquez. All rights reserved.    
 * 
 * Author: Marcos Vazquez <vazquezre@esat-alumni.es>  
 * Created on November 16, 2015, 6:29 PM
 * 
 * Represents the race of a given character
 */

#include "../../include/Character/Race.h"

Race::Race() {
  
}

Race::Race(std::string name) {
  name_ = name;
}

Race::Race(const Race& orig) {
}

Race::~Race() {
}

void Race::LoadFaces() {
  Job::LoadFaces(this->name_, face_imgs_);
}