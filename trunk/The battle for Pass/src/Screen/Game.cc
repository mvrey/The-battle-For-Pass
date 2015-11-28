/* 
 * File:   Game.cc
 * Author: Marcos Vazquez
 * 
 * Created on November 15, 2015, 12:13 AM
 */

#include "../../include/Screen/Game.h"

Game::Game() {
  Screen();
  Init();
}

Game::Game(const Game& orig) {
}

Game::~Game() {
}

void Game::Init() {
  CreateButtons();
  stats_img_ = ESAT::SpriteFromFile("assets/raw/stats.png");
}

void Game::Input() {
  click_ = ESAT::MouseButtonUp(0);
  Grid* collisions = Manager::getInstance()->map_->collisions_;
  
  if (ESAT::IsKeyUp('S')) {
    drawing_stats_ = !drawing_stats_;
  }
  if (ESAT::IsKeyUp('R')) {
    resting_ = true;
  }
  if (ESAT::IsKeyUp('B')) {
    buying_ = true;
  }
  
  if (!drawing_stats_) {
    if (ESAT::IsSpecialKeyPressed(ESAT::kSpecialKey_Up)) {
      Manager::getInstance()->player_->Move(0, collisions);
    } else if (ESAT::IsSpecialKeyPressed(ESAT::kSpecialKey_Right)) {
      Manager::getInstance()->player_->Move(1, collisions);
    } else if (ESAT::IsSpecialKeyPressed(ESAT::kSpecialKey_Down)) {
      Manager::getInstance()->player_->Move(2, collisions);
    } else if (ESAT::IsSpecialKeyPressed(ESAT::kSpecialKey_Left)) {
      Manager::getInstance()->player_->Move(3, collisions);
    }
  }
}

void Game::Draw() {
  DrawBegin();
  
  Map* map = Manager::getInstance()->map_;
  Ally* player = Manager::getInstance()->player_;
  
  for (int i=0; i<map->num_tiles; i++) {
    ESAT::DrawSpriteWithMatrix(map->tiles[i].sprite, map->tiles[i].transform);
  }
  
  ESAT::Mat3 escale, translate, transform;
  ESAT::Mat3InitAsScale(map->player_escale_, map->player_escale_, &escale);
  ESAT::Mat3InitAsTranslate(player->x, player->y - ESAT::SpriteHeight(player->current_sprite_)*map->player_escale_, &translate);
  ESAT::Mat3Multiply(translate, escale, &transform);
  ESAT::DrawSpriteWithMatrix(player->current_sprite_, transform);
  
  if (drawing_stats_) {
    DrawStats();
  }
  if (talking_) {
  DrawDialog();
  }
  
  DrawEnd();
}


/// @brief  Updates main menu status
void Game::Update() {
  Ally* player = Manager::getInstance()->player_;
  Grid* enemies = Manager::getInstance()->map_->enemies_;
  Grid* portals = Manager::getInstance()->map_->portals_;
  Grid* npcs = Manager::getInstance()->map_->npcs_;
  
  if (click_ && player->HP_ <= 0) {
    delete Manager::getInstance()->screen_;
    Manager::getInstance()->screen_ = new GameOver();
  }
  
  player->Update(Manager::getInstance()->map_->tile_width_,
                  Manager::getInstance()->map_->tile_height_);
  
  
  if (resting_) {
    int num = Misc::random(100);
    if (num < 50) {
      Foe* enemy = Manager::getInstance()->map_->SelectRandomEnemy();
      enemies->setElement(player->tile_x, player->tile_y, enemy);
    } else {
      player->HP_ = player->max_HP_;
      player->MP_ = player->max_MP_;
    }
    resting_ = false;
  }
  
  //If there's an enemy at player's position, a battle begins
  if (enemies->getElement(player->tile_x, player->tile_y)) {
    Manager::getInstance()->screen_ = new Battle((Foe*)enemies->getElement(player->tile_x, player->tile_y));
    Manager::getInstance()->screen_->Init();
    
    //The enemy is removed from the enemies Grid beforehand
    Manager::getInstance()->map_->enemies_->setElement(player->tile_x, player->tile_y, 0);
  } else if (portals->getElement(player->tile_x, player->tile_y)) {
    printf("Entering a portal\n");
    Manager::getInstance()->map_ = (Map*)portals->getElement(player->tile_x, player->tile_y);
    printf("Repositioning player\n");
    if (Manager::getInstance()->map_->last_x_ && Manager::getInstance()->map_->last_y_) {
      player->tile_x = Manager::getInstance()->map_->last_x_;
      player->tile_y = Manager::getInstance()->map_->last_y_;
    } else {
      player->tile_x = Manager::getInstance()->map_->init_x_;
      player->tile_y = Manager::getInstance()->map_->init_y_;
    }
    
    player->x = player->tile_x * Manager::getInstance()->map_->tile_width_;
    player->y = player->tile_y * Manager::getInstance()->map_->tile_height_;

    printf("Screen has changed\n");
  } else {
    Manager::getInstance()->map_->last_x_ = player->tile_x;
    Manager::getInstance()->map_->last_y_ = player->tile_y;
  }
  
  
  //Healing potions merchant
  if (npcs->getElement(player->tile_x, player->tile_y) != nullptr) {
    talking_ = true;
    if (buying_) {
      if (player->gold_ >= 15) {
        player->gold_ -= 15;
        player->num_healing_potions_++;
        buying_ = false;
        just_failed_bought_ = false;
        just_bought_ = true;
      } else  {
        just_bought_ = false;
        just_failed_bought_ = true;
      }
    }
  } else {
    buying_ = false;
    talking_ = false;
    just_bought_ = false;
    just_failed_bought_ = false;
  }
}


