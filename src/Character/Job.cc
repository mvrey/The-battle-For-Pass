/* Copyright 2015 Marcos Vazquez. All rights reserved.    
 * 
 * Author: Marcos Vazquez <vazquezre@esat-alumni.es>  
 * Created on November 16, 2015, 6:29 PM
 * 
 * Represents a profession/class for a given character
 */

#include "../../include/Character/Job.h"

std::string Job::job_names_[4];

Job::Job() {
}

Job::Job(const Job& orig) {
}

Job::~Job() {
  Init();
}

void Job::Init() {
  job_names_[0] = "boss";
  job_names_[1] = "hunter";
  job_names_[2] = "warrior";
  job_names_[3] = "wizad";
}


void Job::LoadFaces(std::string race_name, ESAT::SpriteHandle imgs[]) {
  std::string path;
  
  for (int i=0; i<num_jobs_; i++) {
    path = "assets/character" + race_name + "/" + Job::job_names_[i] + "/face.png";
    imgs[i] = ESAT::SpriteFromFile(path.c_str());
  }
}