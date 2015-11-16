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
  dwarf_sprite = ESAT::SpriteFromFile("assets/character/dwarf/dwarf.png");
  elf_sprite = ESAT::SpriteFromFile("assets/character/elf/elf.png");
  human_sprite = ESAT::SpriteFromFile("assets/character/human/human.png");
  orc_sprite = ESAT::SpriteFromFile("assets/character/orc/orc.png");
  
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
      case 2:
        Manager::getInstance()->player_ = new Ally();
        Manager::getInstance()->player_->race_ = new Race("dwarf");
        Manager::getInstance()->player_->race_->LoadFaces();
        
        for (int i=0; i<Job::num_jobs_; i++) {
          this->option_buttons_[6].img = Manager::getInstance()->player_->race_->face_imgs_[0];
        }
        
        Manager::getInstance()->player_->job_ = new Job();
        
        //LoadJobImages('dwarf');
        break;
      case 3:
        break;
      case 4:
        break;
      case 5:
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
  float box_side = 90.0f;
  float start_left = 140.0f;
  float start_right = 830.0f;
  
  //Navigation buttons
  CreateButton(350.0f, 630.0f, 110.0f, 250.0f, 0, button_background_, "Start Game", false);
  CreateButton(650.0f, 630.0f, 110.0f, 250.0f, 0, button_background_, "Go Back", false);
  
  //Race selectors
  CreateButton(start_left, 150.0f, box_side, box_side, 0, dwarf_sprite, "", true);
  CreateButton(start_left+(box_side*1), 150.0f, box_side, box_side, 0, elf_sprite, "", true);
  CreateButton(start_left+(box_side*2), 150.0f, box_side, box_side, 0, human_sprite, "", true);
  CreateButton(start_left+(box_side*3), 150.0f, box_side, box_side, 0, orc_sprite, "", true);
  
  //Class selectors
  CreateButton(start_right, 150.0f, box_side, box_side, 0, nullptr, "", true);
  CreateButton(start_right+(box_side*1), 150.0f, box_side, box_side, 0, nullptr, "", true);
  CreateButton(start_right+(box_side*2), 150.0f, box_side, box_side, 0, nullptr, "", true);
  CreateButton(start_right+(box_side*3), 150.0f, box_side, box_side, 0, nullptr, "", true);
  
}