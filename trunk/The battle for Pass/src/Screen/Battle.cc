/* 
 * File:   Battle.cc
 * Author: Marcos Vazquez
 * 
 * Created on November 23, 2015, 12:07 PM
 */

#include "../../include/Screen/Battle.h"

Battle::Battle() {
  log_ = " ";
  is_over_ = false;
  Init();
}

Battle::Battle(Foe* enemy) {
  enemy_ = enemy;
  log_ = " ";
  is_over_ = false;
  Init();
}

Battle::Battle(const Battle& orig) {
}

Battle::~Battle() {
}

void Battle::Init() {
  printf("initializing battle\n");
  CreateButtons();
  spells_img_ = ESAT::SpriteFromFile("assets/raw/spells.png");
  background_ = ESAT::SpriteFromFile("assets/background/battle_village.png");
}

void Battle::Input() {
  click_ = ESAT::MouseButtonUp(0);
  if (ESAT::IsKeyDown('S')) {
    drawing_spells_ = !drawing_spells_;
  }  
}


void Battle::Update() {
  
  if (click_) {
    if (this->is_over_) {
      Ally* player = Manager::getInstance()->player_;
      if (player->xp_ > player->next_level_xp_) {
        player->xp_ = player->xp_ - player->next_level_xp_;
        player->LevelUp();
      }
      delete Manager::getInstance()->screen_;
      Manager::getInstance()->screen_ = new Game();
    } else {
      int clicked_button = CheckButtonsClick();
      switch (clicked_button) {
        case 0:
          //Attack
          Fight();
          break;
        case 1:
          //Cast
          drawing_spells_ = !drawing_spells_;
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
}


void Battle::Draw() {
  int stat_multiplier = 10;
  Ally* player = Manager::getInstance()->player_;
  DrawBegin();
  
  //Print Healthbars and bust/battler images
  //Print options to attack/flee/cast_spell
  
  DrawRectangle(100.0f, 20.0f, player->HP_*stat_multiplier, 30.0f, 0x00CC00FF, true);
  DrawRectangle(100.0f, 60.0f, player->MP_*stat_multiplier, 30.0f, 0x0000CCFF, true);
  ESAT::DrawSprite(player->battler_img_, 100, 100);
  
  DrawRectangle(1250.0f, 60.0f, enemy_->HP_*stat_multiplier, 30, 0x00CC00FF, false);
  ESAT::DrawSprite(enemy_->battler_img_, 1000, 250);
  
  DrawLog();
  
  if (drawing_spells_) {
    DrawSpells();
  }
  
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

void Battle::CheckResult() {
  if (Manager::getInstance()->player_->HP_ <= 0) {
    CheckLogLength();
    log_ += "\nYou have been defeated. Click anywhere to continue\n";
    Manager::getInstance()->player_->current_sprite_ = Manager::getInstance()->player_->dead_sprite_;
    is_over_ = true;
  } else if (enemy_->HP_ <= 0) {
    CheckLogLength();
    log_ += "\nYou win this battle. Click anywhere to continue\n";
    is_over_ = true;
  }
}

void Battle::Fight() {
  Ally* player = Manager::getInstance()->player_;
  int damage = 0;
  
  CheckLogLength();
          
  damage = player->attack_ * (100 - enemy_->defense_) / 300;
  enemy_->HP_ -= damage;
  log_ += "You attack for "+ std::to_string(damage)+" damage\n";
  
  damage = enemy_->attack_ * (100 - player->defense_) / 300;
  player->HP_ -= damage;
  log_ += "Your foe attacks for "+ std::to_string(damage)+" damage\n";
  
  CheckResult();
  
  //Check if the battle is over and the player has won
  if (player->HP_ > 0 && is_over_) {
    player->xp_ += enemy_->xp_;
    player->gold_ += enemy_->gold_;
    std::string xp_str = std::to_string(enemy_->xp_);
    std::string gold_str = std::to_string(enemy_->gold_);
    log_ += "Your earn "+xp_str+" xp and "+gold_str+" coins\n";
    
    if (player->xp_ > player->next_level_xp_)
      log_ += "You have leveled up!\n";
  }
}

void Battle::Flee() {
  if (Misc::random(100) < 30) {
    CheckLogLength();
    log_ += "You fail to flee!\n";
    int damage = enemy_->attack_ * (100 - Manager::getInstance()->player_->defense_) / 300;
    Manager::getInstance()->player_->HP_ -= damage;
    log_ += "Your foe attacks for "+ std::to_string(damage)+" damage\n";
    CheckResult();
  } else {
    delete Manager::getInstance()->screen_;
    Manager::getInstance()->screen_ = new Game();
  }
}

void Battle::DrawSpells() {
  Ally* player = Manager::getInstance()->player_;
  int base_x = 380;
  float bar_max_length = 505.0f;
  float bar_length = 0;
  std::string bar_str;
  
  ESAT::DrawSetTextSize(18);
  ESAT::DrawSprite(spells_img_, base_x, 0);
//  ESAT::DrawText(base_x+210.0f, 123.0f, std::to_string(player->level_).c_str());
//  
//  bar_str = std::to_string((int)player->xp_)+" / "+std::to_string((int)player->next_level_xp_);
//  bar_length = ((float)player->xp_ / (float)player->next_level_xp_) * bar_max_length;
//  Screen::DrawRectangle(base_x+255.0f, 107.0f, bar_length, 20.0f, 0xCCCCCCDD, true);
//  ESAT::DrawSetFillColor(255, 255, 255, 255);
//  ESAT::DrawText(base_x+450.0f, 120.0f, bar_str.c_str());
//  
//  bar_str = std::to_string((int)player->HP_)+" / "+std::to_string((int)player->max_HP_);
//  bar_length = ((float)player->HP_ / (float)player->max_HP_) * bar_max_length;
//  Screen::DrawRectangle(base_x+255.0f, 145.0f, bar_length, 20.0f, 0x00CC00DD, true);
//  ESAT::DrawSetFillColor(255, 255, 255, 255);
//  ESAT::DrawText(base_x+450.0f, 158.0f, bar_str.c_str());
//  
//  bar_str = std::to_string((int)player->MP_)+" / "+std::to_string((int)player->max_MP_);
//  bar_length = ((float)player->MP_ / (float)player->max_MP_) * bar_max_length;
//  Screen::DrawRectangle(base_x+255.0f, 183.0f, bar_length, 20, 0x0000CCDD, true);
//  ESAT::DrawSetFillColor(255, 255, 255, 255);
//  ESAT::DrawText(base_x+450.0f, 196.0f, bar_str.c_str());
//  
//  ESAT::DrawSetTextSize(18);
//  ESAT::DrawSetFillColor(255, 255, 255, 255);
//  
//  ESAT::DrawText(base_x+465.0f, 348.0f, std::to_string((int)player->attack_).c_str());
//  ESAT::DrawText(base_x+465.0f, 498.0f, std::to_string((int)player->defense_).c_str());
//  
//  ESAT::DrawText(base_x+700.0f, 668.0f, std::to_string((int)player->gold_).c_str());
}