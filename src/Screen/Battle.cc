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
}

Battle::Battle(const Battle& orig) {
}

Battle::~Battle() {
}

void Battle::Init() {
  printf("initializing battle\n");
  num_buttons_ = 0;
}

void Battle::Input() {
  
  if (ESAT::IsKeyDown('F')) {
    Manager::getInstance()->screen_ = new Game();
  }
    
}

void Battle::Draw() {
  DrawBegin();
  
  //Print Healthbars and bust/battler images
  //Print options to attack/flee/cast_spell
  
  Ally* player = Manager::getInstance()->player_;
  
  ESAT::DrawSprite(player->battler_img_, 100, 100);
  
  ESAT::DrawSprite(enemy_->battler_img_, 1000, 250);
  
  DrawEnd();
}
