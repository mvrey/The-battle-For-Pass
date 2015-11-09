/* Copyright 2015 Marcos Vazquez. All rights reserved.    
 * 
 * Author: Marcos Vazquez <vazquezre@esat-alumni.es>  
 * Created on November 9, 2015, 11:53 AM
 */

#ifndef ITEM_H
#define ITEM_H

class Item {
public:
    Item();
    Item(const Item& orig);
    virtual ~Item();
    
    std::string name_;
    int price_;
    float attack_;
    float defense_;
private:

};

#endif /* ITEM_H */

