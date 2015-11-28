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
#include "../../include/Enemy/Foe.h"
#include "../../include/Spell/Heal.h"
#include "../../include/Spell/FireSword.h"
#include "../../include/Spell/Blizzard.h"

class Battle: public Screen {
public:
  Battle();
  Battle(Foe* enemy);
  Battle(const Battle& orig);
  virtual ~Battle();
  
  void Init();
  void Input();
  void Update();
  void DrawBegin();
  void Draw();
  void CreateButtons();
  void DrawLog();
  void Fight(bool player_attacks);
  void CheckLogLength();
  void Flee();
  void CheckResult();
  void DrawSpells();
  void DrawButtons();
  
  Foe* enemy_;
  ESAT::SpriteHandle spells_img_;
  std::string log_;
  bool is_over_;
  bool drawing_spells_ = false;

  //Player stats when entering battle to restore them later
  int original_attack_;
  int original_defense_;
private:

};

#endif /* BATTLE_H */

