/* Copyright 2015 Marcos Vazquez. All rights reserved.    
 * 
 * Author: Marcos Vazquez <vazquezre@esat-alumni.es>  
 * Created on November 17, 2015, 12:27 AM
 */

#ifndef ELF_H
#define ELF_H 1

#include "Race.h"

class Elf: public Race {
public:
  Elf();
  Elf(const Elf& orig);
  virtual ~Elf();
private:

};

#endif /* ELF_H */

