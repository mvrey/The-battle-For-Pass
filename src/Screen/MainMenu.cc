/* 
 * File:   Screen.cc
 * Author: smuchy
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
  
  ESAT::DrawText(200.0f, 200.0f, "The Battle for Pass - Main Menu");
  DrawEnd();
}