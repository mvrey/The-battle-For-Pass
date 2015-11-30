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

/** @brief Casts this spell
 *
 *  Checks if the player has enough mana to cast this Spell.
 *  Aplies spell effects if so, and substracts its mana cost from the player's available mana.
 *
 *  @return Returns if the spell has been cast, or the player didn't have enough mana
 *  @param player The player that casts the spell
 *  @param enemy The foe that the spell CAN be cast upon (some spells are cast on the player himself)
 */
bool Spell::Cast(Character* player, Character* enemy) {
  return false;
}