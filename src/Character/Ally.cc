/* Copyright 2015 Marcos Vazquez. All rights reserved.    
 * 
 * Author: Marcos Vazquez <vazquezre@esat-alumni.es>  
 * Created on November 9, 2015, 12:06 PM
 * 
 * Represents an allied playable character
 */

#include "../../include/Character/Ally.h"
#include "ESAT/draw.h"

Ally::Ally() {
  gold_ = 10;
  xp_ = 0;
  level_ = 1;
  SetNextLevelXP();
}

Ally::Ally(const Ally& orig) {
}

Ally::~Ally() {
}

void Ally::SetBaseStats() {
  HP_ = race_->HP_;
  max_HP_ = race_->HP_;
  MP_ = race_->MP_;
  max_MP_ = race_->MP_;
  attack_ = race_->attack_;
  defense_ = race_->defense_;
}