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
  
  //Initialize textbox
  Point2 pos;
  pos.x = 540;
  pos.y = 160;
  name_box.pos = pos;
  name_box.size = 30;
  name_box.txt = std::string("");
  
  CreateButtons();
}

void NewGame::Update() {
  char key;
  
  //Detect name entry
  key = ESAT::GetNextPressedKey();
  if (key > 0) {
    if (ESAT::IsSpecialKeyDown(ESAT::kSpecialKey_Delete) && name_box.txt.length() > 0) {
      name_box.txt.pop_back();
    } else {
      printf("%c", key);
      name_box.txt += key;
    }
  }
  
  
  if (click_) {
    int clicked_button = CheckButtonsClick();
    switch (clicked_button) {
      //UI Buttons
      case 0:{
        if (race_set && job_set) {
          Manager::getInstance()->screen_ = new Game();
          
          
          //LOAD ALL MAPS AND STORE THEM IN AN ARRAY IN THE MANAGER
          //SO WE CAN STORE POINTERS IN THE PORTALS GRID
          Manager::getInstance()->maps_[0] = new Map();
          Manager::getInstance()->maps_[1] = new Map();
          Manager::getInstance()->maps_[2] = new Map();
          Manager::getInstance()->maps_[3] = new Map();
          Manager::getInstance()->maps_[4] = new Map();
          Manager::getInstance()->maps_[5] = new Map();
          Manager::getInstance()->maps_[0]->LoadFromFile("village", Manager::getInstance()->maps_);
          Manager::getInstance()->maps_[1]->LoadFromFile("house1", Manager::getInstance()->maps_);
          Manager::getInstance()->maps_[2]->LoadFromFile("marsh", Manager::getInstance()->maps_);
          Manager::getInstance()->maps_[3]->LoadFromFile("cave", Manager::getInstance()->maps_);
          Manager::getInstance()->maps_[4]->LoadFromFile("fortress", Manager::getInstance()->maps_);
          Manager::getInstance()->maps_[5]->LoadFromFile("hall", Manager::getInstance()->maps_);
          
          Manager::getInstance()->map_ = Manager::getInstance()->maps_[0];
                  
          //Set player position on map
          Ally* player = Manager::getInstance()->player_;
          int tile_width = Manager::getInstance()->map_->tile_width_;
          int tile_height = Manager::getInstance()->map_->tile_height_;
          player->x = player->tile_x * tile_width - tile_width/2;
          player->y = (player->tile_y+1) * tile_height;
        }}
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
        Manager::getInstance()->player_->LoadImages();
        break;
      default:
        break;
    }
  }
}

void NewGame::Draw() {
  DrawBegin();
  
  ESAT::DrawSetFillColor(255, 255, 255, 255);
  ESAT::DrawText(450.0f, 50.0f, "The Battle for Pass - New Game");

  ESAT::DrawSetFillColor(200, 200, 200, 255);
  ESAT::DrawText(570.0f, 150.0f, "Enter Name");
  DrawTextBox(name_box);
    
  if (race_set) {
    DrawPlayerStats();
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
  
  
  if (Manager::getInstance()->player_ == nullptr) {
    printf("\n\nCreating new player\n\n");
    Manager::getInstance()->player_ = new Ally();
    //Set a default map position
    Manager::getInstance()->player_->tile_x = 4;
    Manager::getInstance()->player_->tile_y = 15;
  } else if (race_set) {
    printf("\n\nDeleting previous race\n\n");
    delete Manager::getInstance()->player_->race_;
  }
          
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

  if(job_set) {
    Manager::getInstance()->player_->LoadImages();
  }
    
  Manager::getInstance()->player_->SetBaseStats();
  if (job_set) {
    selectJob(Manager::getInstance()->player_->job_->id_);
  }
  
  race_set = true;
}

void NewGame::selectJob(int job_id) {
  
  
  if (job_set) {
    printf("\n\nDeleting previous job\n\n");
    delete Manager::getInstance()->player_->job_;
  }
  
  
  switch(job_id) {
    case 0:
      Manager::getInstance()->player_->job_ = new Boss();
      Manager::getInstance()->player_->job_->id_ = job_id;
      Manager::getInstance()->player_->ResetStatsToRace();
      Manager::getInstance()->player_->gold_ *= 2;
      Manager::getInstance()->player_->spells_[0] = new Blizzard();
      Manager::getInstance()->player_->num_spells_ = 1;
      break;
    case 1:
      Manager::getInstance()->player_->job_ = new Hunter();
      Manager::getInstance()->player_->job_->id_ = job_id;
      Manager::getInstance()->player_->ResetStatsToRace();
      Manager::getInstance()->player_->defense_ *= 1.3;
      Manager::getInstance()->player_->spells_[0] = new Heal();
      Manager::getInstance()->player_->num_spells_ = 1;
      break;
    case 2:
      Manager::getInstance()->player_->job_ = new Warrior();
      Manager::getInstance()->player_->job_->id_ = job_id;
      Manager::getInstance()->player_->ResetStatsToRace();
      Manager::getInstance()->player_->attack_ *= 1.3;
      Manager::getInstance()->player_->spells_[0] = new FireSword();
      Manager::getInstance()->player_->num_spells_ = 1;
      break;
    case 3:
      Manager::getInstance()->player_->job_ = new Wizard();
      Manager::getInstance()->player_->job_->id_ = job_id;
      Manager::getInstance()->player_->ResetStatsToRace();
      Manager::getInstance()->player_->MP_ *= 1.3;
      Manager::getInstance()->player_->max_MP_ *= 1.3;
      Manager::getInstance()->player_->spells_[0] = new Heal();
      Manager::getInstance()->player_->spells_[1] = new FireSword();
      Manager::getInstance()->player_->spells_[2] = new Blizzard();
      Manager::getInstance()->player_->num_spells_ = 3;
      break;
    default:
      Manager::getInstance()->player_->job_->id_ = -1;
      job_set = false;
      break;
  }

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

void NewGame::DrawPlayerStats() {
  int multiplier = 4;
  
  int hp = Manager::getInstance()->player_->HP_;
  int mp = Manager::getInstance()->player_->MP_;
  int attack = Manager::getInstance()->player_->attack_;
  int defense = Manager::getInstance()->player_->defense_;
  
  DrawRectangle(500.0f,280.0f,hp*multiplier,30,0x00CC00FF, false);
  DrawRectangle(500.0f,330.0f,mp*multiplier,30,0x0000CCFF, false);
  DrawRectangle(500.0f,380.0f,attack*multiplier,30,0xCC0000FF, false);
  DrawRectangle(500.0f,430.0f,defense*multiplier,30,0x999999FF, false);
}