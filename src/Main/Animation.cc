/* Copyright 2015 Marcos Vazquez. All rights reserved.    
 * 
 * Author: Marcos Vazquez <vazquezre@esat-alumni.es>  
 * Created on November 9, 2015, 2:06 PM
 *
 * File:   Manager.cc                                               
 * A class that manages sprites and animations
 *
 */

#include "../../include/Main/Animation.h"

Animation::Animation() {
}

Animation::Animation(const Animation& orig) {
}

/** @brief
 *
 *
 *
 *  @return
 *  @param
 *  @param
 */
Animation::~Animation() {
  for (int i=0; i<num_frames_; i++) {
    if (frames_[i] != nullptr)
      ESAT::SpriteRelease(frames_[i]);
    frames_[i] = nullptr;
  }
  num_frames_ = 0;
  free(*frames_);
}

/** @brief
 *
 *
 *
 *  @return
 *  @param
 *  @param
 */
void Animation::LoadFromFile(std::string path, int rows, int columns, float width, 
                        float height, float offsetX, float offsetY) {

  num_frames_ = 0;
  ESAT::SpriteHandle spritesheet = ESAT::SpriteFromFile(path.c_str());
  
  for (int j=0; j<columns; j++) {
    for (int i=0; i<rows; i++) {
      frames_[num_frames_] = Misc::GetSubImage(spritesheet, offsetX+(width*j), offsetY+(height*i), width, height);
      num_frames_++;
    }
  }
  
  current_frame_ = 0;
}

/** @brief
 *
 *
 *
 *  @return
 *  @param
 *  @param
 */
int Animation::NextFrame() {
  current_frame_++;
  
  if (current_frame_ >= num_frames_) {
    current_frame_ = 0;
  }
  
  return current_frame_;
}