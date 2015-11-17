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
      //UI Buttons
      case 0:
        break;
      case 1:
        Manager::getInstance()->screen_ = new MainMenu();
        break;
      //Race Buttons
      case 2:
        createPlayer("dwarf");
        break;
      case 3:
        createPlayer("elf");
        break;
      case 4:
        createPlayer("human");
        break;
      case 5:
        createPlayer("orc");
        break;
      //Job/Class Buttons
      case 6:
      case 7:
      case 8:
      case 9:
        selectJob(clicked_button - 6);
        break;
      default:
        break;
    }
  }
}

void NewGame::Draw() {
  DrawBegin();
  ESAT::DrawText(450.0f, 50.0f, "The Battle for Pass - New Game");

  if (race_set) {
    DrawRaceStats();
  }
  
  if (job_set) {
    int id = Manager::getInstance()->player_->job_->id_;

    if (id > -1) {
      //Draw transformed bust image
      ESAT::SpriteHandle bust = Manager::getInstance()->player_->race_->bust_imgs_[id];
      
      float sprite_width = ESAT::SpriteWidth(bust);
      float sprite_height = ESAT::SpriteHeight(bust);
      ESAT::Mat3 translate, escale, transform;
      ESAT::Mat3InitAsScale((float)180/sprite_width, (float)360/sprite_height, &escale);
      ESAT::Mat3InitAsTranslate(550.0f, 210.0f, &translate);
      ESAT::Mat3Multiply(translate, escale, &transform);
      ESAT::DrawSpriteWithMatrix(bust, transform);
      
      //Draw race and job
      std::string profile = Manager::getInstance()->player_->race_->name_ + " - " + Manager::getInstance()->player_->job_->name_;
      ESAT::DrawText(520.0f, 600.0f, profile.c_str());
      
      //Draw job image
      ESAT::SpriteHandle desc_img = Manager::getInstance()->player_->job_->description_image_;
      ESAT::DrawSprite(desc_img, 955.0f, 250.0f);
      
      //Draw job description
      
      DrawTextWithLineBreaks(800.0f, 470.0f, 500, 15.0f, Manager::getInstance()->player_->job_->description_.c_str());
    }
  }
  
  DrawEnd();
}


void NewGame::createPlayer(std::string race_name) {
  
  Manager::getInstance()->player_ = new Ally();
  
  if (race_name == "dwarf") {
      Manager::getInstance()->player_->race_ = new Dwarf();
  } else if (race_name == "elf") {
      Manager::getInstance()->player_->race_ = new Elf();
  } else if (race_name == "human") {
      Manager::getInstance()->player_->race_ = new Human();
  } else if (race_name == "orc") {
      Manager::getInstance()->player_->race_ = new Orc();
  }
  
  Manager::getInstance()->player_->race_->LoadImages();

  for (int i=0; i<Job::num_jobs_; i++) {
    this->option_buttons_[i+6].img = Manager::getInstance()->player_->race_->face_imgs_[i];
  }

  //Manager::getInstance()->player_->job_ = new Job();
  race_set = true;
  job_set = false;
}

void NewGame::selectJob(int job_id) {
  job_set = true;
  
  switch(job_id) {
    case 0:
      Manager::getInstance()->player_->job_ = new Boss();
      break;
    case 1:
      Manager::getInstance()->player_->job_ = new Hunter();
      break;
    case 2:
      Manager::getInstance()->player_->job_ = new Warrior();
      break;
    case 3:
      Manager::getInstance()->player_->job_ = new Wizard();
      break;
    default:
      job_set = false;
      break;
  }

  
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

void NewGame::DrawRaceStats() {
  int multiplier = 4;
  
  int hp = Manager::getInstance()->player_->race_->HP_;
  int mp = Manager::getInstance()->player_->race_->MP_;
  int attack = Manager::getInstance()->player_->race_->attack_;
  int defense = Manager::getInstance()->player_->race_->defense_;
  
  DrawRectangle(500.0f,280.0f,hp*multiplier,30,0x00CC00FF, false);
  DrawRectangle(500.0f,330.0f,mp*multiplier,30,0x0000CCFF, false);
  DrawRectangle(500.0f,380.0f,attack*multiplier,30,0xCC0000FF, false);
  DrawRectangle(500.0f,430.0f,defense*multiplier,30,0x999999FF, false);
}