/* 
 * File:   Black_Dragon.cc
 * Author: Marcos Vazquez
 * 
 * Created on November 28, 2015, 1:01 PM
 */

#include "../../include/Enemy/Black_Dragon.h"

Black_Dragon::Black_Dragon() {
  name_ = "Black Dragon";
  HP_ = 150;
  MP_ = 0;
  attack_ = 80;
  defense_ = 60;
  gold_ = 150;
  xp_ = 100;
}

Black_Dragon::Black_Dragon(const Black_Dragon& orig) {
}

Black_Dragon::~Black_Dragon() {
}

