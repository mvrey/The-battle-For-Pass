/* 
 * File:   Black_Dragon.h
 * Author: Marcos Vazquez
 *
 * Created on November 28, 2015, 1:01 PM
 * 
 * This is intended to act as the final boss of the game.
 */

#ifndef BLACK_DRAGON_H
#define BLACK_DRAGON_H 1

#include "Foe.h"

class Black_Dragon: public Foe {
public:
  Black_Dragon();
  Black_Dragon(const Black_Dragon& orig);
  virtual ~Black_Dragon();
private:

};

#endif /* BLACK_DRAGON_H */

