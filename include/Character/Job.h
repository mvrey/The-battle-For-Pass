/* Copyright 2015 Marcos Vazquez. All rights reserved.    
 * 
 * Author: Marcos Vazquez <vazquezre@esat-alumni.es>  
 * Created on November 16, 2015, 6:28 PM
 */

#ifndef JOB_H
#define JOB_H 1

#include <ESAT/sprite.h>

#include <string>
#include "Race.h"

class Job {
public:
  Job();
  Job(const Job& orig);
  virtual ~Job();
  void Init();
  static void LoadImages(Race* race);
  
  int id_;
  std::string name_;
  std::string description_;
  ESAT::SpriteHandle description_image_;
  
  static std::string job_names_[4];
  static const int num_jobs_ = 4;
  
private:
  
};

#endif /* JOB_H */

