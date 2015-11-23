/* 
 * File:   Battle.h
 * Author: Marcos Vazquez
 *
 * Created on November 23, 2015, 12:06 PM
 */

#ifndef BATTLE_H
#define BATTLE_H 1

#include "Screen.h"

class Battle: public Screen {
public:
  Battle();
  Battle(const Battle& orig);
  virtual ~Battle();
private:

};

#endif /* BATTLE_H */

