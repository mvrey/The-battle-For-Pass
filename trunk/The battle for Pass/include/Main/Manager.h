/* Copyright 2015 Marcos Vazquez. All rights reserved.    
 * 
 * Author: Marcos Vazquez <vazquezre@esat-alumni.es>  
 * Created on November 9, 2015, 12:34 PM
 *
 * File:   Manager.h                                              
 * A class that holds all global variables used throughout the game 
 * or needed by various different classes
 *
 */

#ifndef MANAGER_H
#define MANAGER_H 1

#include "../../include/Main/Map.h"
#include "../../include/Character/Ally.h"
#include "../../include/Screen/Screen.h"

class Manager {
public:
    //Screens in the game
    enum ScreenId {
      kScreen_Intro,
      kScreen_MainMenu,
      kScreen_LoadGame,
      kScreen_NewGame,
      kScreen_Map,
      kScreen_Fight,
      kScreen_GameOver
    };
    
    static Manager* getInstance();
    
    ScreenId screen_id_;
    Screen* screen_;
    Map map_;
    Ally player_;


private:
    
    Manager();
    Manager(const Manager& orig);
    ~Manager();
    
    static Manager* instance_;
};

#endif /* MANAGER_H */

