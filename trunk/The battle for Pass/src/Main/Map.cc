/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Map.cc
 * Author: smuchy
 * 
 * Created on November 15, 2015, 12:13 AM
 */

#include "../../include/Main/Map.h"
#include "ESAT/draw.h"

Map::Map() {
  tile_width_ = 0;
  tile_height_ = 0;
  init_x_ = 0;
  init_y_ = 0;
  last_x_ = 0;
  last_y_ = 0;
  player_escale_ = 0.0f;
}

Map::Map(const Map& orig) {
}

Map::~Map() {
  delete enemies_;
  delete collisions_;
  delete portals_;
  delete npcs_;
  enemies_ = nullptr;
  collisions_ = nullptr;
  portals_ = nullptr;
  npcs_ = nullptr;

  ESAT::SpriteRelease(battle_background_);
  for (int i=1; i<num_tiles_; i++) {
    delete tiles_[i];
  }
  free(*tiles_);
}

int Map::LoadFromFile(std::string filename, Map* maps[10]) {
  //Tileset dimensions
  int width, height;
  //Tile dimensions
  int tile_width, tile_height;
  //Tileset full image
  ESAT::SpriteHandle tileset_img;
  //Tileset caching
  const Tmx::Tileset* tileSets[10];
  int tileSet_first_gid[10];
  int num_tileSets = 0;
  //Path to the tileset image files
  std::string path("assets/raw/");
  static int map_id = 0;
  
  
  map_id++;
  if (map_id==7)
    map_id = 1;
  
  DrawLoadingScreen(map_id, 0);
  
  //Load battle background
  battle_background_ = ESAT::SpriteFromFile(("assets/background/battle_"+filename+".png").c_str());
  
  DrawLoadingScreen(map_id, 1);
  
  //Load Map
  Tmx::Map *map = new Tmx::Map();
  std::string fileName = "assets/raw/"+filename+".tmx";
  map->ParseFile(fileName);

  if (map->HasError()) {
    printf("error code: %d\n", map->GetErrorCode());
    printf("error text: %s\n", map->GetErrorText().c_str());

    return map->GetErrorCode();
  }
  
  printf("Map File Parsed\n");
  
  //Get the starting coordinates of the map via its properties
  const Tmx::PropertySet properties = map->GetProperties();
  init_x_ = properties.GetIntProperty("InitX");
  init_y_ = properties.GetIntProperty("InitY");
  printf("\n\ninit: %d, %d\n\n", init_x_, init_y_);
  //Get player sprite scaling for the current map
  player_escale_ = properties.GetIntProperty("PlayerEscale");
  if (player_escale_ == 0) player_escale_ = 1;


  DrawLoadingScreen(map_id, 2);
  
  // Load tilesets
  for (int i = 0; i < map->GetNumTilesets(); ++i) {

    printf("                                    \n");
    printf("====================================\n");
    printf("Tileset : %02d\n", i);
    printf("====================================\n");

    // Get a tileset.
    const Tmx::Tileset *tileset = map->GetTileset(i);

    //Load the tileset image as a whole
    tileset_img = ESAT::SpriteFromFile((path+tileset->GetImage()->GetSource()).c_str());

    //Tileset dimensions
    width = tileset->GetImage()->GetWidth();
    height = tileset->GetImage()->GetHeight();
    printf("Width is:  %d\n", width);
    printf("Height is:  %d\n", height);

    //Tile dimensions
    tile_width = tileset->GetTileWidth();
    tile_height= tileset->GetTileHeight();
    printf("TIleWidth is:  %d\n", tile_width);
    printf("TileHeight is:  %d\n", tile_height);
    
    tileSets[num_tileSets] = tileset;
    num_tileSets++;
  }

  //Reset tileset image and index
  int current_tileSet = 0;      
  tileset_img = ESAT::SpriteFromFile((path+tileSets[current_tileSet]->GetImage()->GetSource()).c_str());
  //Calculate current tileset last global id
  int horizontal = width / tile_width;
  int vertical = height / tile_height;
  int last_gid = tileSets[current_tileSet]->GetFirstGid() + (horizontal*vertical);
          
  DrawLoadingScreen(map_id, 3);
  
  // Get tile layers
  for (int i = 0; i < map->GetNumTileLayers(); ++i) {

    printf("                                    \n");
    printf("====================================\n");
    printf("Layer : %02d/%s \n", i, map->GetTileLayer(i)->GetName().c_str());
    printf("====================================\n");

    // Get a layer.
    const Tmx::TileLayer *tileLayer = map->GetTileLayer(i);

    printf("\nTileLayer dimensions are: %d, %d\n", tileLayer->GetWidth(), tileLayer->GetHeight());

    
    //Iterate through every single tile
    for (int y = 0; y < tileLayer->GetHeight(); ++y) {
      for (int x = 0; x < tileLayer->GetWidth(); ++x) {

        if (tileLayer->GetTileTilesetIndex(x, y) == -1) {
        } else {

          TileImage* onetile = new TileImage();
          
          // Get the tile's id and gid.
          int tid = tileLayer->GetTileId(x, y);
          int tgid = tileLayer->GetTileGid(x, y);
          
          //Just in case the loop goes apeshit
          int exit = 0;
          //Find the right tileset for the current map tile
          while (!((tgid >= tileSets[current_tileSet]->GetFirstGid()) && (tgid<=last_gid)) && exit<100) {
            exit++;
            if (current_tileSet == num_tileSets-1)
              current_tileSet = 0;
            else
              current_tileSet++;
            
            tileset_img = ESAT::SpriteFromFile((path+tileSets[current_tileSet]->GetImage()->GetSource()).c_str());
            
            // Recalculate new tileset variables
            width = tileSets[current_tileSet]->GetImage()->GetWidth();
            height = tileSets[current_tileSet]->GetImage()->GetHeight();
            horizontal = width / tile_width;
            vertical = height / tile_height;
            last_gid = tileSets[current_tileSet]->GetFirstGid() + (horizontal*vertical);
            /***********/
          }

          int pixel_y = (floor(tid/(width / tile_width))) * tile_height;                  
          int pixel_x = (tid%(width / tile_width)) * tile_width;

          //Store final image for the tile
          onetile->sprite = Misc::GetSubImage(tileset_img, pixel_x, pixel_y, tile_width, tile_height);
          
          //Calculate image stretching before storing the coordinates
          float escale_x = (float)kWindowWidth/(map->GetWidth()*tile_width);
          float escale_y = (float)kWindowHeight/(map->GetHeight()*tile_height);

          //Assign dimensions to class variables, precalculating stretching
          if (!this->tile_width_) {
            this->tile_width_ = tile_width * escale_x;
            this->tile_height_ = tile_height * escale_y;
          }
          
          ESAT::Mat3 escale, translate, transform;
          ESAT::Mat3InitAsScale(escale_x, escale_y, &escale);
          ESAT::Mat3InitAsTranslate((tile_width * x)*escale_x, (tile_height * y)*escale_y, &translate);
          ESAT::Mat3Multiply(translate, escale, &transform);
          
          //Store image final drawing matrix
          onetile->transform = transform;

          tiles_[num_tiles_] = onetile;
          num_tiles_++;
        }
      }
    }
  }

  
  enemies_ = new Grid(map->GetWidth(), map->GetHeight());
  enemies_->init();
  collisions_ = new Grid(map->GetWidth(), map->GetHeight());
  collisions_->init();
  portals_ = new Grid(map->GetWidth(), map->GetHeight());
  portals_->init();
  npcs_ = new Grid(map->GetWidth(), map->GetHeight());
  npcs_->init();
  
  printf("Enemies Grid is  %dx%d",map->GetWidth(), map->GetHeight());
  
  DrawLoadingScreen(map_id, 4);
  
  // Iterate through all of the object groups.
  for (int i = 0; i < map->GetNumObjectGroups(); ++i) {
    
    // Get an object group.
    const Tmx::ObjectGroup *objectGroup = map->GetObjectGroup(i);

    printf("                                    \n");
    printf("====================================\n");
    printf("Object group : %02d (%s)\n", i, objectGroup->GetName().c_str());
    printf("====================================\n");

    int tile_x, tile_y;
    Foe* enemy;
    
    // Iterate through all objects in the object group.
    for (int j = 0; j < objectGroup->GetNumObjects(); ++j) {

      // Get an object.
      const Tmx::Object *object = objectGroup->GetObject(j);

      tile_x = floor(object->GetX() /tile_width);
      tile_y = floor (object->GetY() / tile_height);
      
      // Print information about the object.
//      printf("Object Name: %s\n", object->GetName().c_str());
//      printf("Object Pixel Position: (%03d, %03d)\n", object->GetX(), object->GetY());
//      printf("Object Grid Position: (%d, %d)\n\n", tile_x, tile_y);
      
      if (objectGroup->GetName() == "Collisions") {
        //Assign grid value to this object's pointer (Since it won't cause a segfault)
        collisions_->setElement(tile_x, tile_y, this);
      } else if (objectGroup->GetName() == "Portals"){
        printf("Creating Portal\n");
        //The grid points to its target Map object
        Map* m = maps[atoi(object->GetType().c_str())];
        portals_->setElement(tile_x, tile_y, m);
      } else if (objectGroup->GetName() == "Enemies") {
        //Insert object in corresponding grid (enemies)
        printf("Creating Enemy\n");
        int enemy_id = atoi(object->GetType().c_str());
        enemy = Map::GetEnemy(enemy_id);
        
        //Add this enemy_id to the pool if it doesn't exist yet
        if (std::find(enemies_pool_.begin(), enemies_pool_.end(), enemy_id) == enemies_pool_.end()) {
          printf("PUSHING ENEMY: %d\n", enemy_id);
          enemies_pool_.push_back(enemy_id);
        }
        
        enemy->LoadImages();
        enemies_->setElement(tile_x, tile_y, enemy);
      } else if (objectGroup->GetName() == "NPCs") {
        //Create a new npc and put it in the grid
        Friend* npc = new Friend(atoi(object->GetType().c_str()));
        npcs_->setElement(tile_x, tile_y, npc);
      }
      
    }
  }
  
//  delete map;
  return 0;
}


