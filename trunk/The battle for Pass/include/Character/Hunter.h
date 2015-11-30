/* Copyright 2015 Marcos Vazquez. All rights reserved.    
 * 
 * Author: Marcos Vazquez <vazquezre@esat-alumni.es>  
 * Created on November 17, 2015, 11:13 AM
 */

#ifndef HUNTER_H
#define HUNTER_H 1

#include <string>
#include <ESAT/sprite.h>
#include "Job.h"

class Hunter: public Job {
public:
  Hunter();
  Hunter(const Hunter& orig);
  virtual ~Hunter();
  
private:
  
};

#endif /* HUNTER_H */