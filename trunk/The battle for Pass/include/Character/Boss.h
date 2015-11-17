/* Copyright 2015 Marcos Vazquez. All rights reserved.    
 * 
 * Author: Marcos Vazquez <vazquezre@esat-alumni.es>  
 * Created on November 17, 2015, 11:13 AM
 */

#ifndef BOSS_H
#define BOSS_H 1

#include <ESAT/sprite.h>

#include <string>
#include "Job.h"

class Boss: public Job {
public:
  Boss();
  Boss(const Boss& orig);
  virtual ~Boss();
  void Init();
  static void LoadImage(Race* race);
  
private:
  
};

#endif /* BOSS_H */