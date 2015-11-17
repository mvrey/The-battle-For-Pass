/* Copyright 2015 Marcos Vazquez. All rights reserved.    
 * 
 * Author: Marcos Vazquez <vazquezre@esat-alumni.es> 
 * Created on November 17, 2015, 12:27 AM
 */

#include "../../include/Character/Elf.h"

Elf::Elf() {
  name_ = "Elf";
  HP_ = 20;
  MP_ = 30;
  attack_ = 20;
  defense_ = 30;
}

Elf::Elf(const Elf& orig) {
}

Elf::~Elf() {
}

