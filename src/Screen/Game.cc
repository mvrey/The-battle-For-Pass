/* 
 * File:   Game.cc
 * Author: Marcos Vazquez
 * 
 * Created on November 15, 2015, 12:13 AM
 */

#include "../../include/Screen/Game.h"

Game::Game() {
  Screen();
  Init();
}

Game::Game(const Game& orig) {
}

Game::~Game() {
}

void Game::Init() {
  CreateButtons();
}

void Game::Input() {
  
    if (ESAT::IsSpecialKeyPressed(ESAT::kSpecialKey_Up)) {
      Manager::getInstance()->player_->Move(0);
    } else if (ESAT::IsSpecialKeyPressed(ESAT::kSpecialKey_Right)) {
      Manager::getInstance()->player_->Move(1);
    } else if (ESAT::IsSpecialKeyPressed(ESAT::kSpecialKey_Down)) {
      Manager::getInstance()->player_->Move(2);
    } else if (ESAT::IsSpecialKeyPressed(ESAT::kSpecialKey_Left)) {
      Manager::getInstance()->player_->Move(3);
    }
}

void Game::Draw() {
  DrawBegin();
  
  Map* map = Manager::getInstance()->map_;
  Ally* player = Manager::getInstance()->player_;
  
  for (int i=0; i<map->num_tiles; i++) {
    ESAT::DrawSpriteWithMatrix(map->tiles[i].sprite, map->tiles[i].transform);
  }

  ESAT::DrawSprite(Manager::getInstance()->player_->current_sprite_, player->x, player->y);
  
  DrawEnd();
}


/// @brief  Updates main menu status
void Game::Update() {
  Ally* player = Manager::getInstance()->player_;
  Grid* enemies = Manager::getInstance()->map_->enemies_;
  
  player->Update(Manager::getInstance()->map_->tile_width_,
                  Manager::getInstance()->map_->tile_height_);
  
  
  //If there's an enemy at player's position, a battle begins
  if (enemies->getElement(player->tile_x, player->tile_y)) {
    Manager::getInstance()->screen_ = new Battle();
  }
}


void Game::CreateButtons() {
  num_buttons_ = 0;
}