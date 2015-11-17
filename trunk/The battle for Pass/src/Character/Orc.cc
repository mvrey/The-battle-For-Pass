/* Copyright 2015 Marcos Vazquez. All rights reserved.    
 * 
 * Author: Marcos Vazquez <vazquezre@esat-alumni.es> 
 * Created on November 17, 2015, 12:29 AM
 */

#include "../../include/Character/Orc.h"

Orc::Orc() {
  name_ = "Orc";
  HP_ = 30;
  MP_ = 10;
  attack_ = 40;
  defense_ = 20;
}

Orc::Orc(const Orc& orig) {
}

Orc::~Orc() {
}

