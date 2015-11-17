/* Copyright 2015 Marcos Vazquez. All rights reserved.    
 * 
 * Author: Marcos Vazquez <vazquezre@esat-alumni.es>  
 * Created on November 17, 2015, 11:13 AM
 */

#ifndef WIZARD_H
#define WIZARD_H 1

#include <ESAT/sprite.h>

#include <string>
#include "Job.h"

class Wizard: public Job {
public:
  Wizard();
  Wizard(const Wizard& orig);
  virtual ~Wizard();
  void Init();
  static void LoadImage(Race* race);
  
private:
  
};

#endif /* WIZARD_H */