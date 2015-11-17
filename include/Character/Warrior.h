/* Copyright 2015 Marcos Vazquez. All rights reserved.    
 * 
 * Author: Marcos Vazquez <vazquezre@esat-alumni.es>  
 * Created on November 17, 2015, 11:13 AM
 */

#ifndef WARRIOR_H
#define WARRIOR_H 1

#include <ESAT/sprite.h>

#include <string>
#include "Job.h"

class Warrior: public Job {
public:
  Warrior();
  Warrior(const Warrior& orig);
  virtual ~Warrior();
  void Init();
  static void LoadImage(Race* race);
  
private:
  
};

#endif /* WARRIOR_H */