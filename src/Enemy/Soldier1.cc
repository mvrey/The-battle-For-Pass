/* 
 * File:   Soldier1.cc
 * Author: Marcos Vazquez
 * 
 * Created on November 28, 2015, 1:01 PM
 */

#include "../../include/Enemy/Soldier1.h"

Soldier1::Soldier1() {
  name_ = "Soldier1";
  HP_ = 50;
  MP_ = 0;
  attack_ = 40;
  defense_ = 50;
  gold_ = 30;
  xp_ = 40;
}

Soldier1::Soldier1(const Soldier1& orig) {
}

Soldier1::~Soldier1() {
}

