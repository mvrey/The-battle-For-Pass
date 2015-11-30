/* Copyright 2015 Marcos Vazquez. All rights reserved.    
 * 
 * Author: Marcos Vazquez <vazquezre@esat-alumni.es>  
 * Created on November 17, 2015, 11:13 AM
 */

#ifndef WIZARD_H
#define WIZARD_H 1

#include <string>
#include <ESAT/sprite.h>
#include "Job.h"

class Wizard: public Job {
public:
  Wizard();
  Wizard(const Wizard& orig);
  virtual ~Wizard();
  
private:
  
};

#endif /* WIZARD_H */