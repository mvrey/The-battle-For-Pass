/* Copyright 2015 Marcos Vazquez. All rights reserved.    
 * 
 * Author: Marcos Vazquez <vazquezre@esat-alumni.es>  
 * Created on November 16, 2015, 6:29 PM
 * 
 * Represents the Wizard profession/class for a given character
 */

#include "../../include/Character/Wizard.h"

Wizard::Wizard() {
  id_ = 3;
  name_ = "Wizard";
  description_ = "Wizards have became masters of the arcane arts. They can cast "
          "spells to dominate the elements and play with their foe's minds ";
  
  std::string path = "assets/character/"+name_+".png";
  description_image_ = ESAT::SpriteFromFile(path.c_str());
}

Wizard::Wizard(const Wizard& orig) {
}

Wizard::~Wizard() {
  Init();
}

void Wizard::Init() {
}


void Wizard::LoadImage(Race* race) {
}