Foe* Map::SelectRandomEnemy() {
  
  int index = Misc::random(enemies_pool_.size());
  int id = enemies_pool_[index];
  Foe* enemy;
  
  enemy = GetEnemy(id);
  enemy->LoadImages();
  return enemy;
}


Foe* Map::GetEnemy(int n) {
  Foe* enemy;
  
  switch(n) {
    case 0:
      enemy = new Brown_Asp();
      break;
    case 1:
      enemy = new White_Asp();
      break;
    case 2:
      enemy = new Harpy();
      break;
    case 3:
      enemy = new Skeleton();
      break;
    case 4:
      enemy = new Torturer();
      break;
    case 5:
      enemy = new Troll();
      break;
    case 6:
      enemy = new Soldier1();
      break;
    case 7:
      enemy = new Soldier2();
      break;
    case 8:
      enemy = new Black_Dragon();
      break;
  }
  
  return enemy;
}



void Map::DrawLoadingScreen(int map_id, int stage) {
  std::string stage_str;
  
  ESAT::DrawBegin();
  ESAT::DrawClear(0, 0, 0);
  
  ESAT::DrawSetFillColor(255, 255, 255, 255);
  ESAT::DrawSetTextSize(30);
  ESAT::DrawText(550.0f, 300.0f, ("Loading Map "+std::to_string(map_id)+"/"+std::to_string(kNumMaps)).c_str());
  
  switch(stage) {
    case 0:
      stage_str = "Loading battle background";
      break;
    case 1:
      stage_str = "Reading tmx file";
      break;
    case 2:
      stage_str = "Loading tileset files";
      break;
    case 3:
      stage_str = "Loading tile layers";
      break;
    case 4:
      stage_str = "Loading objects";
      break;
  }
  
  ESAT::DrawText(550.0f, 450, stage_str.c_str());
  
  ESAT::DrawEnd();
  ESAT::WindowFrame();
}