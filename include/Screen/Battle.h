/* 
 * File:   Battle.h
 * Author: Marcos Vazquez
 *
 * Created on November 23, 2015, 12:06 PM
 */

#ifndef BATTLE_H
#define BATTLE_H 1

#include "Screen.h"
#include "Game.h"
#include "../../include/Character/Foe.h"

class Battle: public Screen {
public:
  Battle();
  Battle(Foe* enemy);
  Battle(const Battle& orig);
  virtual ~Battle();
  
  void Init();
  void Input();
  void Update();
  void Draw();
  void CreateButtons();
  void DrawLog();
  void Fight();
  void CheckLogLength();
  void Flee();
  void CheckResult();
  void DrawSpells();
  
  Foe* enemy_;
  ESAT::SpriteHandle spells_img_;
  std::string log_;
  bool is_over_;
  bool drawing_spells_ = false;
  
private:

};

#endif /* BATTLE_H */

