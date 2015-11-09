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

void updateIntro() {

}

void drawIntro() {

}


int main(int argc, char** argv) {

  Manager* manager = Manager::getInstance();  
  
  input();
  
  switch(manager->screen_) {
    case 0:
      input();
      updateIntro();
      drawIntro();
      break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5: 
    default:
      break;
  }
  
  return 0;
}

