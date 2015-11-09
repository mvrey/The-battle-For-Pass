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

#include "../include/Manager.h"


Manager* Manager::instance_ = nullptr;


Manager::Manager() {
  screen_ = kScreen_Intro;
  map_ = kMap_Village;
}

Manager::Manager(const Manager& orig) {
}

Manager::~Manager() {
}

Manager* Manager::getInstance() {
  if(!instance_) {
      instance_ = new Manager();
  }

  return instance_;
}