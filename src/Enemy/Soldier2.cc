/* 
 * File:   Soldier2.cc
 * Author: Marcos Vazquez
 * 
 * Created on November 28, 2015, 1:01 PM
 */

#include "../../include/Enemy/Soldier2.h"

Soldier2::Soldier2() {
  name_ = "Soldier2";
  HP_ = 50;
  MP_ = 0;
  attack_ = 50;
  defense_ = 40;
  gold_ = 30;
  xp_ = 40;
}

Soldier2::Soldier2(const Soldier2& orig) {
}

Soldier2::~Soldier2() {
}

