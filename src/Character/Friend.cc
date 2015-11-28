/* Copyright 2015 Marcos Vazquez. All rights reserved.    
 * 
 * Author: Marcos Vazquez <vazquezre@esat-alumni.es>  
 * Created on November 9, 2015, 12:06 PM
 * 
 * Represents a friendly character controlled by the AI
 */

#include "../../include/Character/Friend.h"

Friend::Friend(int type) {
  id_ = type;
}

Friend::Friend(const Friend& orig) {
}

Friend::~Friend() {
}

std::string Friend::Talk() {
  std::string speech;
  switch (id_) {
    case 1:
      speech = "Hi there stranger! My name is Ceecil Double Plus."
              " You are in the VILLAGE OF PASS, and you seem like a capable warrior that could help us. "
              " But for now, you should explore around. You can find Ada, the potions merchant, inside her house (any house)."
              " If you are willing to help us, go see Arian. She should be working the fields right now. "
              " Oh! And beware the snakes that roam around the village!";
      break;
    case 2:
      speech = "Hello, my name is Arian Summerfield the Third. I've heard you can help us with the beast at the FORTRESS OF DISTINCTION."
              " During the past years, a group of monsters and mercenaries have been raiding us. We have barely nothing left, and we won't be able to hold much more."
              " We would owe you eternal gratitude if you decide to tackle down the monster and its minions."
              " You need to exit the village and enter the MARSH OF MERIT. You'll see there an abandoned mine whose pasage leads to the FORTRESS OF DISTINCTION. "
              " Inside the fortress is a magical orb. Destroy the beast that lurks the HALL OF POINTERS and you'll be done."
              " Good luck you chump!";
      break;
    default:
      speech = "I AM ERROR";
      break;
  }
  
  return speech;
}