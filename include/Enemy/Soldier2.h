/* 
 * File:   Soldier2.h
 * Author: Marcos Vazquez
 *
 * Created on November 28, 2015, 1:01 PM
 */

#ifndef SOLDIER2_H
#define SOLDIER2_H 1

#include "Foe.h"

class Soldier2: public Foe {
public:
  Soldier2();
  Soldier2(const Soldier2& orig);
  virtual ~Soldier2();
private:

};

#endif /* SOLDIER2_H */

