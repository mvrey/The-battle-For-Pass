/* Copyright 2015 Marcos Vazquez. All rights reserved.    
 * 
 * Author: Marcos Vazquez <vazquezre@esat-alumni.es>  
 * Created on November 9, 2015, 12:06 PM
 * 
 * Represents an Enemy character controlled by the AI
 */

#include "../../include/Enemy/Foe.h"

Foe::Foe() {
}

Foe::Foe(const Foe& orig) {
}

Foe::~Foe() {
}

/** @brief Loads images of an enemy
 *
 *  Loads battler image from disk, using the path assets/enemy/<name>battler.png
 *
 */
void Foe::LoadImages() {
  //Load battler image
  std::replace( name_.begin(), name_.end(), ' ', '_');
  std::string path = "assets/enemy/"+name_+"/battler.png";
  printf("Loading Battler from %s\n", path.c_str());
  battler_img_ = ESAT::SpriteFromFile(path.c_str());
}

/// @brief Makes enemies harder and tougher by multiplying his stats in hard mode
void Foe::Harden() {
  this->HP_ *= 1.5;
  this->max_HP_ *= 1.5;
  this->MP_ *= 1.5;
  this->max_MP_ *= 1.5;
  this->attack_ *= 1.5;
  this->defense_ *= 1.5;
}