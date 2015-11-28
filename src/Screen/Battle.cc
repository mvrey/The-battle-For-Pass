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
  background_ = Manager::getInstance()->map_->battle_background_;
  //Player stats when entering battle to restore them later
  original_attack_ = Manager::getInstance()->player_->attack_;
  original_defense_ = Manager::getInstance()->player_->defense_;
}

void Battle::Input() {
  click_ = ESAT::MouseButtonUp(0);
  if (ESAT::IsKeyDown('S')) {
    drawing_spells_ = !drawing_spells_;
  }  
}


void Battle::Update() {
  Ally* player = Manager::getInstance()->player_;
  
  if (click_) {
    if (this->is_over_) {
      //Restore player attack and defense stats
      Manager::getInstance()->player_->attack_ = original_attack_;
      Manager::getInstance()->player_->defense_ = original_defense_;
      
      //Notice that the player's level may increase several times in a single battle
      while (player->xp_ >= player->next_level_xp_) {
        player->xp_ = player->xp_ - player->next_level_xp_;
        player->LevelUp();
      }
      //Go to the GameWon screen if this was the final boss
      if (enemy_->name_ == "Black_Dragon") {
        delete Manager::getInstance()->screen_;
        Manager::getInstance()->screen_ = new GameWon();
      //Return to game otherwise
      } else {
        delete Manager::getInstance()->screen_;
        Manager::getInstance()->screen_ = new Game();
      }
    } else {
      int clicked_button = CheckButtonsClick();
      switch (clicked_button) {
        case 0:
          Fight(true);
          break;
        case 1:
          drawing_spells_ = !drawing_spells_;
          break;
        case 2:
          if (player->num_healing_potions_ > 0) {
            player->num_healing_potions_--;
            log_ += "You use a healing potion and gain 15 HP\n";
            player->HP_ += 15;
            if (player->HP_ > player->max_HP_) {
              player->HP_ = player->max_HP_;
            }  
          } else {
            log_ += "You do not have any potions left!\n";
          }
          //Potion
          break;
        case 3:
          Flee();
          break;
        case 4:
        case 5:
        case 6:
          if (player->spells_[clicked_button-4]->Cast(player, enemy_)) {
            log_ += player->spells_[clicked_button-4]->log_line_;
            Fight(false);
          } else {
            log_ += "You do not have enough mana!\n";
          }
          break;
        default:
          break;
      }
    }
  }
}


/// @brief  Override for Screen::DrawBegin so the buttons are drawn last
void Battle::DrawBegin() {
  ESAT::DrawBegin();
  ESAT::DrawClear(255, 255, 255);
  
  //Draw background image
  float sprite_width = ESAT::SpriteWidth(background_);
  float sprite_height = ESAT::SpriteHeight(background_);
  ESAT::Mat3 escale;
  ESAT::Mat3InitAsScale((float)kWindowWidth/sprite_width, (float)kWindowHeight/sprite_height, &escale);
  ESAT::DrawSpriteWithMatrix(background_, escale);
}

void Battle::Draw() {
  int stat_multiplier = 10;
  std::string stats_str;
  Ally* player = Manager::getInstance()->player_;
  DrawBegin();
  
  DrawRectangle(100.0f, 20.0f, player->HP_*stat_multiplier, 30.0f, 0x00CC00FF, true);
  DrawRectangle(100.0f, 60.0f, player->MP_*stat_multiplier, 30.0f, 0x0000CCFF, true);
  ESAT::DrawSetFillColor(255, 255, 255, 255);
  
  stats_str = std::to_string((int)player->HP_)+"/"+std::to_string((int)player->max_HP_);
  ESAT::DrawText(150.0f, 40.0f, stats_str.c_str());
  stats_str = std::to_string((int)player->MP_)+"/"+std::to_string((int)player->max_MP_);
  ESAT::DrawText(150.0f, 80.0f, stats_str.c_str());
  
  ESAT::DrawSprite(player->battler_img_, 100, 100);
  
  DrawRectangle(1250.0f, 60.0f, enemy_->HP_*stat_multiplier, 30, 0x00CC00FF, false);
  ESAT::DrawSprite(enemy_->battler_img_, 1000, 250);
  
  if (drawing_spells_) {
    DrawSpells();
  }
  DrawButtons();
  DrawLog();
  
  DrawEnd();
}


