/* 
 * File:   Torturer.h
 * Author: Marcos Vazquez
 *
 * Created on November 28, 2015, 1:01 PM
 */

#ifndef TORTURER_H
#define TORTURER_H 1

#include "Foe.h"

class Torturer: public Foe {
public:
  Torturer();
  Torturer(const Torturer& orig);
  virtual ~Torturer();
private:

};

#endif /* TORTURER_H */

