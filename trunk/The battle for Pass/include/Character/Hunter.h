/* Copyright 2015 Marcos Vazquez. All rights reserved.    
 * 
 * Author: Marcos Vazquez <vazquezre@esat-alumni.es>  
 * Created on November 17, 2015, 11:13 AM
 */

#ifndef HUNTER_H
#define HUNTER_H 1

#include <ESAT/sprite.h>

#include <string>
#include "Job.h"

class Hunter: public Job {
public:
  Hunter();
  Hunter(const Hunter& orig);
  virtual ~Hunter();
  void Init();
  static void LoadImage(Race* race);
  
private:
  
};

#endif /* HUNTER_H */