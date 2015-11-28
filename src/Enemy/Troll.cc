/* 
 * File:   Troll.cc
 * Author: Marcos Vazquez
 * 
 * Created on November 28, 2015, 1:01 PM
 */

#include "../../include/Enemy/Troll.h"

Troll::Troll() {
  name_ = "Troll";
  HP_ = 50;
  MP_ = 0;
  attack_ = 45;
  defense_ = 35;
  gold_ = 25;
  xp_ = 38;
}

Troll::Troll(const Troll& orig) {
}

Troll::~Troll() {
}

