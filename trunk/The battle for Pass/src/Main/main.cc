/* Copyright 2015 Marcos Vazquez. All rights reserved.    
 * 
 * Author: Marcos Vazquez <vazquezre@esat-alumni.es>  
 * Created on November 8, 2015, 19:53 PM
 * 
 * The alpha code of main
 */

#include <ESAT/window.h>
#include <ESAT/draw.h>
#include <ESAT/sprite.h>
#include <ESAT/input.h>

#include <cstdlib>
#include <stdio.h>
#include <time.h>

#include "../../include/Main/Grid.h"

#include "../../include/Character/Character.h"
#include "../../include/Character/Ally.h"
#include "../../include/Character/Friend.h"
#include "../../include/Character/Foe.h"
#include "../../include/Character/Race.h"
#include "../../include/Character/Job.h"

#include "../../include/Item/Inventory.h"
#include "../../include/Item/Item.h"
#include "../../include/Main/Manager.h"

#include "../../include/Screen/Intro.h"
#include "../../include/Screen/MainMenu.h"
#include "../../include/Screen/NewGame.h"

#include "../../lib/TMXparser/Tmx.h.in"
#include "../../lib/TMXparser/tinyxml2.cpp"
 /*
 * Global vars
 */

//Empty


//Global functions
//Empty

/*** MAIN ***/


int ESAT::main(int argc, char **argv) {

  srand(time(NULL));

  ESAT::WindowInit(kWindowWidth, kWindowHeight);

  Manager* manager = Manager::getInstance();
  
  
  while (ESAT::WindowIsOpened() && !manager->quit_game_) {
    manager->screen_->Input();
    manager->screen_->Update();
    manager->screen_->Draw();
  }
  
  ESAT::WindowDestroy();
  return 0;
}

