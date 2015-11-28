/* 
 * File:   Troll.h
 * Author: Marcos Vazquez
 *
 * Created on November 28, 2015, 1:01 PM
 */

#ifndef TROLL_H
#define TROLL_H 1

#include "Foe.h"

class Troll: public Foe {
public:
  Troll();
  Troll(const Troll& orig);
  virtual ~Troll();
private:

};

#endif /* TROLL_H */

