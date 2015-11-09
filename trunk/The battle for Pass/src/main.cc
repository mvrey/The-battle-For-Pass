/* Copyright 2015 Marcos Vazquez. All rights reserved.    
 * 
 * Author: Marcos Vazquez <vazquezre@esat-alumni.es>  
 * Created on November 8, 2015, 19:53 PM
 * 
 * The alpha code of main
 */

#include <cstdlib>
#include <stdio.h>

#include "../include/Grid.h"

#include "../include/Character.h"
#include "../include/Ally.h"
#include "../include/Friend.h"
#include "../include/Foe.h"
#include "../include/Inventory.h"
#include "../include/Item.h"
#include "../include/Manager.h"




 /*
 * Global vars
 */
 
//window size
const int kWindowWidth = 800;
const int kWindowHeight = 600;


void input() {
  
}

/*** INTRO ***/

void updateIntro() {

}

void drawIntro() {

}

/*** MAIN MENU ***/

void updateMainMenu() {

}

void drawMainMenu() {

}

/*** LOAD GAME ***/

void updateLoadGame() {

}

void drawLoadGame() {

}

/*** NEW GAME ***/

void updateNewGame() {

}

void drawNewGame() {

}

/*** MAP ***/

void updateMap() {

}

void drawMap() {

}

/*** FIGHT ***/

void updateFight() {

}

void drawFight() {

}

/*** GAME OVER ***/

void updateGameOver() {

}

void drawGameOver() {

}


/*** MAIN ***/


int main(int argc, char** argv) {

  Manager* manager = Manager::getInstance();  
  
  input();
  
  switch(manager->screen_) {
    case 0:
      updateIntro();
      drawIntro();
      break;
    case 1:
      updateMainMenu();
      drawMainMenu();
      break;
    case 2:
      updateLoadGame();
      drawLoadGame();
      break;
    case 3:
      updateNewGame();
      drawNewGame();
      break;
    case 4:
      updateMap();
      drawMap();
      break;
    case 5: 
      updateFight();
      drawFight();
      break;
    case 6: 
      updateGameOver();
      drawGameOver();
      break;
    default:
      break;
  }
  
  return 0;
}

