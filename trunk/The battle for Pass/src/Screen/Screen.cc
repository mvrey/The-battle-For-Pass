/* 
 * File:   Screen.cc
 * Author: Marcos Vazquez
 * 
 * Created on November 15, 2015, 11:55 PM
 */

#include "../../include/Screen/Screen.h"

const int kWindowWidth = 1366;
const int kWindowHeight = 768;

/// @brief Creates a screen and loads its sprites
Screen::Screen() {
    cursor_sprite_ = ESAT::SpriteFromFile("assets/UI/Crosshair_02.png");
    background_ = ESAT::SpriteFromFile("assets/background/main_background.png");
    button_background_ = ESAT::SpriteFromFile("assets/UI/button_bg.png");
    Init();
}

Screen::Screen(const Screen& orig) {
}

Screen::~Screen() {
//  ESAT::SpriteRelease(background_);
  ESAT::SpriteRelease(cursor_sprite_);
  ESAT::SpriteRelease(button_background_);

  for (int i=0; i<num_buttons_; i++) {
//    delete(option_buttons_[i]);
  }
//  free(option_buttons_);
}

void Screen::Init() {
  InitText();
  CreateButtons();
}

/** @brief  Common drawn elements and functions called in every screen
 *
 *  This method must be called at the start of every Draw cycle.
 *  Draws screen background.
 *
 */
void Screen::DrawBegin() {
  ESAT::DrawBegin();
  ESAT::DrawClear(255, 255, 255);
  
  //Draw background image
  float sprite_width = ESAT::SpriteWidth(background_);
  float sprite_height = ESAT::SpriteHeight(background_);
  ESAT::Mat3 escale;
  ESAT::Mat3InitAsScale((float)kWindowWidth/sprite_width, (float)kWindowHeight/sprite_height, &escale);
  ESAT::DrawSpriteWithMatrix(background_, escale);
  
  DrawButtons();
}

/** @brief Common finishing drawing functions called in every screen
 *
 *  This method must be called at the start of every Draw cycle.
 *  Draws cursor sprite and updates screen to the next frame.
 *
 */
void Screen::DrawEnd() {
  DrawCursor();
  ESAT::DrawEnd();
  ESAT::WindowFrame();
}

/// @brief Detects mouse click
void Screen::Input() {
  click_ = ESAT::MouseButtonUp(0);
}

/** @brief Updates the screen
 */
void Screen::Update() {

}

/// @brief Draws the screen
void Screen::Draw() {
  DrawBegin();
  
  ESAT::DrawText(300.0f, 50.0f, "The Battle for Pass - SuperGeneric Screen");
  
  DrawEnd();
}

/** @brief Draws the cursor
 *  Draws the sprite cursor_sprite_ on the mouse coordinates
 */
void Screen::DrawCursor() {
  ESAT::DrawSprite(cursor_sprite_, (float)ESAT::MousePositionX(), (float)ESAT::MousePositionY());
}

/// @brief Creates buttons for the current screen
void Screen::CreateButtons() {
  num_buttons_ = 0;
  
  CreateButton(500.0f, 120.0f, 110.0f, 250.0f, 0, button_background_, "New Game", false);
  CreateButton(500.0f, 260.0f, 110.0f, 250.0f, 0, button_background_, "Load Game", false);
  CreateButton(500.0f, 400.0f, 110.0f, 250.0f, 0, button_background_, "Options", false);
  CreateButton(500.0f, 540.0f, 110.0f, 250.0f, 0, button_background_, "Exit Game", false);
}

/** @brief Creates a interactive t_Button and saves it to g_option_buttons
*  @param x X coordinate of the top-left corner
*  @param y Y coordinate of the top-left corner
*  @param height Number of pixels height
*  @param width Number of pixels width
*  @param option If this is an ingame button, this is used as selection of movement (Rock/Paper/scissors)
*  @param img   An image that will be placed inside the button. It'll be ignored if NULL
*  @param txt   A text that will be displayed inside the button. It'll be ignored if NULL
*  @param height Whether a blue border will be drawn or not
*/
void Screen::CreateButton(float x, float y, float height, float width,
  int option, ESAT::SpriteHandle img, std::string txt, bool has_border) {
  Button b;

  InitPoint2(&b.pos, x, y);
  b.img = img;

  b.text = txt;

  b.height = height;
  b.width = width;
  b.option = option;
  b.border = has_border;
  option_buttons_[num_buttons_] = b;
  num_buttons_++;
}


