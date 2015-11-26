/* Copyright 2015 Marcos Vazquez. All rights reserved.    
 * 
 * Author: Marcos Vazquez <vazquezre@esat-alumni.es>  
 * Created on November 26, 2015, 6:33 PM
 * 
 * A class representing an offensive spell that increments the player attack power
 */

#include "../../include/Spell/FireSword.h"

FireSword::FireSword() {
  id_ = 1;
  name_ = "Fire Sword";
  price_ = 120;
  mana_cost_ = 10;
  img_ = ESAT::SpriteFromFile("assets/raw/firesword_spell.png");
}

FireSword::FireSword(const FireSword& orig) {
}

FireSword::~FireSword() {
}

void FireSword::Cast(Character* player, Character* enemy) {
  player->attack_ *= 1.5;
}