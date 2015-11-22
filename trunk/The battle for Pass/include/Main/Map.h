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

#include <ESAT/sprite.h>
#include <stdio.h>
#include <math.h>
#include "../../include/Main/Grid.h"
#include "../../lib/TMXparser/Tmx.h.in"
#include "../../include/config.h"

class Map {
  
  public:

    //Maps inside the game
    enum MapId {
      kMap_Village,
      kMap_Road,
      kMap_Cavern,
      kMap_Fortress
    };

    struct TileImage {
      ESAT::SpriteHandle sprite;
      ESAT::Mat3 transform;
    };
    typedef struct TileImage TileImage;
    
    Map();
    Map(const Map& orig);
    ~Map();
    int LoadFromFile();
    static ESAT::SpriteHandle GetSubImage(ESAT::SpriteHandle img, int x, int y, 
                                      int width, int height);
    
    MapId id_;
    Grid terrain_;
    Grid characters_;
    Grid collisions_;

    TileImage tiles[5000];
    int num_tiles = 0;

  private:
    
};

#endif /* MAP_H */

