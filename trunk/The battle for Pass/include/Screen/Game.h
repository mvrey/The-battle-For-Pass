/* Copyright 2015 Marcos Vazquez. All rights reserved.    
 * 
 * Author: Marcos Vazquez <vazquezre@esat-alumni.es>  
 * Created on November 9, 2015, 8:15 PM
 *
 * File:   Map.h                                              
 * A class that represents an the overwiev game
 *
 */

#ifndef GAME_H
#define GAME_H 1

#include "../../include/Screen/Screen.h"
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
    
    Map map_;

  private:
    
};

#endif /* GAME_H */

