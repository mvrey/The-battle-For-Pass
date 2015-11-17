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

  if (job_set) {
    int id = Manager::getInstance()->player_->job_->id;

    if (id > -1) {
      ESAT::DrawSprite(Manager::getInstance()->player_->race_->bust_imgs_[id], 600.0f, 350.0f);
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

  Manager::getInstance()->player_->job_ = new Job();
  job_set = false;
}

void NewGame::selectJob(int job_id) {
  Manager::getInstance()->player_->job_->id = job_id;
  job_set = true;
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