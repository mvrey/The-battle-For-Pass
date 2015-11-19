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
  ESAT::DrawText(450.0f, 50.0f, "The Battle for Pass - Overview Game");
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