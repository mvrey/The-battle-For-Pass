/* 
 * File:   GameOver.cc
 * Author: Marcos Vazquez
 * 
 * Created on November 24, 2015, 12:54 PM
 */

#include "../../include/Screen/GameOver.h"

GameOver::GameOver() {
  background_ = ESAT::SpriteFromFile("assets/background/gameover.png");
  num_buttons_ = 0;
}

GameOver::GameOver(const GameOver& orig) {
}

GameOver::~GameOver() {
}

void GameOver::Input() {
  click_ = ESAT::MouseButtonUp(0);
}

void GameOver::Update() {
  if (click_) {
    Manager::Reset();
  }
}

void GameOver::Draw() {
  DrawBegin();
  
  ESAT::DrawSetTextSize(20);
  ESAT::DrawText(100.0f, 100.0f, "You have failed in your mission. All hope is lost.");
  ESAT::DrawText(100.0f, 130.0f, "As darkness surrounds you, you realize your people");
  ESAT::DrawText(100.0f, 160.0f, "and the village of PASS will now face the same fate.");
  ESAT::DrawSetTextSize(50);
  ESAT::DrawText(500.0f, 380.0f, "GAME OVER");
  DrawEnd();
}
