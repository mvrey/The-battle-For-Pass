/* Copyright 2015 Marcos Vazquez. All rights reserved.    
 * 
 * Author: Marcos Vazquez <vazquezre@esat-alumni.es>  
 * Created on November 16, 2015, 6:29 PM
 * 
 * Represents the Warrior profession/class for a given character
 */

#include "../../include/Character/Warrior.h"

/// @brief Sets variables and loads job/profession image for the Warrior
Warrior::Warrior() {
  id_ = 2;
  name_ = "Warrior";
  description_ = "Warriors are strong individuals capable of carrying the "
          "heaviest weapons and armor, and delivering fatal melee blows";
  
  std::string path = "assets/character/"+name_+".png";
  description_image_ = ESAT::SpriteFromFile(path.c_str());
}

Warrior::Warrior(const Warrior& orig) {
}

Warrior::~Warrior() {
}