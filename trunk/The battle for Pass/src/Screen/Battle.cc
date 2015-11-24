/* 
 * File:   Battle.cc
 * Author: Marcos Vazquez
 * 
 * Created on November 23, 2015, 12:07 PM
 */

#include "../../include/Screen/Battle.h"

Battle::Battle() {
  background_ = ESAT::SpriteFromFile("assets/background/battle_village.png");
}

Battle::Battle(Foe* enemy) {
  background_ = ESAT::SpriteFromFile("assets/background/battle_village.png");
  enemy_ = enemy;
  log_ = " ";
}

Battle::Battle(const Battle& orig) {
}

Battle::~Battle() {
}

void Battle::Init() {
  printf("initializing battle\n");
  CreateButtons();
}

void Battle::Input() {
  click_ = ESAT::MouseButtonUp(0);
//  if (ESAT::IsKeyDown('F')) {
//    Manager::getInstance()->screen_ = new Game();
//  }  
}


void Battle::Update() {
  
  if (click_) {
    int clicked_button = CheckButtonsClick();
    switch (clicked_button) {
      case 0:
        //Attack
        Fight();
        break;
      case 1:
        //Cast
        break;
      case 2:
        //Potion
        break;
      case 3:
        //Flee
        Flee();
        break;
      default:
        break;
    }
  }
}


void Battle::Draw() {
  int life_multiplier = 10;
  Ally* player = Manager::getInstance()->player_;
  DrawBegin();
  
  //Print Healthbars and bust/battler images
  //Print options to attack/flee/cast_spell
  
  DrawRectangle(100.0f, 60.0f, player->HP_*life_multiplier, 30.0f, 0x00CC00FF, true);
  ESAT::DrawSprite(player->battler_img_, 100, 100);
  
  DrawRectangle(1250.0f, 60.0f, enemy_->HP_*life_multiplier, 30, 0x00CC00FF, false);
  ESAT::DrawSprite(enemy_->battler_img_, 1000, 250);
  
  DrawLog();
  
  DrawEnd();
}


void Battle::CreateButtons() {
  num_buttons_ = 0;
  
  CreateButton(20.0f, 590.0f, 90.0f, 220.0f, 0, button_background_, "Attack", false);
  CreateButton(20.0f, 680.0f, 90.0f, 220.0f, 0, button_background_, "Cast Spell", false);
  CreateButton(240.0f, 590.0f, 90.0f, 220.0f, 0, button_background_, "Use Potion", false);
  CreateButton(240.0f, 680.0f, 90.0f, 220.0f, 0, button_background_, "Flee", false);
}

void Battle::DrawLog() {
  int text_size = 15;
  int start = 0;
  int end = 0;
  int i,j = 0;
  float height = 620.0f;
  int lines = std::count(log_.begin(), log_.end(), '\n') + 0;
  std::string line = "\0";
  
  DrawRectangle(460.0f, 590.0f, 900.0f, 760.0f, 0x55555599, true);
  ESAT::DrawSetTextSize(text_size);
  ESAT::DrawSetFillColor(255, 255, 255, 255);
  
  for (i=j; j<lines; j++) {
    end = log_.find('\n',start+1);
    line = log_.substr (start, end-start);
    ESAT::DrawText(490.0f, height, line.c_str());
    height += text_size;
    start = end;
  }
}

void Battle::CheckLogLength() {
  int log_lines = std::count(log_.begin(), log_.end(), '\n') + 0;
  
  if (log_lines == 10) {
    log_ = "";
  }
}

void Battle::Fight() {
  Ally* player = Manager::getInstance()->player_;
  int damage = 0;
  
  damage = player->attack_ * (100 - enemy_->defense_) / 300;
  enemy_->HP_ -= damage;
  log_ += "You attack for "+ std::to_string(damage)+" damage\n";
  
  damage = enemy_->attack_ * (100 - player->defense_) / 300;
  player->HP_ -= damage;
  log_ += "Your foe attacks for "+ std::to_string(damage)+" damage\n";
}

void Battle::Flee() {
  if (Misc::random(100) < 33) {
    log_ += "You fail to flee!\n";
    int damage = enemy_->attack_ * (100 - Manager::getInstance()->player_->defense_) / 300;
    Manager::getInstance()->player_->HP_ -= damage;
    log_ += "Your foe attacks for "+ std::to_string(damage)+" damage\n";
  } else {
    delete Manager::getInstance()->screen_;
    Manager::getInstance()->screen_ = new Game();
  }
}