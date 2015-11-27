/* 
 * File:   Brown_Asp.cc
 * Author: Marcos Vazquez
 * 
 * Created on November 22, 2015, 11:44 PM
 */

#include "../../include/Character/White_Asp.h"

White_Asp::White_Asp() {
  name_ = "White Asp";
  HP_ = 20;
  MP_ = 0;
  attack_ = 25;
  defense_ = 20;
  gold_ = 8;
  xp_ = 20;
}

White_Asp::White_Asp(const White_Asp& orig) {
}

White_Asp::~White_Asp() {
}

