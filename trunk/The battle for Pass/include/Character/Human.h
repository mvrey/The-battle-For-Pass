/* Copyright 2015 Marcos Vazquez. All rights reserved.    
 * 
 * Author: Marcos Vazquez <vazquezre@esat-alumni.es>  
 * Created on November 17, 2015, 12:28 AM
 */

#ifndef HUMAN_H
#define HUMAN_H 1

#include "Race.h"

class Human: public Race {
public:
  Human();
  Human(const Human& orig);
  virtual ~Human();
private:

};

#endif /* HUMAN_H */

