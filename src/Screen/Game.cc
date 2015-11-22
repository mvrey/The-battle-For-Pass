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

void Game::Draw() {
  DrawBegin();
  
  Map* map = Manager::getInstance()->map_;
  
  for (int i=0; i<map->num_tiles; i++) {
    ESAT::DrawSpriteWithMatrix(map->tiles[i].sprite, map->tiles[i].transform);
  }
  
  
  //ANIMATION DRAW TEST
  Animation* anim = Manager::getInstance()->player_->animation_south_;
  for (int i=0; i<8; i++) {
    ESAT::DrawSprite(anim->frames_[i], 100*i, 330);
  }
  anim = Manager::getInstance()->player_->animation_west_;
  for (int i=0; i<8; i++) {
    ESAT::DrawSprite(anim->frames_[i], 100*i, 430);
  }
  anim = Manager::getInstance()->player_->animation_east_;
  for (int i=0; i<8; i++) {
    ESAT::DrawSprite(anim->frames_[i], 100*i, 530);
  }
  anim = Manager::getInstance()->player_->animation_north_;
  for (int i=0; i<8; i++) {
    ESAT::DrawSprite(anim->frames_[i], 100*i, 630);
  }
  
  DrawEnd();
}


/// @brief  Updates main menu status
void Game::Update() {
  if (click_) {
    int clicked_button = CheckButtonsClick();
    switch (clicked_button) {
      case 0:
        break;
      case 1:
        break;
      case 2:
        break;
      case 3:
      default:
        break;
    }
  }
}


void Game::CreateButtons() {
  num_buttons_ = 0;
}