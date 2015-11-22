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

Map::Map() {
}

Map::Map(const Map& orig) {
}

Map::~Map() {
}

int Map::LoadFromFile() {
  //Tileset dimensions
  int width, height;
  //Tile dimensions
  int tile_width, tile_height;
  //Tileset full image
  ESAT::SpriteHandle tileset_img;
  
  
  //Load Map
  Tmx::Map *map = new Tmx::Map();
  std::string fileName = "assets/raw/village.tmx";
  map->ParseFile(fileName);

  if (map->HasError()) {
    printf("error code: %d\n", map->GetErrorCode());
    printf("error text: %s\n", map->GetErrorText().c_str());

    return map->GetErrorCode();
  }
  
  printf("Map File Parsed\n");
    
    
  // Load tilesets
  for (int i = 0; i < map->GetNumTilesets(); ++i) {

    printf("                                    \n");
    printf("====================================\n");
    printf("Tileset : %02d\n", i);
    printf("====================================\n");

    // Get a tileset.
    const Tmx::Tileset *tileset = map->GetTileset(i);


    //Load the tileset image as a whole
    std::string path("assets/raw/");
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
  }

  // Get tile layers
  for (int i = 0; i < map->GetNumTileLayers(); ++i) {

    printf("                                    \n");
    printf("====================================\n");
    printf("Layer : %02d/%s \n", i, map->GetTileLayer(i)->GetName().c_str());
    printf("====================================\n");

    // Get a layer.
    const Tmx::TileLayer *tileLayer = map->GetTileLayer(i);


    printf("\nTileLayer dimensions are: %d, %d\n", tileLayer->GetWidth(), tileLayer->GetHeight());

    for (int y = 0; y < tileLayer->GetHeight(); ++y) {
      for (int x = 0; x < tileLayer->GetWidth(); ++x) {

        if (tileLayer->GetTileTilesetIndex(x, y) == -1) {
        } else {

          TileImage onetile;

          // Get the tile's id and gid.
          int tid = tileLayer->GetTileId(x, y);

          int pixel_y = (floor(tid/(width / tile_width))) * tile_height;                  
          int pixel_x = (tid%(width / tile_width)) * tile_width;

          //Store final image for the tile
          onetile.sprite = GetSubImage(tileset_img, pixel_x, pixel_y, tile_width, tile_height);
          
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
          onetile.transform = transform;

          tiles[num_tiles] = onetile;
          num_tiles++;
        }
      }
    }
  }


  delete map;

  return 0;
}


ESAT::SpriteHandle Map::GetSubImage(ESAT::SpriteHandle img, int x, int y, int width, int height) {
  //Iterate through every single pixel and add it to a pixel buffer
  unsigned char pixel_buffer[height*width*4];
  int buffer_index=0;

  for (int h=y; h<y+height; h++) {
    for (int w=x; w<x+width; w++) {
      unsigned char outRGBA[4];
      ESAT::SpriteGetPixel(img, w, h, outRGBA);
      pixel_buffer[buffer_index+0] = outRGBA[0];
      pixel_buffer[buffer_index+1] = outRGBA[1];
      pixel_buffer[buffer_index+2] = outRGBA[2];
      pixel_buffer[buffer_index+3] = outRGBA[3];
      buffer_index += 4;
    }
  }
  
  return ESAT::SpriteFromMemory(width, height, pixel_buffer);
}