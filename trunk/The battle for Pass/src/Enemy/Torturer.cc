/* 
 * File:   Torturer.cc
 * Author: Marcos Vazquez
 * 
 * Created on November 28, 2015, 1:01 PM
 */

#include "../../include/Enemy/Torturer.h"

Torturer::Torturer() {
  name_ = "Torturer";
  HP_ = 43;
  MP_ = 0;
  attack_ = 40;
  defense_ = 30;
  gold_ = 20;
  xp_ = 33;
}

Torturer::Torturer(const Torturer& orig) {
}

Torturer::~Torturer() {
}

