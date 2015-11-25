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
  click_ = ESAT::MouseButtonUp(0);
  Grid* collisions = Manager::getInstance()->map_->collisions_;
  
  if (ESAT::IsSpecialKeyPressed(ESAT::kSpecialKey_Up)) {
    Manager::getInstance()->player_->Move(0, collisions);
  } else if (ESAT::IsSpecialKeyPressed(ESAT::kSpecialKey_Right)) {
    Manager::getInstance()->player_->Move(1, collisions);
  } else if (ESAT::IsSpecialKeyPressed(ESAT::kSpecialKey_Down)) {
    Manager::getInstance()->player_->Move(2, collisions);
  } else if (ESAT::IsSpecialKeyPressed(ESAT::kSpecialKey_Left)) {
    Manager::getInstance()->player_->Move(3, collisions);
  }
}

void Game::Draw() {
  DrawBegin();
  
  Map* map = Manager::getInstance()->map_;
  Ally* player = Manager::getInstance()->player_;
  
  for (int i=0; i<map->num_tiles; i++) {
    ESAT::DrawSpriteWithMatrix(map->tiles[i].sprite, map->tiles[i].transform);
  }

  ESAT::DrawSprite(player->current_sprite_, player->x, player->y - ESAT::SpriteHeight(player->current_sprite_));
  
  DrawEnd();
}


/// @brief  Updates main menu status
void Game::Update() {
  Ally* player = Manager::getInstance()->player_;
  Grid* enemies = Manager::getInstance()->map_->enemies_;
  
  if (click_ && player->HP_ <= 0) {
    delete Manager::getInstance()->screen_;
    Manager::getInstance()->screen_ = new GameOver();
  }
  
  player->Update(Manager::getInstance()->map_->tile_width_,
                  Manager::getInstance()->map_->tile_height_);
  
  
  //If there's an enemy at player's position, a battle begins
  if (enemies->getElement(player->tile_x, player->tile_y)) {
    Manager::getInstance()->screen_ = new Battle((Foe*)enemies->getElement(player->tile_x, player->tile_y));
    Manager::getInstance()->screen_->Init();
    
    //The enemy is removed from the enemies Grid beforehand
    Manager::getInstance()->map_->enemies_->setElement(player->tile_x, player->tile_y, 0);
  }
}


void Game::CreateButtons() {
  num_buttons_ = 0;
}