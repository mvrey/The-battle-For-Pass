/* Copyright 2015 Marcos Vazquez. All rights reserved.    
 * 
 * Author: Marcos Vazquez <vazquezre@esat-alumni.es>  
 * Created on November 26, 2015, 2:43 PM
 * 
 * A class representing a spell to be cast in battle
 */

#include "../../include/Spell/Spell.h"

Spell::Spell() {
}

Spell::Spell(const Spell& orig) {
}

Spell::~Spell() {
  ESAT::SpriteRelease(img_);
}

/** @brief
 *
 *
 *
 *  @return
 *  @param
 *  @param
 */
bool Spell::Cast(Character* player, Character* enemy) {
  return false;
}