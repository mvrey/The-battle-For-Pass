/* 
 * File:   Harpy.cc
 * Author: Marcos Vazquez
 * 
 * Created on November 27, 2015, 3:44 PM
 */

#include "../../include/Enemy/Harpy.h"

Harpy::Harpy() {
  name_ = "Harpy";
  HP_ = 25;
  MP_ = 0;
  attack_ = 25;
  defense_ = 20;
  gold_ = 13;
  xp_ = 20;
}

Harpy::Harpy(const Harpy& orig) {
}

Harpy::~Harpy() {
}

