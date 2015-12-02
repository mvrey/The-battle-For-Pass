/* 
 * File:   MainMenu.cc
 * Author: Marcos Vazquez
 * 
 * Created on November 15, 2015, 11:55 PM
 */

#include "../../include/Screen/MainMenu.h"

MainMenu::MainMenu() {
}

MainMenu::MainMenu(const MainMenu& orig) {
}

MainMenu::~MainMenu() {
}

void MainMenu::Draw() {
  DrawBegin();
  ESAT::DrawText(500.0f, 50.0f, "The Battle for Pass");
  DrawEnd();
}


/// @brief  Updates main menu status
void MainMenu::Update() {
  if (click_) {
    int clicked_button = CheckButtonsClick();
    switch (clicked_button) {
      case 0:
        Manager::getInstance()->screen_ = new NewGame();
        break;
      case 1:
        break;
      case 2:
        break;
      case 3:
        Manager::getInstance()->quit_game_ = true;
      default:
        break;
    }
  }
}