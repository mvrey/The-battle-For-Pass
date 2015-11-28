/* 
 * File:   Skeleton.cc
 * Author: Marcos Vazquez
 * 
 * Created on November 27, 2015, 3:44 PM
 */

#include "../../include/Enemy/Skeleton.h"

Skeleton::Skeleton() {
  name_ = "Skeleton";
  HP_ = 35;
  MP_ = 0;
  attack_ = 35;
  defense_ = 30;
  gold_ = 20;
  xp_ = 28;
}

Skeleton::Skeleton(const Skeleton& orig) {
}

Skeleton::~Skeleton() {
}

