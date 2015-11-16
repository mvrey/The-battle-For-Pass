/* 
 * File:   Screen.h
 * Author: Marcos Vazquez
 *
 * Created on November 15, 2015, 11:55 PM
 */

#ifndef SCREEN_H
#define SCREEN_H

#include <ESAT/window.h>
#include <ESAT/draw.h>
#include <ESAT/sprite.h>
#include <ESAT/input.h>

class Screen {
public:
    Screen();
    Screen(const Screen& orig);
    virtual ~Screen();
    
    void Input();
    void Update();
    void Draw();
    void DrawCursor();
    
    ESAT::SpriteHandle background_;
    ESAT::SpriteHandle cursor_sprite_;
    bool g_click = false;
    
private:
    void DrawBegin();
    void DrawEnd();

};

#endif /* SCREEN_H */

