/* 
 * File:   GameWon.cc
 * Author: Marcos Vazquez
 * 
 * Created on November 28, 2015, 3:18 PM
 */

#include "../../include/Screen/GameWon.h"

GameWon::GameWon() {
  background_ = ESAT::SpriteFromFile("assets/background/gamewon.png");
  num_buttons_ = 0;
}

GameWon::GameWon(const GameWon& orig) {
}

GameWon::~GameWon() {
}

void GameWon::Input() {
  click_ = ESAT::MouseButtonUp(0);
}

void GameWon::Update() {
  if (click_) {
    //go back to the game
    delete Manager::getInstance()->screen_;
    Manager::getInstance()->screen_ = new Game();
  }
}

void GameWon::Draw() {
  DrawBegin();
  
  ESAT::DrawSetTextSize(20);
  ESAT::DrawText(100.0f, 100.0f, "You have defeated the evil dragon and his minions.");
  ESAT::DrawText(100.0f, 130.0f, "The village of PASS rejoices and feasts in this victory.");
  ESAT::DrawText(100.0f, 160.0f, "Bards sing your name and every maiden wants you in their bed.");
  ESAT::DrawSetTextSize(50);
  ESAT::DrawText(500.0f, 380.0f, "GAME OVER");
  DrawEnd();
}
