/* Copyright 2015 Marcos Vazquez. All rights reserved.    
 * 
 * Author: Marcos Vazquez <vazquezre@esat-alumni.es>  
 * Created on November 26, 2015, 6:33 PM
 * 
 * A class representing an offensive spell that damages an enemy
 */

#include "../../include/Spell/Blizzard.h"

Blizzard::Blizzard() {
  id_ = 2;
  name_ = "Blizzard";
  price_ = 150;
  mana_cost_ = 20;
  img_ = ESAT::SpriteFromFile("assets/raw/blizzard_spell.png");
}

Blizzard::Blizzard(const Blizzard& orig) {
}

Blizzard::~Blizzard() {
}

void Blizzard::Cast(Character* player, Character* enemy) {
  enemy->HP_ -= 20;
}