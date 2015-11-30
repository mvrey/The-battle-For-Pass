/* Copyright 2015 Marcos Vazquez. All rights reserved.    
 * 
 * Author: Marcos Vazquez <vazquezre@esat-alumni.es>  
 * Created on November 17, 2015, 11:13 AM
 */

#ifndef BOSS_H
#define BOSS_H 1

#include <string>
#include <ESAT/sprite.h>
#include "Job.h"

class Boss: public Job {
public:
  Boss();
  Boss(const Boss& orig);
  virtual ~Boss();
  
private:
  
};

#endif /* BOSS_H */