void Battle::CreateButtons() {
  Ally* player = Manager::getInstance()->player_;
  num_buttons_ = 0;
  
  CreateButton(20.0f, 590.0f, 90.0f, 220.0f, 0, button_background_, "Attack", false);
  CreateButton(20.0f, 680.0f, 90.0f, 220.0f, 0, button_background_, "Cast Spell", false);
  CreateButton(240.0f, 590.0f, 90.0f, 220.0f, 0, button_background_, "Use Potion", false);
  CreateButton(240.0f, 680.0f, 90.0f, 220.0f, 0, button_background_, "Flee", false);
  
  //Create spell buttons
  int base_x = 380;
  for (int i=0; i<player->num_spells_; i++) {
    CreateButton(base_x + 132.0f*(i+1), 197.0f, 80.0f, 80.0f, 0, player->spells_[i]->img_, "", false);
  }
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

void Battle::Fight(bool player_attacks) {
  Ally* player = Manager::getInstance()->player_;
  int damage = 0;
  
  CheckLogLength();
          
  if (player_attacks) {
    damage = player->attack_ * (100 - enemy_->defense_) / 300;
    enemy_->HP_ -= damage;
    log_ += "You attack for "+ std::to_string(damage)+" damage\n";
  }
  
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
  
  ESAT::DrawSetTextSize(18);
  ESAT::DrawSprite(spells_img_, base_x, 0);
  
  int hovered = CheckButtonsHover();
  if (hovered > 3) {
    ESAT::DrawSetTextSize(15);
    ESAT::DrawText(base_x+110.0f, 110.0f, player->spells_[hovered-4]->description_.c_str());
    ESAT::DrawText(base_x+415.0f , 645.0f, std::to_string(player->spells_[hovered-4]->mana_cost_).c_str());
  }
}

/// @brief  Override for Screen::DrawButtons that excludes the spell buttons
void Battle::DrawButtons() {
  float x = 0.0f;
  float y = 0.0f;
  float height = 0.0f;
  float width = 0.0f;
  float margin = 30.0f;

  for (int i = 0; i < num_buttons_ && (drawing_spells_ || i<4); i++) {
    x = option_buttons_[i].pos.x;
    y = option_buttons_[i].pos.y;
    height = option_buttons_[i].height;
    width = option_buttons_[i].width;

    if (option_buttons_[i].border) {
      float path_points[] = { x, y,
        x + width, y,
        x + width, y + height,
        x, y + height,
        x, y
      };

      /*rgb colors inside the polygon*/
      ESAT::DrawSetFillColor(0, 0, 0, 0);

      ESAT::DrawSetStrokeColor(255, 255, 255, 255);

      ESAT::DrawSolidPath(path_points, 5, true);
    }

    if (option_buttons_[i].img) {
      
      //Adjust background image to button
      float sprite_width = ESAT::SpriteWidth(option_buttons_[i].img);
      float sprite_height = ESAT::SpriteHeight(option_buttons_[i].img);
      ESAT::Mat3 translate, escale, transform;
      ESAT::Mat3InitAsScale((float)width/sprite_width, (float)height/sprite_height, &escale);
      ESAT::Mat3InitAsTranslate(option_buttons_[i].pos.x, option_buttons_[i].pos.y, &translate);
      ESAT::Mat3Multiply(translate, escale, &transform);
      
      ESAT::DrawSpriteWithMatrix(option_buttons_[i].img, transform);
    }

    ESAT::DrawSetTextSize(20);

    if (option_buttons_[i].text.c_str()) {
      ESAT::DrawText(x+margin, y+2*margin, option_buttons_[i].text.c_str());
    }
  }
}