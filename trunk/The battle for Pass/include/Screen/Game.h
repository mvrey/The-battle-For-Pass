/* Copyright 2015 Marcos Vazquez. All rights reserved.    
 * 
 * Author: Marcos Vazquez <vazquezre@esat-alumni.es>  
 * Created on November 9, 2015, 8:15 PM
 *
 * File:   Game.h                                              
 * A class that represents an the overwiev game
 *
 */

#ifndef GAME_H
#define GAME_H 1

#include "../../include/Screen/Battle.h"
#include "../../include/Screen/GameOver.h"
#include "../../include/Main/Manager.h"

class Game: public Screen {
  
  public:

    Game();
    Game(const Game& orig);
    ~Game();

    void Init();
    void Input();
    void Update();
    void Draw();
    void CreateButtons();
    void DrawStats();
    void DrawDialog(Friend* npc);
    
//    Map map_;
    ESAT::SpriteHandle stats_img_;
    bool drawing_stats_ = false;
    bool resting_ = false;
    bool buying_ = false;
    bool talking_ = false;
    bool just_bought_ = false;
    bool just_failed_bought_ = false;
    bool exit_ = false;

  private:
    
};

#endif /* GAME_H */

