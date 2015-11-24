/* 
 * File:   Misc.cc
 * Author: Marcos Vazquez
 * 
 * Created on November 23, 2015, 1:22 AM
 */

#include "../../include/Main/Misc.h"


Misc::Misc() {
}

Misc::Misc(const Misc& orig) {
}

Misc::~Misc() {
}

ESAT::SpriteHandle Misc::GetSubImage(ESAT::SpriteHandle img, int x, int y, int width, int height) {
  //Iterate through every single pixel and add it to a pixel buffer
  //unsigned char pixel_buffer[height*width*4];
  std::vector<unsigned char> pixel_buffer(height*width*4);;
  int buffer_index=0;

  for (int h=y; h<y+height; h++) {
    for (int w=x; w<x+width; w++) {
      unsigned char outRGBA[4];
      ESAT::SpriteGetPixel(img, w, h, outRGBA);
      pixel_buffer[buffer_index+0] = outRGBA[0];
      pixel_buffer[buffer_index+1] = outRGBA[1];
      pixel_buffer[buffer_index+2] = outRGBA[2];
      pixel_buffer[buffer_index+3] = outRGBA[3];
      buffer_index += 4;
    }
  }
  
  unsigned char* pixels_array = &pixel_buffer[0];
  
  return ESAT::SpriteFromMemory(width, height, pixels_array);
}

/* Calculates a random number between 0 and <limit> */
int Misc::random(int limit) {
	return (rand() % limit);
}

/* Randomly returns 1 or -1*/
int Misc::random_sign() {
	if (random(2) == 1)
		return 1;
	else
		return -1;
}