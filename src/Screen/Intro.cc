/* 
 * File:   Intro.cc
 * Author: Marcos Vazquez
 * 
 * Created on November 15, 2015, 11:55 PM
 */

#include "../../include/Screen/Intro.h"

Intro::Intro() {
}

Intro::Intro(const Intro& orig) {
}

Intro::~Intro() {
}

void Intro::Update() {
  Manager::getInstance()->screen_ = new MainMenu();
}

void Intro::Draw() {
  DrawBegin();
  
  ESAT::DrawText(200.0f, 200.0f, "The Battle for Pass - Intro");
  DrawEnd();
}
