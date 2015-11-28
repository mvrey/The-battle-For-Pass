/* 
 * File:   Harpy.h
 * Author: Marcos Vazquez
 *
 * Created on November 27, 2015, 3:44 PM
 */

#ifndef HARPY_H
#define HARPY_H 1

#include "Foe.h"

class Harpy: public Foe {
public:
  Harpy();
  Harpy(const Harpy& orig);
  virtual ~Harpy();
private:

};

#endif /* HARPY_H */

