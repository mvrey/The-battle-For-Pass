/* Copyright 2015 Marcos Vazquez. All rights reserved.    
 * 
 * Author: Marcos Vazquez <vazquezre@esat-alumni.es> 
 * Created on November 17, 2015, 12:28 AM
 */

#include "../../include/Character/Human.h"

Human::Human() {
  name_ = "Human";
  HP_ = 25;
  MP_ = 25;
  attack_ = 25;
  defense_ = 25;
}

Human::Human(const Human& orig) {
}

Human::~Human() {
}