void Game::CreateButtons() {
  num_buttons_ = 0;
}



void Game::DrawDialog() {
  Screen::DrawRectangle(200.0f, 600.0f, 1000.0f, 200.0f, 0x55555599, true);
  ESAT::DrawSetFillColor(255, 255, 255, 255);
  ESAT::DrawSetTextSize(18);
  ESAT::DrawText(240.0f, 660.0f, "You can buy healing potions (15gc each) from me by pressing 'B'");
  
  if (just_bought_) {
    ESAT::DrawText(240.0f, 700.0f, "Thank you for your purchase!");
  } else if (just_failed_bought_) {
    ESAT::DrawText(240.0f, 700.0f, "You do not have the required coin!");
  }
}


void Game::DrawStats() {
  Ally* player = Manager::getInstance()->player_;
  int base_x = 200;
  float bar_max_length = 505.0f;
  float bar_length = 0;
  std::string bar_str;
  
  ESAT::DrawSetTextSize(18);
  ESAT::DrawSprite(stats_img_, base_x, 0);
  ESAT::DrawText(base_x+210.0f, 123.0f, std::to_string(player->level_).c_str());
  
  bar_str = std::to_string((int)player->xp_)+" / "+std::to_string((int)player->next_level_xp_);
  bar_length = ((float)player->xp_ / (float)player->next_level_xp_) * bar_max_length;
  Screen::DrawRectangle(base_x+255.0f, 107.0f, bar_length, 20.0f, 0xCCCCCCDD, true);
  ESAT::DrawSetFillColor(255, 255, 255, 255);
  ESAT::DrawText(base_x+450.0f, 120.0f, bar_str.c_str());
  
  bar_str = std::to_string((int)player->HP_)+" / "+std::to_string((int)player->max_HP_);
  bar_length = ((float)player->HP_ / (float)player->max_HP_) * bar_max_length;
  Screen::DrawRectangle(base_x+255.0f, 145.0f, bar_length, 20.0f, 0x00CC00DD, true);
  ESAT::DrawSetFillColor(255, 255, 255, 255);
  ESAT::DrawText(base_x+450.0f, 158.0f, bar_str.c_str());
  
  bar_str = std::to_string((int)player->MP_)+" / "+std::to_string((int)player->max_MP_);
  bar_length = ((float)player->MP_ / (float)player->max_MP_) * bar_max_length;
  Screen::DrawRectangle(base_x+255.0f, 183.0f, bar_length, 20, 0x0000CCDD, true);
  ESAT::DrawSetFillColor(255, 255, 255, 255);
  ESAT::DrawText(base_x+450.0f, 196.0f, bar_str.c_str());
  
  ESAT::DrawSetTextSize(18);
  ESAT::DrawSetFillColor(255, 255, 255, 255);
  
  ESAT::DrawText(base_x+465.0f, 348.0f, std::to_string((int)player->attack_).c_str());
  ESAT::DrawText(base_x+465.0f, 498.0f, std::to_string((int)player->defense_).c_str());
  
  ESAT::DrawText(base_x+700.0f, 668.0f, std::to_string((int)player->gold_).c_str());
  ESAT::DrawText(base_x+210.0f, 668.0f, std::to_string((int)player->num_healing_potions_).c_str());
}