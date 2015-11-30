/* Copyright 2015 Marcos Vazquez. All rights reserved.    
 * 
 * Author: Marcos Vazquez <vazquezre@esat-alumni.es>  
 * Created on November 16, 2015, 6:29 PM
 * 
 * Represents the Hunter profession/class for a given character
 */

#include "../../include/Character/Hunter.h"

/// @brief Sets variables and loads job/profession image for the Hunter
Hunter::Hunter() {
  id_ = 1;
  name_ = "Hunter";
  description_ = "Hunters are the rangers amongst their kind. "
          "They approach with stealth and attack from afar.";
  
  std::string path = "assets/character/"+name_+".png";
  description_image_ = ESAT::SpriteFromFile(path.c_str());
}

Hunter::Hunter(const Hunter& orig) {
}

Hunter::~Hunter() {
}