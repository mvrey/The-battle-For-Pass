/* Copyright 2015 Marcos Vazquez. All rights reserved.    
 * 
 * Author: Marcos Vazquez <vazquezre@esat-alumni.es>  
 * Created on November 26, 2015, 6:33 PM
 * 
 * A class representing a healing spell to be cast on a Character
 */

#include "../../include/Spell/Heal.h"

Heal::Heal() {
  id_ = 0;
  name_ = "Heal";
  price_ = 70;
  mana_cost_ = 15;
  img_ = ESAT::SpriteFromFile("assets/raw/heal_spell.png");
  log_line_ = "You recover 10 HP\n";
  description_ = "A healing spell";
}

Heal::Heal(const Heal& orig) {
}

Heal::~Heal() {
}

bool Heal::Cast(Character* player, Character* enemy) {
  if (player->MP_ >= this->mana_cost_) {
    player->MP_ -= this->mana_cost_;
    player->HP_ += 10;
    if (player->HP_ > player->max_HP_)
      player->HP_ = player->max_HP_;
    return true;
  } else
    return false;
}
