/* Copyright 2015 Marcos Vazquez. All rights reserved.    
 * 
 * Author: Marcos Vazquez <vazquezre@esat-alumni.es>  
 * Created on November 17, 2015, 12:26 AM
 */

#ifndef DWARF_H
#define DWARF_H

#include "Race.h"

class Dwarf: public Race {
public:
  Dwarf();
  Dwarf(const Dwarf& orig);
  virtual ~Dwarf();
private:

};

#endif /* DWARF_H */

