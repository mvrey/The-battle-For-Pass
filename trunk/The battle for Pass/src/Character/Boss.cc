/* Copyright 2015 Marcos Vazquez. All rights reserved.    
 * 
 * Author: Marcos Vazquez <vazquezre@esat-alumni.es>  
 * Created on November 16, 2015, 6:29 PM
 * 
 * Represents the Boss/Aristocrat profession/class for a given character
 */

#include "../../include/Character/Boss.h"

/// @brief Sets variables and loads job/profession image for the Boss/Aristocrat
Boss::Boss() {
  id_ = 0;
  name_ = "Aristocrat";
  description_ = "Aristocrats have their origins in poweful lineages."
          " Often with no special skills that make them stand amongst other individuals,"
          " they compensate this by being largely wealthy and being able to afford"
          " the best equipment that money can buy";
  
  std::string path = "assets/character/"+name_+".png";
  description_image_ = ESAT::SpriteFromFile(path.c_str());
}

Boss::Boss(const Boss& orig) {
}

Boss::~Boss() {
}