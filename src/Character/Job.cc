/* Copyright 2015 Marcos Vazquez. All rights reserved.    
 * 
 * Author: Marcos Vazquez <vazquezre@esat-alumni.es>  
 * Created on November 16, 2015, 6:29 PM
 * 
 * Represents a profession/class for a given character
 */

#include "../../include/Character/Job.h"

std::string Job::job_names_[4] = {"boss", "hunter", "warrior", "wizard"};

Job::Job() {
}

Job::Job(const Job& orig) {
}

Job::~Job() {
  ESAT::SpriteRelease(description_image_);
}

/** @brief
 *
 *
 *
 *  @return
 *  @param
 *  @param
 */
void Job::LoadImages(Race* race) {
  std::string face_path, bust_path;
  
  for (int i=0; i<num_jobs_; i++) {
    face_path = "assets/character/" + race->name_ + "/" + Job::job_names_[i] + "/face.png";
    printf("Loading job face from %s\n", face_path.c_str());
    race->face_imgs_[i] = ESAT::SpriteFromFile(face_path.c_str());
    bust_path = "assets/character/" + race->name_ + "/" + Job::job_names_[i] + "/bust.png";
    printf("Loading bust from %s\n", bust_path.c_str());
    race->bust_imgs_[i] = ESAT::SpriteFromFile(bust_path.c_str());
  }
}