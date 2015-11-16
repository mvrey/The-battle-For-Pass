/* 
 * File:   Screen.cc
 * Author: smuchy
 * 
 * Created on November 15, 2015, 11:55 PM
 */

#include "../../include/Screen/Screen.h"

Screen::Screen() {
    cursor_sprite_ = ESAT::SpriteFromFile("assets/UI/Crosshair_02.png");
    background_ = ESAT::SpriteFromFile("assets/background/intro.png");
}

Screen::Screen(const Screen& orig) {
}

Screen::~Screen() {
}

/// @brief  Common drawn elements and functions called in every screen
void Screen::DrawBegin() {
  ESAT::DrawBegin();
  ESAT::DrawClear(255, 255, 255);
  ESAT::DrawSprite(background_, 0, 0);
  //DrawOptionButtons();
}

/// @brief  Common finishing drawing functions called in every screen
void Screen::DrawEnd() {
  DrawCursor();
  ESAT::DrawEnd();
  ESAT::WindowFrame();
}

void Screen::Input() {
  g_click = ESAT::MouseButtonUp(0);
}

void Screen::Update() {

}

void Screen::Draw() {
  DrawBegin();
  DrawEnd();
}

void Screen::DrawCursor() {
  ESAT::DrawSprite(cursor_sprite_, (float)ESAT::MousePositionX(), (float)ESAT::MousePositionY());
}