/* Copyright 2015 Marcos Vazquez. All rights reserved.    
 * 
 * Author: Marcos Vazquez <vazquezre@esat-alumni.es>  
 * Created on November 9, 2015, 8:15 PM
 *
 * File:   Map.h                                              
 * A class that represents an in-game map
 *
 */

#ifndef MAP_H
#define MAP_H 1

#include "../../include/Main/Grid.h"

class Map {
  
  public:

    Map();
    Map(const Map& orig);
    ~Map();
    
    //Maps inside the game
    enum MapId {
      kMap_Village,
      kMap_Road,
      kMap_Cavern,
      kMap_Fortress
    };

    MapId id_;
    Grid terrain_;
    Grid characters_;
    Grid collisions_;


  private:
    
};

#endif /* MAP_H */

