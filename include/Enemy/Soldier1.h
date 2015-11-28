/* 
 * File:   Soldier1.h
 * Author: Marcos Vazquez
 *
 * Created on November 28, 2015, 1:01 PM
 */

#ifndef SOLDIER1_H
#define SOLDIER1_H 1

#include "Foe.h"

class Soldier1: public Foe {
public:
  Soldier1();
  Soldier1(const Soldier1& orig);
  virtual ~Soldier1();
private:

};

#endif /* SOLDIER1_H */

