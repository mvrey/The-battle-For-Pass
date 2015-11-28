/* 
 * File:   Brown_Asp.cc
 * Author: Marcos Vazquez
 * 
 * Created on November 22, 2015, 11:44 PM
 */

#include "../../include/Enemy/Brown_Asp.h"

Brown_Asp::Brown_Asp() {
  name_ = "Brown Asp";
  HP_ = 15;
  MP_ = 0;
  attack_ = 20;
  defense_ = 15;
  gold_ = 5;
  xp_ = 15;
}

Brown_Asp::Brown_Asp(const Brown_Asp& orig) {
}

Brown_Asp::~Brown_Asp() {
}

