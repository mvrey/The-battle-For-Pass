/* Copyright 2015 Marcos Vazquez. All rights reserved.    
 * 
 * Author: Marcos Vazquez <vazquezre@esat-alumni.es>  
 * Created on November 9, 2015, 12:34 PM
 *
 * File:   Manager.cc                                               
 * A class that holds all global variables used throughout the game 
 * or needed by various different classes
 *
 */

#include "../../include/Main/Manager.h"


Manager* Manager::instance_ = nullptr;


Manager::Manager() {
  screen_id_ = kScreen_Intro;
  screen_ = new Intro();
  quit_game_ = false;
  player_ = nullptr;
}

Manager::Manager(const Manager& orig) {
}

Manager::~Manager() {
  delete screen_;
//  delete map_;
  delete player_;

  for (int i=0; i<2; i++) {
    delete maps_[i];
    maps_[i] = nullptr;
  }
}

Manager* Manager::getInstance() {
  if(!instance_) {
      instance_ = new Manager();
  }

  return instance_;
}

void Manager::Reset() {
  delete instance_;
  instance_ = nullptr;
  instance_ = new Manager();
}