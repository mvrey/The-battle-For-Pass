/* Copyright 2015 Marcos Vazquez. All rights reserved.    
 * 
 * Author: Marcos Vazquez <vazquezre@esat-alumni.es>  
 * Created on November 9, 2015, 11:50 AM
 */

#ifndef INVENTORY_H
#define INVENTORY_H

class Inventory {
  public:
    Inventory();
    Inventory(const Inventory& orig);
    virtual ~Inventory();
    
    int gold_;
    Weapon left_hand_;
    Weapon right_hand_;
    Armor armor_;
    
    Item slots_[10];
    
  private:

};

#endif /* INVENTORY_H */