/// @brief  Draws all t_Buttons contained within option_buttons_
void Screen::DrawButtons() {
  float x = 0.0f;
  float y = 0.0f;
  float height = 0.0f;
  float width = 0.0f;
  float margin = 30.0f;

  for (int i = 0; i < num_buttons_; i++) {
    x = option_buttons_[i].pos.x;
    y = option_buttons_[i].pos.y;
    height = option_buttons_[i].height;
    width = option_buttons_[i].width;

    if (option_buttons_[i].border) {
      float path_points[] = { x, y,
        x + width, y,
        x + width, y + height,
        x, y + height,
        x, y
      };

      /*rgb colors inside the polygon*/
      ESAT::DrawSetFillColor(0, 0, 0, 0);

      ESAT::DrawSetStrokeColor(255, 255, 255, 255);

      ESAT::DrawSolidPath(path_points, 5, true);
    }

    if (option_buttons_[i].img) {
      
      //Adjust background image to button
      float sprite_width = ESAT::SpriteWidth(option_buttons_[i].img);
      float sprite_height = ESAT::SpriteHeight(option_buttons_[i].img);
      ESAT::Mat3 translate, escale, transform;
      ESAT::Mat3InitAsScale((float)width/sprite_width, (float)height/sprite_height, &escale);
      ESAT::Mat3InitAsTranslate(option_buttons_[i].pos.x, option_buttons_[i].pos.y, &translate);
      ESAT::Mat3Multiply(translate, escale, &transform);
      
      ESAT::DrawSpriteWithMatrix(option_buttons_[i].img, transform);
    }

    ESAT::DrawSetTextSize(25);

    if (option_buttons_[i].text.c_str()) {
      ESAT::DrawText(x+margin, y+2*margin, option_buttons_[i].text.c_str());
    }
  }
}

/** @brief Initializes a Point2 with given coordinates
*  @param p The Point2 to initialize
*  @param x X coordinate of the point
*  @param y Y coordinate of the point
*/
void Screen::InitPoint2(Point2 *p, float x, float y) {
  (*p).x = x;
  (*p).y = y;
}

/// @brief  Stablishes initial font settings
void Screen::InitText() {
  ESAT::DrawSetTextFont("assets/UI/medieval.ttf");
  ESAT::DrawSetTextSize(40);
  ESAT::DrawSetFillColor(0, 0, 0);
  ESAT::DrawSetStrokeColor(0, 0, 0);
}

/// @brief  Checks and returns the index of the button clicked inside g_option_buttons. Returns -1 if no button is clicked.
int Screen::CheckButtonsClick() {
  int i, click = 0;
  float x = 0.0f;
  float y = 0.0f;
  float height = 0.0f;
  float width = 0.0f;

  for (i = 0; i < num_buttons_ && !click; i++) {
    x = option_buttons_[i].pos.x;
    y = option_buttons_[i].pos.y;
    height = option_buttons_[i].height;
    width = option_buttons_[i].width;

    //Check if clicked inside the button
    if (ESAT::MousePositionX() > x
      && ESAT::MousePositionX() < x + width
      && ESAT::MousePositionY() > y
      && ESAT::MousePositionY() < y + height) {
      click = 1;
    }
  }
  return (click) ? i - 1 : -1;
}

/// @brief  An alias for Screen::CheckButtonsClick(), to be used for detecting hover
int Screen::CheckButtonsHover() {
  return CheckButtonsClick();
}

void Screen::DrawTextWithLineBreaks(float x, float y, int width, int font_size, std::string txt) {
  ESAT::DrawSetTextSize(font_size);
  
  int chars_per_line = width / font_size;
  int num_lines = ceil(txt.length()/(chars_per_line));
  
  for (int i=0; i <= num_lines; i++) {
    ESAT::DrawText(x, y+((i+1)*font_size), txt.substr (i*chars_per_line, chars_per_line).c_str());
  }
}


void Screen::DrawRectangle(float x, float y, int width, int height, int color, bool faces_right) {
    
  if (!faces_right) {
    x -= width;
  }

  float path_points[] = { x, y,
    x + width, y,
    x + width, y + height,
    x, y + height,
    x, y
  };

  int red = (color & 0xFF000000) >> 24;
  int green = (color & 0x00FF0000) >> 16;
  int blue = (color & 0x0000FF00) >> 8;
  int alpha = (color & 0x000000FF);
  
  ESAT::DrawSetFillColor(red, green, blue, alpha);

  ESAT::DrawSetStrokeColor(255, 255, 255, 255);

  ESAT::DrawSolidPath(path_points, 5, true);
}

/// @brief  Prints a TextBox
void Screen::DrawTextBox(TextBox box) {
  int padding = 20;

  float pathPoints[] = { box.pos.x, box.pos.y,
    box.pos.x + box.size*8.0f, box.pos.y,
    box.pos.x + box.size*8.0f, box.pos.y + box.size,
    box.pos.x, box.pos.y + box.size,
    box.pos.x, box.pos.y
  };

  ESAT::DrawSetFillColor(30, 30, 0);

  ESAT::DrawSetStrokeColor(255, 255, 255);

  ESAT::DrawSolidPath(pathPoints, 5, true);

  ESAT::DrawSetFillColor(150, 150, 150);
  ESAT::DrawText(box.pos.x, box.pos.y + padding, box.txt.c_str());
}