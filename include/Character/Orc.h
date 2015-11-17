/* Copyright 2015 Marcos Vazquez. All rights reserved.    
 * 
 * Author: Marcos Vazquez <vazquezre@esat-alumni.es>  
 * Created on November 17, 2015, 12:29 AM
 */

#ifndef ORC_H
#define ORC_H

#include "Race.h"

class Orc: public Race {
public:
  Orc();
  Orc(const Orc& orig);
  virtual ~Orc();
private:

};

#endif /* ORC_H */

