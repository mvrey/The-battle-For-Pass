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

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ESAT/sprite.h>
#include <ESAT/window.h>
#include "../../include/Main/Grid.h"
#include "../../lib/TMXparser/Tmx.h.in"

#include "../../include/Character/Friend.h"
#include "../../include/Enemy/Brown_Asp.h"
#include "../../include/Enemy/White_Asp.h"
#include "../../include/Enemy/Harpy.h"
#include "../../include/Enemy/Skeleton.h"
#include "../../include/Enemy/Torturer.h"
#include "../../include/Enemy/Troll.h"
#include "../../include/Enemy/Soldier1.h"
#include "../../include/Enemy/Soldier2.h"
#include "../../include/Enemy/Black_Dragon.h"
#include "../../include/config.h"

class Map {
  
  public:

    //Maps inside the game
    enum MapId {
      kMap_Village,
      kMap_House,
      kMap_Marsh,
      kMap_Cave,
      kMap_Fortress,
      kMap_Hall
    };

    struct TileImage {
      ESAT::SpriteHandle sprite;
      ESAT::Mat3 transform;
      ~TileImage() {
//        printf("Releasing sprite\n");
        ESAT::SpriteRelease(sprite);
      };
    };
    typedef struct TileImage TileImage;
    
    Map();
    Map(const Map& orig);
    ~Map();
    static Foe* GetEnemy(int n);
    int LoadFromFile(std::string filename, Map* maps[10], bool hard);
    virtual Foe* SelectRandomEnemy();
    void DrawLoadingScreen(int map_id, int stage);
    
    //A collection of ids of enemies that can spawn in this map
    std::vector<int> enemies_pool_ ;
    
    MapId id_;
    Grid* enemies_;
    Grid* collisions_;
    Grid* portals_;
    Grid* npcs_;

    TileImage* tiles_[5000];
    int num_tiles_ = 0;
    
    int tile_width_;
    int tile_height_;
    int init_x_;
    int init_y_;
    int last_x_;
    int last_y_;
    float player_escale_;
    
    ESAT::SpriteHandle battle_background_;

  private:
    
};

#endif /* MAP_H */

