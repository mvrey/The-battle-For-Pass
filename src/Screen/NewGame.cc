/* 
 * File:   Screen.cc
 * Author: smuchy
 * 
 * Created on November 15, 2015, 11:55 PM
 */

#include "../../include/Screen/NewGame.h"

NewGame::NewGame() {
  Screen();
  Init();
}

NewGame::NewGame(const NewGame& orig) {
}

NewGame::~NewGame() {
}


void NewGame::Init() {
  CreateButtons();
}

void NewGame::Update() {
  if (click_) {
    int clicked_button = CheckButtonsClick();
    switch (clicked_button) {
      case 0:
        break;
      case 1:
        Manager::getInstance()->screen_ = new MainMenu();
        break;
      default:
        break;
    }
  }
}

void NewGame::Draw() {
  DrawBegin();
  ESAT::DrawText(450.0f, 50.0f, "The Battle for Pass - New Game");
  DrawEnd();
}

void NewGame::CreateButtons() {
  num_buttons_ = 0;
  
  CreateButton(350.0f, 630.0f, 110.0f, 250.0f, 0, button_background_, "Start Game", false);
  CreateButton(650.0f, 630.0f, 110.0f, 250.0f, 0, button_background_, "Go Back", false);
}