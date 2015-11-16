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
  dwarf_sprite = ESAT::SpriteFromFile("assets/character/dwarf.png");
  elf_sprite = ESAT::SpriteFromFile("assets/character/elf.png");
  human_sprite = ESAT::SpriteFromFile("assets/character/human.png");
  orc_sprite = ESAT::SpriteFromFile("assets/character/orc.png");
  
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
  
  //Navigation buttons
  CreateButton(350.0f, 630.0f, 110.0f, 250.0f, 0, button_background_, "Start Game", false);
  CreateButton(650.0f, 630.0f, 110.0f, 250.0f, 0, button_background_, "Go Back", false);
  
  //Race selectors
  CreateButton(430.0f, 150.0f, 70.0f, 70.0f, 0, dwarf_sprite, "", true);
  CreateButton(360.0f, 150.0f, 70.0f, 70.0f, 0, elf_sprite, "", true);
  CreateButton(290.0f, 150.0f, 70.0f, 70.0f, 0, human_sprite, "", true);
  CreateButton(220.0f, 150.0f, 70.0f, 70.0f, 0, orc_sprite, "", true);
  
  //Class selectors
  CreateButton(830.0f, 150.0f, 70.0f, 70.0f, 0, nullptr, "", true);
  CreateButton(900.0f, 150.0f, 70.0f, 70.0f, 0, nullptr, "", true);
  CreateButton(970.0f, 150.0f, 70.0f, 70.0f, 0, nullptr, "", true);
  CreateButton(1040.0f, 150.0f, 70.0f, 70.0f, 0, nullptr, "", true);
  
}