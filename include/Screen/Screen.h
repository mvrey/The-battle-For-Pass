/* 
 * File:   Screen.h
 * Author: Marcos Vazquez
 *
 * Created on November 15, 2015, 11:55 PM
 */

#ifndef SCREEN_H
#define SCREEN_H 1

#include <ESAT/window.h>
#include <ESAT/draw.h>
#include <ESAT/sprite.h>
#include <ESAT/input.h>

#include <string>
#include <math.h> 

class Screen {
public:
  typedef struct {
    float x;
    float y;
  } Point2;

  typedef struct {
    Point2 pos;
    ESAT::SpriteHandle img;
    std::string text;
    float height;
    float width;
    unsigned short int option;
    bool border;
  } Button;

  typedef struct {
    Point2 pos;
    int size;
    std::string txt;
  } TextBox;

  Screen();
  Screen(const Screen& orig);
  virtual ~Screen();

  void virtual Init();
  void virtual Input();
  void virtual Update();
  void virtual Draw();
  void DrawCursor();
  void virtual CreateButtons();
  void CreateButton(float x, float y, float height, float width,
  int option, ESAT::SpriteHandle img, std::string txt, bool has_border);
  void DrawButtons();
  void InitPoint2(Point2 *p, float x, float y);
  void DrawTextWithLineBreaks(float x, float y, int width, int font_size, std::string txt);
  void DrawRectangle(float x, float y, int width, int height, int color, bool faces_right);
  void DrawTextBox(TextBox box);
  
  ESAT::SpriteHandle background_;
  ESAT::SpriteHandle cursor_sprite_;
  ESAT::SpriteHandle button_background_;
  
  bool click_ = false;
    
protected:
  void DrawBegin();
  void DrawEnd();
  void InitText();
  int CheckButtonsClick();
  
  Button option_buttons_[10];
  short int num_buttons_ = 0;

};

#endif /* SCREEN_H */

